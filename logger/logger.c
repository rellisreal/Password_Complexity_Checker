#include "logger.h"

void log_message(const char* text) {
    if (!text) {
        return; 
    } 
    else {
        time_t now = time(NULL);
        printf("[%s] %s\n", ctime(&now), text);
    }
}