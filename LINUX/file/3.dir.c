/*************************************************************************
	> File Name: 3.dir.c
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Thu 17 Jun 2021 03:34:40 PM CST
 ************************************************************************/

#include "head.h"

int main(int argc, char **argv) {
    char dir_name[512] = {0};
    DIR *dir = NULL;
    if (argc == 1) {
        strcpy(dir_name, "/home/admin/LINUX/file");
    } else {
        strcpy(dir_name, argv[1]);
    }
    if ((dir = opendir(dir_name)) == NULL) {
        perror(dir_name);
        exit(1);
    }
    while (1) {
        struct dirent *dir_ptr;
        if ((dir_ptr = readdir(dir)) == NULL) {
            break;
        }
        printf("%s\n", dir_ptr->d_name);
    }
    closedir(dir);
    return 0;
}
