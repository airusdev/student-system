#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int student_counter = 0;
int capacity = 5;

char** saved_student_names;
float* saved_student_gpas;

char** sorted_student_names;
float* sorted_student_gpas;

void sort_students() {
    for (int i = 0; i < student_counter; i++) {
        sorted_student_names[i] = saved_student_names[i];
        sorted_student_gpas[i] = saved_student_gpas[i];
    }
    
    for (int i = 0; i < student_counter; i++) { // bubble sort using grades
        for (int pointer_one = 0; pointer_one < student_counter - 1; pointer_one++) {
            int pointer_two = pointer_one + 1;
            
            if (sorted_student_gpas[pointer_one] < sorted_student_gpas[pointer_two]) {
                int temp_value = sorted_student_gpas[pointer_two];
                char *temp_student = sorted_student_names[pointer_two];
                
                sorted_student_gpas[pointer_two] = sorted_student_gpas[pointer_one];
                sorted_student_names[pointer_two] = sorted_student_names[pointer_one];
                
                sorted_student_gpas[pointer_one] = temp_value;
                sorted_student_names[pointer_one] = temp_student;
            }
        }
    }
}

void add_student(const char* student, const float gpa) {
	if (student == NULL) return;
    if (student_counter == capacity) {
        capacity *= 2;

        saved_student_names = realloc(saved_student_names, capacity * sizeof(char*));
        saved_student_gpas = realloc(saved_student_gpas, capacity * sizeof(float));

        sorted_student_names = realloc(sorted_student_names, capacity * sizeof(char*));
        sorted_student_gpas = realloc(sorted_student_gpas, capacity * sizeof(float));
    }


	char* saved_name; // the system saves only one name for now

	saved_name = malloc(strlen(student) + 1);
	strcpy(saved_name, student);

    saved_student_gpas[student_counter] = gpa;
    saved_student_names[student_counter] = saved_name;
    printf("Student saved successfully: %s %.1f\n\n", saved_student_names[student_counter], saved_student_gpas[student_counter]);

    student_counter = student_counter + 1;
}

void print_student(int index) {
    printf("%d. %s - %.1f\n\n", index + 1, saved_student_names[index], saved_student_gpas[index]);
}


int main() {
    saved_student_names = realloc(saved_student_names, capacity * sizeof(char*));
    saved_student_gpas = realloc(saved_student_gpas, capacity * sizeof(float));

    sorted_student_names = realloc(sorted_student_names, capacity * sizeof(char*));
    sorted_student_gpas = realloc(sorted_student_gpas, capacity * sizeof(float));

	bool accepted_value = false;
    char choice[64] = {0};
    int valid_answers[] = {'1', '2', '3', '4'}; // TO FIX! INSTEAD OF USING ARRAY, JUST DO IF STATEMENT CONDITION
	//int choice = 0;

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
            if (student_counter == 50) {
                printf("Slots are full!\n");
                continue;
            }

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

                if (saved_grade < 60 || saved_grade > 100) { // TO ADD: a way to reset the student counter for Choice 3: view all student
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
                printf("The student list is empty!\n");
                continue;
            } else {
                printf("\n--- Student List ---\n");
                
                sort_students();
                
                for (int i = 0; i < student_counter; i++) {
                    printf("%d. %s - GPA: %.1f\n", i + 1, sorted_student_names[i], sorted_student_gpas[i]);
                }

                printf("--------------------\n");
                printf("Total: %d student(s)\n\n", student_counter);
            }
		} else if (choice[0] == '4') {
            printf("Goodbye!\n\n");
            break;
        }
	}

    choice[0] = '\0';
    for (int i = 0; i < student_counter; i++) {
        free(saved_student_names[i]);
    }
	return 0;
}
