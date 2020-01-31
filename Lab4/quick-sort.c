#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int array[], int low, int high){
  int pivot=array[high];
  int i=(low-1);
  for(int j=low; j<high; j++){
    if(array[j]<=pivot){
      i++;
      int temp=array[i];
      array[i]=array[j];
      array[j]=temp;
    }
  }
  int temp=array[i+1];
  array[i+1]=array[high];
  array[high]=temp;
  return (i+1);
}
void quickSort(int array[], int low, int high){
  if(low<high){
    int pi=partition(array,low,high);
    quickSort(array,low,pi-1);
    quickSort(array,pi+1,high);
  }
}
int main(){
  clock_t start,end,total;
  int n;
  scanf("%d", &n);
  int array[n];
  for(int i=0;i<n;i++){
    array[n]=rand()%1000;
  }
  start=clock();
  quickSort(array,0,n-1);
  end=clock();
  total=end-start;
  printf("Total time taken for random sorting: %f\n", (float)total/CLOCKS_PER_SEC);
}
