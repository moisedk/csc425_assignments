#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int cp = fork();
    if (cp < 0) {
        fprintf(stderr, "An error occurred");
        exit(1);
    }
    else if (cp == 0) {
        close(STDOUT_FILENO);
        printf("Where does this go?\n");
        fprintf(stderr, "This is not an error. It's done in full conscience\n");
    }
    else {
        printf("Child has closed its STDOUT_FILENO; Apparently that's none of my business!\n");
    }
    return 0;
}
/****************************************************************************************************************************
 *Nothing should happen, since the STDOUT is closed
 *
 *
 * **************************************************************************************************************************/
