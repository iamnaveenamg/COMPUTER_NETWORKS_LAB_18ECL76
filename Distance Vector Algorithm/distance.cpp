#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<conio.h>


int main(){
	int i,j,k,n,t;
	int m[10][10];
	int path[10][10];
	//void path(int i,int j);
	printf("enter the no of nodes:");
	scanf("%d",&n);
	printf("enter the path values matrix\n");
	
	for(i=1;i<=n;i++){
		printf("\t%d", i);
		
	}
	printf("\n");
	for(i=1;i<=n;i++){
		printf("\n%d\t",i);
		for(j=1;j<=n;j++){
			scanf("%d",&m[i][j]);
			path[i][j]=j;
		}
	}
	for(i=1;i<=n;i++){
		m[i][j]=0;
	}
	for(k=1;k<=n;k++){
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(m[i][k]+m[k][j]<m[i][j]){
					m[i][j]=m[i][k]+m[k][j];
					path[i][j]=k;
				}
			}
		}
	}
	
	// final cost matrix
	printf("\n The final cost matrix is:\n");
	
	for(i=1;i<=n;i++){
		printf("\t%d", i);
	}
	printf("\n");
	for(i=1;i<=n;i++){
		printf("\n%d", i);
		for(j=1;j<=n;j++){
			printf("\t%d",m[i][j]);
		}
		printf("\n");
	}
	printf("\n The final path matrix is:\n");
	
	for(i=1;i<=n;i++){
		printf("\t%d", i);
	}
	printf("\n");
	for(i=1;i<=n;i++){
		printf("\n%d", i);
		for(j=1;j<=n;j++){
			printf("\t%d",path[i][j]);
		}
		printf("\n");
	}
	for(i=1;i<=n;i++){
		printf("The Routing table info for router %d\n", i);
		printf("\ndest\t NextHop \t dist \n");
		for(j=1;j<=n;j++){
			printf("%d \t %d \t %d \t\n",j,m[i][j],path[i][j]);
		}
	}
}
