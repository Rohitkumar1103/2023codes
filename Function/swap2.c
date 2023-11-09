#include<stdio.h>
int main(){
    int a,b;
        printf("Enter the value of a & b: ");
        scanf("%d%d",&a,&b);

    a=a+b;
    b=a-b;
    a=a-b;

    printf("The value of a & b is %d and %d", a,b);

        return 0;
}