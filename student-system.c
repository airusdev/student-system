#include <stdio.h>
#include <stdbool.h>

int main() {
    bool accepted_value = false; 
    int choice;
    
    while (1) {
        if (choice == 1) {
            printf("placeholder for add_student()\n\n");
        } else if (choice == 2) {
            printf("placeholder for view students\n\n");
        } else if (choice == 3) {
            printf("Goodbye!\n\n");
            break;
        }
        
        accepted_value = false;
        while (accepted_value == false) {
            printf("Options:\n (1) Add Student\n (2) View Students\n (3) Exit\n\n");
            scanf("%d", &choice);

            if (choice == 1 || choice == 2 || choice == 3) {
                accepted_value = true;
            }
        }
    }
    return 0;
}
