#include<stdio.h>
#include<iostream>

void sum(int a,int b,int c);
int main(){
	int a,b,c;
	std::cout<<"Enter the values : \n";
	std::cin>>a>>b>>c;
	sum(a,b,c);
	//sum(a,b);
	//sum(a);
	//sum();
	
}
void sum(int a=10, int b=100, int c=1000){
	int s=a+b+c;
	std::cout<<"The sum: "<<s;
}
