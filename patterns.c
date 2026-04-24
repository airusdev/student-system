#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void diamond(int num) {
    int size = (num * 2) - 1;
    int middle = (size) / 2;
    
    for (int i = 0; i < size; i++) {
        for (int k = 0; k < size; k++) {
            int valid_whitespace = ((k >= (middle - i)) && (k <= (middle + i)));
            
            if (i > middle) {
                int i_placement = size - 1 - i;
                valid_whitespace = (k >= (middle - i_placement) && k <= (middle + i_placement));
            } 
            
            if (valid_whitespace) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

void pyramid(int num) {
    int size = (num * 2) - 1;
    int middle = size / 2;

    for (int i = 0; i < num; i++) {
        for (int k = 0; k < size; k++) {
            if ((k >= (middle - i)) && (k <= (middle + i))) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

void custom_character(int num, char custom_char) {
    int size = (num * 2) - 1;
    int middle = size / 2;
    for (int i = 0; i < num; i++) {
        for (int k = 0; k < size; k++) {
            if (k >= (middle - i) && (k <= (middle + i))) {
                printf("%c", custom_char);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }    
}

int main(void) {
    int num;
    char custom_char;

    printf("Enter character: \n");
    scanf(" %c", &custom_char);

    printf("Enter size: \n");
    scanf(" %d", &num);

    custom_character(num, custom_char);

    return 0;
}



