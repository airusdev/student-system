#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

char* saved_student_names[50];
int student_counter = 0;

void add_student(const char* student) {
	if (student == NULL) return;
	char* saved_name; // the system saves only one name for now

	saved_name = malloc(strlen(student) + 1);
	strcpy(saved_name, student);

    saved_student_names[student_counter] = saved_name;
    printf("Student saved successfully: %s\n\n", saved_student_names[student_counter]);
    student_counter = student_counter + 1;
}

void print_student(int index) {
    printf("%d. %s\n\n", index + 1, saved_student_names[index]);
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

			add_student(name);

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
                printf("The student list is empty!");
                continue;
            } else {
                printf("\n--- Student List ---\n");

                for (int i = 0; i < student_counter; i++) {
                    printf("%d. %s\n", i + 1, saved_student_names[i]);
                }

                printf("--------------------");
                printf("Total: %d student(s)", student_counter);
            }

			printf("Goodbye!\n\n");
			break;
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
