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
2. CMake.


## How to run

```
$ cmake -S . -B build  -DCMAKE_CXX_COMPILER=pgc++
$ cmake --build build
$ ./buid/helloCUDA

```
