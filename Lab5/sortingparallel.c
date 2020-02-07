#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
#define N 10000

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int main(){
  clock_t start,end,total;
  int n,i;
  int arr[N];
  for(i=0;i<N;i++){
    arr[i]=rand()%1000;
  }
  start=clock();
  for(n = 0; n < N; n++) {
    #pragma omp parallel for private(i) shared(arr)
    for(i = 2; i < N; i+=2)
      if(arr[i-1] > arr[i])
        swap(&arr[i-1],&arr[i]);
    #pragma omp parallel for private(i) shared(arr)
    for(i = 1; i < N; i+=2)
      if(arr[i-1] > arr[i])
        swap(&arr[i-1],&arr[i]);
    }
    end=clock();
    total=end-start;
  printf("Time taken for parallel sorting %f\n", (float)total/CLOCKS_PER_SEC);
}
