#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char const *argv[]) {
  int n=5,myval;
  #pragma omp parallel for private (myval) ordered
    for (int i = 0; i < n; i++) {
      myval=10;
      #pragma omp ordered
      {
        printf("%d %d\n",i,myval);
      }
    }
  return 0;
}
