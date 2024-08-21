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
				printf("\n");
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

char convert(enum tpiece type) {
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

struct square *bishop_finder(char *arr,int n,struct square cb[8][8]){
	//checks bishop scope in clockwise starting from bottom right diagonal 
int i,j,c1=0,c2=0,file,rank,qual1,qual2;
	
	if(n==3){				//Ba4
	file = arr[1]-'a';
	rank = (8-(arr[2]-'0'));
	}
	else if(n==4){	//Baa4 or B3a4
		file = arr[2]-'a';
		rank = (8-(arr[3]-'0'));
		
		if(islower(arr[1]))
			qual1 = arr[1]-'a';
		else if(isdigit(arr[1]))
			qual2 =(8-(arr[1]-'0'));	
	}
	 
	for(i=0,j=0;c1<8 && c2<8;i++,j++){ //+- diagonal
		c1=file+j;
		c2=rank+i;
				
		if(cb[c2][c1].p == NULL)
			;
		else{
			if(cb[c2][c1].p->type == B && turn_flag == cb[c2][c1].p->colour){
				if(n==4){	
					if(islower(arr[1])){
						if(qual1 == c1)
							return &cb[c2][c1];
					}
					else if(isdigit(arr[1])){			
						if(qual2 == c2)
							return &cb[c2][c1]; 
					}
				}
				else
					return &cb[c2][c1];
			}
			else
				;
		}		
	}
	
	for(i=0,j=0;c1>0 && c2<8;i++,j++){ // -- diagonal
		c1=file-j;
		c2=rank+i;
				
		if(cb[c2][c1].p == NULL)
			;
		else{
			if(cb[c2][c1].p->type == B && turn_flag == cb[c2][c1].p->colour){
				if(n==4){	
					if(islower(arr[1])){
						if(qual1 == c1)
							return &cb[c2][c1];
					}
					else if(isdigit(arr[1])){			
						if(qual2 == c2)
							return &cb[c2][c1]; 
					}
				}
				else
					return &cb[c2][c1];
			}
			else
				;
		}
	}

	for(i=0,j=0;c1>0 && c2>0;i++,j++){ // +- diagonal
		c1=file-j;
		c2=rank-i;
				
		if(cb[c2][c1].p == NULL)
			;
		else{
			if(cb[c2][c1].p->type == B && turn_flag == cb[c2][c1].p->colour){
				if(n==4){	
					if(islower(arr[1])){
						if(qual1 == c1)
							return &cb[c2][c1];
					}
					else if(isdigit(arr[1])){			
						if(qual2 == c2)
							return &cb[c2][c1]; 
					}
				}
				else
					return &cb[c2][c1];
			}
			else
				;
		}
	}
	
	for(i=0,j=0;c1>0 && c2<8;i++,j++){ // ++ diagonal
		c1=file+j;
		c2=rank-i;
	
	if(cb[c2][c1].p == NULL)
			;
		else{
			if(cb[c2][c1].p->type == B && turn_flag == cb[c2][c1].p->colour){
				if(n==4){	
					if(islower(arr[1])){
						if(qual1 == c1)
							return &cb[c2][c1];
					}
					else if(isdigit(arr[1])){			
						if(qual2 == c2)
							return &cb[c2][c1]; 
					}
				}
				else
					return &cb[c2][c1];
			}
			else
				;
		}				
	}
	
}				
		
struct square *knight_finder(char *arr,int n,struct square cb[8][8]){
	//outside board problem not solved
	//checks clockwise starting form bottom right up
int i,j,c1=0,c2=0,file,rank,qual1,qual2;		
	
	if(n==3){				//Na4
		file = arr[1]-'a';
		rank = (8-(arr[2]-'0'));
	}
	else if(n==4){	//Naa4 or N3a4
		file = arr[2]-'a';
		rank = (8-(arr[3]-'0'));
		
		if(islower(arr[1]))
			qual1 = arr[1]-'a';
		else if(isdigit(arr[1]))
			qual2 =(8-(arr[1]-'0'));	
	}
	
	if(cb[rank+1][file+2].p == NULL) 
		;
	else{ // bottom right up
		if(cb[rank+1][file+2].p->type == N  && turn_flag == cb[rank+1][file+2].p->colour){	
			if(n==4){
				if(islower(arr[1]))
					if(qual1 == arr[1])
						return &cb[rank+1][file+2];
				else if(isdigit(arr[1]))		
					if(qual2 == arr[1])
						return &cb[rank+1][file+2];
			}
			else 
				return &cb[rank+1][file+2];
		}
		else 
			;			
	}
		
	if(cb[rank+2][file+1].p == NULL)
		;	
	else{ //bottom right down
		if(cb[rank+2][file+1].p->type == N && turn_flag == cb[rank+2][file+1].p->colour){
			if(n==4){
				if(islower(arr[1]))
					if(qual1 == arr[1])
						return &cb[rank+2][file+1];
				else if(isdigit(arr[1]))		
					if(qual2 == arr[1])
						return &cb[rank+2][file+1];						
			}
			else 
				return &cb[rank+2][file+1];
		}
		else 
			;		
	}	
			
	if(cb[rank+2][file-1].p == NULL)
		;	
	else{ //bottom left down
		if(cb[rank+2][file-1].p->type == N && turn_flag == cb[rank+2][file-1].p->colour){
			if(n==4){
				if(islower(arr[1]))
					if(qual1 == arr[1])
						return &cb[rank+2][file-1];
				else if(isdigit(arr[1]))		
					if(qual2 == arr[1])
						return &cb[rank+2][file-1];							
			}
			else 
				return &cb[rank+2][file-1];
		}		
	}
			
	if(cb[rank+1][file-2].p == NULL)
		;	
	else{ //bottom left up
		if(cb[rank+1][file-2].p->type == N && turn_flag == cb[rank+1][file-2].p->colour){
			if(n==4){
				if(islower(arr[1]))
					if(qual1 == arr[1])
						return &cb[rank+1][file-2];
				else if(isdigit(arr[1]))		
					if(qual2 == arr[1])
						return &cb[rank+1][file-2];					
			}
		else 
			return &cb[rank+1][file-2];
		}	
	}
			
	if(cb[rank-1][file-2].p == NULL)
		;	
	else{ //top left down
		if(cb[rank-1][file-2].p->type == N && turn_flag == cb[rank-1][file-2].p->colour){
			if(n==4){
				if(islower(arr[1]))
					if(qual1 == arr[1])
						return &cb[rank-1][file-2];
				else if(isdigit(arr[1]))		
					if(qual2 == arr[1])
						return &cb[rank-1][file-2];							
			}
			else 
				return &cb[rank-1][file-2];
		}
	}
	
	if(cb[rank-2][file-1].p == NULL)
		;
	else{ //top left up
		if(cb[rank-2][file-1].p->type == N && turn_flag == cb[rank-2][file-1].p->colour){
			if(n==4){
				if(islower(arr[1]))
					if(qual1 == arr[1])
						return &cb[rank-2][file-1];
				else if(isdigit(arr[1]))		
					if(qual2 == arr[1])
						return &cb[rank-2][file-1];				
		}
		else 
			return &cb[rank-2][file-1];
		}	
	}
		
	if(cb[rank-2][file+1].p == NULL)
		;	
	else{ //top right up
		if(cb[rank-2][file+1].p->type == N && turn_flag == cb[rank-2][file+1].p->colour){
			if(n==4){
				if(islower(arr[1]))
					if(qual1 == arr[1])
						return &cb[rank-2][file+1];
				else if(isdigit(arr[1]))		
					if(qual2 == arr[1])
						return &cb[rank-2][file+1];
							
			}
			else 
				return &cb[rank-2][file+1];
		}
	}
		
	if(cb[rank-1][file+2].p == NULL)
		;	
	else{ //top right down
		if(cb[rank-1][file+2].p->type == N && turn_flag == cb[rank-1][file+2].p->colour){
			if(n==4){
				if(islower(arr[1]))
					if(qual1 == arr[1])
						return &cb[rank-1][file+2];
				else if(isdigit(arr[1]))		
					if(qual2 == arr[1])
						return &cb[rank-1][file+2];
							
			}
			else 
				return &cb[rank-1][file+2];
		}
	}
	
}

struct square *rook_finder(char *arr,int n,struct square cb[8][8]){
	//checks rook scope in clockwise starting from right row
int i,j,c1=0,c2=0,file,rank,qual1,qual2;	
	
	if(n==3){				//Ra4
		file = arr[1]-'a';
		rank = (8-(arr[2]-'0'));
	}
	else if(n==4){	//Raa4 or R3a4
		file = arr[2]-'a';
		rank = (8-(arr[3]-'0'));
		
		if(islower(arr[1]))
			qual1 = arr[1]-'a';
		else if(isdigit(arr[1]))
			qual2 =(8-(arr[1]-'0'));	
	}
	
	for(j=0;c1<8;j++){ //right row
		c1=file+j;
		c2=rank;
		
		if(cb[c2][c1].p == NULL)
			;
		else{
			if(cb[c2][c1].p->type == R && turn_flag == cb[c2][c1].p->colour){
				if(n==4){
					if(islower(arr[1]))
						if(qual1 == c1)
							return &cb[c2][c1];
					else if(isdigit(arr[1]))			
						if(qual2 == c2)
							return &cb[c2][c1];				
				}
				else
					return &cb[c2][c1];
			}
			else
				;
		}
	}
	
	for(i=0;c2<8;i++){ //bottom coloumn
		c1=file;
		c2=rank+i;
		
		if(cb[c2][c1].p == NULL)
			;
		else{
			if(cb[c2][c1].p->type == R && turn_flag == cb[c2][c1].p->colour){
				if(n==4){
					if(islower(arr[1])){
						if(qual1 == c1)
							return &cb[c2][c1];
						else if(qual2 == c2)
							return &cb[c2][c1];
					}				
				}
				else
					return &cb[c2][c1];
			}
			else
				;	
		}
	}
	
	for(j=0;c1>0;j++){ //left row
		c1=file-j;
		c2=rank;
		
		if(cb[c2][c1].p == NULL)
			;
		else{
			if(cb[c2][c1].p->type == R && turn_flag == cb[c2][c1].p->colour){
				if(n==4){
					if(islower(arr[1])){
						if(qual1 == c1)
							return &cb[c2][c1];
						else if(qual2 == c2)
							return &cb[c2][c1];
					}				
				}
				else
					return &cb[c2][c1];
			}
			else
				;
		}
	}
	
	for(j=0;c2>0;i++){ //top coloumn
		c1=file;
		c2=rank-i;
		
		if(cb[c2][c1].p == NULL)
			;
		else{
			if(cb[c2][c1].p->type == R && turn_flag == cb[c2][c1].p->colour){
				if(n==4){
					if(islower(arr[1])){
						if(qual1 == c1)
							return &cb[c2][c1];
						else if(qual2 == c2)
							return &cb[c2][c1];
					}				
				}
				else
					return &cb[c2][c1];
			}
			else
				;
		}
	}
	
}

struct square *queen_finder(char *arr,int n,struct square cb[8][8]){ 
	//checks bishop scope in clockwise starting from bottom right diagonal
	//checks rook scope in clockwise starting from right row
int i,j,c1=0,c2=0,file,rank,qual1,qual2;	

	if(n==3){				//Qa4
	file = arr[1]-'a';
	rank = (8-(arr[2]-'0'));
	}
	else if(n==4){	//Qaa4 or Q3a4
		file = arr[2]-'a';
		rank = (8-(arr[3]-'0'));
		
		if(islower(arr[1]))
			qual1 = arr[1]-'a';
		else if(isdigit(arr[1]))
			qual2 =(8-(arr[1]-'0'));	
	}
	 
	for(i=0,j=0;c1<8 && c2<8;i++,j++){ //+- diagonal
		c1=file+j;
		c2=rank+i;
		
		if(cb[c2][c1].p == NULL)
			;	
		else{
			if(cb[c2][c1].p->type == Q && turn_flag == cb[c2][c1].p->colour){
				if(n==4){	
					if(islower(arr[1])){
						if(qual1 == c1)
							return &cb[c2][c1];
					}
					else if(isdigit(arr[1])){			
						if(qual2 == c2)
							return &cb[c2][c1]; 
					}
				}
				else 
					return &cb[c2][c1];
			}
			else
				;
		}		
	}
	
	for(i=0,j=0;c1>0 && c2<8;i++,j++){ // -- diagonal
		c1=file-j;
		c2=rank+i;
		
		if(cb[c2][c1].p == NULL)
			;
		else{
			if(cb[c2][c1].p->type == Q && turn_flag == cb[c2][c1].p->colour){
				if(n==4){	
					if(islower(arr[1])){
						if(qual1 == c1)
							return &cb[c2][c1];
					}
					else if(isdigit(arr[1])){			
						if(qual2 == c2)
							return &cb[c2][c1]; 
					}
				}
				else 
					return &cb[c2][c1];
			}
			else
				;
		}		
	}
	
	for(i=0,j=0;c1>0 && c2>0;i++,j++){ // -+ diagonal
		c1=file-j;
		c2=rank-i;
		
		if(cb[c2][c1].p == NULL)
			;
		else{
			if(cb[c2][c1].p->type == Q && turn_flag == cb[c2][c1].p->colour){
				if(n==4){	
					if(islower(arr[1])){
						if(qual1 == c1)
							return &cb[c2][c1];
					}
					else if(isdigit(arr[1])){			
						if(qual2 == c2)
							return &cb[c2][c1]; 
					}
				}
				else 
					return &cb[c2][c1];
			}
			else
				;
		}		
	}
	
	for(i=0,j=0;c1>0 && c2<8;i++,j++){ // ++ diagonal
		c1=file+j;
		c2=rank-i;
		
		if(cb[c2][c1].p == NULL)
			;
		else{
			if(cb[c2][c1].p->type == Q && turn_flag == cb[c2][c1].p->colour){
				if(n==4){	
					if(islower(arr[1])){
						if(qual1 == c1)
							return &cb[c2][c1];
					}
					else if(isdigit(arr[1])){			
						if(qual2 == c2)
							return &cb[c2][c1]; 
					}
				}
				else 
					return &cb[c2][c1];
			}
			else
				;
		}		
	}
	
	for(j=0;c1<8;j++){ // right row
		c1=file+j;
		c2=rank;
		
		if(cb[c2][c1].p == NULL)
			;
		else{
			if(cb[c2][c1].p->type == Q && turn_flag == cb[c2][c1].p->colour){
				if(n==4){	
					if(islower(arr[1])){
						if(qual1 == c1)
							return &cb[c2][c1];
					}
					else if(isdigit(arr[1])){			
						if(qual2 == c2)
							return &cb[c2][c1]; 
					}
				}
				else 
					return &cb[c2][c1];
			}
			else
				;
		}
	}
	
	for(i=0;c2<8;i++){ //bottom coloumn
		c1=file;
		c2=rank+i;
		
		if(cb[c2][c1].p == NULL)
			;
		else{
			if(cb[c2][c1].p->type == Q && turn_flag == cb[c2][c1].p->colour){
				if(n==4){	
					if(islower(arr[1])){
						if(qual1 == c1)
							return &cb[c2][c1];
					}
					else if(isdigit(arr[1])){			
						if(qual2 == c2)
							return &cb[c2][c1]; 
					}
				}
				else 
					return &cb[c2][c1];
			}
			else
				;
		}
	}
	
	for(j=0;c1>0;j++){ // left row
		c1=file-j;
		c2=rank;
		
		if(cb[c2][c1].p == NULL)
			;
		else{
			if(cb[c2][c1].p->type == Q && turn_flag == cb[c2][c1].p->colour){
				if(n==4){	
					if(islower(arr[1])){
						if(qual1 == c1)
							return &cb[c2][c1];
					}
					else if(isdigit(arr[1])){			
						if(qual2 == c2)
							return &cb[c2][c1]; 
					}
				}
				else 
					return &cb[c2][c1];
			}
			else
				;
		}
	}
	
	for(j=0;c2>0;i++){ // top coloumn
		c1=file;
		c2=rank-i;
		
		if(cb[c2][c1].p == NULL)
			;
		else{
			if(cb[c2][c1].p->type == Q && turn_flag == cb[c2][c1].p->colour){
				if(n==4){	
					if(islower(arr[1])){
						if(qual1 == c1)
							return &cb[c2][c1];
					}
					else if(isdigit(arr[1])){			
						if(qual2 == c2)
							return &cb[c2][c1]; 
					}
				}
				else 
					return &cb[c2][c1];
			}
			else
				;
		}
	}

}

struct square *king_finder(char *arr,int n,struct square cb[8][8]){
	//outside board problem not solved
	//checks all 8 positions in clockwise rotation starting from right
int i,j,c1=0,c2=0,file,rank,qual1,qual2;	

	file = arr[1]-'a'; //Ka1 
	rank = (8-(arr[2]-'0'));
	
	if(cb[rank][file+1].p == NULL) //right 
		;
	else{  
		if(cb[rank][file+1].p->type == K && turn_flag == cb[rank][file+1].p->colour)
			return &cb[rank][file+1];
		else
			;	
	}
	if(cb[rank+1][file+1].p == NULL)  //bottom right
		;	
	else{ 
		if(cb[rank+1][file+1].p->type == K && turn_flag == cb[rank+1][file+1].p->colour)
			return &cb[rank+1][file+1];
		else
			;
	}
	if(cb[rank+1][file].p == NULL) //bottom
		;	
	else{
		if(cb[rank+1][file].p->type == K && turn_flag == cb[rank+1][file].p->colour)
			return &cb[rank][file];
		else
			;	
	}
	if(cb[rank+1][file-1].p == NULL) //bottom left
		;	
	else{ 
		if(cb[rank+1][file-1].p->type == K && turn_flag == cb[rank+1][file-1].p->colour)
			return &cb[rank+1][file-1];
		else
			;
	}
	if(cb[rank][file-1].p == NULL) //left
		;
	else{  
		if(cb[rank][file-1].p->type == K && turn_flag == cb[rank][file-1].p->colour)
			return &cb[rank][file-1];
		else
			;
	}
	if(cb[rank-1][file-1].p == NULL) //top left
		;	
	else{
		if(cb[rank-1][file-1].p->type == K && turn_flag == cb[rank-1][file-1].p->colour)
			return &cb[rank-1][file-1];
		else
			;
	}
	if(cb[rank-1][file].p == NULL) //top
		;	
	else{
		if(cb[rank-1][file].p->type == K && turn_flag == cb[rank-1][file].p->colour)
			return &cb[rank-1][file];
		else
			;
	}
	if(cb[rank-1][file+1].p == NULL) //top right
		;	
	else{
		if(cb[rank-1][file+1].p->type == K && turn_flag == cb[rank-1][file+1].p->colour)
			return &cb[rank-1][file+1];
		else
			;
	}
	
}

struct square *pawn_finder(char *arr,int n,struct square cb[8][8]){
	//check all 2 positions from pawn to behind
int i,j,c1=0,c2=0,file,rank,qual1,qual2;		
	
	file = arr[0]-'a';
	rank = (8-(arr[1]-'0'));
	
	//printf("%d %d\n",file ,rank);
	
	if(turn_flag == 1){
		if(cb[rank+1][file].p == NULL) //white pwn 1 behind
				;		
		else{	
			if(cb[rank+1][file].p->type == P) 
				return &cb[rank+1][file];
		}
		
		if(cb[rank+2][file].p == NULL) //white pwn 2 behind
				;	
		else
			if(cb[rank+2][file].p->type == P)
				return &cb[rank+2][file];			
	}
	else if(turn_flag == 0){	
		if(cb[rank-1][file].p == NULL) //black pwn 1 behind
				;
		else {
			if(cb[rank-1][file].p->type == P)
				return &cb[rank-1][file];
		}	
			
		if(cb[rank-2][file].p == NULL) //black pwn 2 behind
				;
		else
			if(cb[rank-2][file].p->type == P)
				return &cb[rank-2][file];
	}
	
}

struct square *pawncapt_finder(char *arr , int n,struct square cb[8][8]){
	
int i,j,c1=0,c2=0,file,rank,qual1,qual2;		
	
	file = arr[2]-'a';
	rank = (8-(arr[3]-'0'));		
	qual1 = arr[0]-'a';	
	
	
	if(turn_flag==0){
		if(cb[rank-1][file-1].p == NULL) 
				;
		else{		
			if(cb[rank-1][file-1].p->type == P)
				if(qual1 == file-1)
					return &cb[rank-1][file-1];
				else
					;
			else
				;		
		}
		if(cb[rank-1][file+1].p == NULL) 
				;
		else{		
			if(cb[rank-1][file+1].p->type == P)
				if(qual1 == file+1)
					return &cb[rank-1][file+1];
				else
					;	
			else
				;
		}
	}
	
	else if(turn_flag==1){
		if(cb[rank+1][file-1].p == NULL) 
				;
		else{	
			if(cb[rank+1][file-1].p->type == P)
				if(qual1 == file-1)
					return &cb[rank+1][file-1];
				else
					;
			else
				;		
		}
		if(cb[rank+1][file+1].p == NULL) 
				;
		else{		
			if(cb[rank+1][file+1].p->type == P)
				if(qual1 == file+1)
					return &cb[rank+1][file+1];
				else
					;
			else
				;			
		}
	}
	
}

struct square *source_finder(char *arr,int n,struct square cb[8][8]){

	 if(arr[1] == 'x')
		return(pawncapt_finder(arr,n,cb));
	else if(n==2)
		return(pawn_finder(arr,n,cb));
	else if(arr[0]=='R')
		return(rook_finder(arr,n,cb));
	else if (arr[0]=='B')
		return(bishop_finder(arr,n,cb));
	else if (arr[0]=='N')
		return(knight_finder(arr,n,cb));
	else if (arr[0]=='Q')
		return(queen_finder(arr,n,cb));
	else if (arr[0]=='K')
		return(king_finder(arr,n,cb));	
	//else if(arr[1] == 'x')
	//	return(pawncapt_finder(arr,n,cb));
		//printf("233\n");
	//}			
}

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
	
	//printf("%c%c%c %d\n",dst_array[0] ,dst_array[1],dst_array[2],n); 
	
	ptr1 = (source_finder(dst_array , n ,cb))->p; //seg fault here
	
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
	
	//printf("%d %d\n",file ,rank); 

	ptr2 = &cb[rank][file];
	
	make_move(ptr1,ptr2);
	
}
