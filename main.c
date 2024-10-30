#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isInAlphabet(const char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return true;
    }
    return false;
}

void print(char* input_str) {
    printf("%s\n", input_str);
}

void reverse(char* input_str) {
    const size_t len = strlen(input_str);
    size_t left = 0;
    size_t right = len - 1;
    while(left < right) {
        const char temp = input_str[left];
        input_str[left] = input_str[right];
        input_str[right] = temp;
        left++;
        right--;
    }
}

void decrement(char* input_str, const unsigned int amount) {
    const size_t len = strlen(input_str);
    for(size_t i = 0; i < len; i++) {
        const char letter = input_str[i];
        if(isInAlphabet(letter)) {
            const int ascii_pos = (letter >= 'a' && letter <= 'z') ? 97 : 65;
            const char decremented  = ((letter - amount + 26 - ascii_pos) % 26) + ascii_pos;
            input_str[i] = decremented;
        }
    }
}

void invertCase(char* input_str) {
    const size_t len = strlen(input_str);
    for(size_t i = 0; i < len; i++) {
        const char c = input_str[i];
        if(c >= 'A' && c <= 'Z') {
            input_str[i] = c + 32;
        }
        if(c >= 'a' && c <= 'z') {
            input_str[i] = c - 32;
        }
    }
}

void snakeify(char** input_str) {
    const size_t len = strlen(*input_str);
    char* str_c = strdup(*input_str);
    free(*input_str);
    *input_str = (char*) malloc(2 * len * sizeof(char));
    size_t j = 0;
    (*input_str)[j++] = str_c[0];
    for(size_t i = 1; i < len; i++) {
        (*input_str)[j++] = '_';
        (*input_str)[j++] = str_c[i];
    }
    (*input_str)[j] = '\0';
    free(str_c);
}

void saveResultInFile(const char* result) {
    FILE *f = fopen("output.txt", "w");
    if(f == NULL) {
        printf("Could not open file!\n");
        return;
    }
    fprintf(f, "The resulting string is: %s\n", result);
    fclose(f);
}

int main(int argc, char* argv[])
{
    char* str = strdup("Luca Wissmeyer");
    if(argc > 1) {
        str = strdup(argv[1]);
    }
    //Matrikelnummer: 12555872
    print(str);
    reverse(str);
    decrement(str, 5);
    decrement(str, 5);
    decrement(str, 8);
    invertCase(str);
    snakeify(&str);
    reverse(str);
    saveResultInFile(str);
    free(str);
}
