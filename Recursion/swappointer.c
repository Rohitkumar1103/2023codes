#include<stdio.h>
void swap(int* x,int* y){
    int temp;
    temp=*x;
    *x=*y; //*y value is changed to y.
    *y=temp;
    return;
}

int main(){
    int a,b;
    printf("Enter the value of a: ");
    scanf("%d",&a);

    printf("Enter the value of b: ");
    scanf("%d",&b);

    swap(&a,&b);

    printf("Value of a is %d\n",a);
    printf("Value of b is %d",b);
        return 0;
}