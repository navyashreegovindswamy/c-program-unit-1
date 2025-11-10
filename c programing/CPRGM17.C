#include<stdio.h>
int main() {
    int age;
    float height;
    char grade;
    printf("Enter your age: "); 
    scanf("%d",&age);
    printf("Enter your height in meters: "); 
    scanf("%f",&height);
    printf("Enter grade (A/B/C): "); 
    scanf(" %c",&grade);
    printf("\n---student details---\n");
    printf("Age: %d years\n",age);
    printf("Height: %.2f meters\n",height);
    printf("Grade: %c\n",grade);
    return 0;
}
