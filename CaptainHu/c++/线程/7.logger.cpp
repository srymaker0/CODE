/*************************************************************************
	> File Name: 7.logger.cpp
	> Author: ZYJ 
	> Mail: NO
	> Created Time: Wed 12 May 2021 02:12:36 PM CST
 ************************************************************************/

#include <iostream>
#include <sstream>
#include <map>
#include "thread_pool.h"

// 临时对象  文件名 行号
#define LOG(level) haizei::Logger::LoggerStream(level, __FILE__, __LINE__, haizei::haizei_log)
#define LOG_INFO LOG(haizei::LogLevel::INFO)
#define LOG_WARNING LOG(haizei::LogLevel::WARNING)
#define LOG_DEBUG LOG(haizei::LogLevel::DEBUG)
#define LOG_ERROR LOG(haizei::LogLevel::ERROR)
#define LOG_FATAL LOG(haizei::LogLevel::FATAL)
#define SET_LEVEL(level) haizei::haizei_log.set_level(level)

namespace haizei {
    // 日志等级
    class LogLevel {
    public :
        static const int INFO;
        static const int WARNING;
        static const int DEBUG;
        static const int ERROR;
        static const int FATAL;
    };
    const int LogLevel::INFO = 1;
    const int LogLevel::WARNING = 2;
    const int LogLevel::DEBUG = 3;
    const int LogLevel::ERROR = 4;
    const int LogLevel::FATAL = 5;
    // 把日志等级映射成相应的字符串
    static std::map<int, std::string> LevelString = {
        {LogLevel::INFO, "INFO"},
        {LogLevel::WARNING, "WARNING"},
        {LogLevel::DEBUG, "DEBUG"},
        {LogLevel::ERROR, "ERROR"},
        {LogLevel::FATAL, "FATAL"}
    };
    
    // logger
    class Logger {
    public :
        Logger() : LOG_LEVEL(LogLevel::INFO) {}
        // 临时对象
        class LoggerStream : public std::ostringstream {
        public:
            // 构造函数 参数：等级，文件名，行号
            // raw_log指向logger对象， 让所有的临时对象去抢占一个锁
            LoggerStream(
                int level, const char *file_name,
                int line_no, Logger &raw_log
            ) : line_no(line_no), level(level), raw_log(raw_log) {
                std::ostringstream &now = *this;
                now << "[" << file_name << " : " << LevelString[level] << "] ";
            }
            // 析构
            ~LoggerStream() {
                if (level < raw_log.LOG_LEVEL) return ;                  // 当前等级小于我们设置的等级
                std::unique_lock<std::mutex> lock(raw_log.m_mutex);                    // 抢占互斥锁 同步打印到屏幕上
                std::cout << this->str() << " (" << line_no << ")" << std::endl;       // 输出信息，打印行号
            }
        private:
            int line_no, level;
            Logger &raw_log;
        };
        void set_level(int level) { this->LOG_LEVEL = level;}
        int LOG_LEVEL;
        std::mutex m_mutex;    // 锁
    };
    Logger haizei_log;         
    Logger haizei_log1;
} // end of haizei

void func(int a, int b, int c) {
    LOG_INFO << a << " " << b << " " << c;
    return ;
}

int main() {
    // SET_LEVEL(haizei::LogLevel::DEBUG);                // 如果设置了日志等级，所有小于DEBUG等级的都不会显示
    LOG_INFO << "hello world " << 123 << " " << 12.45;
    LOG_WARNING << "hello world " << 123 << " " << 12.45;
    LOG_DEBUG << "hello world " << 123 << " " << 12.45;
    LOG_ERROR << "hello world " << 123 << " " << 12.45;
    LOG_FATAL << "hello world " << 123 << " " << 12.45;
    haizei::ThreadPool tp;
    for (int i = 0; i < 100; i++) {
        tp.addOneTask(func, i, 2 * i, 3 * i);
    }
    tp.stop();
    return 0;
}
