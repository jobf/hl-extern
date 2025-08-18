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