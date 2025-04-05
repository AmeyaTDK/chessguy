
struct piece *source_finder(int dst_file,int dst_rank,enum piece_type move_piece,int (*piece_arr)[2],int piece_arr_size,int src_file,int src_rank){

    int inner_max_file,inner_max_rank,inner_min_file,inner_min_rank;
    int outer_max_file,outer_max_rank,outer_min_file,outer_min_rank;
    int og_dst_file = dst_file;
    int og_dst_rank = dst_rank;

    if((cb[og_dst_rank][og_dst_file].p != NULL && cb[og_dst_rank][og_dst_file].p->color == turn_flag && SF)){
        printf("Invalid move,square occupied by own piece\n");                   
        return false;
    }//Pre src_finder verif

        for(int j=0;j<piece_arr_size;j++){ 
            file = og_dst_file;
            rank = og_dst_rank;

            if((move_piece == K)|| (move_piece == N) || (move_piece == P)){
                if(move_piece == P){
                    if(!cmet.capture_sym && ((rank == 4 && turn_flag == 1)||(rank == 3 && turn_flag == -1))){
                        if(j>1)
                            break;
                    }
                    else if(cmet.capture_sym||cmet.check_sym||cmet.checkmate_sym){
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
                if(cb[rank][file].p != NULL){
                    if(cb[rank][file].p->type == move_piece){
                        if(cb[rank][file].p->color == turn_flag){ 
                            if((src_file != -1 && src_rank != -1 && src_file == file && src_rank == rank)||
                               (src_file != -1 && src_file == file)||(src_rank != -1 && src_rank == rank)||
                               (src_file == -1 && src_rank == -1)){
                                return true;
                            }
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
}
