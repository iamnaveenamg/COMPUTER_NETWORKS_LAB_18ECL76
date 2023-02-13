#include<stdio.h>
#define degree 16
int frm[30];
int getNext(int frm[], int pos){ //function to remove leading zeroes in the frame
	int i=pos;
	while(frm[i]==0){
		++i;
	}
	return i;
}
void crc(int len){ // function to perform xor operation and find the CRC
	int cp[]={1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1}; //degree
	int i=0,pos=0,newpos;
	while(pos<len-degree){
		for(i=pos;i<pos+degree+1;i++)
		frm[i]=(frm[i]==cp[i-pos])?0:1;
		newpos=getNext(frm, pos);
		if(newpos>pos+1)
		pos=newpos-1;
		++pos;
			
		
	}
}
int main(){
	int arr[30];
	int len, i=0, j=0;
	// length of data stream
	printf("enter the length of data stream\n");
	scanf("%d", &len);
	
	printf("enter the data:\n");
	for(i=0;i<len;i++){
		scanf("%d", &arr[i]);
		
	}
	printf("\n");
	
	// print the data given
	printf("The given data is :\n");
	for(i=0;i<len;i++){
		printf("%d\n", arr[i]);
	}printf("\n");
	
	// appending the zeros after the given data
	for(i=0;i<degree;i++){
		arr[i+len]=0;
	}
	len+=degree; // increasing the lenth of data
	
	// copy the values of arr to frame
	for(i=0;i<len;i++){
		frm[i]=arr[i];
	}
	
	// print the transmitting frame
	printf("\n The Transmitted frame  :");
	for(i=0;i<len-degree; i++){
		printf("%d", frm[i]);
	}
	crc(len);
	for(i=len-degree;i<len;++i){
		printf("%d",frm[i]);
	}
	
	printf("\n enter the receivinng data\n\n\n");
	for(i=0;i<len;i++){
		scanf("%d", &arr[i]);
		
	}
	for(i=0;i<len;i++){
		frm[i]==arr[i];
		
	}
	crc(len);
	printf("check sum");
	for(i=len-degree;i<len;++i){
		printf("%d", frm[i]);
	}
	for(i=len-degree;i<len;++i){
		if(frm[i]==1){
			++j;
		}
	}
	if(j==0){
		printf("No error");
	}else{
		printf("erroe in data");
		
	}
	
}
