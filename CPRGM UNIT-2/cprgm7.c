#include<stdio.h>
#include<string.h>
struct book 
{
 int id;
 char title[50];   
};
int main()
{
    struct book b1 ={101,"c programming","dennis ritchie"};
    struct book b2 ={102,"data science","mark weiss"};
    struct book b3 ={103,"operating systems","Silberschatz"};
    
    // array of pointers in structure
    struct book *book[3]={&b1 ,&b2, &b3};
    int search_id, i, found=0;
    printf("Enter book id to search: ");
    scanf("%d", &search_id);
    for(i=0;i<3;i++)
    {
        if(book[i]->id == search_id)
        {
            printf("Book found: \n");
            printf("ID: %d\n", book[i]->id);
            printf("Title: %s\n", book[i]->title);
            printf("Author: %s\n", book[i]->author);
            found=1;
            break;
        }
    }
    
}