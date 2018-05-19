#include <stdio.h>
#include <unistd.h>

int get_key();
int encrypt();
int decrypt();
void print_help();

int main(int argc, char argv[]) {
    if(argc!=3 && &argv[1] != "help") {
        printf("unexpected number of arguments\n");
        return -1;
    }
    if (&argv[1] == "help"){
        print_help();
        return 0;
    }

    if( access( &argv[1], F_OK ) == -1 ) {
        printf("Cannot find file: %s \n", &argv[1]);
        return -1;
    }

    FILE *txt = fopen(&argv[1], "r+");

    if(argv[2] == 'e'){
        return encrypt();
    }
    else if(argv[2] == 'd'){
        return decrypt();
    }
    else{
        printf("Argument not recognized: %c \n", argv[2]);
    }

}

int get_key(){
    return 0;
}

int encrypt(){
    return 0;
}

int decrypt(){
    return 0;
}

void print_help(){
    printf("Help text goes here.");
}
