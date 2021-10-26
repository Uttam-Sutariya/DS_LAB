// Create array of structure STUDENT_DETAIL (Enrollment_no, Name, Sem, CPI) for 5 student, scan therir information and print it

#include <stdio.h>
#define N 5

//student detail structure
struct STUDENT_DETAIL{
    char Name[20];
    unsigned long Enrollment_no;
    int sem;
    float cpi;
};

void main(){
    
    //creating array of structure STUDENT_DETAIL
    struct STUDENT_DETAIL student[5];
    
    //Reading details
    for(int i = 0 ; i<N ; i++){
        //Reading details
        printf("\nEnter %d record : \n", i+1);
        printf("Enter Name : ");
        scanf("%s", student[i].Name);
        printf("Enter Enrollment_No : ");
        scanf("%lu", &student[i].Enrollment_no);
        printf("Enter SEM : ");
        scanf("%d", &student[i].sem);
        printf("Enter CPI : ");
        scanf("%f", &student[i].cpi);
    }
    
    //Printing details
    printf("\n\tName\tEnrollment_no\tSEM\tCPI\t\n");
    for(int i = 0 ; i<N ; i++){
        printf("\t%s\t%lu\t%d\t%.2f\t\n", student[i].Name, student[i].Enrollment_no, student[i].sem, student[i].cpi);
    }
}