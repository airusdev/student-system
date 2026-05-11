#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int comparator_function(int arr[], int count, )

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int swap_marker = low - 1;
    int temp = 0;

    for (int index = low; index < high; index++) {
        if (arr[index] <= pivot) {
            swap_marker++;
            
            temp = arr[index];
            arr[index] = arr[swap_marker];
            arr[swap_marker] = temp;
        }
    }

    temp = arr[swap_marker + 1];
    arr[swap_marker + 1] = arr[high];
    arr[high] = temp;

    return swap_marker + 1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// solving hackerrank

// my own solving algorithm (not built in qsort)


// four string comparison functions
// { "apple", "banana", "carrots", "dogs" }
// { "dogs", "carrots", "apple", "banana" }
// "apple" , "appbl"

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lexicographic_sort(const char* string_one, const char* string_two) {
    // if output is 1, switch them up
    int length = max(strlen(string_one), strlen(string_two));

    for (int i = 0; i < length; i++) {
        char char_one = string_one[i];
        char char_two = string_two[i];

        if (char_one < char_two) return -1;
        if (char_one > char_two) return 1;
    }

    return 0;
}

int lexicographic_sort_reverse(const char* string_one, const char* string_two) {
    // if output is -1, switch it up 
    int length = max(strlen(string_one), strlen(string_two));

    for (int i = 0; i < length; i++) {
        char char_one = string_one[i];
        char char_two = string_two[i];

        if (char_one < char_two) return 1;
        if (char_one > char_two) return -1;
    }

    return 0;
}

int sort_by_number_of_distinct_characters(const char* string_one, const char* string_two) {
    int distinct_one = 0;
    int distinct_two = 0;

    int alphabet_one[26] = {0};
    int alphabet_two[26] = {0};
    int i;

    // how do i know if a char from any of the strigs is distinct?
    // answer: check if alphabet_x[index of the letter] where x is either one or two is already 1
    
    // TO DOUBLE CHECK
    // distinct checker for string_one
    for (i = 0; string_one[i] != '\0'; i++) {
        char my_char = string_one[i];
        int char_index = my_char - 'a';

        if (alphabet_one[char_index] == 0) {
            distinct_one++;
            alphabet_one[char_index]++;
        }
    } 

    // distinct checker for string_two
    for (i = 0; string_two[i] != '\0'; i++) {   
        char my_char = string_two[i];
        int char_index = my_char - 'a';

        if (alphabet_two[char_index] == 0) {
            distinct_two++;
            alphabet_two[char_index]++;
        }
    }
    
    if (distinct_one < distinct_two) return -1;
    if (distinct_one > distinct_two) return 1;
    
    return lexicographic_sort(string_one, string_two);
}

int sort_by_length(const char* string_one, const char* string_two) {
    int length_one = strlen(string_one);
    int length_two = strlen(string_two);

    if (length_one < length_two) return -1;
    if (length_one > length_two) return 1;

    return lexicographic_sort(string_one, string_two);
}

int main() {
    int num[] = {1, 4, 3, 2};
    quicksort(&num[0], 0, 3);

    for (int i = 0; i < 4; i++) {
        printf("%d ", num[i]);
    }

    return 0;
}