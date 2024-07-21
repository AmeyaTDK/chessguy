#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(){

	int i=0,j,n,m,e=0;
	char c;
 //	char word1[3];
	char word2[3];

	struct notation{
		char piece[3];
		int count;
		char position[3];
	}chess[32]={
		{"BK" , 0,"e8"},
		{"BQ" , 0,"d8"},
		{"BR" , 0,"a8"},
		{"BR" , 0,"h8"},
		{"BB" , 0,"c8"},
		{"BB" , 0,"f8"},
		{"BN" , 0,"b8"},
		{"BN" , 0,"g8"},
		{"BP" , 0,"a7"},
		{"BP" , 0,"b7"},
		{"BP" , 0,"c7"},
		{"BP" , 0,"d7"},
		{"BP" , 0,"e7"},
		{"BP" , 0,"f7"},
		{"BP" , 0,"g7"},
		{"BP" , 0,"h7"},
		{"WK" , 0,"e1"},
		{"WQ" , 0,"d1"},
		{"WR" , 0,"a1"},
		{"WR" , 0,"h1"},
		{"WB" , 0,"c1"},
		{"WB" , 0,"f1"},
		{"WN" , 0,"b1"},
		{"WN" , 0,"g1"},
		{"WP" , 0,"a2"},
		{"WP" , 0,"b2"},
		{"WP" , 0,"c2"},
		{"WP" , 0,"d2"},
		{"WP" , 0,"e2"},
		{"WP" , 0,"f2"},
		{"WP" , 0,"g2"},
		{"WP" , 0,"h2"} 
	};
	

	printf("Enter your starting position -\n"); 

		while((c=getchar())!=EOF){
		
			if(!isalnum(c) || isspace(c)){
					continue;
			}
		
	/*		else if(isupper(c)){
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
	*/	
			else if(islower(c)){
				word2[0]=c;
				continue;
			}
				
		
			else if(isdigit(c)){
				word2[1]=c;
				word2[2]='\0';
			}
			
			else
				continue;

			for(i=0;i<32;i++){			    	
				m=strcmp(word2,chess[i].position);
					if(m==0){
					n=i;
					break;
				}
				else
					;	
			}	
			
			if(n>=0)				
				chess[n].count++ ;
		}
		
		for(i=1;i<=8;i++){
			for(j=1;j<=8;j++){
				     if(i==1 && j==1 && chess[2].count>0)
					printf(" BR");				
				else if(i==1 && j==2 && chess[6].count>0)
					printf(" BN");
				else if(i==1 && j==3 && chess[4].count>0)
					printf(" BB");
				else if(i==1 && j==4 && chess[1].count>0)
					printf(" BQ");
				else if(i==1 && j==5 && chess[0].count>0)
					printf(" BK");
				else if(i==1 && j==6 && chess[5].count>0)
					printf(" BB");
				else if(i==1 && j==7 && chess[7].count>0)
					printf(" BN");
				else if(i==1 && j==8 && chess[3].count>0) 
					printf(" BR");
				else if(i==2 && j==1 && chess[8].count>0)
					printf(" BP");												
				else if(i==2 && j==2 && chess[9].count>0)
					printf(" BP");
				else if(i==2 && j==3 && chess[10].count>0)
					printf(" BP");
				else if(i==2 && j==4 && chess[11].count>0)
					printf(" BP");
				else if(i==2 && j==5 && chess[12].count>0)
					printf(" BP");
				else if(i==2 && j==6 && chess[13].count>0)
					printf(" BP");
				else if(i==2 && j==7 && chess[14].count>0)
					printf(" BP");
				else if(i==2 && j==8 && chess[15].count>0)
					printf(" BP");
				else if(i==7 && j==1 && chess[24].count>0)
					printf(" WP");				
				else if(i==7 && j==2 && chess[25].count>0)
					printf(" WP ");				
				else if(i==7 && j==3 && chess[26].count>0)
					printf(" WP");				
				else if(i==7 && j==4 && chess[27].count>0)				
					printf(" WP");				
				else if(i==7 && j==5 && chess[28].count>0)
					printf(" WP");				
				else if(i==7 && j==6 && chess[29].count>0)
					printf(" WP");				
				else if(i==7 && j==7 && chess[30].count>0)
					printf(" WP");				
				else if(i==7 && j==8 && chess[31].count>0)
					printf(" WP");
				else if(i==8 && j==1 && chess[18].count>0)
					printf(" WR");				
				else if(i==8 && j==2 && chess[22].count>0)
					printf(" WN");
				else if(i==8 && j==3 && chess[20].count>0)
					printf(" WB");
				else if(i==8 && j==4 && chess[17].count>0)
					printf(" WQ");				
				else if(i==8 && j==5 && chess[16].count>0)
					printf(" WK");		
				else if(i==8 && j==6 && chess[21].count>0)
					printf(" WB");		
				else if(i==8 && j==7 && chess[23].count>0)
					printf(" WN");	
				else if(i==8 && j==8 && chess[19].count>0)
					printf(" WR");	
				else 
					printf(" * ");																
			}
			printf("\n");
		}	
}
		
