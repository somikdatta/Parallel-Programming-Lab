#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int main(int argc, char const *argv[]) {
  int buf[10],i=-1,c=0;
  do{
    #pragma omp parallel
    {
      if(omp_get_thread_num()==1){
        if(i==-1){
          printf("Buffer Empty\n");
        }else{
          printf("Consumer consumed %d\n", buf[i]);
          i--;
        }
      }else{
        if(i==0){
          printf("Buffer Full\n");
        }else{
          buf[++i]=i+1;
          printf("Producer produced %d\n", (i+1));
        }
      }
      i++;
    }
  }(while c<15);
  return 0;
}
