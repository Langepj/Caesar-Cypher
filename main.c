#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

int get_key();
int code(char[], char*);
void print_help();

int main(int argc, char *argv[]) {
    puts(argv[1]);
    if (strcmp(argv[1], "help") == 0){
        print_help();
        return 0;
    }
    else if(argc != 3) {
        printf("unexpected number of arguments\n");
        return -1;
    }

    if(access(argv[1], F_OK ) == -1 ) {
        printf("Cannot find file \n");
        return -1;
    }

    if((strcmp(argv[2], "e") == 0) || (strcmp(argv[2], "d") == 0)){
        return code(argv[1], argv[2]);
    }
    else{
        printf("Argument not recognized:  %c \n", argv[2]);
        return -1;
    }
}

int get_key(){
    int c;

    printf("Enter character: ");
    c = getchar();

    return c;
}

int code(char fname[], char *mode){
    int buffer[1024];
    int i = 0, key = tolower(get_key()) - 96;
    FILE *fp = fopen( fname , "r");
    int c;
    while ((c = fgetc(fp)) != EOF){
        buffer[i]  = tolower(c);
        i++;
    }

    fclose(fp);
    fp = fopen( fname , "w");
    //TODO: Handle Integers in file
    for(int j = 0; j < i; j++){
        if(buffer[j] == '\0') break;
        if(buffer[j] == ' ' || buffer[j] == '\n' )
            c = buffer[j];
        else if (strcmp(mode, "e") == 0) {
            c = ((buffer[j] - 96) + key) % 25 + 96;
        } else {
            c =  buffer[j] - 96 > key ? ((buffer[j] - 96) - key) % 25 + 96 : 25 + ((buffer[j] - 96) - key) + 96;
        }
        fputc(c , fp);
    }
    fclose(fp);

    strcmp(mode, "e") == 0 ? printf("%s ENCRYPTED \n", fname): printf("%s DECRYPTED \n", fname);
    return 0;
}

void print_help(){
    printf("Help text goes here. \n");
}
