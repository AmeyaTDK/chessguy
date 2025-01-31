/*
           ** Feature issues **
//Pinnned piece detection
//Discovered attack moves detection
//Check and Checkmate implementation
//Pawn promotion
//Move card
//Special moves(En-passant,Castling) implementation
//Move retract function

            ** Validation issues **
//Double Discovered check using en passant possible
//Smothers checkmate
//Yet to add general_verif() 

            ** Legality issues **
//Unrelated input producing seg fault instead of proper error
//Unrelated input for white piece producing wrong error
//Error production is incorrect in a lot of cases for both colors

            **Miscallenous issues **
//Pawn logic could be better
//Could use less global variables
//Create program that feeds input through file and can also parse it

*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include<unistd.h>

enum tpiece{
    K,Q,R,B,N,P
}type;

struct piece{
    int color;
    struct square *sqr;
    enum tpiece type;
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
    enum tpiece type;
    int dst_file;
    int dst_rank;
    int src_file;
    int src_rank;
    bool check_sym;
    bool checkmate_sym;
    bool capture;
    bool promotion;
    enum tpiece promo_piece;
}cmet;

void init_cmet(){
    cmet.dst_file = -1;
    cmet.dst_rank = -1;
    cmet.src_file = -1;
    cmet.src_rank = -1;
    cmet.check_sym = false;
    cmet.checkmate_sym = false;
    cmet.capture = false;
    cmet.promotion = false;
    cmet.promo_piece = -1;
}

static int *col;
static int *row;
static int (*move_arr)[2];
static int *move_arr_size;

int input();
void piece_parser(char*);
void pawn_parser(char*);
struct piece* source_finder(); 
void make_move(struct piece*, struct square*);
char convert(enum tpiece);
void output(struct square [8][8]);
bool check_verif(int ,int ,int (*)[2],int);
bool postfix_verif();


bool check_state = false;
bool checkmate_state = false;
int turn_flag = 1;

int main(int argc, char *argv[]){ 

    init();    
    while(1){
        init_cmet();
        if(input()){
            continue;
        }
        output(cb);
    }	
} 

void piece_parser(char *inp_arr){

    int file_qty=0,rank_qty=0;
    char file_index[2],rank_index[2];

    int len = strlen(inp_arr);

    cmet.promotion=false;
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
            cmet.capture = true;
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

void pawn_parser(char *inp_arr){ //hxf3=Q+

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
            cmet.capture = true;
        }
        else if(inp_arr[i] == '+'){
            cmet.check_sym = true;
        }
        else if(inp_arr[i] == '#'){
            cmet.checkmate_sym = true;
        }
        else if(inp_arr[i] == '='){
            cmet.promotion = true;
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
        piece_parser(inp_arr);//Nf3xd4#  
    }
    else if(islower(inp_arr[0])){
        pawn_parser(inp_arr);//hxf3=Q#
    }

    if(check_state == true){
        if(check_verif(*row,*col,move_arr,*move_arr_size)){
            printf("Invalid move(King is in check),Please try again\n");
            return 1;
        }
        else
            check_state = false;
    }
    
    if((piece_ptr = source_finder()) == NULL||(postfix_verif() == false)){
        printf("Invalid move ,Please try again\n");
        return 1;
    }

    dst_sqr_ptr = &cb[cmet.dst_rank][cmet.dst_file];

    make_move(piece_ptr,dst_sqr_ptr);

    turn_flag *= -1; 

    return 0;
}

struct piece *source_finder(){

    int file,rank,piece_arr_size;
    int (*piece_arr)[2];
    int inner_max_file,inner_max_rank,inner_min_file,inner_min_rank;
    int outer_max_file,outer_max_rank,outer_min_file,outer_min_rank;

    int og_dst_file = file = cmet.dst_file;
    int og_dst_rank = rank = cmet.dst_rank;

    if(cb[rank][file].p != NULL && cb[rank][file].p->color == turn_flag){
        printf("Can't capture own pieces, try again\n");                   
        return NULL;
    }

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
        
        for(int i=0;i<piece_arr_size;i++){
            file = og_dst_file;
            rank = og_dst_rank;
            
            if(cmet.type == K || cmet.type == N || cmet.type == P){
                if(cmet.type == P){
                    if(cmet.capture == false && ((rank == 4 && turn_flag == 1)||(rank == 3 && turn_flag == -1)))
                        piece_arr_size = 2;                    
                    else if(cmet.capture == true){
                        if(i<2)
                            continue;
                    }
                    else 
                        i=0;
                
                    if(cb[rank][file].p != NULL && cb[rank][file].p->color != turn_flag && cmet.capture == false){
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

            if(cb[og_dst_rank][og_dst_file].p != NULL && cb[og_dst_rank][og_dst_file].p->color != turn_flag && cmet.capture == false){
                return NULL;
            }

            for(;file<inner_max_file && file<outer_max_file && rank<inner_max_rank && rank<outer_max_rank && 
                 file>inner_min_file && file>outer_min_file && rank >inner_min_rank && rank>outer_min_rank
                ;file += piece_arr[i][0], rank+=piece_arr[i][1]){
                if(cb[rank][file].p != NULL && (file != og_dst_file || rank != og_dst_rank)){
                    if(cb[rank][file].p->color == turn_flag && cb[rank][file].p->type == cmet.type){
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
                else
                    continue;
            }
            if(cmet.type == P && cmet.capture == false && ((og_dst_rank != 4 && turn_flag == 1)||(og_dst_rank != 3 && turn_flag == -1))){
                printf("Invalid move(Piece(Pawn) could not be found), try again\n");
                return NULL;
            }
        }
        printf("Invalid move(Piece could not be found), try again\n");
        return NULL;
}

bool postfix_verif(){

    int file = cmet.dst_file;
    int rank = cmet.dst_rank;

    int (*piece_arr)[2];
    int piece_arr_size;

    switch(cmet.type){
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
    }

    if(cmet.check_sym == true){
        if(check_verif(file,rank,&piece_arr[2],piece_arr_size)){
            check_state = true;
            return true;
        }
        else
            return false;
    }
    else
        return true;
    /*
    else if(cmet.checkmate_sym == true){
        if(checkmate_verif(file,rank,(*piece_arr)[2],piece_arr_size))
            checkamte_state = true;
            return true;
        }
        else
            return false;
    }
    else 
        return true;
    */
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

