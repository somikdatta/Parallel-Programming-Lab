#include <stdio.h>
#include <time.h>
#include <omp.h>
#define ASIZE 1000000

int main(){
  clock_t start,end,total;
  int i,sum=0,array[ASIZE],tid,numt,psum=0;
  for(i=0;i<ASIZE;i++)
    array[i]=1;
  start=clock();
  #pragma omp parallel default(shared) private(i,tid,psum)
  {
    tid=omp_get_thread_num();
    numt=omp_get_num_threads();
    int start=(ASIZE/numt)*tid;
    int end=(ASIZE/numt)*(tid+1)-1;
    if(tid==numt-1)
      end=ASIZE-1;
    for(i=start;i<=end;i++){
      psum+=array[i];
    }
    #pragma omp critical
    {
      sum+=psum;
    }
  }
  end=clock();
  total=end-start;
  printf("Sum is %d\n", sum);
  printf("Time taken to calculate sum parallely: %f\n", (float)total/CLOCKS_PER_SEC);
}
