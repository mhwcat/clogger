#include "clogger.h"

#ifdef WIN32
#define EPOCH_FILETIME          116444736000000000ULL // FILETIME of Jan 1 1970 00:00:00
#endif

#define MS_PART_BUFFER_SIZE     6  // "sss] "
#define TIME_BUFFER_SIZE        27 // "[2020-01-01 11:11:11.111] "

static inline void internal_gettimeofday(struct timeval* tp) {
#ifdef WIN32
    FILETIME file_time;
    SYSTEMTIME system_time;
    ULARGE_INTEGER ularge;

    GetSystemTime(&system_time);
    SystemTimeToFileTime(&system_time, &file_time);
    ularge.LowPart = file_time.dwLowDateTime;
    ularge.HighPart = file_time.dwHighDateTime;

    tp->tv_sec = (long) ((ularge.QuadPart - EPOCH_FILETIME) / 10000000L);
    tp->tv_usec = (long) (system_time.wMilliseconds * 1000);
#else
    gettimeofday(tp, 0);
#endif
}

static inline void internal_get_current_time_str(char* date_time_str) {
    time_t now_time = time(NULL);

    struct timeval tp;
    internal_gettimeofday(&tp);

    char ms_str[MS_PART_BUFFER_SIZE];
    memset(ms_str, '\0', MS_PART_BUFFER_SIZE * sizeof(char));

    snprintf(ms_str, MS_PART_BUFFER_SIZE, "%03ld] ", tp.tv_usec / 1000L);
    strftime(date_time_str, TIME_BUFFER_SIZE, "[%Y-%m-%d %H:%M:%S.", localtime(&now_time));
    strncat(date_time_str, ms_str, MS_PART_BUFFER_SIZE);
}

void debug(const char* format, ...) {
    char time_formatted[TIME_BUFFER_SIZE];
    memset(time_formatted, '\0', TIME_BUFFER_SIZE * sizeof(char));
    internal_get_current_time_str(time_formatted);

    va_list args;
    fputs(time_formatted, stdout);
    fputs(CLOGGER_DEBUG_TAG, stdout);
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
    fputs("\n", stdout);
}

void info(const char* format, ...) {
    char time_formatted[TIME_BUFFER_SIZE];
    memset(time_formatted, '\0', TIME_BUFFER_SIZE * sizeof(char));
    internal_get_current_time_str(time_formatted);

    va_list args;
    fputs(time_formatted, stdout);
    fputs(CLOGGER_INFO_TAG, stdout);
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
    fputs("\n", stdout);
}

void warn(const char* format, ...) {
    char time_formatted[TIME_BUFFER_SIZE];
    memset(time_formatted, '\0', TIME_BUFFER_SIZE * sizeof(char));
    internal_get_current_time_str(time_formatted);

    va_list args;
    fputs(time_formatted, stdout);
    fputs(CLOGGER_WARN_TAG, stdout);
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
    fputs("\n", stdout);
}

void error(const char* format, ...) {
    char time_formatted[TIME_BUFFER_SIZE];
    memset(time_formatted, '\0', TIME_BUFFER_SIZE * sizeof(char));
    internal_get_current_time_str(time_formatted);

    va_list args;
    fputs(time_formatted, stdout);
    fputs(CLOGGER_ERROR_TAG, stdout);
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
    fputs("\n", stdout);
}