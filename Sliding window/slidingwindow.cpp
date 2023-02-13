#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int main(){
	int i,j,s,noofframes, nooflostframe;
	int choice;
	int w_size;
	int lost_frame[100];
	int rn;
	printf("enter the no of frames in even:");
	scanf("%d ",&noofframes);
	
	w_size=noofframes/2;
	printf("\nThe window size is %d", w_size);
	printf("\n%d frames arrived in the network layer", noofframes);
	printf("\nout of %d frame %d frame transmitted in one window\n",noofframes, w_size);
	
	printf("----------------------------------->\n");
	for(i=0,s=0;i<w_size;i++){
		printf("\n\nframe %d is transmitted with sequence no %d\n",i,i);
		printf("----------------------------------->\n");
		rn=rand()%3;
		if(rn==1){
			printf("\t<----------------------------------->\n");
			printf("\n\tack for frame %d is received : send frame %d",i,i+1);
		}else if(rn==0){
			printf("\t<----------------------------------->\n");
			printf("\n\ttime out: retransmitted %d\n",i);
			sleep(1);
			printf("\n\tframe %d retransmit hence time out\n",i);
			sleep(4);
			printf("\n\tack for frame %d sent , transmit",i,i+1);
		}else{
			lost_frame[s++]=i;
		}
	}
	nooflostframe=s;
	printf("no of lost frame %d\n", nooflostframe);
	if(nooflostframe!=0){
		printf("\nChecking for arrival of ack for frame in sent window\n");
		int k;
		for(k=0;k<nooflostframe;k++){
			printf("frame %d ack is not received\n ",lost_frame[k]);
			sleep(4);
		}
		for(k=0;k<nooflostframe;k++){
			printf("\n\tretransmited frame %d successfully\n ",lost_frame[k]);
			
			sleep(4);
			printf("\n\tack is received for frame %d \n ",lost_frame[k]);
			sleep(4);
			
		}
	}
	printf("\nall frames ar senvt in one window\n frame %d , will transmitted by sliding window\n",i);
	
}
