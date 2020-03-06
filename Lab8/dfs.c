#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>

int vis[1000],g[1000][1000],q[1000],nodes;
void dfs_para(int);
void dfs(int);

void main()
{
	int i,j;
	printf("Enter the number of nodes: ");
	scanf("%d",&nodes);
	printf("Adjecent matrix: %d*%d\n",nodes,nodes);
	printf("***Reading values for adjacency matrix randomly***\n");
	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{

			g[i][j]=rand()%2;
		}
	}
	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{
			printf("%d\t",g[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<nodes;i++)
	{
		vis[i]=0;
	}
	printf("\nDfs sequence for serial:\n");
	clock_t p1,p,s1,s;
	s=clock();
	dfs(0);
	s1=clock();

	for(i=0;i<nodes;i++)
	{
		vis[i]=0;
	}
	printf("\nDfs sequence for parallel:\n\n");
	p=clock();
	dfs_para(0);
	p1=clock();


	printf("\n\nTime taken for serial sequence: %ld\n",s1-s);
	printf("Time taken for parallel sequence: %ld\n",p1-p);
}

void dfs(int i)
{
	int j;
	printf("%d\t",i);
	vis[i]=1;
	for(j=0;j<nodes;j++)
	{
		if(!vis[j] && g[i][j]==1)
		{
			dfs(j);
		}
	}

}

void dfs_para(int i)
{
	int j;
	printf("%d\t",i);
	vis[i]=1;
	#pragma omp parallel for
	for(j=1;j<=nodes;j++)
	{
		if(!vis[j] && g[i][j]==1)
		{
			dfs(j);
		}
	}

}
