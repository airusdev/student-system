#include <stdio.h>
// #include "utils.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int student_counter = 0;
int capacity = 5;

struct students {
    char* name;
    float gpa;
};
    
struct students* saved;
struct students* sorted;

int compare_by_gpa(const void* a, const void* b) {
    const struct students* ia = (const struct students *)a;
    const struct students* ib = (const struct students *)b;

    if (ia->gpa < ib->gpa) return 1;
    if (ia->gpa > ib->gpa) return -1;
    return 0;
}

int compare_by_name(const void* a, const void* b) { 
    const struct students* ia = (const struct students *)a;
    const struct students* ib = (const struct students *)b;

    return strcmp(ia->name, ib->name);
}

void add_student(const char* student, const float gpa) {
	if (student == NULL) return;
    if (student_counter == capacity) {
        capacity *= 2;

        saved = realloc(saved, capacity * sizeof(struct students));
        sorted = realloc(sorted, capacity * sizeof(struct students));
    }

	char* saved_name; // the system saves only one name for now

	saved_name = malloc(strlen(student) + 1);
	strcpy(saved_name, student);

    saved[student_counter].gpa = gpa;
    saved[student_counter].name = saved_name;
    printf("Student saved successfully: %s %.1f\n\n", saved[student_counter].name, saved[student_counter].gpa);

    // add the names to the sorted also. this will be sorted later when option 3 is called
    sorted[student_counter].gpa = saved[student_counter].gpa;
    sorted[student_counter].name = saved[student_counter].name;

    student_counter += 1;
}

void print_student(int index) {
    printf("%d. %s - %.1f\n\n", index + 1, saved[index].name, saved[index].gpa);
}


int main() {
    saved = malloc(capacity * sizeof(struct students));
    sorted = malloc(capacity * sizeof(struct students));

	bool accepted_value = false;
    char choice[64] = {0};
    int valid_answers[] = {'1', '2', '3', '4'}; // TO FIX! INSTEAD OF USING ARRAY, JUST DO IF STATEMENT CONDITION

	while (1) {
        accepted_value = false; // wait until valid choice
        while (!accepted_value) {
            printf("Options:\n (1) Add Student\n (2) View Students\n (3) View All Students\n (4) Exit\n\n");
            scanf(" %[^\n]%*c", choice);

            if (strlen(choice) > 1) {
                printf("INVALID INPUT!\n\n");
                continue;
            }

            for (int i = 0; i < (sizeof(valid_answers) / sizeof(valid_answers[0])); i++) {
                if (choice[0] == valid_answers[i]) {
                    accepted_value = true;
                }
            }

            if (accepted_value == true) {
                printf("VALID INPUT!!\n\n");
            } else {
                printf("INVALID INPUT!!\n\n");
            }
        }

		if (choice[0] == '1') {
            char name[100];
            float* grades = malloc(3 * sizeof(float));
            float gpa = 0;
            int valid = 1;

            printf("Enter student name: \n");
            fgets(name, 100, stdin);
            name[strcspn(name, "\n")] = '\0';

            // Empty ?
            if (strlen(name) == 0) {
                printf("The system doesn't accept an empty input.\n\n");
                continue;
            }

            // All spaces ?
            int all_spaces = 1;
            for (int i = 0; name[i] != '\0'; i++) {
                if (!isspace(name[i])) all_spaces = 0;
            }

            if (all_spaces == true) {
                printf("The system doesn't accept an input of all spaces\n\n");
                continue;
            }

            for (int i = 0; i < 3; i++) { // parse the char grade here to float
                char grade[100];
                int grade_is_spaces = 1;

                printf("Enter student's grade: \n");
                fgets(grade, 100, stdin);
                grade[strcspn(grade, "\n")] = '\0';

                if (strlen(grade) == 0) {
                    printf("The system doesn't accept an empty input.");
                    int valid = 0;
                    break;
                }

                for (int i = 0; grade[i] != '\0'; i++) {
                    if (!isspace(grade[i])) {
                        grade_is_spaces = 0;
                    }
                }

                if (grade_is_spaces == true) {
                    printf("The system doesn't accept an input of all spaces\n\n");
                    int valid = 0;
                    break;
                }

                float saved_grade = atof(grade);

                if (saved_grade < 60 || saved_grade > 100) {
                    printf("\nThe grade must be within 60 and 100 only.\n\n");
                    valid = 0;
                    break;
                } else {
                    grades[i] = saved_grade;
                    gpa += saved_grade;
                }
            }
            if (gpa >= 180 && gpa <= 300) gpa /= 3.0;
            
            if (valid == true) {
                add_student(name, gpa); // we should use pointer to grades
            }
            else {
                printf("Input wasn't valid.\n\n");
                continue;
            }

		} else if (choice[0] == '2') {
            if (student_counter == 0) {
                printf("No student added yet!\n");
                continue;
            }

            int index = 0;                             
            printf("Please give a valid index (0-49)\n");
            scanf(" %d", &index);

            if (index < 0 || index >= student_counter) {
                printf("Invalid index!");
                continue;
            } else {
                print_student(index);
            }

		} else if (choice[0] == '3') {
            if (student_counter == 0) {
                printf("The student list is empty!\n\n");
                continue;
            } else {
                char* choice_sort = malloc(10 * sizeof(char));
                int contains_spaces_letters = 1;

                printf("Sort by:\n  (1) Name\n  (2) GPA\n");
                printf("Choose: ");

                fgets(choice_sort, 10, stdin);
                choice_sort[strcspn(choice_sort, "\n")] = '\0';

                // CHOICE VALIDATION
                if (strlen(choice_sort) == 0 || choice_sort[0] == '\0') {
                    printf("The system does not accept an empty input.\n\n");
                    continue;
                }

                for (int i = 0; choice_sort[i] != '\0'; i++) {
                    if (!isspace(choice_sort[i] || !isalpha(choice_sort[i]))) {
                        contains_spaces_letters = 0;
                        break;
                    }
                }

                if (contains_spaces_letters == true) {
                    printf("The system does not accept an input that only has spaces in it.\n\n");
                    continue;
                }

                int valid_choice_sort = atoi(choice_sort);
                if (valid_choice_sort > 2 || valid_choice_sort < 1) {
                    printf("The system does not accept an input greater than 2 or less than 1.\n\n");
                    continue;
                }

                if (valid_choice_sort == 1) {
                    qsort(sorted, student_counter, sizeof(struct students), compare_by_name); 
                    
                    printf("\n--- Student List (sorted by name) ---\n");
                    for (int i = 0; i < student_counter; i++) {
                        printf("%d. %s - GPA: %.1f\n", i + 1, sorted[i].name, sorted[i].gpa);
                    }
                }
                else if (valid_choice_sort == 2) {
                    qsort(sorted, student_counter, sizeof(struct students), compare_by_gpa);

                    printf("\n--- Student List (sorted by GPA) ---\n");
                    for (int i = 0; i < student_counter; i++) {
                        printf("%d. %s - GPA: %.1f\n", i + 1, sorted[i].name, sorted[i].gpa);
                    }
                }

                printf("------------------------------------\n");
                printf("Total: %d student(s)\n\n", student_counter);
            }
		} else if (choice[0] == '4') {
            printf("Goodbye!\n\n");
            break;
        }
	}

    choice[0] = '\0';
    for (int i = 0; i < student_counter; i++) {
        free(saved[i].name);
    }

    free(saved);
    free(sorted);

	return 0;
}
