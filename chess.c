/*
IMP -  
GAME SHOULD WORK FOR CORRECT INPUT

 ** Feature issues **
//Move card
//Special moves(En-passant,Castling) implementation
//Game conclusion DRAW due to 50 move rule, 3 fold repetition , Insufficient material , stalemate , etc ..

 ** Validation issues **
//Double discoveredered check using en passant possible
//Smothers checkmate

 ** Legality issues **
//Error production is incorrect in a lot of cases for both colors

 **Miscallenous issues **
//Create program that feeds input through file and can also parse it
//Pieces should not be able to capture king

//TO DO-
//Reset global vars after each turn
//Incorrect input error
//Typecast enum piece types to character
//back rank error given unnecessarily
//Arguments passing can be more organized ad efficient

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

struct move_node{
    int og_file;
    int og_rank;
    int dst_file;
    int dst_rank;
    struct piece *captured_piece;
    bool promo_move;
    struct move_node *prev;
    struct move_node *next;
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

void init_cmet(void);
int input(void);
void piece_parser(char*);
void pawn_parser(char*);
bool source_finder(int,int,int*,int*,enum piece_type,int(*)[2],int,int,int,int*,int*,enum piece_type **,int(*)[8],bool,bool,bool,bool,bool,bool); 
bool postfix_verify(int,int,enum piece_type,int(*)[2],int);
bool general_verify(void);
bool check_verify(enum piece_type,int(*)[2],int,enum piece_type**,int(*)[8],bool);
bool checkmate_verify(enum piece_type,int(*)[2],int);
void retract_move();
void insert_newnode(int,int,int,int);
void delete_newnode();
void make_move(struct piece*, struct square*);
char convert(enum piece_type);
void output(struct square [8][8]);

struct move_node *head = NULL;
struct move_node *current = NULL;
struct move_node *prevnode_addr = NULL;
bool double_check = false;
bool check_state = false;
bool checkmate_state = false;
int turn_flag = 1;
bool program_stop = false;

int main(int argc, char *argv[]){ 

    square_init();    
    while(1){
        init_cmet();
        if(input())
            continue;
        output(cb);
        if(checkmate_state)
            return 0;
    }
} 

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
            switch(inp_arr[i]){
                case 81:
                    cmet.promo_piece = 1;
                    break;
                case 82:
                    cmet.promo_piece = 2;
                    break;
                case 66:
                    cmet.promo_piece = 3;
                    break;
                case 78:
                    cmet.promo_piece = 4;
                    break;
            }
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

void retract_move(){

    if(current->promo_move){
        cb[current->dst_rank][current->dst_file].p->type = P;
    }

    struct piece *piece_ptr = cb[current->dst_rank][current->dst_file].p;
    struct square *dst_sqr_ptr = &cb[current->og_rank][current->og_file];

    make_move(piece_ptr,dst_sqr_ptr);

    if(current->captured_piece != NULL){
        cb[current->dst_rank][current->dst_file].present = true;
        cb[current->dst_rank][current->dst_file].p = current->captured_piece;
        cb[current->dst_rank][current->dst_file].p->sqr = &cb[current->dst_rank][current->dst_file];
        cb[current->dst_rank][current->dst_file].p->type = current->captured_piece->type;
        cb[current->dst_rank][current->dst_file].p->color = current->captured_piece->color;
    }

    delete_newnode();
}

void insert_newnode(int file,int rank,int og_dst_file,int og_dst_rank){

    if(current == NULL){
        current = (struct move_node*)malloc(sizeof(struct move_node));
        if(current == NULL){
            printf("Error in allocating memory for newnode\n");
        }
        current->og_file = file;
        current->og_rank = rank;
        current->dst_file = og_dst_file;
        current->dst_rank = og_dst_rank;
        current->captured_piece = NULL;
        current->promo_move = false;
        current->next = NULL;
        current->prev = NULL;
        head = current;
        prevnode_addr = current;
    }
    else{
        current->next = (struct move_node*)malloc(sizeof(struct move_node));
        if(current->next == NULL){
            printf("Error in allocating memory for newnode\n");
        }
        current = current->next;
        if(cb[og_dst_rank][og_dst_file].p != NULL){
            current->captured_piece = cb[og_dst_rank][og_dst_file].p;
        }
        else
            current->captured_piece = NULL;
        if(cmet.promo_sym){
            current->promo_move = true;
        }
        else
            current->promo_move = false;
        current->og_file = file;
        current->og_rank = rank;
        current->dst_file = og_dst_file;
        current->dst_rank = og_dst_rank;
        current->next = NULL;
        current->prev = prevnode_addr;
        prevnode_addr = current;
    }
}

void delete_newnode(){

    if(current->prev == NULL){
        prevnode_addr = head = current = NULL;
        return;
    }

    current->prev->next = NULL;
    prevnode_addr = current->prev;
    current->prev = NULL;
    current = prevnode_addr;
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
    else if(inp_arr[0]=='^' && inp_arr[1]=='R'){
        if(current == NULL){
            printf("Starting position,can't go back\n\n");
            return 0;
        }
        retract_move();
        turn_flag *= -1;
        return 0;
    }

    int dst_file = cmet.dst_file,dst_rank = cmet.dst_rank;
    int src_file = cmet.src_file,src_rank = cmet.src_rank;
    enum piece_type move_piece = cmet.type;
    //enum piece_type promotion_piece = cmet.promo_piece;
    int (*piece_arr)[2],piece_arr_size,target_piece_file,target_piece_rank,ghost_file,ghost_rank;

    switch(move_piece){
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
    }


    if(source_finder(dst_file,dst_rank,&target_piece_file,&target_piece_rank,move_piece,piece_arr,piece_arr_size,src_file,src_rank,NULL,NULL,NULL,NULL,true,false,false,false,false,false) == false){
        delete_newnode();
        printf("Invalid move ,Please try again\n");
        return 1;      
    }

    piece_ptr = cb[target_piece_rank][target_piece_file].p;
    dst_sqr_ptr = &cb[dst_rank][dst_file];
    make_move(piece_ptr,dst_sqr_ptr);

    if(cmet.promo_sym){
        cb[dst_rank][dst_file].p->type = cmet.promo_piece;
    }

    if(postfix_verify(dst_file,dst_rank,move_piece,piece_arr,piece_arr_size) == false||general_verify() == false){
        retract_move();
        printf("Invalid move ,Please try again\n");
        return 1;
    }

    if(checkmate_state){
        printf("\nCHECKMATE !!!\nYou win\n");
        return 0;
    }

    turn_flag *= -1; 
    return 0;
}

bool general_verify(){

    int king_file,king_rank;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(cb[i][j].p != NULL && cb[i][j].p->type == K && cb[i][j].p->color == turn_flag){
                king_file = j;
                king_rank = i;
            }
        }
    }

    if(source_finder(king_file,king_rank,NULL,NULL,-1,NULL,-1,-1,-1,NULL,NULL,NULL,NULL,false,false,false,false,true,false)){
        printf("Invalid move,KING is/would being/be threatened\n");
        return false;
    }
    return true;
}

bool postfix_verify(int dst_file,int dst_rank,enum piece_type move_piece,int(*piece_arr)[2],int piece_arr_size){

    if(cmet.check_sym){
        if(check_verify(move_piece,piece_arr,piece_arr_size,NULL,NULL,false)){
            check_state = true;
            return true;
        }
        else
            return false;
    }
    if(cmet.checkmate_sym){
        if(checkmate_verify(move_piece,piece_arr,piece_arr_size)){
            checkmate_state = true;
            return true;
        }
        else
            return false;
    }
    else
        return true;
}
/*
   bool promo_verify(struct piece *piece_ptr,enum piece_type promo_piece){


   1)h8=Q 
   2)Pawn promotion move, henec verify if promotion is possible (rank condn)
   3)Run source finder and move pawn to dst_sqr and turn promotion metric in move_node to true
   4)Run promo func and change piece type to promo piece
   5)Run postfixx verify and general verify
   6)



   }
   */