bool check_verif(int file, int rank, int (*piece_arr)[2], int piece_arr_size){ 

// File and Rank are source file and rank of given piece which are confirmed

    int inner_max_file,inner_max_rank,inner_min_file,inner_min_rank;
    int outer_max_file,outer_max_rank,outer_min_file,outer_min_rank;

    for(int i=0;i<piece_arr_size;i++){
        file = og_dst_file;
        rank = og_dst_rank;
            
        if(cmet.type == K || cmet.type == N || cmet.type == P){
            if(cmet.type == P){
                if(cmet.capture == false && ((rank == 4 && turn_flag == 1)||(rank == 3 && turn_flag == -1)))
                    piece_arr_size = 2;                    
                else if(cmet.capture == true){
                    if(i<2)
                        continue;
                }
                else 
                    i=0;
                
                if(cb[rank][file].p != NULL && cb[rank][file].p->color != turn_flag && cmet.capture == false)
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
             file>inner_min_file && file>outer_min_file && rank >inner_min_rank && rank>outer_min_rank
            ;file += piece_arr[i][0], rank+=piece_arr[i][1]){
            if(cb[rank][file].p != NULL){
                if(cb[rank][file].p->color != turn_flag && cb[rank][file].p->type == K)
                    return true;
                else
                    break;
            }
        }
        return false;
    }
}

/*
bool checkmate_verif(int file, int rank, int (*piece_arr)[2], int piece_arr_size){

    //Check if king can move
    //Check if attacking piece can be captured
    //Check if defending piece can be relocated on the path

    //Loop between all the piece arrays
    //Piece to arrive can be any
    //Piece on dst_sqr will be a peice of opp color

    int i,j;
    int piece_file = file;
    int piece_rank = rank;

    if(check_verif(file,rank,(*piece_arr)[2],piece_arr_size) == false){
        return false;
    }

    for(i=-1;i<2;i++){
        for(j=-1;j<2;j++){
            file = king_file+i;
            rank = king_rank+j;
            if(file<8 && file>-1 && rank<8 && rank>0 && cb[file][rank].p == NULL){
                return false;
            }
            else
                continue;
        }
    }
}

*/
