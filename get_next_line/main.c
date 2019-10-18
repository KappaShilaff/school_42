#include "get_next_line.h"

int main(int ac, char **argv) {
    char *line;
    int fd1;
    int fd2;
    fd1 = open(argv[1], O_RDONLY);
    while (get_next_line(fd1, &line) > 0) {
        printf("%s\n", line);
        free(line);
    }
    return (0);
}
