#ifndef HF_LOG_H
#define HF_LOG_H

typedef enum LogLevel
{
	HF_LOG_LEVEL_FATAL = 0,
	HF_LOG_LEVEL_ERROR,
	HF_LOG_LEVEL_WARN,
	HF_LOG_LEVEL_INFO,
	HF_LOG_LEVEL_DEBUG,
	HF_LOG_LEVEL_TRACE
} LogLevel;

void logger_log(LogLevel level, const char* name, const char* message, ...);

#define HF_CORE_FATAL(...) logger_log(HF_LOG_LEVEL_FATAL, "HELLFIRE", __VA_ARGS__)
#define HF_CORE_ERROR(...) logger_log(HF_LOG_LEVEL_ERROR, "HELLFIRE", __VA_ARGS__)
#define HF_CORE_WARN(...) logger_log(HF_LOG_LEVEL_WARN, "HELLFIRE", __VA_ARGS__)
#define HF_CORE_INFO(...) logger_log(HF_LOG_LEVEL_INFO, "HELLFIRE", __VA_ARGS__)
#define HF_CORE_DEBUG(...) logger_log(HF_LOG_LEVEL_DEBUG, "HELLFIRE", __VA_ARGS__)
#define HF_CORE_TRACE(...) logger_log(HF_LOG_LEVEL_TRACE, "HELLFIRE", __VA_ARGS__)

#define HF_FATAL(...) logger_log(HF_LOG_LEVEL_FATAL, "APPLICATION", __VA_ARGS__)
#define HF_ERROR(...) logger_log(HF_LOG_LEVEL_ERROR, "APPLICATION", __VA_ARGS__)
#define HF_WARN(...) logger_log(HF_LOG_LEVEL_WARN, "APPLICATION", __VA_ARGS__)
#define HF_INFO(...) logger_log(HF_LOG_LEVEL_INFO, "APPLICATION", __VA_ARGS__)
#define HF_DEBUG(...) logger_log(HF_LOG_LEVEL_DEBUG, "APPLICATION", __VA_ARGS__)
#define HF_TRACE(...) logger_log(HF_LOG_LEVEL_TRACE, "APPLICATION", __VA_ARGS__)

#endif