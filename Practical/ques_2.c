//Write a C program to generate a Fibonacci series.
#include<stdio.h>
int main(){
    int num1=0,num2=1,num3,i,num;

    printf("Enter the Number till Fibonacci series need to print: ");
    scanf("%d",&num);

    printf("%d\t%d",num1,num2);
    num3= num1 + num2;
    for(i=2;i<num;i++)
    {
        printf("\t%d",num3);
        num1 = num2;
        num2 = num3;
        num3 = num1+ num2;
        }
        return 0;
}