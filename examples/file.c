#include "../clogger.h"

int main(int argc, char** argv) {
    const char* name = "clogger";
    unsigned int i = 0;

    CLOG_INIT_FILE("logs/");

    CLOG_DEBUG("Hello number %d from %s!", i, name); i++;
    CLOG_INFO("Hello number %d from %s!", i, name); i++;
    CLOG_WARN("Hello number %d from %s!", i, name); i++;
    CLOG_ERROR("Hello number %d from %s!", i, name);

    CLOG_CLEANUP_FILE();    

    return 0;
}    