bool check_verify(enum piece_type move_piece,int(*piece_arr)[2],int piece_arr_size,enum piece_type **attacking_piece,int (*path_sqrs_ptr)[8],bool CM){

    int king_file,king_rank,ghost_file,ghost_rank;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(cb[i][j].p != NULL && cb[i][j].p->type == K && cb[i][j].p->color != turn_flag){
                king_file = j;
                king_rank = i;
            }
        }
    }

    if(source_finder(king_file,king_rank,NULL,NULL,move_piece,piece_arr,piece_arr_size,-1,-1,&ghost_file,&ghost_rank,attacking_piece,path_sqrs_ptr,false,true,false,false,false,false)){
        if(source_finder(king_file,king_rank,NULL,NULL,move_piece,NULL,-1,-1,-1,&ghost_file,&ghost_rank,attacking_piece,path_sqrs_ptr,false,true,true,false,false,false)){
            double_check = true;
            return true;
        }
        return true;
    }

    else if(source_finder(king_file,king_rank,NULL,NULL,move_piece,NULL,-1,-1,-1,&ghost_file,&ghost_rank,attacking_piece,path_sqrs_ptr,false,false,true,false,false,false)){
        if(source_finder(king_file,king_rank,NULL,NULL,move_piece,NULL,-1,-1,-1,&ghost_file,&ghost_rank,attacking_piece,path_sqrs_ptr,false,false,true,true,false,false)){
            double_check = true;
            return true;
        }
        return true;    
    }

    printf("Invalid move,KING is not being checked\n");
    return false;
}

