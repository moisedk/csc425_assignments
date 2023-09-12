#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int pipefd[2];
    char buffer;

    if (pipe(pipefd) == -1) {
        fprintf(stderr, "Error creating pipe\n");
        exit(1);
    }
    pid_t c1pid = fork(), c2pid = fork();
    if (c1pid < 0 || c2pid < 0) {
        fprintf(stderr, "Error creating subprocesses\n");
        exit(1);
    }
    if (c1pid == 0) {
        // Child 1 process writing to one end of the pipe
        const char *data = "Message from process 1\n";
        write(pipefd[1], data, strlen(data));
    }
    if (c2pid == 0) {
        // Child 2 process reading from one end of the pipe;
        while (read(pipefd[0], &buffer, 1) > 0) {
             write(STDOUT_FILENO, &buffer, 1);
        }
    }
    else {
        waitpid(c1pid, NULL, WNOHANG);
        waitpid(c2pid, NULL, WNOHANG);
        close(pipefd[0]);
        close(pipefd[1]);
    }
    return 0;
}
/*************************************************
 *The pipes are not "coordinated" so that their in/output come in order. I don't know how to guaranty that process 1 runs first
 *
 * ************************************************/
