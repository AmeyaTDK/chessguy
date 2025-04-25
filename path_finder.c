/*
    for 
        K - 
 */

#include"chess.h"

struct square *path_finder(int ,int ,enum piece_type ,int (*)[2],int ,int ,int ,bool);

int main(){
    
    square_init();

    make_move(cb[6][3].p,&cb[3][4]);

    struct square *path_sqrs = path_finder(6,3,B,bishop_arr,4,-1,-1,true);

    for(int i=0;i<6;i++){
        printf("%d",path_sqrs[i].file);
        printf("%d",path_sqrs[i].rank);
        printf("\n");
    }

    return 0;
}

struct square *path_finder(int dst_file,int dst_rank,enum piece_type move_piece,int (*piece_arr)[2],int piece_arr_size,int src_file,int src_rank,bool king_flag){

    int (*piece_array_list[6])[2] = {queen_arr,rook_arr,bishop_arr,knight_arr,NULL,king_arr};
    int inner_max_file,inner_max_rank,inner_min_file,inner_min_rank;
    int outer_max_file,outer_max_rank,outer_min_file,outer_min_rank;
    int og_dst_file = dst_file;
    int og_dst_rank = dst_rank;
    int distance = 0;
    struct square *path_sqrs = NULL;
    
    if(cb[og_dst_rank][og_dst_file].p != NULL && cb[og_dst_rank][og_dst_file].p->color == turn_flag && cb[og_dst_rank][og_dst_file].p->type != K){
        printf("Invalid move,square occupied by own piece\n");                   
        return false;
    }

    for(int sub_array=0; sub_array<piece_arr_size; sub_array++){ 
        
        path_sqrs = (struct square*)malloc(sizeof(struct square)*6);
        if(path_sqrs == NULL){
            printf("Memory allocation failed\n");
            return NULL;
        }

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

        for(distance = 0;dst_file<inner_max_file && dst_file<outer_max_file && dst_rank<inner_max_rank && dst_rank<outer_max_rank && 
                dst_file>inner_min_file && dst_file>outer_min_file && dst_rank>inner_min_rank && dst_rank>outer_min_rank
                ;dst_file += piece_arr[sub_array][0], dst_rank+=piece_arr[sub_array][1], distance++){
            
            if(dst_file == og_dst_file && dst_rank == og_dst_rank)
                continue;

            if(cb[dst_rank][dst_file].p != NULL){
                if(cb[dst_rank][dst_file].p->type == move_piece && ((cb[dst_rank][dst_file].p->color == turn_flag && king_flag)||(cb[dst_rank][dst_file].p->color != turn_flag && !king_flag))){
                    if((src_file != -1 && src_rank != -1 && src_file == dst_file && src_rank == dst_rank)||(src_file != -1 && src_file == dst_file)||
                                (src_rank != -1 && src_rank == dst_rank)||(src_file == -1 && src_rank == -1)){ 
                        path_sqrs[distance].file = dst_file;
                        path_sqrs[distance].rank = dst_rank;
                        path_sqrs[distance].present = true;
                        path_sqrs[distance].p = cb[dst_rank][dst_file].p;
                        return path_sqrs;
                    }
                }
                else{
                    free(path_sqrs);
                    break;
                }
            }
            else{
                path_sqrs[distance].file = dst_file;
                path_sqrs[distance].rank = dst_rank;
                path_sqrs[distance].present = false;
                path_sqrs[distance].p = NULL;
                continue;
            }
        }
        //free(path_sqrs);
    }
    return NULL;
}
