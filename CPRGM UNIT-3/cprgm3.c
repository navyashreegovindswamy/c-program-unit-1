#include<stdio.h>
struct date
{
    int day;
    int mon;
    int yr;
};
struct student
{
    int id;
    char name[20];
    struct date dob//nested structure
};
int main()
{
    struct student s1 ={101,"kiran",{15,8,2000}};
    printf("name: %s\n",s1.name);
    printf("DOB: %d-%d\n",s1.dob.day,s1.dob.mon,s1.dob.yr);
    return 0;
}

