#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

int main(){
  int arr[5]={0,1,2,3,4};
  int lock=0;
  #pragma omp parallel
  {
    while(1){
      if((omp_get_thread_num()==0)&&lock==0){
        lock=1;
        printf("\nWriter %d writes ", omp_get_thread_num());
        arr[0]+=1;
        for(int i=0;i<1;i++){
          printf("\t %d \t\n", arr[i]);
        }
        sleep(1);
      }
      if((omp_get_thread_num()%2!=0)&&lock==1){
        lock=0;
        printf("\nReader %d reads ", omp_get_thread_num());
        for(int i=0;i<1;i++){
          printf("\t %d \t", arr[i]);
        }
      }
    }
  }
}
