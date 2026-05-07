#include <stdio.h>

struct students {
    char* name;
    int age;
    float score;
};

// char names[3][50] = {"Alice", "Bob", "Charlie"};
// int ages[3] = {20, 25, 30};
// float scores[3] = {88.5, 92.0, 75.5};

void print_person(int index, students student) {
    printf("Name: %s | Age: %d | Score: %.1f\n", 
           students[index], students[index], students[index]);
}

int main() {
    struct students student[3];

    student[0].name = "Alice";
    student[0].age = 20;
    student[0].score = 88.5;

    student[1].name = "Bob";
    student[1].age = 25;
    student[1].score = 92.0;

    student[2].name = "Charlie";
    student[2].age = 30;
    student[2].score = 75.5;

    for (int i = 0; i < 3; i++) {
        print_person(i, struct students);
    }
    return 0;
}
