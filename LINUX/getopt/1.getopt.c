/*************************************************************************
	> File Name: 1.getopt.c
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Tue 15 Jun 2021 03:38:03 PM CST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int opt;
    while ((opt = getopt(argc, argv, "ab:c::")) != -1) {
        switch (opt) {
            case 'a': {
                printf("opt a found!\n");
                printf("int = %d\n", optind);
            } break;
            case 'b': {
                printf("opt b found!\n");
                printf("ind = %d\n", optind);
                printf("arg for b = %s\n", optarg);
            } break;
            case 'c': {
                printf("opt c found!\n");
                printf("ind = %d\n", optind);
                printf("arg for c = %s\n", optarg);
            } break;
            default : {
                fprintf(stderr, "Usage : %s -a -b barg -c[carg]!\n", argv[0]);
                exit(1);
            }
        }
    }
    return 0;
}
