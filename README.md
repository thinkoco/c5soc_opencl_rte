# c5soc_opencl runtime environment
Intel FPGA Cyclone V SoC OpenCL runtime environment with some drivers on Linux 4.19.x  or newer

## Works

- change fpga bridges name for aclsoc driver
- change fpga manager path for aclsoc driver
- add /dev/fpga0 char driver and file operation
- fixed the interrupt number issue in aclsoc driver for new linux kernel
- fixed the signal issue in aclsoc driver for new linux kernel
- add c5soc_opencl device tree source

## Guides

[here is some guides](documents/How_to_do.md)

## Logs

    root@c5soc:~# ./boardtest_host                                                  
    Boardtest usage information                                                     
    Usage: boardtest_host [--device d] [--test t]                                   
    --device d: device number (0 - NUM_DEVICES-1)                                 
    --test t: test number (0 - 7)                                                 
    (default is running all tests on all devices)                                 
    Total number of devices = 1.                                                    
    Running all tests.                                                              
    Running on all devices.                                                         
    Reprogramming device [0] with handle 1                                          
    Program object created for all devices.                                         
    Program built for all devices.                                                  
                                                                                    
    *****************************************************************               
    ********************** TEST FOR DEVICE 0 ***********************                
    *****************************************************************               
                                                                                    
                                                                                    
    *****************************************************************               
    *********************** Host Speed Test *************************               
    *****************************************************************               
                                                                                    
    clGetDeviceInfo CL_DEVICE_GLOBAL_MEM_SIZE = 536870912                           
    clGetDeviceInfo CL_DEVICE_MAX_MEM_ALLOC_SIZE = 134217728                        
    Memory consumed for internal use = 402653184                                    
    Actual maximum buffer size = 134217728 bytes                                    
    Writing 128 MB to global memory ... 105.199330 MB/s                             
    Reading 134217728 bytes from global memory ... 64.082148 MB/s                   
    Verifying data ...                                                              
    Successfully wrote and readback 128 MB buffer                                   
                                                                                    
    Transferring 8192 KBs in 256 32 KB blocks ...                                   
    Transferring 8192 KBs in 128 64 KB blocks ...                                   
    Transferring 8192 KBs in 64 128 KB blocks ...                                   
    Transferring 8192 KBs in 32 256 KB blocks ...                                   
    Transferring 8192 KBs in 16 512 KB blocks ...                                   
    Transferring 8192 KBs in 8 1024 KB blocks ...                                   
    Transferring 8192 KBs in 4 2048 KB blocks ...                                   
    Transferring 8192 KBs in 2 4096 KB blocks ...                                   
    Transferring 8192 KBs in 1 8192 KB blocks ...                                   
                                                                                    
    PCIe Gen2.0 peak speed: 500MB/s/lane                                            
                                                                                    
    Block_Size Avg Max Min End-End (MB/s)                                           
    Writing 8192 KBs with block size (in bytes) below:                              
    32768 83.68 98.37 67.51 59.29                                                
    65536 99.70 105.02 89.06 86.52                                               
    131072 103.83 107.50 97.31 96.88                                              
    262144 109.03 109.97 105.23 106.50                                            
    524288 110.25 110.85 108.96 109.00                                            
    1048576 109.64 110.82 109.04 108.99                                            
    2097152 111.25 111.36 111.14 110.98                                            
    4194304 111.44 111.49 111.39 111.35                                            
    8388608 111.55 111.55 111.55 111.55                                            
    Reading 8192 KBs with block size (in bytes) below:                              
    32768 52.23 59.42 44.79 41.60                                                
    65536 54.27 61.37 42.67 49.26                                                
    131072 58.19 61.26 46.51 56.27                                                
    262144 60.69 62.79 60.02 59.83                                                
    524288 60.92 62.40 59.58 60.47                                                
    1048576 59.70 61.13 52.43 59.47                                                
    2097152 61.21 61.62 61.02 61.11                                                
    4194304 61.20 61.39 61.02 61.17                                                
    8388608 56.79 56.79 56.79 56.79                                                
                                                                                    
    Host write top speed = 111.55 MB/s                                              
    Host read top speed = 62.79 MB/s                                                
                                                                                    
                                                                                    
    HOST-TO-MEMORY BANDWIDTH = 87 MB/s                                              
                                                                                    
                                                                                    
    *****************************************************************               
    ********************* Host Read Write Test **********************               
    *****************************************************************               
                                                                                    
    --- test_rw with device ptr offset 0                                            
                                                                                    
    HOST READ-WRITE TEST PASSED!                                                    
                                                                                    
    *****************************************************************               
    *******************  Kernel Clock Frequency Test  ***************               
    *****************************************************************               
                                                                                    
    Measured Frequency    =   120.713226 MHz.                                       
    Quartus Compiled Frequency  =   120.879997 MHz.                                 
                                                                                    
    Measured Clock frequency is within 2 percent of quartus compiled frequency.     
                                                                                    
                                                                                    
    *****************************************************************               
    ********************* Kernel Launch Test ************************               
    *****************************************************************               
                                                                                    
    Launching kernel kernel_sender ...                                              
    Launching kernel kernel_receiver ...                                            
    ... Waiting for sender                                                        
    Sender sent the token to receiver                                             
    ... Waiting for receiver                                                      
                                                                                    
    KERNEL_LAUNCH_TEST PASSED                                                       
                                                                                    
                                                                                    
    *****************************************************************               
    ********************  Kernel Latency   **************************               
    *****************************************************************               
                                                                                    
    Creating kernel (nop)                                                           
    Processed 10000 kernels in 2006.9458 ms                                         
    Single kernel round trip time = 200.6946 us                                     
    Throughput = 4.9827 kernels/ms                                                  
    Kernel execution is complete.                                                   
                                                                                    
    *****************************************************************               
    *************  Kernel-to-Memory Read Write Test   ***************               
    *****************************************************************               
                                                                                    
    Launching kernel mem_read_writestream ...                                       
    clGetDeviceInfo CL_DEVICE_MAX_MEM_ALLOC_SIZE = 134217728 bytes.                 
    Available max buffer size = 134217728 bytes.                                    
    Created kernel buffer.                                                          
    Finished initializing host vectors.                                             
    Finished writing to buffers.                                                    
    Finished initializing host vectors.                                             
    Finished writing to buffers.                                                    
    Finished setting kernel args.                                                   
    Kernel executed.                                                                
    Finished Reading buffer.                                                        
    Finished Reading buffer.                                                        
    KERNEL MEMORY READ WRITE TEST PASSED.                                           
                                                                                    
    *****************************************************************               
    *****************  Kernel-to-Memory Bandwidth   *****************               
    *****************************************************************               
                                                                                    
    clGetDeviceInfo CL_DEVICE_MAX_MEM_ALLOC_SIZE = 134217728 bytes.                 
    Available max buffer size = 134217728 bytes.                                    
    Size of memory bank 1 = 0x40000000 B                                            
                                                                                    
    Performing kernel transfers of 32 MBs on the default global memory (address sta 
    Note: This test assumes that design was compiled with --no-interleaving       
                                                                                    
    Launching kernel mem_writestream ...                                            
    Launching kernel mem_readstream ...                                             
    Launching kernel mem_read_writestream ...                                       
                                                                                    
    Summarizing bandwidth in MB/s/bank for banks 1 to 8                             
    2406  2415  2282  2409  2400  2404  2409  2407  mem_writestream                
    2953  2938  2936  2939  2937  2933  1894  2937  mem_readstream                 
    2669  2666  2665  2668  2668  2673  2673  2666  mem_read_writestream           
                                                                                    
    Name of the global memory type not found in the board_spec.                     
    Number Of Interfaces            :    1                                          
    Max Bandwidth (all memory interfaces)   :    6400 MB/s                          
    Max Bandwidth of 1 memory interface :    6400 MB/s                              
                                                                                    
    It is assumed that all memory interfaces have equal widths.                     
                                                                                    
    BOARD BANDWIDTH UTILIZATION = 40.98%                                            
    Warning : Board bandwidth utilization is less than 90%                          
                                                                                    
    Kernel mem bandwidth assuming ideal memory: 15451 MB/s                        
                * If this is lower than your board's peak memory                  
                * bandwidth then your kernel's clock isn't fast enough            
                * to saturate memory                                              
                *   approx. fmax = 121                                            
                                                                                    
    Kernel mem bandwidth assuming ideal memory is greater than board's peak memory .
                                                                                    
                                                                                    
    KERNEL-TO-MEMORY BANDWIDTH = 2623 MB/s/bank                                     
                                                                                    
    *****************************************************************               
    **************** TEST COMPLETED FOR DEVICE 0 *******************                
    *****************************************************************               
                                                                                    
                                                                                    
    BOARDTEST PASSED                                                                
    root@c5soc:~# uname -a                                                          
    Linux c5soc 4.19.29 #12 SMP Sun Apr 14 15:21:18 CST 2019 armv7l armv7l armv7l Gx

