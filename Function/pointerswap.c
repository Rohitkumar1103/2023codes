#include<stdio.h>
void swap(int* x, int* y){
    int c;
    c=*x;
    *x=*y;
    *y=c;
    return;
}
int main(){
        int a,b;
        printf("Enter the value of a and b: ");
        scanf("%d%d", &a,&b);

        swap(&a,&b);

        printf("The value of a and b is: %d and %d", a,b);
        return 0;
}