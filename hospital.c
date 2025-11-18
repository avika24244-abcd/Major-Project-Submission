#include <stdio.h>
#include <string.h>

struct Patient {
    char name[50];
    int age;
    char disease[30];
    int admitted;   // 1 = Yes, 0 = No
};

int main() {
    struct Patient p[100];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- Hospital Menu ---\n");
        printf("1. Add Patient\n");
        printf("2. Display All Patients\n");
        printf("3. Search by Disease\n");
        printf("4. Display Admitted Patients\n");
        printf("5. Count Admitted Patients\n");
        printf("6. Average Age\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter name: ");
            scanf(" %[^\n]", p[count].name);

            printf("Enter age: ");
            scanf("%d", &p[count].age);

            printf("Enter disease: ");
            scanf(" %[^\n]", p[count].disease);

            printf("Is admitted? (1=Yes, 0=No): ");
            scanf("%d", &p[count].admitted);

            count++;
            printf("Patient added!\n");
        }

        else if (choice == 2) {
            printf("\n--- All Patients ---\n");
            for (int i = 0; i < count; i++) {
                printf("Name: %s | Age: %d | Disease: %s | Admitted: %d\n",
                       p[i].name, p[i].age, p[i].disease, p[i].admitted);
            }
        }

        else if (choice == 3) {
            char dis[30];
            printf("Enter disease to search: ");
            scanf(" %[^\n]", dis);

            printf("\n--- Patients with %s ---\n", dis);
            for (int i = 0; i < count; i++) {
                if (strcmp(p[i].disease, dis) == 0) {
                    printf("Name: %s | Age: %d\n", p[i].name, p[i].age);
                }
            }
        }

        else if (choice == 4) {
            printf("\n--- Admitted Patients ---\n");
            for (int i = 0; i < count; i++) {
                if (p[i].admitted == 1) {
                    printf("Name: %s | Disease: %s\n",
                           p[i].name, p[i].disease);
                }
            }
        }

        else if (choice == 5) {
            int admittedCount = 0;

            for (int i = 0; i < count; i++) {
                if (p[i].admitted == 1) {
                    admittedCount++;
                }
            }

            printf("Total admitted patients: %d\n", admittedCount);
        }

        else if (choice == 6) {
            int sum = 0;

            for (int i = 0; i < count; i++) {
                sum += p[i].age;
            }

            if (count > 0)
                printf("Average age: %.2f\n", (float)sum / count);
            else
                printf("No patients added yet.\n");
        }

        else if (choice == 7) {
            break;
        }

        else {
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
