#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
void merge(size_t a[], size_t l, size_t m, size_t r)
{
	size_t temp[m-l+1], temp2[r-m];
	for(size_t i=0; i<(m-l+1); i++)
		temp[i]=a[l+i];
	for(size_t i=0; i<(r-m); i++)
		temp2[i]=a[m+1+i];
	size_t i=0, j=0, k=l;
	while(i<(m-l+1) && j<(r-m))
	{
		if(temp[i]<temp2[j])
			a[k++]=temp[i++];
		else
			a[k++]=temp2[j++];
	}
	while(i<(m-l+1))
		a[k++]=temp[i++];
	while(j<(r-m))
		a[k++]=temp2[j++];

}

void mergeSort(size_t a[], size_t l, size_t r)
{
	if(l<r)
	{
		size_t m=(l+r)/2;
		#pragma omp parallel sections
		{
			#pragma omp section
			{
				mergeSort(a,l,m);
			}
			#pragma omp section
			{
				mergeSort(a,m+1,r);
			}
		}
		merge(a,l,m,r);
	}
}
void print(size_t a[], size_t n)
{
	for(size_t i=0; i<n; i++)
		printf("%ld\n", a[i]);
}
int main()
{
  clock_t start_t, end_t, total_t;
  size_t n;
  scanf("%ld", &n);
  size_t a[n];
  for(size_t i=0; i<n; i++)
    a[i]=rand();
  printf("Unsorted array: \n");
  print(a,n);
  start_t=clock();
  mergeSort(a,0,n-1);
  end_t = clock();
  printf("Sorted array: \n");
  print(a,n);
  total_t=(end_t-start_t);
  printf("Total time: %f\n",(float)total_t/CLOCKS_PER_SEC);
  return 0;
}
