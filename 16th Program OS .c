#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int empId;
    char empName[50];
    float empSalary;
};

void addEmployee(FILE *file);
void displayEmployees(FILE *file);
void updateEmployee(FILE *file, int empId);
void deleteEmployee(FILE *file, int empId);

int main() {
    FILE *file;
    file = fopen("employee_data.dat", "r+");
    
    if (file == NULL) {

        file = fopen("employee_data.dat", "w+");
        if (file == NULL) {
            printf("Error creating file.\n");
            return 1;
        }
    }

    int choice;
    do {
        printf("\nEmployee Database Menu:\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Update Employee\n");
        printf("4. Delete Employee\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(file);
                break;
            case 2:
                displayEmployees(file);
                break;
            case 3: {
                int empId;
                printf("Enter employee ID to update: ");
                scanf("%d", &empId);
                updateEmployee(file, empId);
                break;
            }
            case 4: {
                int empId;
                printf("Enter employee ID to delete: ");
                scanf("%d", &empId);
                deleteEmployee(file, empId);
                break;
            }
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    fclose(file);
    return 0;
}


void addEmployee(FILE *file) {
    struct Employee emp;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.empId);

    printf("Enter Employee Name: ");
    scanf("%s", emp.empName);

    printf("Enter Employee Salary: ");
    scanf("%f", &emp.empSalary);

    fseek(file, (emp.empId - 1) * sizeof(struct Employee), SEEK_SET);
    fwrite(&emp, sizeof(struct Employee), 1, file);

    printf("Employee added successfully.\n");
}

void displayEmployees(FILE *file) {
    struct Employee emp;

    rewind(file);

    printf("\nEmployee Records:\n");
    printf("%-10s%-20s%-10s\n", "Emp ID", "Emp Name", "Emp Salary");
    while (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
        printf("%-10d%-20s%-10.2f\n", emp.empId, emp.empName, emp.empSalary);
    }
}

void updateEmployee(FILE *file, int empId) {
    struct Employee emp;

    fseek(file, (empId - 1) * sizeof(struct Employee), SEEK_SET);

    if (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
        printf("Enter new Employee Name: ");
        scanf("%s", emp.empName);

        printf("Enter new Employee Salary: ");
        scanf("%f", &emp.empSalary);

        fseek(file, (empId - 1) * sizeof(struct Employee), SEEK_SET);
        fwrite(&emp, sizeof(struct Employee), 1, file);

        printf("Employee updated successfully.\n");
    } else {
        printf("Employee with ID %d not found.\n", empId);
    }
}


void deleteEmployee(FILE *file, int empId) {
    struct Employee emp;

    fseek(file, (empId - 1) * sizeof(struct Employee), SEEK_SET);

    if (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
        
        emp.empId = 0;
        fseek(file, (empId - 1) * sizeof(struct Employee), SEEK_SET);
        fwrite(&emp, sizeof(struct Employee), 1, file);

        printf("Employee deleted successfully.\n");
    } else {
        printf("Employee with ID %d not found.\n", empId);
    }
}
