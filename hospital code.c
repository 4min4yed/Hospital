#include <stdio.h>
#include <string.h>

struct patient {
    char fullname[100];
    char illness[50];
    int year;
};

void displaypatient(struct patient patient) {
    printf("Full Name: %s\n", patient.fullname);
    printf("Illness: %s\n", patient.illness);
    printf("Year: %d\n", patient.year);
}

int main() {
    const int MAX_patients = 100;
    struct patient sbitar[MAX_patients];
    int numpatients = 0;
    int choice;

    while (1) {
        printf("hospital Management System\n");
        printf("1. Add patient\n");
        printf("2. Display patients\n");
        printf("3. Search by Full Name\n");
        printf("4. Search by Illness\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (numpatients < MAX_patients) {
                struct patient newpatient;
                printf("Enter Full Name: ");
                scanf(" %[^\n]", newpatient.fullname);
                printf("Enter Illness: ");
                scanf(" %[^\n]", newpatient.illness);
                printf("Enter Year: ");
                scanf("%d", &newpatient.year);

                sbitar[numpatients] = newpatient;
                numpatients++;
                printf("Patient added successfully.\n");
            } else {
                printf("Hospital is full. Cannot add more patients.\n");
            }
        } else if (choice == 2) {
            if (numpatients == 0) {
                printf("Hospital is empty.\n");
            } else {
                printf("Patients in the hospital:\n");
                for (int i = 0; i < numpatients; i++) {
                    printf("Patient %d:\n", i + 1);
                    displaypatient(sbitar[i]);
                }
            }
        } else if (choice == 3) {
            if (numpatients == 0) {
                printf("Hospital is empty.\n");
            } else {
                char searchFullName[100];
                printf("Enter the full name to search: ");
                scanf(" %[^\n]", searchFullName);
                int found = 0;
                for (int i = 0; i < numpatients; i++) {
                    if (strcmp(searchFullName, sbitar[i].fullname) == 0) {
                        displaypatient(sbitar[i]);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Patient not found with that full name.\n");
                }
            }
        } else if (choice == 4) {
            if (numpatients == 0) {
                printf("Hospital is empty.\n");
            } else {
                char searchIllness[50];
                printf("Enter the illness to search: ");
                scanf(" %[^\n]", searchIllness);
                int found = 0;
                for (int i = 0; i < numpatients; i++) {
                    if (strcmp(searchIllness, sbitar[i].illness) == 0) {
                        displaypatient(sbitar[i]);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Patient not found with that illness.\n");
                }
            }
        } else if (choice == 5) {
            printf("Exiting the Hospital Management System.\n");
            return 0;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
