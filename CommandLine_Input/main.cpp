#include <stdio.h>

// ALSO: main(int argc, char **argv){};
int main(int argc, char *argv[]){
    // argc is number of arguments
    // argv are arguments

    printf("All input arguments.\n");
    for(int i = 0; i < argc; i++){
        printf("%i) Argument: %s\n", i, argv[i]);
    }

    return 0;
}