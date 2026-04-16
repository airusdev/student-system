#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int str_length(const char* string) {
    int total_char = 0;
    int letters_count = 0;
    int numbers_count = 0;
    int special_char_count = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        total_char = total_char + 1;

        if (isalpha(string[i])) {
            letters_count = letters_count + 1;
        } else if (isdigit(string[i])) {
            numbers_count = numbers_count + 1;
        } else {
            special_char_count = special_char_count + 1;
        }
    }

    return total_char;
}

char* to_upper(const char* string) { // do it manually
    // get the length of string first
    // allocate memory using (new_str) string len, and add 1 for buffer for the NULL terminator
    // a safety check for if string is NULL then return null
    // a for loop that loops over string and we do new_str[i] = string[i];
    // return new_str as the upper version
    // add NULL terminator at the end

    int len = strlen(string);
    char* new_str = malloc((len + 1) * sizeof(char));
    if (new_str == NULL) return NULL;

    for (int i = 0; string[i] != '\0'; i++) {
        new_str[i] = toupper(string[i]);
    }
    new_str[len] = '\0';

    return new_str;
}

char* to_lower(const char* string) { // do it manually
    int len = strlen(string);
    char* lowercase = malloc((len + 1) * sizeof(char));
    if (string == NULL) return NULL;

    for (int i = 0; string[i] != '\0'; i++) {
        lowercase[i] = tolower(string[i]);
    }
    lowercase[len] = '\0';

    return lowercase;
}

int main() {
    // code here
    char str_to_be_given[100];
    scanf("%[^\n]%*c", &str_to_be_given);

    printf("Total char count / str length: %d\n", str_length(str_to_be_given));
    printf("Uppercase: %s\n", to_upper(str_to_be_given));
    printf("Lowercase: %s", to_lower(str_to_be_given));
    // to_upper(str_to_be_given);

    return 0;
}
