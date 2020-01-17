#include <stdio.h>
#include <time.h>

int main() {
  clock_t start_t, end_t, total_t;
  int i,sum=0;
  start_t=clock();
  printf("Start of loop, start_t= %ld\n", start_t);
  for(i=0;i<10000000;i++){
    sum++;
  }
  end_t = clock();
  printf("End of loop, end_t= %ld\n", end_t);
  total_t=(end_t-start_t);
  printf("Total time: %ld\n",total_t);
  return 0;
}
