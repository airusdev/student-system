// to add: input validation on the (1) (2) (3), input must be a number

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
    int valid_answers[] = {'1', '2', '3'};
	//int choice = 0;

	while (1) {
        accepted_value = false; // wait until valid choice
        while (!accepted_value) {
            printf("Options:\n (1) Add Student\n (2) View Students\n (3) Exit\n\n");
            scanf(" %[^\n]%*c", choice);

            if (strlen(choice) > 1) {
                printf("INVALID INPUT!\n\n");
                continue;
            }

            for (int i = 0; i < (sizeof(choice) / sizeof(choice[0])); i++) {
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

		if (choice[0] == '1') { // we need to do an if condition, we have to make sure student_name_given has a value first
            char student_name_given[100];
            
            printf("Enter student name: \n");
			scanf(" %[^\n]%*c", student_name_given);

			add_student(student_name_given);

		} else if (choice[0] == '2') {
            int index = 0;
            printf("Please give the index of the student's name you want to print: ");
            scanf(" %d", &index);
            print_student(index - 1);

			//printf("placeholder for view students\n\n");
		} else if (choice[0] == '3') {
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
