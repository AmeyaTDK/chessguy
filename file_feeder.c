
 
/*
////////////////////
//Declerations - 
//void input_packager(FILE *);
//void packet_reader();
//struct move *move_list(char *, struct move *, int , int);

//Main statemnets -

init();    
if(argc == 2){
//FILE *fp = fopen(argv[1], "r");                
//input_packager(fp);
//packet_reader();
//fclose(fp);    
}
else{
while(1){
init_cmet();
if(input()){
continue;
}
output(cb);
if(turn_flag == 1)
turn_flag = 0;
else
turn_flag = 1;
}	
}
///////////////////////
///code -  
void input_packager(FILE *fp){

int i,j,move_counter=0,empty_line=0,char_counter=0,space_counter,move_char=0;
char input,line_buff[2],move_buff[2],dst_arr[8];
struct move *head = NULL;

if(fp == NULL){
printf("Error in opening the file\n");
}

while((input=fgetc(fp)) != EOF){

line_buff[0]=line_buff[1];
line_buff[1]=input;

if(empty_line == 0 && line_buff[0] == line_buff[1] && line_buff[1] == '\n'){    //Ignores tags
empty_line = 1;
continue;
}

else if(empty_line == 1){   
if(input == '.'){
space_counter=0;
move_counter++;
continue;
} 
if(input == ' ' || input == '\n'){
space_counter++;
dst_arr[move_char] = '\0';
if(space_counter == 2 || space_counter == 3){ 
//for(int i=0; dst_arr[i] != '\0';i++){
//    printf("%c",dst_arr[i]);
//}
//printf(" ");
head = move_list(dst_arr,head,turn_flag,move_counter);
}
move_char=0;
continue;
}
if(space_counter == 1){
turn_flag = 1;
dst_arr[move_char]=input;
move_char++;
continue;
}
if(space_counter == 2){
    //head = move_list(dst_arr,head,turn_flag,move_counter);
    turn_flag = 0; 
    dst_arr[move_char]=input;
    move_char++;
    continue;
}
if(space_counter == 3){
    //head = move_list(dst_arr,head,turn_flag,move_counter);
    continue;
}
else
;
}   
}

//while(start->next != NULL){
//    printf("")
//}

}

void packet_reader(){

    while(start->next != NULL){
        make_move(start->p, start->dst);
        output(cb);
        printf("\n");
        start=start->next;
    }
    make_move(start->p, start->dst);
    output(cb);
    printf("\nGame completed\n");
}

struct move *create_node(){
    struct move *new_node = malloc(sizeof(struct move));
    return new_node;
}

struct move *move_list(char *dst_arr, struct move *head, int turn_flag, int move_counter){
    //Append node to existing / Start a list
    //Store neccessary data in that node
    //return head to the list pointer variable

    int file,rank,qual;
    struct move *new_node;

    if(head == NULL){
        start = head = create_node();
    }
    else{
        head->next = create_node();
        head = head->next;
    }

    head->move_no = move_counter;
    head->turn_flag = turn_flag;

    int n = strlen(dst_arr);

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

    if(type == P && n==2)
        head->p = pawn_finder(file, rank, cb);
    else if(type == P && n==4)
        head->p = pawncapt_finder(file, rank, qual, cb);
    else 	
        head->p = source_finder(type, file, rank, qual, cb, n); 

    head->dst = &cb[rank][file];
    head->next = NULL;

    return head;
}




if(input == '.'){
    //move_counter++;
    space_counter=char_counter=0;
    //printf("|");
}
if(input == ' ' || input == '\n'){
    space_counter++;
}
if(char_counter<15 && input != '.' && space_counter>=1 && space_counter<3){
    move_set[move_counter][char_counter] = input;
    //printf("%c",move_set[move_counter][char_counter]);
    char_counter++;
}
if(space_counter == 3){
    for(i=char_counter)
}

   struct move{
       int move_no;
       int turn_flag;
       struct piece *p;
       struct square *dst;
       struct move *next;
   };

*/
