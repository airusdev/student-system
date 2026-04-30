#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

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

    if (len > 0) titlecase[0] = toupper(string[0]);
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

float subtract(float first_num, float second_num) {
    return (first_num - second_num);
}

float multiply(float first_num, float second_num) {
    return (first_num * second_num);
}

float safe_divide(float first_num, float second_num, int* error) {
    if (second_num == 0) {
        *error = 1;
        return 0;
    }
    
    *error = 0;
    return first_num / second_num;
}

int digit_sum(int num) {
    int sum = 0;

    while (num > 0) {
        int temp_num = num % 10;
        sum = sum + temp_num;
        num = num / 10;
    }

    return sum;
}

int digit_count(int num) {
    int num_count = 0;

    while (num > 0) {
        num_count = num_count + 1;
        num = num / 10;
    }
    
    return num_count;
}

bool is_palindrome(int num) { // i want to avoid using string for now.
    if (num == 0) {
        return true;
    }

    bool is_palindrome = true;
    int num_length = digit_count(num);
    int *num_arr = malloc(num_length * sizeof(int));

    for (int *p = num_arr; p < num_arr + num_length; p++) {
        *p = num % 10;
        num = num / 10;
    }

    int *p = num_arr + num_length - 1;
    int index = 0;
    
    while (p >= num_arr) {
        if (*p != num_arr[index]) {
            is_palindrome = false;
            break;
        }

        index = index + 1;
        p--;
    }

    free(num_arr);
    return is_palindrome;
    // "%s\n", is_palindrome ? "Yes" : "No" in the caller
}   

void reverse_number(int num) {
    if (num == 0) return;
    while (num > 0) {
        int temp_num = num % 10;
        printf("%d", temp_num);
        num = num / 10;
    }
}

char* to_binary_string(unsigned int num) {
    char *binary_array = malloc(9 * sizeof(char));
    uint8_t value = num;

    for (int i = 0; i < 8; i++) {
        int reverse_index = 7 - i;
        int desired_value = (value >> i) & 1;
        binary_array[reverse_index] = desired_value + '0';
    }

    return binary_array;
}

int check_bit(int num, int bit_position) {
    if (bit_position > 7) return 0;
    uint8_t bit_num = num;
    
    if (!(bit_num >> bit_position & 1)) {
        return 0;
    }
    else {
        return 1;
    }
}

char* get_permission_flags(int num) {
    uint8_t binary_num = num;
    char *output = malloc(4 * sizeof(char));
    char valid_output[] = {'x', 'w', 'r'};

    for (int i = 0; i < 3; i++) {
        int reverse_index = 2 - i;
        int desired_value = binary_num & 1;
        binary_num = binary_num >> 1;
        
        if (desired_value == 1) {
            output[reverse_index] = valid_output[i];
        }
        else {
            output[reverse_index] = '-';
        }
    }
    output[3] = '\0';
    return output;
}

void tokenize(const char* input) {
    char *temp_word = malloc(10 * sizeof(char));
    int temp_counter = 0;
    
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            temp_word[temp_counter] = '\0'; 
            printf("%s | ", temp_word);
            temp_counter = 0;
        } else {
            temp_word[temp_counter] = input[i];
            temp_counter =  temp_counter + 1;
        }
    }
    temp_word[temp_counter] = '\0';
    printf("%s\n", temp_word);
    free(temp_word);
}

int count_words(const char* input) {
    int word_count = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            word_count = word_count + 1;
        }     
    }
    word_count = word_count + 1;
    
    return word_count;
}

void split_name(const char* input) {
    char* first_name = malloc(10 * sizeof(char));
    int temp_count1 = 0;
    
    char* last_name = malloc(10 * sizeof(char));
    int space_index;
    int temp_count2 = 0;
    
    for (int i = 0; input[i] != ' '; i++) {
        first_name[temp_count1] = input[i];
        temp_count1 = temp_count1 + 1;
    }
    first_name[temp_count1] = '\0';
    
    // acquire space index
    for (int i = strlen(input) - 1; input[i] != ' '; i--) {
        if (i == 0) {
            space_index = i;
            printf("No last name!");
        } else {
            space_index = i;
        }
    }
    
    for (space_index; space_index != ' '; space_index++) {
        last_name[temp_count2] = input[space_index]; 
        temp_count2 = temp_count2 + 1;
    }
    last_name[temp_count2] = '\0';
    
    printf("%s", first_name);
    printf("\n");
    printf("%s", last_name);
    
    free(first_name); free(last_name);
}

char* print_histogram(const int freq) {
    char* histogram = malloc(freq * sizeof(char) + 1);
    int i;
    
    for (i = 0; i < freq; i++) {
        histogram[i] = '#';
    }
    histogram[freq] = '\0';
    
    return histogram;
}

void char_frequency(const char* input) {
    int alphabet_arr[26] = {0};
    int i; char* histogram;
    
    for (i = 0; input[i] != '\0'; i++) {
        char lower = tolower(input[i]);
        alphabet_arr[lower - 'a'] = alphabet_arr[lower - 'a'] + 1;
    }
    
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ') continue;
        
        int letter_index = input[i] - 'a';
        if (alphabet_arr[letter_index] > 0) {
            histogram = print_histogram(alphabet_arr[letter_index]);
            printf("%c: %d  |%s\n", input[i], alphabet_arr[letter_index], histogram);
            free(histogram);
            alphabet_arr[letter_index] = 0;
        }
    }
}


int main() {
    char str_to_be_given[100];
    float first_num;
    float second_num;

    printf("Please give me a sentence to work with:\n");
    scanf("%[^\n]%*c", &str_to_be_given);

    printf("Total char count / str length: %d\n", str_length(str_to_be_given));

    char* upper = to_upper(str_to_be_given);
    char* lower = to_lower(str_to_be_given);
    char* titlecase = title_case(str_to_be_given);

    printf("Uppercase: %s\n", upper);
    free(upper);
    
    printf("Lowercase: %s\n", lower);
    free(lower);

    printf("Title Case: %s\n", titlecase);
    free(titlecase);
    
    printf("Give me two numbers: N_1 N_2\n");
    scanf(" %f %f", &first_num, &second_num);
    printf("Sum: %.1f\n", add(first_num, second_num));
    printf("Difference: %.1f\n", subtract(first_num, second_num));
    printf("Product: %.1f\n", multiply(first_num, second_num));

    int my_error;
    float result = safe_divide(first_num, second_num, &my_error);

    if (my_error) {
        printf("Quotient: ERROR\n");
    } else if (!my_error) {
        printf("Quotient: %.1f\n", result);
    }

    return 0;
}
