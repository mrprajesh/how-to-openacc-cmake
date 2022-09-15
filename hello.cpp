//~~~START:Fri, 02-Sep-2022, 12:48:21 IST
//~~~Author:Rajesh Pandian M | mrprajesh.co.in

#include <iostream>
#include <iterator>
#include <vector>
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[]) {
  unsigned n = 1 << 28;
  std::cout << "N:" << n << '\n';
 
  int* a = (int*) malloc (sizeof(int) *n);
  int* b = (int*) malloc (sizeof(int) *n);
  int* c = (int*) malloc (sizeof(int) *n);
  
  #pragma acc data copyin(a,b) copyout(c) 
  //~ #pragma acc data copy(a,b,c)
  {
  
    #pragma acc parallel loop 
    //~ #pragma acc parallel loop async(1)
    for (unsigned i = 0; i < n; ++i) {
      a[i] = i;
    }

    #pragma acc parallel loop 
    //~ #pragma acc parallel loop async(2)
    for (unsigned i = 0; i < n; ++i) {
      b[i] = n - i;
    }
    
    //~ #pragma acc wait
    
    #pragma acc parallel loop 
    for (unsigned i = 0; i < n; ++i) {
      c[i] = a[i] + 2 * b[i];
    }

  }
  
  // PRINT VEC 
    
  for (unsigned i = 0; i < 10; ++i) {
    std::cout<< i << " " << c[i] << '\n';
  }
  
  return 0;
}
