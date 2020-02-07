#include <stdio.h>
#include <time.h>
#define ASIZE 100000
int main() {
  clock_t start,end,total;
  int i,sum=0,array[ASIZE];
  for(i=0;i<ASIZE;i++)
    array[i]=1;
  start=clock();
  for(i=0;i<ASIZE;i++)
    sum+=array[i];
  end=clock();
  total=end-start;
  printf("Sum is %d\n", sum);
  printf("Time taken to calculate sum serially: %f\n", (float)total/CLOCKS_PER_SEC);
  return 0;
}
