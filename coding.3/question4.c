#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(int argc, char *argv[]) {
    int cp = fork();
    if (cp < 0) {
        fprintf(stderr, "An error occurred");
        exit(1);
    }
    else if (cp == 0) {
        execl("/bin/ls", "ls", "-l", "/home",  NULL);
    }
    wait(NULL);
    return 0;
}
/***********************************************************************************************************
 *I tried a couple of variants of exec() and with some documentation, I figured out the main difference is how the arguments are passed
 *excl*** takes generally the program name and argument names (and env variable names) as list of individual element,
 * while execv*** takes generally the program name and argument names (and env variable names) as a vector
 * 
 *Those variants give both flexibility and speed to the programmer: each function does just one thing, instead of letting the programmer
 * input any argument and the function would have to do the work of figuring out how to use them
 * *******************************************************************************************************/
