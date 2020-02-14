#include <stdio.h>


void bsearch(int arr[], int item, int low, int high){
  if(low>=high){
    printf("Not found\n");
    return;
  }
  else{
    int mid=(low+high)/2;
    if(item==arr[mid]){
      printf("Item found\n");
    }else if(item<arr[mid]){
      return bsearch(arr,item,low,mid-1);
    }else{
      return bsearch(arr,item,mid+1,high);
    }
  }
}

int main() {
  int arr[10],item;
  printf("Enter array of size 10 in sorted order\n");
  for(int i=0;i<10;i++){
    scanf("%d",&arr[i]);
  }
  printf("Enter item to search\n");
  scanf("%d", &item);
  bsearch(arr,item,0,9);
  return 0;
}
