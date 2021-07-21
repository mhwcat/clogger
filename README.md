# clogger 
*Very simple logging utility for C/C++*

Lightweight, cross-platform utility that can be used for logging needs in C/C++. It should compile and run on Linux, Windows and macOS. It outputs to stdout and optionally to file and supports parameters.
## Compiling
Copy `clogger.h` and `clogger.c` to your project and add to your compilation script.  
Example compilation:  
GCC: `gcc -o bin/simple -Wall -DCLOGGER_USE_COLORED_OUTPUT  -DCLOGGER_LOG_LEVEL=CLOG_LVL_DEBUG clogger.c examples/simple.c`  
Clang: `clang -o bin/simple -Wall -DCLOGGER_USE_COLORED_OUTPUT -DCLOGGER_LOG_LEVEL=CLOG_LVL_DEBUG clogger.c examples/simple.c `
### Compile options
- **`CLOGGER_USE_COLORED_OUTPUT`**  - enables colored terminal output
- **`CLOGGER_LOG_LEVEL`** - sets log level, possible values: `CLOG_LVL_DEBUG` (default), `CLOG_LVL_INFO`, `CLOG_LVL_WARN`, `CLOG_LVL_ERROR`
## Usage
```c
#include "clogger.h"
// (...)
CLOG_INIT_FILE("logs/"); // do it once at the beggining if you want to use log files
CLOG_INFO("Hello number %d from %s!", i, name); 
CLOG_CLEANUP_FILE(); // do it once at the end if you enabled log files    
```
Also see `examples/`.  
Example output:  
`[2021-07-19 16:12:46.748] INFO Hello number 3 from clogger!`
## To do
- Use WinAPI calls when writing to log files on Win32 (stdlib is not reliable there)
## Changelog
- v0.6 (2021-07-21)  
Added log files support
- v0.5 (2021-07-19)  
Initial version
## License
Copying and distribution of this software, with or without modification, are permitted in any medium without royalty, provided the copyright notice and this notice are preserved.  
This software is offered as-is, without any warranty.