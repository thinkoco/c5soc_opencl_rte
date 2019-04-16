/*
 * FPGA Framework file operations
 *
 *  Copyright (C) 2013 Altera Corporation
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/vmalloc.h>
#include <linux/fpga/fpga-mgr.h>

struct fpga_image_info fops_info;

static ssize_t fpga_mgr_write(struct file *file, const char __user *buf,
		size_t count, loff_t *offset)
{
	struct fpga_manager *mgr = file->private_data;
	char *kern_buf;
	int len = count;

	kern_buf = memdup_user(buf, count);
	if (IS_ERR(kern_buf))
		return PTR_ERR(kern_buf);

	mgr->mops->write(mgr, kern_buf, count);
	kfree(kern_buf);
	return len;
}

static int fpga_mgr_open(struct inode *inode, struct file *file)
{
	struct fpga_manager *mgr;
	struct fpga_manager_ops *mops;
	bool fmode_wr = (file->f_mode & FMODE_WRITE) != 0;
	int ret = 0;

	mgr = container_of(inode->i_cdev, struct fpga_manager, cdev);


	if (!mgr)
		return -ENODEV;

	mops = mgr->mops;

	/* Don't allow read or write if we don't have read/write fns. */
	if (fmode_wr && !mops->write)
		return -EPERM;

//	if (test_and_set_bit_lock(FPGA_MGR_DEV_BUSY, fops_info.flags))
//		return -EBUSY;

	file->private_data = mgr;

	if (fmode_wr && mops->write_init)
		ret = mops->write_init(mgr,&fops_info,NULL,0);
	return ret;
}

static int fpga_mgr_release(struct inode *inode, struct file *file)
{
	struct fpga_manager *mgr = file->private_data;
	struct fpga_manager_ops *mops = mgr->mops;
	bool fmode_wr = (file->f_mode & FMODE_WRITE) != 0;
	int ret = 0;

	if (fmode_wr && mops->write_complete)
		ret = mops->write_complete(mgr,NULL);

	file->private_data = NULL;
//	clear_bit_unlock(FPGA_MGR_DEV_BUSY, fops_info.flags);

	return ret;
}

const struct file_operations socfpga_mgr_fops = {
	.owner		= THIS_MODULE,
	.llseek		= no_llseek,
	.write		= fpga_mgr_write,
	.open		= fpga_mgr_open,
	.release	= fpga_mgr_release,
};
