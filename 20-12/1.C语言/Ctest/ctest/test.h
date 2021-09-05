/*************************************************************************
	> File Name: test.h
	> Author: 
	> Mail: 
	> Created Time: Tue 10 Nov 2020 08:08:16 PM CST
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"

#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a, 34)
#define YELLOW(a) COLOR(a, 33)

#define GREEN_HL(a) COLOR_HL(a, 32)
#define RED_HL(a) COLOR_HL(a, 31)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define YELLOW_HL(a) COLOR_HL(a, 33)

//TEST 所实现的功能是函数定义的功能
#define TEST(a,b)\
void a##_QQQ_##b();\
__attribute__((constructor))\
void add##_QQQ_##a##_QQQ_##b() {\
    add_function(a##_QQQ_##b, #a "." #b);\
}\
void a##_QQQ_##b()

//_Generic返回值是一个表达式 会根据a的内容做相应的字符串替换 并且只能用于c语言 
#define Type(a) _Generic((a),\
    int : "%d",\
    double : "%lf",\
    float : "%f",\
    long long : "%lld",\
    const char * : "%s",\
    char * : "%s"\
)

//此处封装的P是为了改善后面的宏嵌套宏出现的问题
#define P(a, color) {\
    char frm[1000];\
    sprintf(frm, color("%s"), Type(a));\
    printf(frm, a);\
}

#define EXPECT(a, b, comp) {\
    c_test_info.total += 1;\
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    if (_a comp _b) c_test_info.success += 1;\
    else {\
        printf("\n");\
        printf(YELLOW_HL("\t%s:%d: failure\n"), __FILE__, __LINE__);\
        printf(YELLOW_HL("\t\texpect : " #a " " #comp " " #b "\n\t\t" "actual : "));\
        P(_a, YELLOW_HL);\
        printf(YELLOW_HL(" vs "));\
        P(_b, YELLOW_HL);\
        printf("\n\n");\
    }\
    printf(GREEN_HL("[-----------] "));\
    printf("%s %s %s  %s\n", #a, #comp, #b, _a comp _b ? GREEN_HL("True") : RED_HL("False"));\
}

#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)



typedef void (*TestFuncT)();

typedef struct Function {
    TestFuncT func;
    const char *str;
} Function;

struct FunctionInfo {
    int total, success;
};

extern struct FunctionInfo c_test_info;
void add_function(TestFuncT, const char *);
int RUN_ALL_TESTS();

#endif
