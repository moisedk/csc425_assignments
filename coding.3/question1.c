#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int x = 100;

    printf("X according to the parent process (%d): %d\n", getpid(), x);
    int rc = fork();
    if (rc < 0) {
        fprintf(stderr, "An error occurred");
        exit(1);
    }
    else if (rc == 0) {
        printf("X accoring to child process (%d): %d\n", getpid(), x);
        x = 12;
        printf("New value of X after child changed it to 12: %d\n", x);
    }
    else {
        int wait_id = wait(NULL);
        printf("Child process (%d) must have done executing\n", wait_id);
        printf("X according to parent (%d): %d\n", getpid(), x);
    }
}
/************************************************************************************************************************
 * The variable's value in the child process is the same as the one set in the parent
 * It depens:
 * If the child changes it, executes its branch of code and exit, only the child will see the change
 * I made my parent process wait to enforce that case; When the parent process resumes running, it see its original x
 * If the parents changes the value before calling fork(), the child will see the latest value of the variable;
 * If the parent changes the value after calling fork(), only the parent will see the change;
 *
 *
 * *********************************************************************************************************************/
