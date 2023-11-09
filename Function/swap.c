#include<stdio.h>
int main(){
    int a,b;
    printf("Enter the value of a and b: ");
    scanf("%d%d", &a,&b);

        int c;
        c=a;
        a=b;
        b=c;
        printf("The value of a and b is : %d and %d",a,b);

        return 0;
}