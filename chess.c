/*
 ** Feature issues **
//Pinnned piece detection
//Discoveredered attack moves detection
//Check and Checkmate implementation
//Pawn promo_sym
//Move card
//Special moves(En-passant,Castling) implementation
//Move retract function
//Game conclusion DRAW due to 50 move rule, 3 fold repetition , Insufficient material , stalemate , etc ..

 ** Validation issues **
//Double discoveredered check using en passant possible
//Smothers checkmate
//Cross check

 ** Legality issues **
//Unrelated input producing seg fault instead of proper error
//Unrelated input for white piece producing wrong error
//Error production is incorrect in a lot of cases for both colors

 **Miscallenous issues **
//Pawn logic could be better
//Could use less global variables
//Create program that feeds input through file and can also parse it
//Checkmate patterns possible similar to checkin patterns
//Promotion plus check/checkmate creates new patterns
//Pieces should not be able to capture king

**TOMMOROW**
Replicate all modifications of general_verif() in rest of the functions
Write retract_move(),it should retrace game till start (Maybe we can use retract in many verif() functions)
Add promotion feature
Add checkmate feature
double check and its consquences
Maybe source finder individual validations needed in other functions too??
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include<unistd.h>

enum piece_type{
    K,Q,R,B,N,P
}type;

struct piece{
    int color;
    struct square *sqr;
    enum piece_type type;
} BR1={-1,NULL,R}, 
  BN1={-1,NULL,N},
  BB1={-1,NULL,B},
  BQ={-1,NULL,Q},
  BK={-1,NULL,K},
  BB2={-1,NULL,B},
  BN2={-1,NULL,N},
  BR2={-1,NULL,R},
  BP1={-1,NULL,P},
  BP2={-1,NULL,P},
  BP3={-1,NULL,P},
  BP4={-1,NULL,P},
  BP5={-1,NULL,P}, 
  BP6={-1,NULL,P},
  BP7={-1,NULL,P}, 
  BP8={-1,NULL,P},
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

struct square{
    bool present;
    struct piece *p;
}cb[8][8];

void square_init(){

    for(int rank=2;rank<6;rank++){
        for(int file=0;file<8;file++){
            cb[rank][file].present=0;
            cb[rank][file].p = NULL;
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

int white_pawn_arr[4][2]={
    {0,1},
    {0,2},
    {1,1},
    {-1,1}
};

int black_pawn_arr[4][2]={
    {0,-1},
    {0,-2},
    {1,-1},
    {-1,-1}
};

struct metrics{
    enum piece_type type;
    int dst_file;
    int dst_rank;
    int src_file;
    int src_rank;
    bool check_sym;
    bool checkmate_sym;
    bool capture_sym;
    bool promo_sym;
    enum piece_type promo_piece;
}cmet;

void init_cmet(){
    cmet.type = -1;
    cmet.dst_file = -1;
    cmet.dst_rank = -1;
    cmet.src_file = -1;
    cmet.src_rank = -1;
    cmet.check_sym = false;
    cmet.checkmate_sym = false;
    cmet.capture_sym = false;
    cmet.promo_sym = false;
    cmet.promo_piece = -1;
}

int input(void);
void piece_parser(char*);
void pawn_parser(char*);
struct piece* source_finder(int,int,enum type,int(*)[2],int,int,int); 
void make_move(struct piece*, struct square*);
char convert(enum piece_type);
void output(struct square [8][8]);
bool check_verif(int,int,enum type,int(*)[2],int);
bool checkmate_verif(int,int,int(*)[2],int);
bool discovered_check_verif(int,int,int,int);
bool postfix_verif(int,int,enum type,int(*)[2],int);
bool general_verif(void); 

static struct piece *prev_move_piece = NULL;
static struct square *prev_move_sqr = NULL;
bool double_check = false;
bool check_state = false;
int turn_flag = 1;
bool program_stop = false;

int main(int argc, char *argv[]){ 

    square_init();    
    while(1){
        init_cmet();
        if(input()){
            if(program_stop == true)
                break;
            continue;
        }
        output(cb);
    }	
} 

void piece_parser(char *inp_arr){

    int file_qty=0,rank_qty=0;
    char file_index[2],rank_index[2];

    int len = strlen(inp_arr);

    cmet.promo_sym=false;
    cmet.promo_piece = -1;

    switch(inp_arr[0]) {
        case 75:
            cmet.type = K;
            break;
        case 81:
            cmet.type = Q;
            break;
        case 82:
            cmet.type = R;
            break;
        case 66:
            cmet.type = B;
            break;
        case 78:
            cmet.type = N;
            break;
    }

    for(int i=0;i<len;i++){
        if(islower(inp_arr[i]) && inp_arr[i] != 'x'){
            file_qty++;
            file_index[file_qty-1]=inp_arr[i];
        }
        else if(isdigit(inp_arr[i])){
            rank_qty++;
            rank_index[rank_qty-1]=inp_arr[i];
        }
        else if(inp_arr[i] == 'x'){
            cmet.capture_sym = true;
        }
        else if(inp_arr[i] == '+'){
            cmet.check_sym = true;
        }
        else if(inp_arr[i] == '#'){
            cmet.checkmate_sym = true;
        }
    }

    if(file_qty == 2){
        cmet.src_file = file_index[0]-'a';
        cmet.dst_file = file_index[1]-'a';
    }
    else{
        cmet.dst_file = file_index[0]-'a';
    }
    if(rank_qty == 2){
        cmet.src_rank = 8-(rank_index[0]-'0');
        cmet.dst_rank = 8-(rank_index[1]-'0');
    }
    else{
        cmet.dst_rank = 8-(rank_index[0]-'0');
    }
}

void pawn_parser(char *inp_arr){ 

    int file_qty=0;
    char file_index[2];

    int len = strlen(inp_arr);

    cmet.type = P;
    cmet.src_rank=-1;

    for(int i=0;i<len;i++){
        if(islower(inp_arr[i]) && inp_arr[i] != 'x'){
            file_qty++;
            file_index[file_qty-1]=inp_arr[i];
        }
        else if(isdigit(inp_arr[i])){
            cmet.dst_rank = 8-(inp_arr[i]-'0');
        }
        else if(inp_arr[i] == 'x'){
            cmet.capture_sym = true;
        }
        else if(inp_arr[i] == '+'){
            cmet.check_sym = true;
        }
        else if(inp_arr[i] == '#'){
            cmet.checkmate_sym = true;
        }
        else if(inp_arr[i] == '='){
            cmet.promo_sym = true;
        }
        else if(isupper(inp_arr[i])){
            cmet.promo_piece = inp_arr[i];
        }
    }

    if(file_qty == 2){
        cmet.src_file = file_index[0]-'a';
        cmet.dst_file = file_index[1]-'a';
    }
    else{
        cmet.dst_file = file_index[0]-'a';
    }
}

int input(){

    char c,inp_arr[8];
    struct piece *piece_ptr;
    struct square *dst_sqr_ptr;

    if(turn_flag == 1)
        printf("Enter move as white -\n");
    else
        printf("Enter move as black -\n");

    for(int i=0;i<8;i++){
        c=getchar();
        if(c =='\n'){
            inp_arr[i]='\0';
            break;
        }
        else{
            inp_arr[i]=c;
            continue;
        }
    }

    if(isupper(inp_arr[0])){
        piece_parser(inp_arr);
    }
    else if(islower(inp_arr[0])){
        pawn_parser(inp_arr);
    }
    
    int file = cmet.dst_file;
    int rank = cmet.dst_rank;
    int src_file = cmet.src_file;
    int src_rank = cmet.src_rank;
    enum type move_piece = cmet.type;

    int (*piece_arr)[2];
    int piece_arr_size;

    switch(cmet.type){
        case K:
            piece_arr = king_arr;
            piece_arr_size = 8;
            break;
        case Q:
            piece_arr = queen_arr;
            piece_arr_size = 8;
            break;
        case R:
            piece_arr = rook_arr;
            piece_arr_size = 4;
            break;
        case B:
            piece_arr = bishop_arr;
            piece_arr_size = 4;
            break;
        case N:
            piece_arr = knight_arr;
            piece_arr_size = 8;
            break;
        case P:
            if(turn_flag == 1)
                piece_arr = white_pawn_arr;
            else
                piece_arr = black_pawn_arr;
            piece_arr_size = 4;
            break;
        default:
            return NULL;
    }
    if((piece_ptr = source_finder(file,rank,move_piece,piece_arr,piece_arr_size,src_file,src_rank)) == NULL||
            (postfix_verif(file,rank,piece_arr,piece_arr_size) == false)||(general_verif() == false)){
        printf("Invalid move ,Please try again\n");
        return 1;
    }

    dst_sqr_ptr = &cb[cmet.dst_rank][cmet.dst_file];

    make_move(piece_ptr,dst_sqr_ptr);

    turn_flag *= -1; 

    return 0;
}

struct piece *source_finder(int file,int rank,enum move_piece,int (*piece_arr)[2],int piece_arr_size,int src_file,int src_rank){

    int inner_max_file,inner_max_rank,inner_min_file,inner_min_rank;
    int outer_max_file,outer_max_rank,outer_min_file,outer_min_rank;

    int og_dst_file = file;
    int og_dst_rank = rank;

    if(cb[rank][file].p != NULL && cb[rank][file].p->color == turn_flag){
        printf("Can't capture_sym own pieces, try again\n");                   
        return NULL;
    }

    for(int i=0;i<piece_arr_size;i++){
        file = og_dst_file;
        rank = og_dst_rank;

        if(move_piece == K || move_piece == N || move_piece == P){
            if(cmet.type == P){
                if(cmet.capture_sym == false && ((rank == 4 && turn_flag == 1)||(rank == 3 && turn_flag == -1)))
                    piece_arr_size = 2;                    
                else if(cmet.capture_sym == true){
                    if(i<2)
                        continue;
                }
                else 
                    i=0;

                if(cb[rank][file].p != NULL && cb[rank][file].p->color != turn_flag && cmet.capture_sym == false){
                    return NULL;
                }
            }

            file+= piece_arr[i][0];
            rank+= piece_arr[i][1];

            inner_max_file = file+1; 
            inner_max_rank = rank+1;
            inner_min_file = file-1;
            inner_min_rank = rank-1;
        }
        else{
            inner_max_file = inner_max_rank = 8;
            inner_min_file = inner_min_rank = -1;
        }

        outer_max_file = outer_max_rank = 8;
        outer_min_file = outer_min_rank = -1;

        if(cb[og_dst_rank][og_dst_file].p != NULL && cb[og_dst_rank][og_dst_file].p->color != turn_flag && cmet.capture_sym == false){
            return NULL;
        }

        for(;file<inner_max_file && file<outer_max_file && rank<inner_max_rank && rank<outer_max_rank && 
                file>inner_min_file && file>outer_min_file && rank >inner_min_rank && rank>outer_min_rank
                ;file += piece_arr[i][0], rank+=piece_arr[i][1]){
            if(cb[rank][file].p != NULL && (file != og_dst_file || rank != og_dst_rank)){
                if(cb[rank][file].p->color == turn_flag && cb[rank][file].p->type == move_piece){
                    if((cmet.src_file != -1 && cmet.src_rank != -1 && cmet.src_file == file && cmet.src_rank == rank)||
                            (cmet.src_file != -1 && cmet.src_file == file)||(cmet.src_rank != -1 && cmet.src_rank == rank)||
                            (cmet.src_file == -1 && cmet.src_rank == -1))
                        return cb[rank][file].p;
                    else
                        return NULL;
                }
                else
                    break;
            }
        }
        if(move_piece == P && cmet.capture_sym == false && ((og_dst_rank != 4 && turn_flag == 1)||(og_dst_rank != 3 && turn_flag == -1))){
            printf("Invalid move(Piece(Pawn) could not be found), try again\n");
            return NULL;
        }
    }
    printf("Invalid move(Piece could not be found), try again\n");
    return NULL;
}

bool postfix_verif(int file,int rank,enum move_piece,int(*piece_arr)[2],int piece_arr_size){

    if(cmet.check_sym == true){
        if(check_verif(file,rank,move_piece,piece_arr,piece_arr_size)){
            check_state = true;
            return true;
        }
        else
            return false;
    }
    /*
    if(cmet.checkmate_sym == true){
        if(checkmate_verif(file,rank,piece_arr,piece_arr_size)){
            printf("CHECKMATE ,GAME IS OVER\n")
            program_stop = true;
            return true;
        }
        else
            return false;
    }
    */
    else 
        return true;
}

