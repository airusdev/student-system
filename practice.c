#include <stdio.h>

char names[3][50] = {"Alice", "Bob", "Charlie"};
int ages[3] = {20, 25, 30};
float scores[3] = {88.5, 92.0, 75.5};

void print_person(int index) {
    printf("Name: %s | Age: %d | Score: %.1f\n", 
           names[index], ages[index], scores[index]);
}

int main() {
    for (int i = 0; i < 3; i++) {
        print_person(i);
    }
    return 0;
}