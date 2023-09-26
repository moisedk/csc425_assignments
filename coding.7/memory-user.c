#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    
    if (argc > 3 || argc < 2) {
        fprintf(stderr, "Incorrect use of arguments\nProvide the number of megabytes and the runtime (optional) to use\n");
        return -1;
    }

    int mem_size, run_time;
    mem_size = atoi(argv[1]);
    
    if (argc == 3) {
        run_time = atoi(argv[2]);
    }
    else {
        run_time = 0;
    }

    const int size = mem_size * 1000000; // I have 1000 000 * mem_size bytes to use or mem_size MB to use
    char array[size];

    if (run_time) {
        for (int i = 0; i < run_time; i++) {
            printf("%d\n", array[i]);
        }
    }
    else {
        int i = 0;
        while (1) {
            printf("%d\n", array[i]);
            i = i >= size ? 0 : i + 1;
        }
    }
    return 0;
}
