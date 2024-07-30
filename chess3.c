#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

enum tpiece{
        K,
        Q,
	R,
	B,
	N,
	P
}type;

struct square{
	bool present;
	struct piece *p;
}cb[8][8];

struct piece{
	bool colour;
	struct square *sqr;
	enum tpiece type;
} BR1={0,NULL,R},
  BN1={0,NULL,N},
  BB1={0,NULL,B},
  BQ={0,NULL,Q},
  BK={0,NULL,K},
  BB2={0,NULL,B},
  BN2={0,NULL,N},
  BR2={0,NULL,R},
  BP1={0,NULL,P},
  BP2={0,NULL,P},
  BP3={0,NULL,P},
  BP4={0,NULL,P},
  BP5={0,NULL,P},
  BP6={0,NULL,P},
  BP7={0,NULL,P},
  BP8={0,NULL,P},
  WP1={1,NULL,P},
  WP2={1,NULL,P},
  WP3={1,NULL,P},
  WP4={1,NULL,P},
  WP5={1,NULL,P},
  WP6={1,NULL,P},
  WP7={1,NULL,P},
  WP8={1,NULL,P},
  WR1={1,NULL,R},
  WN1={1,NULL,N},
  WB1={1,NULL,B},
  WQ={1,NULL,Q},
  WK={1,NULL,K},
  WB2={1,NULL,B},
  WN2={1,NULL,N},
  WR2={1,NULL,R}; 

void init(){
  cb[0][0].present=1;
  cb[0][0].p=&BR1;
  cb[0][1].present=1;
  cb[0][1].p=&BN1;
  cb[0][2].present=1;
  cb[0][2].p=&BB1;
  cb[0][3].present=1;
  cb[0][3].p=&BQ;
  cb[0][4].present=1;
  cb[0][4].p=&BK;
  cb[0][5].present=1;
  cb[0][5].p=&BB2;
  cb[0][6].present=1;
  cb[0][6].p=&BN2;
  cb[0][7].present=1;
  cb[0][7].p=&BR2;
  cb[1][0].present=1;
  cb[1][0].p=&BP1;
  cb[1][1].present=1;
  cb[1][1].p=&BP2;
  cb[1][2].present=1;
  cb[1][2].p=&BP3;
  cb[1][3].present=1;
  cb[1][3].p=&BP4;
  cb[1][4].present=1;
  cb[1][4].p=&BP5;
  cb[1][5].present=1;
  cb[1][5].p=&BP6;
  cb[1][6].present=1;
  cb[1][6].p=&BP7;
  cb[1][7].present=1;
  cb[1][7].p=&BP8;
  cb[6][0].present=1;
  cb[6][0].p=&WP1;
  cb[6][1].present=1;
  cb[6][1].p=&WP2;
  cb[6][2].present=1;
  cb[6][2].p=&WP3;
  cb[6][3].present=1;
  cb[6][3].p=&WP4;
  cb[6][4].present=1;
  cb[6][4].p=&WP5;
  cb[6][5].present=1;
  cb[6][5].p=&WP6;
  cb[6][6].present=1;
  cb[6][6].p=&WP7;
  cb[6][7].present=1;
  cb[6][7].p=&WP8;
  cb[7][0].present=1;
  cb[7][0].p=&WR1;
  cb[7][1].present=1;
  cb[7][1].p=&WN1;
  cb[7][2].present=1;
  cb[7][2].p=&WB1;
  cb[7][3].present=1;
  cb[7][3].p=&WQ;
  cb[7][4].present=1;
  cb[7][4].p=&WK;
  cb[7][5].present=1;
  cb[7][5].p=&WB2;
  cb[7][6].present=1;
  cb[7][6].p=&WN2;
  cb[7][7].present=1;
  cb[7][7].p=&WR2;
};

int main(){ 

  int i,j;

  for(i=0;i<8;i++){
      for(j=0;j<8;j++){
          if(cb[i][j].present!=EOF)
              printf("%c",cb[i][j].p->type);
          else
              printf("* ");
      }
    printf("\n");
  }
}
