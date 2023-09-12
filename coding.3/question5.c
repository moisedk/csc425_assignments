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
        int wait_id = wait(NULL);
        printf("Child done waiting for nobody: (%d)\n", wait_id);
    }
    else {
        int child_id = wait(NULL);
        printf("Parent here waiting for child (id: %d)...DONE\n", child_id);
    }
    return 0;
}

/***************************************************************************************************************************
 *Wait returns the id of the child that finished running;
 *Calling wait() in the child process does not have any effect because there is no process to wait for;
 *The wait() call returns -1;
 * * ************************************************************************************************************************/
