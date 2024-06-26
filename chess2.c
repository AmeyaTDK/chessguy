#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(){

	int i=0,j,n,m,e=0;
	char c;
	char word1[3];
	char word2[3];

	struct notation{
		char piece[3];
		int count;
		char position[3];
	}chess[12]={
		{"BK" , 0,""},
		{"BQ" , 0,""},
		{"BR" , 0,""},
		{"BB" , 0,""},
		{"BN" , 0,""},
		{"BP" , 0,""},
		{"WK" , 0,""},
		{"WQ" , 0,""},
		{"WR" , 0,""},
		{"WB" , 0,""},
		{"WN" , 0,""},
		{"WP" , 0,""} 
	};

	printf("Enter your starting position -\n"); 

		while((c=getchar())!=EOF){
		
			if(!isalnum(c) || isspace(c)){
					continue;
			}
		
			else if(isupper(c)){
				if(e==0){
					word1[0]=c;
					e=1;
				}	
				else{
					word1[1]=c;				
					word1[2]='\0';
					e=0;
				}		
				continue;			
			}
		
			else if(islower(c)){
				word2[0]=c;
				continue;
			}	
				
			else if(isdigit(c)){
				word2[1]=c;
				word2[2]='\0';
			}

										
			for(i=0;i<12;i++){			    	
				m=strcmp(word1,chess[i].piece);
				if(m==0){
					n=i;
					break;
				}
				else
					;	
			}
			
			if(n>=0)				
				chess[n].count++ ;
				
			strcpy(chess[n].position ,word2);
			
		}
		
	//	printf("%c%c %c%c\n", word1[0],word1[1],word2[0],word2[1]);
		for(i=0;i<12;i++){
			printf("%s %d %s\n",chess[i].piece , chess[i].count , chess[i].position);	
		}
		
		for(i=1;i<=8;i++){
			for(j=1;j<=8;j++){
				if(i==1 && j==1 && chess[2].count>0 && strcmp(chess[2].position,"a8")==0)
					printf(" BR ");				
				else if(i==1 && j==2 && chess[4].count>0 && strcmp(chess[4].position ,"b8")==0)
					printf(" BN ");
				else if(i==1 && j==3 && chess[3].count>0 && strcmp(chess[3].position ,"c8")==0)
					printf(" BB ");
				else if(i==1 && j==4 && chess[1].count>0 && strcmp(chess[1].position ,"d8")==0)
					printf(" BQ ");
				else if(i==1 && j==5 && chess[0].count>0 && strcmp(chess[0].position ,"e8")==0)
					printf(" BK ");
				else if(i==1 && j==6 && chess[3].count>0 && strcmp(chess[3].position ,"f8")==0)
					printf(" BB ");
				else if(i==1 && j==7 && chess[4].count>0 && strcmp(chess[4].position ,"g8")==0)
					printf(" BN ");
				else if(i==1 && j==8 && chess[2].count>0 && strcmp(chess[2].position ,"h8")==0)
					printf(" BR");
				else if(i==2 && chess[5].count>0 && strcmp(chess[5].position ,"a7")==0)
					printf(" BP ");												
				else if(i==2 && chess[5].count>0 && strcmp(chess[5].position ,"b7")==0)
					printf(" BP ");
				else if(i==2 && chess[5].count>0 && strcmp(chess[5].position ,"c7")==0)
					printf(" BP ");
				else if(i==2 && chess[5].count>0 && strcmp(chess[5].position ,"d7")==0)
					printf(" BP ");
				else if(i==2 && chess[5].count>0 && strcmp(chess[5].position ,"e7")==0)
					printf(" BP ");
				else if(i==2 && chess[5].count>0 && strcmp(chess[5].position ,"f7")==0)
					printf(" BP ");
				else if(i==2 && chess[5].count>0 && strcmp(chess[5].position ,"g7")==0)
					printf(" BP ");
				else if(i==2 && chess[5].count>0 && strcmp(chess[5].position ,"h7")==0)
					printf(" BP");
				else if(i==7 && chess[11].count>0 && strcmp(chess[11].position ,"a2")==0)
					printf(" WP ");				
				else if(i==7 && chess[11].count>0 && strcmp(chess[11].position ,"b2")==0)
					printf(" WP ");				
				else if(i==7 && chess[11].count>0 && strcmp(chess[11].position ,"c2")==0)
					printf(" WP ");				
				else if(i==7 && chess[11].count>0 && strcmp(chess[11].position ,"d2")==0)				
					printf(" WP ");				
				else if(i==7 && chess[11].count>0 && strcmp(chess[11].position ,"e2")==0)
					printf(" WP ");				
				else if(i==7 && chess[11].count>0 && strcmp(chess[11].position ,"f2")==0)
					printf(" WP ");				
				else if(i==7 && chess[11].count>0 && strcmp(chess[11].position ,"g2")==0)
					printf(" WP ");				
				else if(i==7 && chess[11].count>0 && strcmp(chess[11].position ,"h2")==0)
					printf(" WP");
				else if(i==8 && j==1 && chess[8].count>0 && strcmp(chess[8].position ,"a1")==0)
					printf(" WR ");				
				else if(i==8 && j==2 && chess[10].count>0 && strcmp(chess[10].position ,"b1")==0)
					printf(" WN ");
				else if(i==8 && j==3 && chess[9].count>0 && strcmp(chess[9].position ,"c1")==0)
					printf(" WB ");
				else if(i==8 && j==4 && chess[7].count>0 && strcmp(chess[7].position ,"d1")==0)
					printf(" WQ ");				
				else if(i==8 && j==5 && chess[6].count>0 && strcmp(chess[6].position ,"e1")==0)
					printf(" WK ");		
				else if(i==8 && j==6 && chess[9].count>0 && strcmp(chess[9].position ,"f1")==0)
					printf(" WB ");		
				else if(i==8 && j==7 && chess[10].count>0 && strcmp(chess[10].position ,"g1")==0)
					printf(" WN ");	
				else if(i==8 && j==8 && chess[8].count>0 && strcmp(chess[8].position ,"h1")==0)
					printf(" WR ");	
				else 
					printf(" * ");																
			}
			printf("\n");
		}	
}
	
