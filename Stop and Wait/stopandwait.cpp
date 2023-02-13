#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int main(){
	int n,i,rn;
	int seq[50]={1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,};
	srand(time(0));
	printf("Enter the no of frames transmitted:\n");
	scanf("%d ", &n);
	srand(time(0));
	
	printf("The stop and wait protocol\n");
	for(i=1;i<=n;i++){
		srand(time(0));
		printf("\n \t TRANSMITTER: Frame %d is transmitted \n\n", seq[i]);
		sleep(5);
		rn=rand()%4;
		if(rn==0){
			printf("\t RECEIVER: No ack signal %d\n", seq[i]);
			printf("\t TRANSMITTER: Frame %d\n", seq[i]);
			sleep(4);
			printf("\t RECEIVER: ack %d\n", seq[i+1]);
			printf("---------------------->\n");
			
		}else if(rn==1){
			printf("\t RECEIVER: ack %d\n", seq[i+1]);
			printf("---------------------->\n");
		}else if(rn==2){
			printf("\t TRANSMITTER: Time out frame %d\n", seq[i]);
			printf("\t TRANSMITTER: retransmit %d \n", seq[i]);
			printf("\t RECEIVER: Ack signal %d\n", seq[i+1]);
			printf("---------------------->\n");
		}else{
			printf("\t %d frame lost in network \n", seq[i]);
			printf("\t TRANSMITTER: frame i retransmitted %d\n",seq[i]);
			printf("\t RECEIVER: ack signal %d", seq[i+1]);
			printf("---------------------->\n");
		}
	}
	printf("%d frames transmitted success", i-1);
}
