#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int stack[SIZE];
int top=-1;
void push(int value)
{
    if(top==SIZE-1)
    
        printf("Stack Overflow\n,cannot push %d\n",value);
            else{
    stack[++top]=value;
    printf("Pushed %d to stack\n",value);
    }
}
    void pop()
    {
        if(top==-1)
        
            printf("Stack Underflow! no element to pop\n");
        
        else
        
            printf("stack elements");
    }
void display()
{
    if(top==-1)
        printf("Stack is empty\n");
    else
    {
        printf("Stack elements are:\n");
        for(int i=top;i>=0;i--)
            printf("%d\n",stack[i]);
    }
}
int main()
{
push(10);
push(20);
push(30);
display();
pop();
display();
return 0;
}
