#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include<unistd.h>

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

void print_board(struct square board[8][8]);
struct piece *input();
char convert(enum tpiece type);
char (*input_packager(FILE *, char [50][15]))[15];
void packet_reader(char (*)[15]);

int program_stop=0;
int turn_flag=1;

int main(int argc, char *argv[]){ 

    char move_set[50][15];

	init();    
    if(argc == 2){
        FILE *fp = fopen(argv[1], "r");        
        char (*ptr)[15]=input_packager(fp, move_set);        
        //void packet_reader(char (*)[15]);
        fclose(fp);    
    }
    else{
	    while(1){
		    if(turn_flag==1){
                print_board(cb);
		        printf("\n");
			    input(); 
		        //system("clear");
                sleep(1);    
			    turn_flag = 0;
		    }
		    else if(turn_flag==0){
	    	    print_board(cb);
		        printf("\n");
		        input();     
                //system("clear");
                sleep(1);              
		        turn_flag = 1;
		    }	
        }
    }
} 

void print_board(struct square board[8][8]){

    int i,j;  
    char c;

    printf("\n");    

	for(i=0;i<9;i++){		
		if(i==8){
			for(j=0;j<9;j++){
				if(j==0)
					printf("    ");
				else
					printf("%c  ",('a'+j-1));					
				if(j==8)
					printf("\n");	
			}
		}
		else{
		    printf(" %d  ",(8-i));
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

struct piece *pawn_finder(int file, int rank, struct square cb[8][8]){
	
	if(turn_flag == 1){
			if(cb[rank+1][file].p != NULL && cb[rank+1][file].p->type == P) 	 
				return (cb[rank+1][file]).p;
			else if(cb[rank+2][file].p != NULL && cb[rank+2][file].p->type == P) 
				return (cb[rank+2][file]).p;	
			else{
				printf("Illegal move\n");								
                return NULL;           
            }         
     }
	else if(turn_flag == 0){
			if(cb[rank-1][file].p != NULL && cb[rank-1][file].p->type == P) 
					return (cb[rank-1][file]).p;
			else if(cb[rank-2][file].p != NULL && cb[rank-2][file].p->type == P) 
					return (cb[rank-2][file]).p;
			else{ 
				printf("Illegal move\n");
                return NULL;            
            }
    }
}

struct piece *pawncapt_finder(int file, int rank, char qual, struct square cb[8][8]){
	
	if(turn_flag==0){
		if(cb[rank-1][file-1].p != NULL && cb[rank-1][file-1].p->type == P && file-1 == (qual-'a')) 
					return (cb[rank-1][file-1]).p;
		else if(cb[rank-1][file+1].p != NULL && cb[rank-1][file+1].p->type == P && file+1 == (qual-'a')) 
					return (cb[rank-1][file+1]).p;
	}
	else if(turn_flag==1){ 
		if(cb[rank+1][file-1].p != NULL && cb[rank+1][file-1].p->type == P && file-1 == (qual-'a')) 
					return (cb[rank+1][file-1]).p;
		else if(cb[rank+1][file+1].p != NULL && cb[rank+1][file+1].p->type == P && file+1 == (qual-'a')) 
					return (cb[rank+1][file+1]).p;
	}
}	

struct piece *source_finder(enum tpiece type, int file, int rank, char qual, struct square cb[8][8], int n){

	int i,j,c1,c2,piece_arr_size;
	int (*piece_arr)[2];
	int max_file,max_rank,min_file,min_rank,file_inc,rank_inc;

	switch(type){
		case K:
			piece_arr = king_arr;	
			piece_arr_size = sizeof(king_arr)/sizeof(king_arr[0]);
			break;
		case Q:
			piece_arr = queen_arr;	
			piece_arr_size = sizeof(queen_arr)/sizeof(queen_arr[0]);
			break;
		case R:
			piece_arr = rook_arr;	
			piece_arr_size = sizeof(rook_arr)/sizeof(rook_arr[0]);
			break;
		case B:
			piece_arr = bishop_arr;	
			piece_arr_size = sizeof(bishop_arr)/sizeof(bishop_arr[0]);
			break;
		case N:
			piece_arr = knight_arr;	
			piece_arr_size = sizeof(knight_arr)/sizeof(knight_arr[0]);
			break;
		default:
			;

	}

	c1 = file; 
	c2 = rank; 		
    
    
    if(cb[rank][file].p != NULL && cb[rank][file].p->colour == turn_flag){
        printf("Can't capture own pieces, try again\n");
        return NULL;
    }    
    else
        ;

	for(i=0;i<piece_arr_size;i++){ 
	    file = c1;
        rank = c2;
        if(type == K || type == N){     	        

             file+= piece_arr[i][0]; 
			 rank+= piece_arr[i][1]; 

		 	 max_file = file+1; 
			 max_rank = rank+1; 
			 min_file = file-1; 
			 min_rank = rank-1; 

			 file_inc = rank_inc =1;	 
		}	
		else{
			max_file = max_rank = 7;
			min_file = min_rank = 0;
			
			file_inc = piece_arr[i][0];
			rank_inc = piece_arr[i][1];
		}

		for(; file<=max_file && rank<=max_rank && file>=min_file && rank >=min_rank; file += file_inc, rank+= rank_inc){
				if(cb[rank][file].p != NULL){
					if(cb[rank][file].p->type == type && turn_flag == cb[rank][file].p->colour){
						if(n==4){ 
							if(islower(qual) && file == (qual-'a'))
								return (cb[rank][file]).p;	
							else if(rank == (8-(qual-'0')))
								return (cb[rank][file]).p;
							else
								;			
						}
						else
							return (cb[rank][file]).p;
					}
					else if(cb[rank][file].p->type != type)
						    break;
			    }
				else
					;
	    }
	}
    printf("Piece couldn't be found, try again\n");
    return NULL; 
}	
	
struct piece *input (){
	
	int i,n,file,rank;
	char c,qual,dst_arr[10];	
	struct piece *ptr1;
	struct square *ptr2;

    if(turn_flag == 1)
        printf("Enter move as white -\n");
    else
        printf("Enter move as black -\n");

	for(i=0;i<5;i++){
		if((c=getchar())=='\n'){
			dst_arr[i]='\0';
			break;
		}	
		else if(c==EOF){
			program_stop=1;
			break;
		}
		else{
			dst_arr[i]=c;
			continue;
		}		
	}	
	
	n = strlen(dst_arr);
	
	if(n==2){
		file = dst_arr[0]-'a';
		rank = (8-(dst_arr[1]-'0'));
		qual = -1;
	}
	if(n==3){				
		file = dst_arr[1]-'a';
		rank = (8-(dst_arr[2]-'0'));
		qual = -1;
	}
	else if(n==4){	
		file = dst_arr[2]-'a';
		rank = (8-(dst_arr[3]-'0'));
		
		if(dst_arr[1] == 'x')
			qual = dst_arr[0];
		else if(islower(dst_arr[1]))
			qual = dst_arr[1];
		else
			qual = dst_arr[1];	
	}
		
	switch(dst_arr[0]) {
		case 'K':
			type = K;
			break;
		case 'Q':
			type = Q;
		    break;	
		case 'R':
	   		type = R;
			break;
		case 'B':
			type = B;
			break;
		case 'N':
			type = N;
			break;	
		default:
			type = P;
		    break;
	}
    
	ptr2 = &cb[rank][file];
	
	if(type == P && n==2)
		ptr1 = pawn_finder(file, rank, cb);
	else if(type == P && n==4)
		ptr1 = pawncapt_finder(file, rank, qual, cb);
	else 	
		ptr1 = source_finder(type, file, rank, qual, cb, n); 

    if(ptr1 != NULL)
        make_move(ptr1, ptr2);
    else{
        printf("\n");
        ptr1 = input();
    }

    return NULL;
}

char (*input_packager(FILE *fp, char move_set[50][15]))[15]{ 

    int i,j,move_counter=0,line_counter=15,char_counter=0,space_counter=0;
    char input;

    if(fp == NULL){
        printf("Error in opening the file\n");
    }
   
    while((input=fgetc(fp)) != EOF){
        if(line_counter>0 && input == '\n'){    //Ignores first 16 lines 
            line_counter--;
        }
        else if(line_counter>0 && input !='\n'){
            continue;
        }
        else if(line_counter == 0){ //Eg - _d4_d5
            if(input == '.'){
                move_counter++;
                space_counter=char_counter=0;
                //printf("|");
            }
            if(input == ' '){
                space_counter++;
            }
            if(input == '\n'){
                continue;
            }
            if(char_counter<15 && input != '.' && space_counter>=1 && space_counter<3){
                move_set[move_counter][char_counter] = input;
                printf("%c",move_set[move_counter][char_counter]);
                char_counter++;
            }           
        }
    }
    /*
    printf("\n");
    for(i=1;i<50;i++){
        for(j=0;j<6;j++){
            move_set[i][j]=move_set[i][j+1];
            printf("%c",move_set[i][j]);
        }
    }
    //printf("%c",move_set[move_counter][char_counter]);
    */
    return move_set;
}    

//void packet_reader(char (*)[15]){
    
//}
