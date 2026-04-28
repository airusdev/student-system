#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

char* saved_student_names[50];
float saved_student_grades[50];

char* sorted_student_names[50];
float sorted_student_grades[50];

int student_counter = 0;

void sort_students() {
    for (int i = 0; i < student_counter; i++) {
        sorted_student_names[i] = saved_student_names[i];
        sorted_student_grades[i] = saved_student_grades[i];
    }
    
    for (int i = 0; i < student_counter; i++) {
        for (int pointer_one = 0; pointer_one < student_counter - 1; pointer_one++) {
            int pointer_two = pointer_one + 1;
            
            if (sorted_student_grades[pointer_one] < sorted_student_grades[pointer_two]) {
                int temp_value = sorted_student_grades[pointer_two];
                char *temp_student = sorted_student_names[pointer_two];
                
                sorted_student_grades[pointer_two] = sorted_student_grades[pointer_one];
                sorted_student_names[pointer_two] = sorted_student_names[pointer_one];
                
                sorted_student_grades[pointer_one] = temp_value;
                sorted_student_names[pointer_one] = temp_student;
            }
        }
    }
}

void add_student(const char* student, const char* grade) {
	if (student == NULL || grade == NULL) return;
	char* saved_name; // the system saves only one name for now
    float saved_grade;    

    saved_grade = atof(grade);
	saved_name = malloc(strlen(student) + 1);
	strcpy(saved_name, student);

    saved_student_grades[student_counter] = saved_grade;
    saved_student_names[student_counter] = saved_name;
    printf("Student saved successfully: %s %.1f\n\n", saved_student_names[student_counter], saved_student_grades[student_counter]);

    student_counter = student_counter + 1;
}

void print_student(int index) {
    printf("%d. %s - %.1f\n\n", index + 1, saved_student_names[index], saved_student_grades[index]);
}


int main() {
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
            char grade[100];

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

            printf("Enter student's grade: \n");
            fgets(grade, 100, stdin);
            grade[strcspn(grade, "\n")] = '\0';

            // empty?
            if (strlen(grade) == 0) {
                printf("The system doesn't accept an empty input");
                break;
            }

            // all spaces ? 
            int grade_is_spaces = 1;
            for (int i = 0; grade[i] != '\0'; i++) {
                if (!isspace(name[i])) grade_is_spaces = 0;
            }

            if (grade_is_spaces == true) {
                printf("The system doesn's accept an input of all spaces\n\n");
                break;
            }

			add_student(name, grade);

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
                    printf("%d. %s - %.1f\n", i + 1, sorted_student_names[i], sorted_student_grades[i]);
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
