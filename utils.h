#ifndef UTILS_H
#define UTILS_H
#endif

int str_length(const char* string);

char* to_upper(const char* string);
char* to_lower(const char* string);
char* title_case(const char* string);

float add(float first_num, float second_num);
float subtract(float first_num, float second_num);
float multiply(float first_num, float second_num);
float safe_divide(float first_num, float second_num, int* error);

int digit_sum(int num);
int digit_count(int num);
bool is_palindrome(int num);
void reverse_number(int num);

char* to_binary_string(unsigned int num);
int check_bit(int num, int bit_position);
char* get_permission_flags(int num);

void tokenize(const char* input);
int count_words(const char* input);
void split_name(const char* input);

char* print_histogram(const int freq);
void char_frequency(const char* input);

int fibonacci(int n);
int factorial(int n);
int power(int base, int exp);

int max(int a, int b);
int string_compare(const char* string_one, const char* string_two);
int partition(char* arr[], int low, int high, int (*cmp)(const char*, const char*));
void quicksort(char* arr[]. int low, int high, int (*cmp)(const char*, const char*));
void sort_names(char* arr[], int count, int (*cmp)(const char*, const char*));

int integer_comparator(const void* a, const void* b);
int custom_partition(void* base, int low, int high, size_t element_size, int (*cmp)(const void*, const void*));
void custom_recurse(void* base, int low, int high, size_t element_size, int (*cmp)(const void*, const void*));
void custom_qsort(void* arr, int count, size_t element_size, int (*cmp)(const void*, const void*));

int anagram(char* string_one, char* string_two);