bool checkmate_verify(enum piece_type move_piece,int(*piece_arr)[2],int piece_arr_size){

    int king_file,king_rank,path_len,*piece_sub_array,path_sqrs[2][8]={{-1,-1,-1,-1,-1,-1,-1,-1},{0}};
    int (*path_sqrs_ptr)[8] = path_sqrs;
    enum piece_type *attacking_piece;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(cb[i][j].p != NULL && cb[i][j].p->type == K && cb[i][j].p->color != turn_flag){
                king_file = j;
                king_rank = i;
            }
        }
    }

    if(check_verify(move_piece,piece_arr,piece_arr_size,&attacking_piece,path_sqrs_ptr,true)){//Confirm king is in check as well as record the squares

        int (*piece_array_list[5])[2]={queen_arr,rook_arr,bishop_arr,knight_arr};

        if(turn_flag == 1)
            *(piece_array_list+4) = white_pawn_arr;
        else
            *(piece_array_list+4) = black_pawn_arr;

        for(int i=0;i<5;i++){
            piece_arr = *(piece_array_list + i);

            switch(i){
                case 0:
                    move_piece = Q;
                    piece_arr_size = 8;
                    break;
                case 1:
                    move_piece = R;
                    piece_arr_size = 4;
                    break;
                case 2:
                    move_piece = B;
                    piece_arr_size = 4;
                    break;
                case 3:
                    move_piece = N;
                    piece_arr_size = 8;
                    break;
                case 4:
                    move_piece = P;
                    piece_arr_size = 4;
                    break;
            }        
        }

        for(int i=0;path_sqrs[0][i] != -1;i++){
            ++path_len;
        }

        for(int i=0;i<path_len;i++){
            if(source_finder(path_sqrs[0][i],path_sqrs[1][i],NULL,NULL,move_piece,piece_arr,piece_arr_size,-1,-1,NULL,NULL,NULL,NULL,true,false,false,false,false,false)){
                printf("Invalid move,KING is not being checkmated\n");
                return false;
            }
            else{
                return true;
            }
        }
    }
    else{
        printf("Invalid move,KING is not being checkmated\n");
        return false;
    }
}

