#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
    
    FILE *fp = fopen(argv[1], "r");
    char inp;
    int k=16;

    if(fp == NULL){
        printf("Error in opening file\n");
    }
    
    printf("\n");

    while((inp = fgetc(fp)) != EOF){
        if(k>0 && inp == '\n'){
            k--;
        }
        else if(k>0 && inp !='\n')
            ;
    
        else if(k == 0){
            printf("%c",inp);
        }
    }

    fclose(fp);
    return 0;    
}


