# how-to-openacc-cmake


## Prereq

1. HPC SDK
  - Install HPC [SDK](https://developer.nvidia.com/nvidia-hpc-sdk-downloads) from here.
  - Follow the instructions.  Something like this. Download, Extract and add path.

  ```
  $ wget https://developer.download.nvidia.com/hpc-sdk/22.7/nvhpc_2022_227_Linux_x86_64_cuda_multi.tar.gz
  $ tar xpzf nvhpc_2022_227_Linux_x86_64_cuda_multi.tar.gz
  $ nvhpc_2022_227_Linux_x86_64_cuda_multi/install
  ```
  - `nvc++ --version` list the version (formerly `pgc++`).
2. CMake 3.14. // No strict constraint though
3. `export PGI_ACC_TIME=1`


## How to run

```
$ cmake -S . -B build  -DCMAKE_CXX_COMPILER=nvc++
$ cmake --build build
$ ./build/helloCUDA

```

## A Sample run

```
$ cmake -S . -B build  -DCMAKE_CXX_COMPILER=nvc++
-- The CXX compiler identification is PGI 22.7.0
-- Check for working CXX compiler: /opt/nvidia/hpc_sdk/Linux_x86_64/22.7/compilers/bin/pgc++
-- Check for working CXX compiler: /opt/nvidia/hpc_sdk/Linux_x86_64/22.7/compilers/bin/pgc++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Found OpenACC_CXX: -acc  
-- Configuring done
-- Generating done
-- Build files have been written to: /home/rajesh/d13/how-to-openacc-cmake/build
$ cmake --build build
Scanning dependencies of target bin
[ 50%] Building CXX object CMakeFiles/bin.dir/hello.cpp.o
main:
     21, Generating copyin(a[:]) [if not already present]
         Generating copyout(c[:]) [if not already present]
         Generating copyin(b[:]) [if not already present]
         Generating NVIDIA GPU code
         25, #pragma acc loop gang, vector(128) /* blockIdx.x threadIdx.x */
     27, Generating NVIDIA GPU code
         31, #pragma acc loop gang, vector(128) /* blockIdx.x threadIdx.x */
     33, Generating NVIDIA GPU code
         38, #pragma acc loop gang, vector(128) /* blockIdx.x threadIdx.x */
[100%] Linking CXX executable helloCUDA
[100%] Built target bin

$ ./build/helloCUDA

N:268435456
0 536870912
1 536870911
2 536870910
3 536870909
4 536870908
5 536870907
6 536870906
7 536870905
8 536870904
9 536870903

Accelerator Kernel Timing data
/home/rajesh/d13/how-to-openacc-cmake/hello.cpp
  main  NVIDIA  devicenum=0
    time(us): 121,928
    21: compute region reached 1 time
        21: kernel launched 1 time
            grid: [65535]  block: [128]
             device time(us): total=39,598 max=39,598 min=39,598 avg=39,598
            elapsed time(us): total=39,636 max=39,636 min=39,636 avg=39,636
    21: data region reached 2 times
    27: compute region reached 1 time
        27: kernel launched 1 time
            grid: [65535]  block: [128]
             device time(us): total=37,717 max=37,717 min=37,717 avg=37,717
            elapsed time(us): total=37,730 max=37,730 min=37,730 avg=37,730
    33: compute region reached 1 time
        33: kernel launched 1 time
            grid: [65535]  block: [128]
             device time(us): total=44,613 max=44,613 min=44,613 avg=44,613
            elapsed time(us): total=44,625 max=44,625 min=44,625 avg=44,625


```
