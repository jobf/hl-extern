#include <stdio.h>

const char* getGreeting() {
    return "Hello from c! äöü : external const char*";
}

void greetMe(const char *text) {
    printf("%s\n", text);
}

const int getInteger(){
    return 0xC0FFEE;
}

void passInteger(const int *integer){
    printf("%d : integer from haxe\n", integer);
}

const char **getStringsStatic(int *count) {
    static const char *strings[] = {
        "haxe",
        "python",
        "perl"
    };

    *count = sizeof(strings) / sizeof(strings[0]);
    
    return strings;
}