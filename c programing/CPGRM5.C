#include<stdio.h>
int main()
    {
        const int maxscore = 100;
        volatile int sensorvalue = 50;
    printf("constant value:%d\n",maxscore);
    printf("volatile value:%d\n",sensorvalue);
    return 0;
    }
