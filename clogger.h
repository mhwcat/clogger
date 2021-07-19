/*
clogger v0.5 - Very simple logging utility for C/C++
2021 (c) Michał 'mhwcat' Gumny

This is lightweight, cross-platform utility that can be used for logging needs in C/C++.
It should compile and run on Linux, Windows and macOS. It outputs to stdout and supports parameters.
Four log levels are available: DEBUG, INFO, WARN, ERROR.
Example usage:
CLOG_INFO("Hello number %d from %s!", i, name);
Example output: 
[2021-07-19 16:12:46.748] INFO Hello number 3 from clogger!

Colored terminal output can be enabled by passing CLOGGER_USE_COLORED_OUTPUT option during compilation.
Log level can be selected by passing CLOGGER_LOG_LEVEL option with possible values:
CLOG_LVL_DEBUG (default)
CLOG_LVL_INFO
CLOG_LVL_WARN
CLOG_LVL_ERROR

To do:
- Support saving logs to files

Changelog:
- v0.5 (2021-07-19)
    Initial version

License:
Copying and distribution of this software, with or without modification, 
are permitted in any medium without royalty, provided the copyright notice 
and this notice are preserved. 
This software is offered as-is, without any warranty.

*/

#ifndef CLOGGER_H
#define CLOGGER_H

#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#ifdef WIN32
#include <stdint.h>
#include <windows.h>
#else
#include <sys/time.h>
#endif

#define CLOG_LVL_DEBUG              0
#define CLOG_LVL_INFO               1
#define CLOG_LVL_WARN               2
#define CLOG_LVL_ERROR              3

#ifndef CLOGGER_LOG_LEVEL
#define CLOGGER_LOG_LEVEL           CLOG_LVL_DEBUG
#endif

#if CLOGGER_LOG_LEVEL == CLOG_LVL_INFO
#define CLOG_DEBUG(format, ...)     ;
#define CLOG_INFO(format, ...)      info(format, ##__VA_ARGS__)
#define CLOG_WARN(format, ...)      warn(format, ##__VA_ARGS__)
#define CLOG_ERROR(format, ...)     error(format, ##__VA_ARGS__)
#elif CLOGGER_LOG_LEVEL == CLOG_LVL_WARN
#define CLOG_DEBUG(format, ...)     ;
#define CLOG_INFO(format, ...)      ;
#define CLOG_WARN(format, ...)      warn(format, ##__VA_ARGS__)
#define CLOG_ERROR(format, ...)     error(format, ##__VA_ARGS__)
#elif CLOGGER_LOG_LEVEL == CLOG_LVL_ERROR
#define CLOG_DEBUG(format, ...)     ;
#define CLOG_INFO(format, ...)      ;
#define CLOG_WARN(format, ...)      ;
#define CLOG_ERROR(format, ...)     error(format, ##__VA_ARGS__)
#else
#define CLOG_DEBUG(format, ...)     debug(format, ##__VA_ARGS__)
#define CLOG_INFO(format, ...)      info(format, ##__VA_ARGS__)
#define CLOG_WARN(format, ...)      warn(format, ##__VA_ARGS__)
#define CLOG_ERROR(format, ...)     error(format, ##__VA_ARGS__)
#endif

#ifdef CLOGGER_USE_COLORED_OUTPUT
#define CLOGGER_INFO_TAG            "\033[92mINFO\033[39m  "
#define CLOGGER_DEBUG_TAG           "\033[36mDEBUG\033[39m "
#define CLOGGER_WARN_TAG            "\033[33mWARN\033[39m  "
#define CLOGGER_ERROR_TAG           "\033[91mERROR\033[39m "
#else
#define CLOGGER_INFO_TAG            "INFO  "
#define CLOGGER_DEBUG_TAG           "DEBUG "
#define CLOGGER_WARN_TAG            "WARN  "
#define CLOGGER_ERROR_TAG           "ERROR "
#endif

void debug(const char* format, ...);
void info(const char* format, ...);
void warn(const char* format, ...);
void error(const char* format, ...);

#endif