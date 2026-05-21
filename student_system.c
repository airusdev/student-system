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

// char* partial_name_search() { // scour the student database and look for partial name match
//     // create a new array that contains a valid partial_name
//     // logic goes here
//     // return the new array
//     return;
// }

// void filter_by_gpa() { // filter by minimum gpa or maximum gpa
//     // malloc a new array that contains the
//     return;
// }

// void filter_by_gpa_range() { // filter by an accepted range of gpa
//     return;
// }

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

int string_input_validation(char* input) {
    int all_spaces = 1;

    // is string empty?
    if (strlen(input) == 0 || input[0] == '\0') {
        printf("The system does not accept an empty string.\n\n");
        return 0;
    }

    // check if string is all spaces
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isspace(input[i]) || !isalpha(input[i])) {
            all_spaces = 0;
            break;
        }
    }

    if (all_spaces) {
        printf("The system does not accept an input that is only spaces.\n\n");
        return 0;
    }

    return 1;
}



int main() {
    saved = malloc(capacity * sizeof(struct students));
    sorted = malloc(capacity * sizeof(struct students));

	bool accepted_value = false;
    char choice[64] = {0};
    int valid_answers[] = {'1', '2', '3', '4'}; // TO FIX! INSTEAD OF USING ARRAY, JUST DO IF STATEMENT CONDITION

	while (1) {
        // validate main menu input
        accepted_value = false; // wait until valid choice
        while (!accepted_value) {
            printf("Options:\n (1) Add Student\n (2) View All Students\n (3) Exit\n\n");
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
        }

        // main menu input logic
		if (choice[0] == '1')
        {
            // variables
            char name[100];
            float gpa = 0;
            int valid_gpa = 1;
            int i;

            // acquire name
            printf("Enter student name: \n");
            fgets(name, 100, stdin);
            name[strcspn(name, "\n")] = '\0';

            int is_a_valid_name = string_input_validation(name);
            if (!is_a_valid_name) continue;

            // acquire grade and convert to gpa
            for (i = 0; i < 3; i++) {
                char grade[100];

                printf("Enter student's grade: \n");
                fgets(grade, 100, stdin);
                grade[strcspn(grade, "\n")] = '\0';

                int is_a_valid_grade = string_input_validation(grade);
                if (!is_a_valid_grade) break;

                float saved_grade = atof(grade);
                if (saved_grade < 60 || saved_grade > 100) {
                    printf("\nThe grade must be greater than 60 and less than 100.\n\n");
                    valid_gpa = 0;
                    break;
                }

                gpa += saved_grade;
            }

            if (!valid_gpa) continue;
            
            gpa /= 3.0;
            add_student(name, gpa);
		}
        
        else if (choice[0] == '2') 
        {
            if (student_counter == 0) {
                printf("The student list is empty!\n\n");
                continue;
            }
            char* choice_sort = malloc(10 * sizeof(char));
            int contains_spaces_letters = 1;

            printf("Sort by:\n  (1) Name\n  (2) GPA\n");
            printf("Choose: ");

            fgets(choice_sort, 10, stdin);
            choice_sort[strcspn(choice_sort, "\n")] = '\0';

            int is_a_valid_sort = string_input_validation(choice_sort);
            if (!is_a_valid_sort) continue;

            int valid_choice_sort = atoi(choice_sort);
            if (valid_choice_sort > 2 || valid_choice_sort < 1) continue;

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
        
        else if (choice[0] == '3') 
        {
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
