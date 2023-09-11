#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int fd = open("file.txt", O_RDWR | O_CREAT, 0644);
    int cp = fork();
    if (cp < 0) {
        fprintf(stderr, "Could not fork the child process");
        exit(1);
    }
    else if (cp == 0) {
        // Child process running
        const char *data = "Text from child process\n";
        write(fd, data, strlen(data));
    }
    else {
        const char *data = "Text from parent process\n";
        write(fd, data, strlen(data));
    }
    return 0;
}
/***********************************************************************************************************************************
 *Yes, both processes can access the file descriptor created by the call to open();
 *
 *What happens when both processes attempt to write to the file depends on the mode in which the
 *file is opened. In any case, both processes are able
 * to append to, truncate, or write to the file whose descriptor they are using. 
 * So if the file is opened in APPEND mode, then both process can write to it correctly, appending in the order they access the file
 * If the file is opened in O_TRUNC mode, then the process writing will trucate the file, overriding anything the previous process
 * has written
 *
 *
 **********************************************************************************************************************************/
