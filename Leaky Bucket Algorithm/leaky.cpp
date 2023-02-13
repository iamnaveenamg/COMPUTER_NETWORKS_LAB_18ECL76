//leaky bucket
#include<stdio.h>
#include<stdlib.h>
#define b_size 512
void inBucket(int p_size,int opr){
	if(p_size>b_size){
		printf("\n\t\t\bucket over flow\n");
	}else{
		while(p_size>opr){
			printf("\n\t\t %d", opr);
			printf("Byte passed");
			p_size=p_size-opr;
		}
		if(p_size>0){
			printf("\n\t\t Last %d", p_size);
			printf("\n\t\t Byte sent");
		}
		printf("\nbucket output sucess");
	}
}
int main(){
	int i,op_rate, ptk_size;
	printf("Enter the output rate");
	scanf("%d",&op_rate);
	for(i=1;i<=5;i++){
		ptk_size=rand()%600;
		printf("\n\n The packet no: %d", i);
		printf("\t The packet size: %d", ptk_size);
		inBucket(ptk_size, op_rate);
		
	}
}