bool general_verif(void){
    //1)King should not be in check after your move has been played
    //

    int file,rank,king_file,king_rank;
    int inner_max_file,inner_max_rank,inner_min_file,inner_min_rank;
    int outer_max_file,outer_max_rank,outer_min_file,outer_min_rank;
    enum piece_type defend_piece;
    int (*piece_arr)[2],piece_arr_size;

    int (*piece_array_list[6])[2]={king_arr,queen_arr,rook_arr,bishop_arr,knight_arr};

    for(rank=0;rank<8;rank++){
        for(file=0;file<8;file++){
            if(cb[rank][file].p != NULL && cb[rank][file].p->type == K && cb[rank][file].p->color == turn_flag){
                king_file = file;
                king_rank = rank;
                break;
            }
        }
    }
    
    if(turn_flag == 1)
        piece_array_list[5]=black_pawn_arr;
    else
        piece_array_list[5]=white_pawn_arr;

    for(int i=0;i<6;i++){
        
        piece_arr = *(piece_array_list + i);
        piece_arr_size = sizeof(piece_arr)/sizeof(piece_arr[0]);
        
        switch(i){
            case 0:
                defend_piece = K;
                break;
            case 1:
                defend_piece = Q;
                break;
            case 2:
                defend_piece = R;
                break;
            case 3:
                defend_piece = B;
                break;
            case 4:
                defend_piece = N;
                break;
            case 5:
                defend_piece = P;
                break;
        }        
        
        for(int j=0;j<piece_arr_size;j++){
            
            file = king_file;
            rank = king_rank;

            if(defend_piece == K || defend_piece == N || defend_piece == P){
                if(defend_piece == P && j<2){
                    continue;
                }
                
                file+= piece_arr[j][0];
                rank+= piece_arr[j][1];
                
                inner_max_file = file+1; 
                inner_max_rank = rank+1;
                inner_min_file = file-1;
                inner_min_rank = rank-1;
            }
            else{
                inner_max_file = inner_max_rank = 8;
                inner_min_file = inner_min_rank = -1;
            }

            outer_max_file = outer_max_rank = 8;
            outer_min_file = outer_min_rank = -1;
            
            for(;file<inner_max_file && file<outer_max_file && rank<inner_max_rank && rank<outer_max_rank && 
                    file>inner_min_file && file>outer_min_file && rank>inner_min_rank && rank>outer_min_rank
                    ;file += piece_arr[j][0], rank+=piece_arr[j][1]){
                if(cb[rank][file].p != NULL && (file != king_file || rank != king_rank)){
                    if(cb[rank][file].p->color != turn_flag && cb[rank][file].p->type == defend_piece){
                        printf("King is still in check\n");
                        return false;
                    }
                    else
                        break;
                }
            }
        }
    }
   return true;
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

char convert(enum piece_type type){
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

void output(struct square board[8][8]){

    int i,j;  
    char c;

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
                    if(board[i][j].p->color == -1)
                        printf("B%c ",convert(board[i][j].p->type));
                    else if(board[i][j].p->color == 1)
                        printf("W%c ",convert(board[i][j].p->type));
                }
                else 
                    printf("*  ");
            }
            printf("\n");
        }         
    }
    printf("\n");
}

