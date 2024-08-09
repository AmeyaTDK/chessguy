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
BR1.sqr =&cb[0][0];
cb[0][1].present=1;
cb[0][1].p=&BN1;
BN1.sqr =&cb[0][1];
cb[0][2].present=1;
cb[0][2].p=&BB1;
BB1.sqr =&cb[0][2];
cb[0][3].present=1;
cb[0][3].p=&BQ;
BQ.sqr =&cb[0][3];
cb[0][4].present=1;
cb[0][4].p=&BK;
BK.sqr =&cb[0][4];
cb[0][5].present=1;
cb[0][5].p=&BB2;
BB2.sqr =&cb[0][5];
cb[0][6].present=1;
cb[0][6].p=&BN2;
BN2.sqr =&cb[0][6];
cb[0][7].present=1;
cb[0][7].p=&BR2;
BR2.sqr =&cb[0][7];
cb[1][0].present=1;
cb[1][0].p=&BP1;
BP1.sqr =&cb[1][0];
cb[1][1].present=1;
cb[1][1].p=&BP2;
BP2.sqr =&cb[1][1];
cb[1][2].present=1;
cb[1][2].p=&BP3;
BP3.sqr =&cb[1][2];
cb[1][3].present=1;
cb[1][3].p=&BP4;
BP4.sqr =&cb[1][3];
cb[1][4].present=1;
cb[1][4].p=&BP5;
BP5.sqr =&cb[1][4];
cb[1][5].present=1;
cb[1][5].p=&BP6;
BP6.sqr =&cb[1][5];
cb[1][6].present=1;
cb[1][6].p=&BP7;
BP7.sqr =&cb[1][6];
cb[1][7].present=1;
cb[1][7].p=&BP8;
BP8.sqr =&cb[1][7];
cb[6][0].present=1;
cb[6][0].p=&WP1;
WP1.sqr =&cb[6][0];
cb[6][1].present=1;
cb[6][1].p=&WP2;
WP2.sqr =&cb[6][1];
cb[6][2].present=1;
cb[6][2].p=&WP3;
WP3.sqr =&cb[6][2];
cb[6][3].present=1;
cb[6][3].p=&WP4;
WP4.sqr =&cb[6][3];
cb[6][4].present=1;
cb[6][4].p=&WP5;
WP5.sqr =&cb[6][4];
cb[6][5].present=1;
cb[6][5].p=&WP6;
WP6.sqr =&cb[6][5];
cb[6][6].present=1;
cb[6][6].p=&WP7;
WP7.sqr =&cb[6][6];
cb[6][7].present=1;
cb[6][7].p=&WP8;
WP8.sqr =&cb[6][7];
cb[7][0].present=1;
cb[7][0].p=&WR1;
WR1.sqr =&cb[7][0];
cb[7][1].present=1;
cb[7][1].p=&WN1;
WN1.sqr =&cb[7][1];
cb[7][2].present=1;
cb[7][2].p=&WB1;
WB1.sqr =&cb[7][2];
cb[7][3].present=1;
cb[7][3].p=&WQ;
WQ.sqr =&cb[7][3];
cb[7][4].present=1;
cb[7][4].p=&WK;
WK.sqr =&cb[7][4];
cb[7][5].present=1;
cb[7][5].p=&WB2;
WB2.sqr =&cb[7][5];
cb[7][6].present=1;
cb[7][6].p=&WN2;
WN2.sqr =&cb[7][6];
cb[7][7].present=1;
cb[7][7].p=&WR2;
WR2.sqr =&cb[7][7];
};

void print_board(struct square board[8][8]);
void input();

int program_stop=0;

int main(){ 
    
int turn_flag=0;
    
	init();
    	while(1){

			if(program_stop == 1){
				printf("\n");
				break;
			}
			else { 
				if(turn_flag==0){
					printf("Enter move as white -\n");
					input();
					printf("\n");
					print_board(cb);
					printf("\n");
					turn_flag = 1;
				}
				else if(turn_flag==1){
					printf("Enter move as black -\n");
					input();
					printf("\n");
					print_board(cb);
					printf("\n");
					turn_flag = 0;
			   	}
			}
    	}
} 

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

void make_move(struct piece *p, struct square *dst){

	if(dst->p != NULL){     
        	dst->p->sqr = NULL;
        	dst->present = 0;
        } 
        p->sqr->p = NULL;
        p->sqr->present = 0;

        p->sqr = dst;       
        dst->present = 1;
        dst->p = p;
}

void input(){

int col_no,row_no,srcdst_flag;
char c;
char src_array[2],dst_array[2];
struct piece *ptr1;
struct square *ptr2;     

	while((c=getchar()) != '\n'){

		if(c==EOF){
			program_stop=1;
			return;
		}

		else if(islower(c)){
			if(srcdst_flag==1){
			 	dst_array[0]=c;
			 	continue;
			}
			src_array[0]=c;
		}

		else if(isdigit(c)){
			if(srcdst_flag==1){
		  		dst_array[1]=c;
		  		dst_array[2]='\0';
		  		continue;
			} 
			src_array[1]=c;
			src_array[2]='\0';
			srcdst_flag=1;
		}
        else
        	continue;
    }

	col_no = src_array[0]-'a';
	row_no = 8 - (src_array[1]-'0');

  //	 printf("%d %d\n", i,j);

	ptr1=cb[row_no][col_no].p; 

    col_no = dst_array[0]-'a';
    row_no = 8-(dst_array[1]-'0');

  //	 printf("%d %d\n", i,j);

    ptr2=&cb[row_no][col_no];

    make_move(ptr1,ptr2); 

}

