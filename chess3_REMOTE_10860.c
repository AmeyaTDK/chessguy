#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

struct square{
	bool present;
	struct piece *p;
}cb[8][8];

struct piece{
	bool colour;
	struct square *sqr;
	char arr[3];
} BR1={0,NULL,"BR"},
  BN1={0,NULL,"BN"},
  BB1={0,NULL,"BB"},
  BQ={0,NULL,"BQ"},
  BK={0,NULL,"BK"},
  BB2={0,NULL,"BB"},
  BN2={0,NULL,"BN"},
  BR2={0,NULL,"BR"},
  BP1={0,NULL,"BP"},
  BP2={0,NULL,"BP"},
  BP3={0,NULL,"BP"},
  BP4={0,NULL,"BP"},
  BP5={0,NULL,"BP"},
  BP6={0,NULL,"BP"},
  BP7={0,NULL,"BP"},
  BP8={0,NULL,"BP"},
  WP1={1,NULL,"WP"},
  WP2={1,NULL,"WP"},
  WP3={1,NULL,"WP"},
  WP4={1,NULL,"WP"},
  WP5={1,NULL,"WP"},
  WP6={1,NULL,"WP"},
  WP7={1,NULL,"WP"},
  WP8={1,NULL,"WP"},
  WR1={1,NULL,"WR"},
  WN1={1,NULL,"WN"},
  WB1={1,NULL,"WB"},
  WQ={1,NULL,"WQ"},
  WK={1,NULL,"WK"},
  WB2={1,NULL,"WB"},
  WN2={1,NULL,"WN"},
  WR2={1,NULL,"WR"}; 

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

void print_board(struct square board[8][8]);
void input();
void make_move(struct piece *,struct square *);

int main(){ 
    
    init();
  //  print_board(cb);
    printf("Enter your move as white -\n");
    input();
    
}                 
/*
void print_board(struct square board[8][8]){

    int i,j;  

    for(i=0;i<8;i++){
          for(j=0;j<8;j++){
                if(board[i][j].present)
                        printf("%c%c ",board[i][j].p->arr[0],board[i][j].p->arr[1]);
                else 
                        printf("*  ");
          }
        printf("\n");
    }
}
*/
void make_move(struct piece *p, struct square *dst)
{
      // if dst has piece, remove it
      dst->p->sqr = NULL;
      dst->present = 0;
      // remove the piece from current square
      p->sqr->p = NULL;
      p->sqr->present = 0;
      // connect piece to dst square
      p->sqr = dst;
      dst->present = 1;
      dst->p = p;
}

void input(){
    int i,j,k=0;
    char x,y,c;
    char src_array[2],dst_array[2];
    struct piece *ptr1;
    struct square *ptr2;     

      while((c=getchar())!=EOF){
          if(islower(c)){
              if(k==1){
                  dst_array[0]=c;
                  continue;
              }
              src_array[0]=c;
          }

          else if(isdigit(c)){
              if(k==1){
                  dst_array[1]=c;
                  dst_array[2]='\0';
                  continue;
              } 
              src_array[1]=c;
              src_array[2]='\0';
              k=1;
          }

          else
                  continue;
      }

      x=src_array[0];
      y=src_array[1];

      switch(x){
        case 'a':
          i=0;
          break; 
  
        case 'b':
          i=1;
          break;
        
        case 'c':
          i=2;
          break;      
           
        case 'd':
          i=3;
          break;      
             
        case 'e':
          i=4;
          break;
  
        case 'f':
          i=5;
          break;      
  
        case 'g':
          i=6;
          break;      
  
        case 'h':
          i=7;
          break;      
      }

      j=y-1;

      ptr1=cb[i][j].p; //pointer type test 
      
      x=dst_array[0];
      y=dst_array[1];
      
       switch(x){
        case 'a':
          i=0;
          break; 
  
        case 'b':
          i=1;
          break;
        
        case 'c':
          i=2;
          break;      
           
        case 'd':
          i=3;
          break;      
             
        case 'e':
          i=4;
          break;
  
        case 'f':
          i=5;
          break;      
  
        case 'g':
          i=6;
          break;      
  
        case 'h':
          i=7;
          break;      
      }
      
      j=y-1;

      ptr2=&cb[i][j];


    
  //   make_move(ptr1,ptr2);
}
