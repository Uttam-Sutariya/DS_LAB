// Create structure Employee_detail (Employee_id, Name, Designation, Salary). Write a program to read the details from user and print it

#include <stdio.h>
#include <string.h>

//employee structure
struct Employee_detail{
    char Name[100];
    char Designation[100];
    int Employee_id;
    int salary;
};

void main(){
    struct Employee_detail employee;

    //Reading details
    printf("\nEnter the Name of Employee : ");
    fgets(employee.Name, 100, stdin);
    
    printf("Enter the Designation of Employee : ");
    fgets(employee.Designation, 50, stdin);

    printf("Enter Employee Id : ");
    scanf("%d" , &employee.Employee_id);

    printf("Enter the Salary of Employee : ");
    scanf("%d", &employee.salary);

    //Printing details
    printf("\nName: %s", employee.Name);
    printf("Designation: %s", employee.Designation);
    printf("ID: %d\n", employee.Employee_id);
    printf("Salary: %d\n", employee.salary);
}