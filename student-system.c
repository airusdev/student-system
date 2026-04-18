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


int main() {
	bool accepted_value = false;
	int choice = 0;

	while (1) {
        accepted_value = false; // wait until valid choice
        while (!accepted_value) {
            printf("Options:\n (1) Add Student\n (2) View Students\n (3) Exit\n\n");
            scanf(" %d", &choice);

            if (choice == 1 || choice == 2 || choice == 3) {
                accepted_value = true;
            }
        }

		if (choice == 1) { // we need to do an if condition, we have to make sure student_name_given has a value first
            char student_name_given[100];
            
            printf("Enter student name: \n");
			scanf(" %[^\n]%*c", student_name_given);

			add_student(student_name_given);
            for (int i = 0; i < student_counter; i++) {
                free(saved_student_names[i]);
            }

		} else if (choice == 2) {
			printf("placeholder for view students\n\n");    
		} else if (choice == 3) {
			printf("Goodbye!\n\n");
			break;
		}
		choice = 0;
	}
	return 0;
}