bool check_verif(int file,int rank,enum move_piece,int(*piece_arr)[2],int piece_arr_size){ 

    int og_dst_file = file;
    int og_dst_rank = rank;

    int inner_max_file,inner_max_rank,inner_min_file,inner_min_rank;
    int outer_max_file,outer_max_rank,outer_min_file,outer_min_rank;

    for(int i=0;i<piece_arr_size;i++){
        file = og_dst_file;
        rank = og_dst_rank;

        if(move_piece == K || move_piece == N || move_piece == P){
            if(move_piece == P){
                if(cmet.capture_sym == false && ((rank == 4 && turn_flag == 1)||(rank == 3 && turn_flag == -1)))
                    piece_arr_size = 2;                    
                else if(cmet.capture_sym == true){
                    if(i<2)
                        continue;
                }
                else 
                    i=0;

                if(cb[rank][file].p != NULL && cb[rank][file].p->color != turn_flag && cmet.capture_sym == false)
                    return NULL;
            }

            file+= piece_arr[i][0];
            rank+= piece_arr[i][1];

            inner_max_file = file+1; 
            inner_max_rank = rank+1;
            inner_min_file = file-1;
            inner_min_rank = rank-1;
        }
        else{
            inner_max_file = inner_max_rank = 8;
            inner_min_file = inner_min_rank = -1;
        }

        outer_max_file = outer_max_rank = 8;
        outer_min_file = outer_min_rank = -1;

        for(;file<inner_max_file && file<outer_max_file && rank<inner_max_rank && rank<outer_max_rank && 
                file>inner_min_file && file>outer_min_file && rank>inner_min_rank && rank>outer_min_rank
                ;file += piece_arr[i][0], rank+=piece_arr[i][1]){
            if(cb[rank][file].p != NULL){
                if(cb[rank][file].p->color != turn_flag && cb[rank][file].p->type == K){
                    if(discovered_check_verif(og_dst_file,og_dst_rank,file,rank))
                        double_check = true;
                    return true;
                }
                else
                    break;
            }
        }
    }

    if(discovered_check_verif(og_dst_file,og_dst_rank,file,rank))
        return true;
    else
        return false;
}

