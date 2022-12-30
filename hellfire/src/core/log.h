#ifndef HF_LOG_H
#define HF_LOG_H

void logger_log(const char* name, const char* message, ...);

#define HF_CORE_LOG(...) logger_log("HELLFIRE", __VA_ARGS__)
#define HF_LOG(...) logger_log("APPLICATION", __VA_ARGS__)

#endif