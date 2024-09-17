#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>

struct square{
	bool present;
	struct piece *p;
}cb[8][8];

enum tpiece{
	K,Q,R,B,N,P
}type;

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

int i,j;
for(i=2;i<6;i++){
	for(j=0;j<8;j++){
		cb[i][j].present=0;
		cb[i][j].p = NULL;
	}
}

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
char convert(enum tpiece type);

int program_stop=0;
int turn_flag=1;

int main(){ 
        
	init();
	while(1){

		if(program_stop == 1){
			printf("Program stopped\n");
			break;
		}
		else { 
			if(turn_flag==1){
				printf("Enter move as white -\n");
				input();
				printf("\n");
				print_board(cb);
				printf("\n");
				turn_flag = 0;
			}
			else if(turn_flag==0){
				printf("Enter move as black -\n");
				input();
				printf("\n");
				print_board(cb);
				printf("\n");
				turn_flag = 1;
		   	}
		}
	}
} 

void print_board(struct square board[8][8]){

int i,j;  
char c;

	for(i=0;i<9;i++){
		if(i != 8)
			printf("%d  ",(8-i));
		
		if(i==8){
			for(j=0;j<9;j++){
				if(j==0)
					printf("   ");
				else
					printf("%c  ",('a'+j-1));					
				if(j==8)
					printf("\n");	
			}
		}
		else{
			for(j=0;j<8;j++){
				if(board[i][j].present){
					if(board[i][j].p->colour == 0)
						printf("B%c ",convert(board[i][j].p->type));
					else if(board[i][j].p->colour == 1)
						printf("W%c ",convert(board[i][j].p->type));
					}
				else 
					printf("*  ");
			}
			printf("\n");
		}         
	}
}