bool discovered_check_verif(int file,int rank,int king_file,int king_rank){
    
    int king_file,king_rank;
    enum piece_type discovered_piece;
    int inner_max_file,inner_max_rank,inner_min_file,inner_min_rank;
    int outer_max_file,outer_max_rank,outer_min_file,outer_min_rank;
    
    int ghost_file = file;
    int ghost_rank = rank;

    int(*piece_array_list[5])[2]={king_arr,queen_arr,rook_arr,bishop_arr,knight_arr};

    for(int i=0;i<5;i++){
        file = king_file;
        rank = king_rank;
        piece_arr = *(piece_array_list+i);
        piece_arr_size = sizeof(piece_arr)/sizeof(piece_arr[0]);

        switch(i){
            case 0:
                discovered_piece = K;
                break;
            case 1:
                discovered_piece = Q;
                break;
            case 2:
                discovered_piece = R;
                break;
            case 3:
                discovered_piece = B;
                break;
            case 4:
                discovered_piece = N;
                break;
        }        
            
        for(int j=0;j<piece_arr_size;i++){
            if(discovered_piece == K || discovered_piece == N){
                file+= piece_arr[j][0];
                rank+= piece_arr[j][1];
                inner_max_file = file+1; 
                inner_max_rank = rank+1;
                inner_min_file = file-1;
                inner_min_rank = rank-1;
            }
            else{
                inner_max_file = inner_max_rank = 8;
                inner_min_file = inner_min_rank = -1;
            }

            outer_max_file = outer_max_rank = 8;
            outer_min_file = outer_min_rank = -1;

            for(;file<inner_max_file && file<outer_max_file && rank<inner_max_rank && rank<outer_max_rank && 
                    file>inner_min_file && file>outer_min_file && rank>inner_min_rank && rank>outer_min_rank
                    ;file += piece_arr[j][0], rank+=piece_arr[j][1]){
                if(cb[rank][file].p != NULL){
                    if(cb[rank][file].p->color != turn_flag && cb[rank][file].p->type == discovered_piece && file != ghost_file && rank != ghost_rank)
                        return true;
                    else if(rank == ghost_rank && file == ghost_file)
                        continue;
                    else
                        break;
                }
            }
        }
    }
    return false;
}

