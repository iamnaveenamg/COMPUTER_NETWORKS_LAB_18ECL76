#include<stdio.h>
#include<string.h>
#define MAX 1000

int main(){
	int si=0;
	int di=0;
	int count=0;
	char flag1[MAX]="DLESTX";
	char flag2[MAX]="DLEESTX";
	char src[MAX], des[MAX];
	
	// enter the data
	printf("Enter the user input:\n");
	scanf("%s", &src);
	
	// character stuffing
	di=strlen(flag1);
	strcpy(des, flag1);
	while(src[si]!='\0'){
		if(src[si]=='D' && src[si+1]=='L' && src[si+2]=='E'){
			des[di]='D';
			des[di+1]='L';
			des[di+2]='E';
			des[di+3]='D';
			des[di+4]='L';
			des[di+5]='E';
			di+=6;
			si+=3;	
		}else{
			des[di++]=src[si++];
		}
	}
	des[di]='\0';
	strcat(des, flag2);
	printf("\n The stuffing string is : %s", des);
	
	// destuffing the data
	di=strlen(des)-strlen(flag2);
	des[di]='\0';
	for(di=strlen(flag1), si=0; des[di]!='\0'; si++, di++){
		src[si]=des[di];
		//src[si]
	}
	
	src[si]='\0';
	si=0;
	di=0;
	while(src[di]!='\0'){
		if(src[si]=='D' && src[si+1]=='L' && src[si+2]=='E'){
			des[di]='D';
			des[di+1]='L';
			des[di+2]='E';
			si+=6;
			di+=3;
		}
		else{
			des[di++]=src[si++];	
		}
	}
	des[di]='\0';
	printf("\n The destuffing data is : %s", des);	
}
