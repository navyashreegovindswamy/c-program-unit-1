#include<stdio.h>
int main()
{
    float m1, m2, m3, avg,total;
    char grade;
    printf("Enter marks of three subjects(out of hundred): ");
    scanf("%f %f %f", &m1, &m2, &m3);
    // arthmetic operations
    total = m1 + m2 + m3;
    avg = total / 3.0;
    //displaying total and average
    printf("Total marks = %.2f\n", total);
    printf("Average marks = %.2f\n", avg);
    //determine grade using if...else
    if (avg >= 90)
        grade = 'A';
    else if (avg >= 80)
        grade = 'B';
    else if (avg >= 70)
        grade = 'C';
    else if (avg >= 60)
        grade = 'D';
    else
        grade = 'F';
    printf("Grade = %c\n", grade);
    return 0;
}