bool source_finder(int file,int rank,int *target_piece_file,int *target_piece_rank,enum piece_type move_piece,int (*piece_arr)[2],int piece_arr_size,
        int src_file,int src_rank,int *ghost_file,int *ghost_rank,enum piece_type **attacking_piece,int (*path_sqr_ptr)[8],
        bool SF,bool PC,bool DC,bool DDC,bool GV,bool CM){

    int (*piece_array_list[6])[2] = {queen_arr,rook_arr,bishop_arr,knight_arr,NULL,king_arr};
    int inner_max_file,inner_max_rank,inner_min_file,inner_min_rank;
    int outer_max_file,outer_max_rank,outer_min_file,outer_min_rank;
    int square_count = 0;
    bool record = false;
    int og_dst_file = file;
    int og_dst_rank = rank;

    if((cb[og_dst_rank][og_dst_file].p != NULL && cb[og_dst_rank][og_dst_file].p->color == turn_flag && SF)){
        printf("Invalid move,square occupied by own piece\n");                   
        return false;
    }

    for(int i=0;i<6;i++){
        if(DC||GV){
            if((DC && i>2)||(GV && i == 5)){
                break;
            }

            if(turn_flag == 1 && DC || turn_flag == -1 && GV){
                *(piece_array_list + 4) = white_pawn_arr;
            }
            else if(turn_flag == -1 && DC || turn_flag == 1 && GV){
                *(piece_array_list + 4) = black_pawn_arr;
            }

            piece_arr = *(piece_array_list + i);

            switch(i){
                case 0:
                    move_piece = Q;
                    piece_arr_size = 8;
                    break;
                case 1:
                    move_piece = R;
                    piece_arr_size = 4;
                    break;
                case 2:
                    move_piece = B;
                    piece_arr_size = 4;
                    break;
                case 3:
                    move_piece = N;
                    piece_arr_size = 8;
                    break;
                case 4:
                    move_piece = P;
                    piece_arr_size = 4;
                    break;
                case 5:
                    move_piece = K;
                    piece_arr_size = 8;
                    break;
            }        
        }

        for(int j=0;j<piece_arr_size;j++){ 
            file = og_dst_file;
            rank = og_dst_rank;

            if((move_piece == K && SF)|| (move_piece == N && !DC) || (move_piece == P && !DC)){
                if(move_piece == P){
                    if(!cmet.capture_sym && ((rank == 4 && turn_flag == 1)||(rank == 3 && turn_flag == -1))){
                        if(j>1)
                            break;
                    }
                    else if((cmet.capture_sym||cmet.check_sym||cmet.checkmate_sym||GV)){
                        if(j<2)
                            continue;
                    }
                    else 
                        j=0;

                    if(cb[rank][file].p != NULL && cb[rank][file].p->color != turn_flag && !cmet.capture_sym && SF){
                        printf("Invalid move,PAWN is blocked\n");
                        return false; //Pawn should not be able to move forward if opp color piece encountered 
                    }
                    if(!cmet.capture_sym && ((rank != 4 && turn_flag == 1)||(rank != 3 && turn_flag == -1)) && SF && j>0){
                        printf("Invalid move,PAWN could not be found\n");//Pawn shouldnt be able to move 2 sqrs only on thier first move
                        return false;//Exits after one sqr is checked
                    }
                    if(cmet.promo_sym && ((rank != 0 && turn_flag == 1)||(rank != 7 && turn_flag == -1))){
                        printf("Invalid move,PAWN can only promote on opposition's back rank\n");
                        return false;//Pawn promotion should only be possible on back opp back rank
                    }
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
                if(file == og_dst_file && rank == og_dst_rank)
                    continue;
                if(record){
                    if(cb[rank][file].p == NULL && (file != og_dst_file||rank != og_dst_rank)){
                        *((*path_sqr_ptr+0)+square_count) = file;
                        *((*path_sqr_ptr+1)+square_count) = rank;
                        ++square_count;
                        continue;
                    }
                    else if(cb[rank][file].p != NULL && cb[rank][file].p->type == **attacking_piece){
                        *((*path_sqr_ptr+0)+square_count) = file;
                        *((*path_sqr_ptr+1)+square_count) = rank;
                        return true;
                    }
                }
                if(cb[rank][file].p != NULL){
                    if(cb[rank][file].p->type == move_piece){
                        if(cb[rank][file].p->color == turn_flag){ 
                            if(SF &&((src_file != -1 && src_rank != -1 && src_file == file && src_rank == rank)||(src_file != -1 && src_file == file)||(src_rank != -1 && src_rank == rank)||(src_file == -1 && src_rank == -1))){
                                *target_piece_file = file;
                                *target_piece_rank = rank;
                                insert_newnode(file,rank,og_dst_file,og_dst_rank);
                                return true;
                            }
                            else if(PC||DC){
                                *ghost_file = file;
                                *ghost_rank = rank;
                                if(CM){
                                    --j;
                                    record = true;
                                    **attacking_piece = move_piece;
                                    break;
                                }
                                return true;       
                            }
                            else if((PC && DC)||(DC && DDC)){
                                if(file != *ghost_file || rank != *ghost_rank){
                                    if(CM){
                                        --j;
                                        record = true;
                                        **attacking_piece = move_piece;
                                        break;
                                    }
                                    return true;
                                }
                                continue;
                            }
                            else
                                break;
                        }
                        else{
                            if(GV)
                                return true;
                            else
                                break;
                        }
                    }
                    else
                        break;
                }
                else
                    continue;
            }
        }
        if(SF||PC)
            return false;
    }
    if(DC||GV)
        return false;
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


