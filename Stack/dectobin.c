#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int stack_arr[MAX];
int top=-1;


void push(int data){
    if(top==MAX-1){
        printf("STACK OVERFLOW\n");
        return;
    }
    top=top+1;
    stack_arr[top]=data;
}
void dec2bin(int n){
    while(n!=0){
        push(n%2);
        n=n/2;
    }
}
void print(){
    if(top==-1){
        printf("Stack Underflow\n");
        return ;
    }
    for(int i=top;i>=0;i--){
        printf(" %d ",stack_arr[i]);
    }
    printf("\n");
}
int main(){
    int dec;
    printf("Enter the decimal number: ");
    scanf("%d",&dec);
    dec2bin(dec);
    print();

    return 0;
}
