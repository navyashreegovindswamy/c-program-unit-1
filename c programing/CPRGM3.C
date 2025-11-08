#include<stdio.h>
int main()
{char name[20];
int age;
float marks;
printf("enter name: ");
scanf("%s",name);
printf("enter age: ");
scanf("%d",&age);
printf("enter marks: ");
scanf("%f",&marks);
printf("\nstudent details:\n");
printf("name: %s\nage: %d\nmarks: %.2f\n",name,age,marks);
return 0;
}