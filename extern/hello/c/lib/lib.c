#include <stdio.h>

const char* getGreeting() {
    return "Hello from c! äöü : external const char*";
}

void greetMe(const char *text) {
    // printf("%s", text); // lime does not like this, todo : investigate why
    puts(text);
}