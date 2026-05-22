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

struct students* partial_name;
struct students* gpa_range;
struct students* min_max;

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

void partial_name_search(char* substring) {
    partial_name = malloc(100 * sizeof(struct students));
    int valid_count = 0;

    for (int i = 0; i < student_counter; i++) {
        char* current_name = saved[i].name;
        if (!strstr(current_name, substring)) continue;

        partial_name[valid_count].name = saved[i].name;
        partial_name[valid_count].gpa = saved[i].gpa;
        valid_count++;
    }

    partial_name = realloc(partial_name, (valid_count + 1) * sizeof(struct students));

    printf("\n--- Student List (Substring: %s) ---\n", substring);
    for (int i = 0; i < valid_count; i++) {
        printf("%d. %s - GPA: %.1f\n", i + 1, partial_name[i].name, partial_name[i].gpa);
    }

    printf("------------------------------------\n");
    printf("Total Searched Students: %d student(s)\n", valid_count);
    printf("Total Number of Students: %d student(s)\n\n", student_counter); 

    free(partial_name);
}

void filter_by_gpa(int is_minimum, float gpa_given) {
    min_max = malloc(100 * sizeof(struct students));
    int valid_count = 0;

    for (int i = 0; i < student_counter; i++) {
        if (is_minimum == 1) {
            if (saved[i].gpa >= gpa_given) {
                min_max[valid_count].name = saved[i].name;
                min_max[valid_count].gpa = saved[i].gpa;
                valid_count++;
            }
        } else {
            if (saved[i].gpa <= gpa_given) {
                min_max[valid_count].name = saved[i].name;
                min_max[valid_count].gpa = saved[i].gpa;
                valid_count++;
            }
        }
    }

    min_max = realloc(min_max, ((valid_count + 1) * sizeof(struct students)));

    // add sort for both minimum and maximum
    if (is_minimum == 1) {
        printf("\n--- Student List (Minimum GPA: %.1f) ---\n", gpa_given);
        qsort(min_max, valid_count, sizeof(struct students), compare_by_gpa);

        for (int i = 0; i < (valid_count); i++) {
            printf("%d. %s - GPA: %.1f\n", i + 1, min_max[i].name, min_max[i].gpa);
        }
    }
    else {
        printf("\n--- Student List (Maximum GPA) ---\n");
        qsort(min_max, valid_count, sizeof(struct students), compare_by_gpa);

        for (int i = 0; i < valid_count; i++) {
            printf("%d. %s - GPA: %.1f\n", i + 1, min_max[i].name, min_max[i].gpa);
        }
    }

    printf("------------------------------------\n");
    printf("Total Searched Students: %d student(s)\n", valid_count);
    printf("Total Number of Students: %d student(s)\n\n", student_counter);
    
    free(min_max);
}

void filter_by_gpa_range(float min_gpa, float max_gpa) {
    gpa_range = malloc(100 * sizeof(struct students));
    int valid_count = 0;

    for (int i = 0; i < student_counter; i++) {
        if (saved[i].gpa >= min_gpa && saved[i].gpa <= max_gpa) {
            gpa_range[valid_count].name = saved[i].name;
            gpa_range[valid_count].gpa = saved[i].gpa;
            valid_count++;
        }
    }

    gpa_range = realloc(gpa_range, (valid_count + 1) * sizeof(struct students));

    printf("\n--- Student List (GPA Range: %.1f-%.1f) ---\n", min_gpa, max_gpa);
    qsort(gpa_range, valid_count, sizeof(struct students), compare_by_gpa);
    
    for (int i = 0; i < valid_count; i++) {
        printf("%d. %s - GPA: %.1f\n", i + 1, gpa_range[i].name, gpa_range[i].gpa);
    }

    printf("------------------------------------\n");
    printf("Total Searched Students: %d student(s)\n", valid_count);
    printf("Total Number of Students: %d student(s)\n\n", student_counter);

    free(gpa_range);
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
            printf("Options:\n (1) Add Student\n (2) View All Students\n (3) Custom Search\n (4) Exit\n\n");
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
                if (!is_a_valid_grade) continue;

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

            char choice_sort[10];
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
            // three options: 
            if (student_counter == 0) {
                printf("The student list is empty!\n\n");
                continue;
            }

            printf("Search by:\n (1) Partial Name\n (2) Maximum/Minimum GPA\n (3) Accepted GPA Using Range\n");
            printf("Choose: ");

            char choice_search[10];
            fgets(choice_search, 10, stdin);
            choice_search[strcspn(choice_search, "\n")] = '\0';

            int is_valid_search = string_input_validation(choice_search);
            if (!is_valid_search) continue;

            int search_type = atoi(choice_search);
            if (search_type < 1 || search_type > 3) continue;

            if (search_type == 1) { // partial name
               printf("Enter partial name: ");

               char partial_name[10];
               fgets(partial_name, 10, stdin);
               partial_name[strcspn(partial_name, "\n")] = '\0';

               int valid_partial = string_input_validation(partial_name);
               if (!valid_partial) continue;

               partial_name_search(partial_name);

            }
            else if (search_type == 2) { // minimum gpa or maximum gpa
                printf("\nSearch by minimum GPA (1) or by maximum GPA (0)?\n");
                printf("\nChoose: ");
               
                char is_minimum[10];
                fgets(is_minimum, 10, stdin);
                is_minimum[strcspn(is_minimum, "\n")] = '\0';

                printf("Input a GPA you want to use as parameters: ");
                char given_gpa[10];
                fgets(given_gpa, 10, stdin);
                given_gpa[strcspn(given_gpa, "\n")] = '\0';

                int is_a_valid_type = string_input_validation(is_minimum);
                int is_a_valid_given_gpa = string_input_validation(given_gpa);

                if (!is_a_valid_type) continue;
                if (!is_a_valid_given_gpa) continue;

                int min_max_type = atoi(is_minimum);
                float gpa = atof(given_gpa);

                if (min_max_type < 0 || min_max_type > 1) continue;
                if (gpa < 60 || gpa > 100) continue;

                filter_by_gpa(min_max_type, gpa);

            }
            else if (search_type == 3) { // gpa range
                printf("Input a minimum GPA: ");
                char minimum_gpa[10];
                fgets(minimum_gpa, 10, stdin);
                minimum_gpa[strcspn(minimum_gpa, "\n")] = '\0';

                printf("Input a maximum GPA: ");
                char maximum_gpa[10];
                fgets(maximum_gpa, 10, stdin);
                maximum_gpa[strcspn(maximum_gpa, "\n")] = '\0';

                int is_a_valid_min = string_input_validation(minimum_gpa);
                int is_a_valid_max = string_input_validation(maximum_gpa);

                if (!is_a_valid_min) continue;
                if (!is_a_valid_max) continue;

                float min_gpa = atof(minimum_gpa);
                float max_gpa = atof(maximum_gpa);

                if (min_gpa < 60 || min_gpa > 100) continue;
                if (max_gpa < 60 || max_gpa > 100) continue;

                if (min_gpa > max_gpa) {
                    printf("\nMinimum GPA must not be less than the maximum GPA\n\n");
                    continue;
                } else if (max_gpa < min_gpa) {
                    printf("\nMaximum GPA must not be less than minimum GPA");
                    continue;
                }

                filter_by_gpa_range(min_gpa, max_gpa);
            }
        }
        
        else if (choice[0] == '4') 
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