/*
bool checkmate_verif(){

    int inner_max_file,inner_max_rank,inner_min_file,inner_min_rank;
    int outer_max_file,outer_max_rank,outer_min_file,outer_min_rank;
    enum piece_type defend_piece;

    enum piece_type attack_piece = cmet.type;
    int attack_piece_file = cmet.dst_file;
    int attack_piece_rank = cmet.dst_rank;

    int (*piece_array_list[6])[2]={king_arr,queen_arr,rook_arr,bishop_arr,knight_arr};
    
    if(turn_flag == 1)
        piece_array_list[5]=black_pawn_arr;
    else
        piece_array_list[5]=white_pawn_arr;

    switch(piece_arr){
        case king_arr:
            defend_piece = K;
            break;
        case queen_arr:
            defend_piece = Q;
            break;
        case rook_arr:
            defend_piece = R;
            break;
        case bishop_arr:
            defend_piece = B;
            break;
        case knight_arr:
            defend_piece = N;
            break;
        case white_pawn_arr:
            defend_piece = P
            break;
        case black_pawn_arr:
            defend_piece = P;
            break;
    }        

    for(int i=0;i<6;i++){  
        file = attack_piece_file;
        rank = attack_piece_rank;

        if(defend_piece == K || defend_piece == N){
            file+= piece_arr[i][0];
            rank+= piece_arr[i][1];
            inner_max_file = file+1; 
            inner_max_rank = rank+1;
            inner_min_file = file-1;
            inner_min_rank = rank-1;
        }
        else{
            inner_max_file = inner_max_rank = 8;
            inner_min_file = inner_min_rank = -1;
        }

        outer_max_file = outer_max_rank = 8;
        outer_min_file = outer_min_rank = -1;
        
        for(;file<inner_max_file && file<outer_max_file && rank<inner_max_rank && rank<outer_max_rank && 
                file>inner_min_file && file>outer_min_file && rank>inner_min_rank && rank>outer_min_rank
                ;file += piece_arr[i][0], rank+=piece_arr[i][1]){
            if(cb[rank][file].p != NULL){
                if(cb[rank][file].p->color != turn_flag && cb[rank][file].p->type != defend_piece && cmet.capture_sym != true){
                    return true;
                }
                else
                    break;
            }
        }
    }
   return false;
}
*/

