#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 10 

int main(){

	int i,j,k,n,temp;
	int array[MAX];

	printf("Enter your numbers -\n");
	
	for(i=0;i<MAX;i++){
		scanf("%d",&array[i]);
	}
	
	for(i=1;i<MAX;i++){
		for(j=0;j<i;j++){
			if(array[i]<array[j]){
				temp=array[i];
				n=j;
				for(k=i;k>=0;k--){
					array[k]=array[k-1];
				}
				break;
				array[n]=temp;
			}
			else if(array[i]==array[j]){
				;
			}
			else if(array[i]>array[j]){
				;
			}								
		}
	}
	for(i=0;i<MAX;i++)
		printf("%2d",array[i]);
}
