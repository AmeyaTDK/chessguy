
struct move_data{
    int move_no;
    char string1[7];
    char string2[7];
    struct move_data *next;
}chess_move_data;

int main(){

    if(argc == 2){
        FILE *fp = fopen(argv[1],"r");
        move_packager(fp);
        fclose(fp);
    }

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

void move_packager(FILE *fp){

    if(fp == NULL)
        printf("Error in opening the file\n");

    int move_counter=0,move_length_counter=0,space_counter=0,main_body_length=0;
    char c,cache[2];
    bool record = false;

    struct move_data *file_head = NULL;
    struct move_data *file_current = NULL;

    while((c = fgetc(fp)) != EOF){

        cache[0] = cache[1];
        cache[1] = c;

        if(cache[0] == cache[1] == '\n')
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
            if(c  == ' '){
                space_counter++;
                move_length_counter = 0;
                continue;
            }
            if(space_counter == 1){
                move_length_counter++;
                file_current->string1[move_length_counter] = c;
            }
            if(space_counter == 2){
                move_length_counter++;
                file_current->string2[move_length_counter] = c;
            }
            else if(space_counter == 3)
                record = false;
        }
        else
            continue;
    }

}

struct move_data *create_file_node(){
    struct move_data newnode = (struct move_data *)malloc(sizeof(struct move_data));
    return newnode;
}






















/*

   for(int i=0;(c = fgetc(fp)) != EOF;i++){


   if(main_body == NULL){
   main_body = (FILE *)calloc(sizeof(char)*50);
   }

   if(main_body == NULL){
   printf("Memory allocation using malloc failed\n");
   }

   if(i < sizeof(main_body))
 *(main_body + i) = c;
 else
 new_main_body = realloc(main_body,sizeof(char)*50);

 if(new_main_body == NULL){
 printf("Memory allocation using realloc failed\n");
 }
 else
 main_body = new_main_body;

 }

 for(int i=0;i<sizeof(main_body);i++){
 if(main_body[i] == '\n')
 main_body[i] = '\0';

 if(isdigit(*(main_body+i)) && *(main_body+i+1) == '.'){

 }

 }
//write the parsing logic as per required condition

}


while((c = fgetc(fp)) != EOF){

cache[0] = cache[1];
cache[1] = c;

if(isdigit(cache[0]) && cache[1] == '.')
++move_counter;
++main_body_length;
}

main_body = (FILE *)calloc(sizeof(char)*main_body_length);

for(int i=0;i<main_body_length;i++){
if(main_body[i] == '\n'){
for(int j=i;)
main_body[j] = main_body[j+1]; 
if(j+1 == main_body_length)
main_body[j+1] = '\0';

//Can just add null termiation when storing the array
}
}


*/
