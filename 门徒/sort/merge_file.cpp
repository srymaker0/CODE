/*************************************************************************
	> File Name: merge_file.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Tue 15 Jun 2021 11:16:48 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

struct Data {
    FILE *fin;          // 文件指针
    int val, flag;      // val：读入的值  flag：标记是否文件被读空
};

int main(int argc, char **argv) {
    int n = argc - 1;       // 文件数量
    Data *data = (Data *)malloc(sizeof(Data) * n);
    for (int i = 1; i <= n; i++) {
        data[i - 1].fin = fopen(argv[i], "r");         // 打开n个文件
        // 初始化文件
        if (fscanf(data[i - 1].fin, "%d", &data[i - 1].val) == EOF) {
            data[i - 1].flag = 1;
        } else {
            data[i - 1].flag = 0;
        }
    }
    // 合并
    FILE *fout = fopen("output", "w");
    while (1) {
        int flag = 0;
        int ind = -1;
        for (int i = 0; i < n; i++) {
            if (data[i].flag) continue;     // 若flag为1，表示文件读空
            // 进行比较 
            if (ind == -1 || data[i].val < data[ind].val) {
                ind = i;
            }
        }
        if (ind != - 1) {      // ind不等于1表示要向输出文件输出一个值
            fprintf(fout, "%d\n", data[ind].val);
            // 继续读入一个值
            if (fscanf(data[ind].fin, "%d", &data[ind].val) == EOF) {
                data[ind].flag = 1;
            } else {
                data[ind].flag = 0;
            }
            flag = 1;
        }
        if (flag == 0) break;
    }
    return 0;
}
