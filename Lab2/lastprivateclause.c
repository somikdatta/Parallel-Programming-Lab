#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char const *argv[]) {
  int i,x=44;
  #pragma omp parallel for lastprivate(x)
    for (size_t i = 0; i <=10; i++) {
      x=i;
      printf("Thread number: %d x: %d\n",omp_get_thread_num(),x);
    }
  printf("x is %d\n", x);
  return 0;
}
