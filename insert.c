#include<stdio.h>
#include<ctype.h>

#define MAX 5

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
				for(k=i;k>j;k--){
					array[k]=array[k-1];
				}
				array[n]=temp;
				break;
			}
			else if(array[i]==array[j])
				;
			else if(array[i]>array[j])
				;							
		}
	}
	
	for(i=0;i<MAX;i++)
		printf("%2d",array[i]);
	printf("\n");	
}

