#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// -- STRING
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

char* title_case(const char* string) { // do it manually
    int len = strlen(string);
    char* titlecase = malloc((len + 1) * sizeof(char));
    if (string == NULL) return NULL;

    titlecase[0] = toupper(string[0]);
    for (int i = 1; string[i] != '\0'; i++) {
        if (string[i - 1] == ' ') {
            titlecase[i] = toupper(string[i]);
        } else {
            titlecase[i] = tolower(string[i]);
        }
    }
    titlecase[len] = '\0';
    
    return titlecase;
}


// -- NUMBER
float add(float first_num, float second_num) {
    return (first_num + second_num);
}


int main() {
    char str_to_be_given[100];
    float first_num;
    float second_num;

    printf("Please give me a sentence to work with:\n");
    scanf("%[^\n]%*c", &str_to_be_given);

    printf("Total char count / str length: %d\n", str_length(str_to_be_given));
    printf("Uppercase: %s\n", to_upper(str_to_be_given));
    printf("Lowercase: %s\n", to_lower(str_to_be_given));
    printf("Title Case: %s\n", title_case(str_to_be_given));
    
    printf("Give me two numbers: N_1 N_2\n");
    scanf("%f %f", &first_num, &second_num);
    printf("Sum: %.1f", add(first_num, second_num));

    return 0;
}
