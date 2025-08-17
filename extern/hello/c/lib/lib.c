#include <stdio.h>

const char* getGreeting() {
    return "Hello from c! : external const char*";
}

void greetMe(const char *text) {
    printf(text);
}