#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int cp = fork();
    if (cp < 0) {
        fprintf(stderr, "An error occurred\n");
        exit(1);
    }
    else if (cp == 0) {
        printf("hello\n");
    }
    else {
        wait(NULL);
        printf("goodbye\n");
    }
    return 0;
}
/***********************************************************************************************************************************
 * No, I can't. The book never did that so I looked it up;
 * Apparently you can use sleep() to make the parent process wait for the child to complete execution.
 ** ********************************************************************************************************************************/
