/*************************************************************************
	> File Name: 8.ostringstream.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Wed 12 May 2021 02:19:22 PM CST
 ************************************************************************/

#include <iostream>
#include <sstream>
using namespace std;

int main() {
    std::ostringstream s;
    s << "hello world" << " " << 123 << std::endl;     // 把信息打印到字符串的缓冲区
    std::cout << s.str() << std::endl;                 // 再统一打印到屏幕  
    return 0;
}
