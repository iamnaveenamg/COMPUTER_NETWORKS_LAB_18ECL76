#include<stdio.h>
#include<string.h>
#define MAX 100

int main(){
	int si=0;
	int di=0;
	int count=0;
	char flag[MAX]="01111110";
	char src[MAX], des[MAX];
	
	// user data
	printf("Enter the data for stufiing and destuffing\n");
	scanf("%s",&src);
	
	di=strlen(flag);
	
	strcpy(des,flag);
	
	// data  stuffing
	while(src[si]!='\0'){ //nul character
		if(src[si]=='1'){
			count++;	
		}else{
			count=0;
		}
		des[di++]=src[si++];
		if(count==5){
			count=0;
			des[di++]='0';
		}
	}
	des[di]='\0';
	//printf("The stuffing data is :%s\n", des);
	
	strcat(des,flag);
	printf("\n The stuffing data is :%s", des);
	
	//destuffing the data
	di=strlen(des)-strlen(flag);
	des[di]='\0';
	for(di=strlen(flag), si=0; des[di]!='\0';si++,di++){
		src[si]=des[di];
		//
	}
	src[si]='\0';
	si=0;
	di=0;
	count=0;
	while(src[si]!='\0'){
		if(src[si]=='1'){
			count++;
			
		}else{
			count=0;
		}
		des[di++]=src[si++];
		if(count==5){
			count=0;
			si++;
		}
	}
	//des[di]='\0';
	//des[di]='\0';
	printf("\n the destuffing data is : %s", des);
}
