#include <string.h>
#include <stdio.h>
#include <ctest/test.h>
#include <math.h>
int func_cnt = 0; //记录大TEST的值
Function func_arr[100];
struct FunctionInfo c_test_info;

int RUN_ALL_TESTS() {
    for (int i = 0; i < func_cnt; i++) {
        printf(GREEN_HL("[====RUN====] ") BLUE_HL("%s\n"), func_arr[i].str);
        c_test_info.total = 0;
        c_test_info.success = 0;
        func_arr[i].func();
        double rate = 1.0 * c_test_info.success / c_test_info.total;
        rate *= 100.0;
        //全通过显示绿色 不完全通过显示红色
        //对于浮点数的判等 我们需要设置一个精度 去判断
        printf(YELLOW_HL("[  "));
        if (fabs(rate - 100.0) < 1e-6) {
            printf(BLUE_HL("%6.2lf%%"), rate);//6表示总共占6位（包括% 为了使[]和后面的对齐） 2表示保留2位
        } else {
            printf(RED_HL("%6.2lf%%"), rate);
        }
        printf(YELLOW_HL("  ]")  GREEN_HL(" Total: %d   ")     YELLOW_HL("Success: %d\n" ) , 
            c_test_info.total,
            c_test_info.success
        );
    }    
    return 0;
}

void add_function(TestFuncT func, const char *str) {
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].str = strdup(str);
    func_cnt++;
    return ;
}
