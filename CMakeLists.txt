cmake_minimum_required(VERSION 3.14)
project(VerifyFindOpenAcc CXX)


#~ cmake -S . -B build  -DCMAKE_C_COMPILER=pgcc -DCMAKE_CXX_COMPILER=pgc++
#~ cmake -S . -B build  -DCMAKE_CXX_COMPILER=pgc++

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-acc -gpu=managed -Minfo=all") # -fast

find_package(OpenACC REQUIRED)

# Build Executable
add_executable(bin
        hello.cpp
        )

## NEW FOR OPEN ACC
target_link_options(bin PRIVATE ${OpenACC_CXX_OPTIONS})
target_compile_options(bin PRIVATE ${OpenACC_CXX_OPTIONS})

set_target_properties(bin PROPERTIES OUTPUT_NAME helloCUDA)
