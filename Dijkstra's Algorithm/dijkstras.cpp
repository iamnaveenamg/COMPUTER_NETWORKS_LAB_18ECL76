#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<conio.h>

int p[10][10];
int main(){
	int i,j,k,n,t;
	int m[10][10];
	void path(int i,int j);
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
			p[i][j]=0;
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
					p[i][j]=k;
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
			printf("\t%d",p[i][j]);
		}
		printf("\n");
	}
	
	do{
		printf("\n Enter the source and destination nodes:");
		scanf("%d%d", &i, &j);
		printf("\n The weight is: %d", m[i][j]);
		printf("\n The path is:\n");
		printf("\n %d --->",i);
		path(i,j);
		printf("%d", j);
		printf("\nto repeat press r");
	}while(getch()=='r');
	
}
void path(int i,int j){
	int k;
	k=p[i][j];
	if(k!=0){
		path(i,k);
		printf("%d--->", k);
		path(k,j);
		
	}
}
