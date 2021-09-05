/*************************************************************************
	> File Name: 1.fd.c
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Tue 15 Jun 2021 04:44:10 PM CST
 ************************************************************************/

#include "head.h"

int main(int argc, char **argv) {
    int fd, fd2;
    if (argc != 3) {
        fprintf(stderr, "Usage %s file1 file2\n", argv[0]);
        exit(1);
    }
    if ((fd = open(argv[1], O_RDONLY)) < 0) {
        perror("open");
        exit(1);
    }
    if ((fd2 = open(argv[2], O_CREAT | O_RDWR, 0666)) < 0) {
        perror("open");
        exit(1);
    }
    while (1) {
        char buff[512] = {};
        size_t size = read(fd, buff, sizeof(buff));
        printf("%s", buff);
        write(fd2, buff, size);
        if (size <= 0) {
            break;
        }
    }
    close(fd);
    close(fd2);
    return 0;
}