char convert(enum tpiece type){
	switch(type) {
		case K:
			return 'K';
		case Q:
			return 'Q';
		case R:
	        return 'R';
		case B:
			return 'B';
		case N:
			return 'N';
		case P:
			return 'P';
		default:
			return '\0'; 
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

struct square *source_finder(char *arr1,int arr2[][2],int arr2_size,int n,struct square cb[8][8]){

int i,j,c1,c2,file,rank,qual1,qual2;

	if(n==3){				
		file = arr1[1]-'a';
		rank = (8-(arr1[2]-'0'));
	}
	else if(n==4){	
		file = arr1[2]-'a';
		rank = (8-(arr1[3]-'0'));
		
		if(islower(arr1[1]))
			qual1 = arr1[1]-'a';
		else
			qual1 =(8-(arr1[1]-'0'));	
	}

	c1=rank;
	c2=file;

	for(i=0;i<arr2_size;i++){
		if(arr1[0] == Q || arr1[0] == B || arr1[0] == R){
			printf("%d\n",arr2[i][0]);
			for(;c1<8 && c2<8 && c1>0 && c2>0;c1+=arr2[i][0],c2+=arr2[i][1]){
				if(cb[c1][c2].p->type == arr1[0] && turn_flag == cb[c1][c2].p->colour){
					if(n==4){ 
						if(arr1[1]==qual1)	
							return &cb[c1][c2];	
						else
							printf("Illegal move\n");			
					}
					else
						return &cb[c1][c2];
				}
				else
					;
			}
		}
		else if(arr1[0] == K || arr1[0] == N){
			c1+=arr2[i][0];
			c2+=arr2[i][1];

			if(cb[c1][c2].p->type == arr1[0] && turn_flag == cb[c1][c2].p->colour){
				if(n==4){
					if(arr1[1]==qual1)	
						return &cb[c1][c2];	
					else
						printf("Illegal move\n");			
				}
				else
					return &cb[c1][c2];
			}
			else
				;
		}
	}	
}	

struct square *pawn_finder(char *arr,int n,struct square cb[8][8]){
	//check all 2 positions from pawn to behind
int i,j,c1=0,c2=0,file,rank,qual1,qual2;		
	
	file = arr[0]-'a';
	rank = (8-(arr[1]-'0'));
	
	if(turn_flag == 1){
			if(cb[rank+1][file].p != NULL && cb[rank+1][file].p->type == P) //white pwn 1 behind	 
				return &cb[rank+1][file];
			
			else if(cb[rank+2][file].p != NULL && cb[rank+2][file].p->type == P) //white pwn 2 behind	
				return &cb[rank+2][file];	
	
			else
				printf("Illegal move\n");								
	}
	
	else if(turn_flag == 0){
			if(cb[rank-1][file].p != NULL && cb[rank-1][file].p->type == P) //black pwn 1 behind
					return &cb[rank-1][file];
			
			else if(cb[rank-2][file].p == NULL && cb[rank-2][file].p->type == P) //black pwn 2 behind
					return &cb[rank-2][file];

			else 
				printf("Illegal move\n");			
		}
}

struct square *pawncapt_finder(char *arr , int n,struct square cb[8][8]){
	
int i,j,c1=0,c2=0,file,rank,qual1,qual2;		
	
	file = arr[2]-'a';
	rank = (8-(arr[3]-'0'));		
	qual1 = arr[0]-'a';	
		
	if(turn_flag==0){
		if(cb[rank-1][file-1].p != NULL && cb[rank-1][file-1].p->type == P && qual1 == file-1) 
					return &cb[rank-1][file-1];
				
		else if(cb[rank-1][file+1].p != NULL && cb[rank-1][file+1].p->type == P && qual1 == file+1) 
					return &cb[rank-1][file+1];
	}
	
	else if(turn_flag==1){ 
		if(cb[rank+1][file-1].p != NULL && cb[rank+1][file-1].p->type == P && qual1 == file-1) 
					return &cb[rank+1][file-1];
				
		else if(cb[rank+1][file+1].p != NULL && cb[rank+1][file+1].p->type == P && qual1 == file+1) 
					return &cb[rank+1][file+1];
	}
	
}

struct square *piece_finder(char *inp_arr,int n,struct square cb[8][8]){
	
int king_arr[8][2]={	
	{1,0},
	{1,1},
	{0,1},
	{-1,1},
	{-1,0},
	{-1,-1},
	{0,-1},
	{1,-1}
};

int queen_arr[8][2]={
	{1,0},
	{0,1},
	{-1,0},
	{0,-1},
	
	{1,1},
	{-1,1},
	{-1,-1},
	{1,-1}	
};

int rook_arr[4][2]={
	{1,0},
	{0,1},
	{-1,0},
	{0,-1}	
};

int bishop_arr[4][2]={
	{1,1},
	{-1,1},
	{-1,-1},
	{1,-1}
};

int knight_arr[8][2]={
	{1,2},
	{1,-2},
	{-1,2},
	{-1,-2},
	{2,1},
	{2,-1},
	{-2,1},
	{-2,-1}
};
			
	if(inp_arr[1] == 'x')
		return(pawncapt_finder(inp_arr,n,cb));
	else if(n==2)
		return(pawn_finder(inp_arr,n,cb));
	else if(inp_arr[0]=='R'){
		int arr2_size = sizeof(rook_arr)/sizeof(rook_arr[0]);
		return(source_finder(inp_arr,rook_arr,arr2_size,n,cb));
	}
	else if (inp_arr[0]=='B'){
		int arr2_size = sizeof(bishop_arr)/sizeof(bishop_arr[0]);
		return(source_finder(inp_arr,bishop_arr,arr2_size,n,cb));
	}
	else if (inp_arr[0]=='N'){
		int arr2_size = sizeof(knight_arr)/sizeof(knight_arr[0]);
		return(source_finder(inp_arr,knight_arr,arr2_size,n,cb));
	}
	else if (inp_arr[0]=='Q'){
		int arr2_size = sizeof(queen_arr)/sizeof(queen_arr[0]);
		return(source_finder(inp_arr,queen_arr,arr2_size,n,cb));
	}
	else if (inp_arr[0]=='K'){
		int arr2_size = sizeof(king_arr)/sizeof(king_arr[0]);
		return(source_finder(inp_arr,king_arr,arr2_size,n,cb));		
	}
};

void input (){
	
int i,n,file,rank;
char c,dst_array[5];	
struct piece *ptr1;
struct square *ptr2;
	
	for(i=0;i<5;i++){
		if((c=getchar())=='\n'){
			dst_array[i]='\0';
			break;
		}	
		else if(c==EOF){
			program_stop=1;
			break;
		}
		else{
			dst_array[i]=c;
			continue;
		}		
	}	
	
	n = strlen(dst_array);

	//printf("%c%c%c\n",dst_array[0],dst_array[1],dst_array[2]);

	ptr1 = (piece_finder(dst_array , n ,cb))->p; 
	
	if(n==2){
		file =  dst_array[0]-'a';
		rank = (8-(dst_array[1]-'0'));
	}
	else if(n==3){
		file =  dst_array[1]-'a';
		rank = (8-(dst_array[2]-'0'));
	}
	else if(n==4){
		file = dst_array[2]-'a';
		rank = (8-(dst_array[3]-'0'));  
	} 
	
	ptr2 = &cb[rank][file];
	
	make_move(ptr1,ptr2);
	
}

