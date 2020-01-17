#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main(int argc, char const *argv[]) {
  int sum=0,n,a[10];
  #pragma omp parallel
  {
    if(omp_get_thread_num()==0){
      printf("Enter numbers: \n");
      for (size_t i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
      }
    }
  }
  #pragma omp parallel
  {
    if(omp_get_thread_num()==1){
      for (size_t i = 0; i < 10; i++) {
        sum+=a[i];
      }
    }
  }
  #pragma omp parallel
  {
    if(omp_get_thread_num()==2){
      printf("Sum: %d\n", sum);
    }
  }
  return 0;
}
