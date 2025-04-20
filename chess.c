/*
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
//Pieces should not be able to capture king

//TO DO-
//Incorrect input error
//Typecast enum piece types to character
//back rank error given unnecessarily
//Arguments passing can be more organized ad efficient

//functions return value shoudl be as per thier purpose

//Promotion checkmate move cant be processed properly

//Need to ignore the moves in the pareanthesis in pgn
//Need to parse 0-0/0-0-0 or EP inputs

//Probably still issues related to king related moves
//Other game conclusion mechanism need to be added (50 move rule, 3 fold rep, Insufficient material ,Stalemate)

*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include<unistd.h>

#include "chess.h"

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

struct move_data{
    int move_no;
    char string1[7];
    char string2[7];
    struct move_data *next;
};

struct move_node{
    int src_file;
    int src_rank;
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

int input(struct move_data *);
void piece_parser(char*);
void pawn_parser(char*);
struct piece *source_finder(int,int,enum piece_type,int(*)[2],int,int *,int *,int(*)[3],bool); 
bool postfix_verify(int,int,enum piece_type,int(*)[2],int);
bool general_verify(bool);
bool check_verify(int,int,enum piece_type,int(*)[2],int,int(*)[3]);
bool checkmate_verify(int,int,enum piece_type,int(*)[2],int);
void retract_move();
void insert_newnode(int,int,int,int);
void delete_newnode();
void make_move(struct piece*, struct square*);
char convert(enum piece_type);
void output(struct square [8][8]);
void move_packager(FILE *);
struct move_data *create_file_node(void);

bool king_flag = true;
struct move_data *file_head = NULL;
struct move_data *file_current = NULL;
struct move_node *head = NULL;
struct move_node *current = NULL;
struct move_node *prevnode_addr = NULL;
bool double_check = false;
bool check_state = false;
bool checkmate_state = false;
int turn_flag = 1;
bool program_stop = false;

int main(int argc, char *argv[]){

    //printf("\033[2J\033[H");

    if(argc == 2){
        FILE *fp = fopen(argv[1],"r");
        move_packager(fp);
        fclose(fp);
    }

    square_init();    
    while(1){
        init_cmet();
        int res = input(file_head);
        switch(res){
            case 0://Normal exit
                break;
            case 1://Invalid move exit
                printf("Invalid move,Please try again !\n");
                continue;
            case 2://Game finishing exit
                output(cb);
                printf("Game is finished, Exiting normally\n");
                return 0;
            case 3://Game unfinished exit
                output(cb);
                printf("Game is unfinished, Exiting normally\n");
                return 0;
        }
        output(cb);
        if(file_head != NULL && turn_flag == -1){
            if(file_current->next == NULL){
                printf("Game complete\n");
                return 1;
            }
            file_current = file_current->next;
        }
        turn_flag *= -1;
    }

}

void move_packager(FILE *fp){

    if(fp == NULL){
        printf("Error in opening the file\n");
        return;
    }

    int move_counter=0,move_length_counter=0,space_counter=0,main_body_length=0;
    char c,cache[2];
    bool record = false;

    while((c = fgetc(fp)) != EOF){

        cache[0] = cache[1];
        cache[1] = c;

        if(cache[0] == '\n' && cache[1] == '\n')
            break;
    }

    while((c = fgetc(fp)) != EOF){

        if(c == '.'){
            if(file_head == NULL){
                file_head = create_file_node();
                file_current = file_head;
            }
            else{
                file_current->next = create_file_node();
                file_current = file_current->next;        
            }
            move_counter++;
            file_current->move_no = move_counter;
            record = true;
            space_counter = 0;
            continue;
        }
        if(record){
            if(c  == ' ' || c == '\n'){
                space_counter++;
                move_length_counter = 0;
                continue;
            }
            if(space_counter == 1){
                file_current->string1[move_length_counter] = c;
                move_length_counter++;
            }
            if(space_counter == 2){
                file_current->string2[move_length_counter] = c;
                move_length_counter++;
            }
            else if(space_counter == 3)
                record = false;
        }
        else
            continue;
    }
    file_current = file_head;
}

struct move_data *create_file_node(){
    struct move_data *newnode = (struct move_data *)calloc(1,sizeof(struct move_data));
    if(newnode == NULL){
        printf("Memory allocation during file input list creation failed\n");
        return NULL;
    }
    return newnode;
}

int input(struct move_data *file_head){

    char c,inp_arr[8]={'\0'};
    struct piece *piece_ptr;
    struct square *dst_sqr_ptr;

    if(file_head == NULL){
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
    }
    else{

        for(int i=0;inp_arr[i] != '\0';i++){
            inp_arr[i] = '\0';
        }

        if(turn_flag == 1){
            int  i=0;
            while(file_current->string1[i] != '\0'){
                inp_arr[i] = file_current->string1[i];
                i++;
            }
        }
        else{
            int  i=0;
            while(file_current->string2[i] != '\0'){
                inp_arr[i] = file_current->string2[i];
                i++;
            }
        }
    }

    if(isupper(inp_arr[0]))
        piece_parser(inp_arr);

    else if(islower(inp_arr[0]))
        pawn_parser(inp_arr);

    else if(isdigit(inp_arr[0]) && inp_arr[1] == '-' && isdigit(inp_arr[2])){
        printf("%c%c%c\n",inp_arr[0],inp_arr[1],inp_arr[2]);
        return 2;
    }
    else if(inp_arr[0] == '*')
        return 3;

    else if(inp_arr[0] == 'O'){
    }

    else if(inp_arr[0]=='^' && inp_arr[1]=='R'){
        if(current == NULL){
            printf("Starting position,can't go back\n");
            return 0;
        }
        retract_move();
        turn_flag *= -1;
        return 0;
    }

    int dst_file = cmet.dst_file,dst_rank = cmet.dst_rank;
    int src_file = cmet.src_file,src_rank = cmet.src_rank;
    enum piece_type move_piece = cmet.type;
    int (*piece_arr)[2],piece_arr_size;

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

    if(source_finder(dst_file,dst_rank,move_piece,piece_arr,piece_arr_size,&src_file,&src_rank,NULL,true) != NULL)
        insert_newnode(src_file,src_rank,dst_file,dst_rank);
    else
        return 1;

    piece_ptr = cb[src_rank][src_file].p;
    dst_sqr_ptr = &cb[dst_rank][dst_file];
    make_move(piece_ptr,dst_sqr_ptr); 

    if(cmet.promo_sym){
        cb[dst_rank][dst_file].p->type = cmet.promo_piece;
        move_piece = cmet.promo_piece;

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
    }

    if(postfix_verify(dst_file,dst_rank,move_piece,piece_arr,piece_arr_size) == false||general_verify(true) == false){
        retract_move();
        return 1;
    }

    if(check_state)
        printf("CHECK! Opponent must protect their KING\n");

    if(checkmate_state){
        printf("\nCHECKMATE! Opponent KING cannot be protected, YOU WIN\n");
        return 2;
    }

    return 0;
}

struct piece *source_finder(int dst_file,int dst_rank,enum piece_type move_piece,int (*piece_arr)[2],int piece_arr_size,int *src_file,int *src_rank,int (*checking_piece_info)[3],bool king_flag){

    int (*piece_array_list[6])[2] = {queen_arr,rook_arr,bishop_arr,knight_arr,NULL,king_arr};
    int inner_max_file,inner_max_rank,inner_min_file,inner_min_rank;
    int outer_max_file,outer_max_rank,outer_min_file,outer_min_rank;
    int og_dst_file = dst_file;
    int og_dst_rank = dst_rank;

    if(cb[og_dst_rank][og_dst_file].p != NULL && cb[og_dst_rank][og_dst_file].p->color == turn_flag && cb[og_dst_rank][og_dst_file].p->type != K){
        printf("Invalid move,square occupied by own piece\n");                   
        return false;
    } //King capture issues

    for(int sub_array=0; sub_array<piece_arr_size; sub_array++){ 
        dst_file = og_dst_file;
        dst_rank = og_dst_rank;

        if(move_piece == K || move_piece == N || move_piece == P){
            if(move_piece == P){
                if(cmet.promo_sym && ((dst_rank != 0 && turn_flag == 1)||(dst_rank != 7 && turn_flag == -1))){
                    printf("Invalid move,PAWN can only promote on opposition's back rank\n");
                    return false;
                }


                if(cb[dst_rank][dst_file].p == NULL){
                    if(cmet.capture_sym){
                        printf("Invalid move,\n");
                        return false;
                    }
                    else{
                        if((((dst_rank == 4 && turn_flag == 1)||(dst_rank == 3 && turn_flag == -1)) && sub_array > 1)||
                                (((dst_rank != 4 && turn_flag == 1)||(dst_rank != 3 && turn_flag == -1)) && sub_array > 0)){
                            printf("Invalid move,\n");
                            return false;
                        }
                    }
                }
                else{
                    if(cb[dst_rank][dst_file].p->type != K){
                        if(cmet.capture_sym){
                            if(sub_array < 2)
                                continue;
                            //else{
                            //    printf("Invalid move,\n");
                            //    return false;
                            //}
                        }
                        else{
                            printf("Invalid move,\n");
                            return false;
                        }
                    }
                    else{
                        if(sub_array < 2)
                            continue;
                    }
                }
            }
                dst_file+= piece_arr[sub_array][0];
                dst_rank+= piece_arr[sub_array][1];
                inner_max_file = dst_file+1; 
                inner_max_rank = dst_rank+1;
                inner_min_file = dst_file-1;
                inner_min_rank = dst_rank-1;
        }

        else{
            inner_max_file = inner_max_rank = 8;
            inner_min_file = inner_min_rank = -1;
        }

        outer_max_file = outer_max_rank = 8;
        outer_min_file = outer_min_rank = -1;

        for(;dst_file<inner_max_file && dst_file<outer_max_file && dst_rank<inner_max_rank && dst_rank<outer_max_rank && 
                dst_file>inner_min_file && dst_file>outer_min_file && dst_rank>inner_min_rank && dst_rank>outer_min_rank
                ;dst_file += piece_arr[sub_array][0], dst_rank+=piece_arr[sub_array][1]){

            if(cb[dst_rank][dst_file].p != NULL && (dst_file != og_dst_file || dst_rank != og_dst_rank)){
                if(cb[dst_rank][dst_file].p->type == move_piece && ((cb[dst_rank][dst_file].p->color == turn_flag && king_flag)||(cb[dst_rank][dst_file].p->color != turn_flag && !king_flag))){
                    if(checking_piece_info != NULL){
                        checking_piece_info[0][0] = dst_file;
                        checking_piece_info[0][1] = dst_rank;
                        checking_piece_info[0][2] = sub_array;
                    }
                    if(src_file != NULL && src_rank != NULL && ((*src_file != -1 && *src_rank != -1 && *src_file == dst_file && *src_rank == dst_rank)||(*src_file != -1 && *src_file == dst_file)||
                                (*src_rank != -1 && *src_rank == dst_rank)||(*src_file == -1 && *src_rank == -1))){ 
                        *src_file = dst_file;
                        *src_rank = dst_rank;
                        return cb[dst_rank][dst_file].p;
                    }
                    else if(src_file == NULL && src_rank == NULL){
                        return cb[dst_rank][dst_file].p;
                    }
                }
                else
                    break;
            }
            else
                continue;
        }
    }
    return NULL;
}

bool general_verify(bool king_flag){ 

    int king_file,king_rank,(*piece_arr)[2],piece_arr_size;
    enum piece_type move_piece;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(cb[i][j].p == NULL)
                continue;
            else if(cb[i][j].p != NULL && cb[i][j].p->type == K && ((cb[i][j].p->color == turn_flag) && king_flag)||((cb[i][j].p->color != turn_flag) && !king_flag)){
                king_file = j;
                king_rank = i;
            }
        }
    }

    for(int i=0;i<5;i++){
        switch(i){
            case 0:
                piece_arr = queen_arr;
                piece_arr_size = 8;
                move_piece = Q;
                break;
            case 1:
                piece_arr = rook_arr;
                piece_arr_size = 4;
                move_piece = R;
                break;
            case 2:
                piece_arr = bishop_arr;
                piece_arr_size = 4;
                move_piece = B;
                break;
            case 3:
                piece_arr = knight_arr;
                piece_arr_size = 8;
                move_piece = N;
                break;
            case 4:
                if((turn_flag == 1 && king_flag)||(turn_flag == -1 && !king_flag))
                    piece_arr = black_pawn_arr;
                else if((turn_flag == -1 && king_flag)||(turn_flag == 1 && !king_flag))
                    piece_arr = white_pawn_arr;
                piece_arr_size = 4;
                move_piece = P;
                break;
        }
        if(source_finder(king_file,king_rank,move_piece,piece_arr,piece_arr_size,NULL,NULL,NULL,false) != NULL){
            printf("Invalid move,KING is/would being/be threatened\n");
            return false;
        }
    }
    if(check_state && !cmet.check_sym)
        check_state = false;

    return true;
}

bool postfix_verify(int dst_file,int dst_rank,enum piece_type move_piece,int(*piece_arr)[2],int piece_arr_size){

    if(cmet.check_sym){
        if(check_verify(dst_file,dst_rank,move_piece,piece_arr,piece_arr_size,NULL)){
            check_state = true;
            return true;
        }
        else
            return false;
    }
    if(cmet.checkmate_sym){
        if(checkmate_verify(dst_file,dst_rank,move_piece,piece_arr,piece_arr_size)){
            checkmate_state = true;
            return true;
        }
        else
            return false;
    }
    else
        return true;
}

bool check_verify(int dst_file,int dst_rank,enum piece_type move_piece,int(*piece_arr)[2],int piece_arr_size,int (*checking_piece_info)[3]){

    int king_file,king_rank;
    int (*discov_piece_array[2])[2];
    bool direct,discov;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(cb[i][j].p != NULL && cb[i][j].p->type == K && cb[i][j].p->color != turn_flag){
                king_file = j;
                king_rank = i;
            }
        }
    }

    if(source_finder(king_file,king_rank,move_piece,piece_arr,piece_arr_size,NULL,NULL,checking_piece_info,true) != NULL)
        direct = true;

    if(checking_piece_info != NULL)
        checking_piece_info += 1;

    if(current->src_file == king_file){
        discov_piece_array[0] = rook_arr;
        discov_piece_array[1] = queen_arr;
        for(int i=0;i<2;i++){
            piece_arr = discov_piece_array[i];
            if(piece_arr == rook_arr)
                move_piece = R;
            else
                move_piece = Q;
            if(source_finder(king_file,king_rank,move_piece,piece_arr,piece_arr_size,NULL,NULL,checking_piece_info,true) != NULL){
                discov = true;
                break;
            }
        }
    }

    if(abs(king_file - current->src_file) == abs(king_rank - current->src_rank)){
        discov_piece_array[0] = bishop_arr;
        discov_piece_array[1] = queen_arr;
        for(int i=0;i<2;i++){
            piece_arr = discov_piece_array[i];
            if(piece_arr == bishop_arr)
                move_piece = B;
            else
                move_piece = Q;
            if(source_finder(king_file,king_rank,move_piece,piece_arr,piece_arr_size,NULL,NULL,checking_piece_info,true) != NULL){
                discov = true;
                break;
            }
        }
    }

    if(direct||discov)
        return true;

    return false;
}

bool checkmate_verify(int dst_file,int dst_rank,enum piece_type move_piece,int(*piece_arr)[2],int piece_arr_size){

    int king_file,king_rank,path_len,*piece_sub_array,direction_index;
    int safe_sqrs[2][8]={{-1,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1}};
    int path_sqrs[2][8]={{-1,-1,-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1,-1,-1}};
    struct piece *blocking_piece = NULL;
    int checking_piece_info[2][3];

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(cb[i][j].p != NULL && cb[i][j].p->type == K && cb[i][j].p->color != turn_flag){
                king_file = j;
                king_rank = i;
            }
        }
    }

    if(check_verify(king_file,king_rank,move_piece,piece_arr,piece_arr_size,&checking_piece_info[0])){

        if(checking_piece_info[0][0] != '\0' && checking_piece_info[1][0] != '\0'){//if both pieces are attacking the king then only movement escape possible
            for(int i=0;i<8;i++){
                if((king_file + king_arr[i][0] <8) && (king_file + king_arr[i][0] >0) && (king_rank + king_arr[i][1] <8) && (king_rank + king_arr[i][1] >0)){
                    safe_sqrs[0][i] = king_file + king_arr[i][0];
                    safe_sqrs[1][i] = king_rank + king_arr[i][1];
                }
            }
            for(int i=0;i<8 && (safe_sqrs[0][i] != -1 || safe_sqrs[1][i] != -1);i++){
                turn_flag *= -1;
                if(source_finder(safe_sqrs[0][i],safe_sqrs[1][i],K,king_arr,8,NULL,NULL,NULL,false) != NULL){ //Confirm for correct king
                    make_move(cb[king_rank][king_file].p,&cb[safe_sqrs[1][i]][safe_sqrs[0][i]]);
                    insert_newnode(safe_sqrs[0][i],safe_sqrs[1][i],king_file,king_rank);
                    if(!general_verify(false)){
                        retract_move();
                        continue;
                    }
                    else{
                        retract_move();
                        return false;
                    }
                }
                turn_flag *= -1;
            }
        }   

        else if(checking_piece_info[0][0] != '\0' || checking_piece_info[1][0] != '\0'){
            int (*checking_piece_info_ptr)[3];
            if(checking_piece_info[0][0] != '\0')
                checking_piece_info_ptr = checking_piece_info;
            else
                checking_piece_info_ptr = checking_piece_info + 1;

            switch(cb[checking_piece_info_ptr[0][1]][checking_piece_info_ptr[0][0]].p->type){ //problem here
                case Q:
                    piece_arr = (queen_arr + checking_piece_info_ptr[0][2]);
                    break;
                case R:
                    piece_arr = (rook_arr + checking_piece_info_ptr[0][2]);
                    break;
                case B:
                    piece_arr = (bishop_arr + checking_piece_info_ptr[0][2]);
                    break;
                case N:
                    piece_arr = (knight_arr + checking_piece_info_ptr[0][2]);
                    break;
                case P:
                    if(cb[checking_piece_info[0][1]][checking_piece_info[0][0]].p->color)
                        piece_arr = (white_pawn_arr + checking_piece_info_ptr[0][2]);
                    else
                        piece_arr = (black_pawn_arr + checking_piece_info_ptr[0][2]);
                    break;
            }

            for(int i=0;checking_piece_info_ptr[0][0] != king_file && checking_piece_info_ptr[0][1] != king_rank;
                    checking_piece_info_ptr[0][0] += piece_arr[i][0],checking_piece_info_ptr[0][1] += piece_arr[i][1],i++){
                path_sqrs[0][i] = checking_piece_info_ptr[0][0];
                path_sqrs[1][i] = checking_piece_info_ptr[0][1];
            }//calculates path of checking piece to king

            for(int i=0;i<8 && (path_sqrs[0][i] != -1 || path_sqrs[1][i] != -1);i++){//examining each square for blocking
                for(int j=0;j<5;j++){
                    switch(j){
                        case 0:
                            piece_arr = queen_arr;
                            piece_arr_size = 8;
                            move_piece = Q;
                            break;
                        case 1:
                            piece_arr = rook_arr;
                            piece_arr_size = 4;
                            move_piece = R;
                            break;
                        case 2:
                            piece_arr = bishop_arr;
                            piece_arr_size = 4;
                            move_piece = B;
                            break;
                        case 3:
                            piece_arr = knight_arr;
                            piece_arr_size = 8;
                            move_piece = N;
                            break;
                        case 4:
                            if(turn_flag)
                                piece_arr = white_pawn_arr;
                            else
                                piece_arr = black_pawn_arr;
                            piece_arr_size = 4;
                            move_piece = P;
                            break;
                    }
                    if(source_finder(path_sqrs[0][i],path_sqrs[1][i],move_piece,piece_arr,piece_arr_size,NULL,NULL,NULL,false) != NULL){ //piece that can move should be opposite sides
                        make_move(blocking_piece,&cb[checking_piece_info_ptr[0][1]][checking_piece_info_ptr[0][0]]); //make the oppositions temp blocking move !?
                        general_verify(false);
                        return false;
                    }
                }
            }

            for(int i=0;i<8;i++){
                if((king_file + king_arr[i][0] <8) && (king_file + king_arr[i][0] >0) && (king_rank + king_arr[i][1] <8) && (king_rank + king_arr[i][1] >0)){
                    safe_sqrs[0][i] = king_file + king_arr[i][0];
                    safe_sqrs[1][i] = king_rank + king_arr[i][1];
                }
            }
            for(int i=0;i<8 && (safe_sqrs[0][i] != -1 || safe_sqrs[1][i] != -1);i++){
                if(source_finder(safe_sqrs[0][i],safe_sqrs[1][i],K,king_arr,8,NULL,NULL,NULL,false) != NULL){
                    make_move(cb[king_rank][king_file].p,&cb[safe_sqrs[1][i]][safe_sqrs[0][i]]);
                    insert_newnode(safe_sqrs[0][i],safe_sqrs[1][i],king_file,king_rank);
                    if(!general_verify(false)){
                        retract_move();
                        return true;        
                    }
                    else{
                        retract_move();
                        return false;
                    }
                }
            }
        }
    }
    else
        return false;
}

void retract_move(){

    if(current->promo_move){
        cb[current->dst_rank][current->dst_file].p->type = P;
    }

    struct piece *piece_ptr = cb[current->dst_rank][current->dst_file].p;
    struct square *dst_sqr_ptr = &cb[current->src_rank][current->src_file];

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

void insert_newnode(int src_file,int src_rank,int dst_file,int dst_rank){

    if(current == NULL){
        current = (struct move_node*)malloc(sizeof(struct move_node));
        if(current == NULL){
            printf("Error in allocating memory for newnode\n");
        }
        current->src_file = src_file;
        current->src_rank = src_rank;
        current->dst_file = dst_file;
        current->dst_rank = dst_rank;
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
        if(cb[dst_rank][dst_file].p != NULL){
            current->captured_piece = cb[dst_rank][dst_file].p;
        }
        else
            current->captured_piece = NULL;
        if(cmet.promo_sym){
            current->promo_move = true;
        }
        else
            current->promo_move = false;
        current->src_file = src_file;
        current->src_rank = src_rank;
        current->dst_file = dst_file;
        current->dst_rank = dst_rank;
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

    if(file_head != NULL){
        if(turn_flag  == 1){
            for(int i=0;file_current->string1[i] != '\0';i++){
                printf("%c",file_current->string1[i]);
            }
        }
        else{
            for(int i=0;file_current->string2[i] != '\0';i++){
                printf("%c",file_current->string2[i]);
            }
        }
        printf("\n");
    }


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

    /*
     ***TREE***

     promo           capture             non capture
     4               1            piece exist   dst_rank(3/4)   dst_rank(else)     

     5               3               2

     1 === Run sub_array 2,3
     1'=== No piece exist to capture

     2 === Run sub_array 0
     2'=== Pawn could not be found

     3 === Run sub_array 0,1 in that order
     3'=== Pawn could not be found

     4 === dst rank must be final rank
     4'=== Pawn can only promote on final rank

     5 === dst_sqr should not have ANY piece
     5'=== Pawn is blocked

*/
    /*
       while(file_current->next != NULL){
       for(int i=0;file_current->string1[i] != '\0';i++)
       printf("%c",file_current->string1[i]);
       printf("\t");
       for(int i=0;file_current->string2[i] != '\0';i++)
       printf("%c",file_current->string2[i]);
       printf("\n");
       file_current = file_current->next;
       }
       return 1;
       */
    /*
     *
     if(cmet.capture_sym && sub_array < 2){
     continue;
     }
     else if(!cmet.capture_sym){
     if(cb[dst_rank][dst_file].p == NULL){
     if((((dst_rank == 4 && turn_flag == 1)||(dst_rank == 3 && turn_flag == -1)) && sub_array > 1)||
     ((dst_rank != 4 && turn_flag == 1)||(dst_rank != 3 && turn_flag == -1)) && sub_array > 0){
     printf("PAWN could not be found\n");
     break;        
     }
     }
     else{ 
     if(cb[dst_rank][dst_file].p->type != K){
     printf("Invalid move,PAWN is blocked\n");
     return false;
     }
     else{
     if(sub_array < 2)
     continue;
     }
     }

     if((((dst_rank == 4 && turn_flag == 1)||(dst_rank == 3 && turn_flag == -1)) && sub_array > 1 && cb[dst_rank][dst_file].p->type != K)||
     ((dst_rank != 4 && turn_flag == 1)||(dst_rank != 3 && turn_flag == -1)) && sub_array > 0 && cb[dst_rank][dst_file].p->type != K){
     printf("PAWN could not be found\n");
     break;        
     }
     }
     }
     *
     */

