#include <stdio.h>


#include <stdio.h>
#include <string.h>


struct StringWithSpaces {
    char str[100];
};

int main() {
    struct StringWithSpaces myString;
    strcpy(myString.str, "Hello,");

    int count = 0;
    while (count < 5) {
        strcat(myString.str, " ");
        count++;
    }

    strcat(myString.str, "world!");

    printf("Concatenated string: %s\n", myString.str);

    return 0;
}