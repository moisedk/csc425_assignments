#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    
    int son = fork();
    if (son < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    if (son == 0) {
        while (1) {
            printf("Son: %d\n", getpid());
            sleep(1);
        }
    }
    else {
        int daughter = fork();
        if (daughter < 0) {
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        if (daughter == 0) {
            while (1) {
                printf("Daughter: %d\n", getpid());
                sleep(1);
            }
        }
        else {
            while (1) {
                printf("Parent: %d\n", getpid());
                sleep(1);
            }
        }
    }
    return 0;
}
