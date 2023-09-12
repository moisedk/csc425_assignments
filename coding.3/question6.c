#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int cp = fork();
    if (cp < 0) {
        fprintf(stderr, "An error occurred\n");
        exit(1);
    }
    else if (cp == 0) {
        printf("Child running here...DONE\n");
    }
    else {
        int child_id = waitpid(cp, NULL, 0);
        printf("Parent here waiting for child (id: %d)...DONE\n", child_id);
    }
    return 0;
}

/***************************************************************************************************************************
 *waitpid() would be useful when you need one specific child process to finish running before you continue running the parent process
 * * ************************************************************************************************************************/
