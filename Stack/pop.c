#include<stdio.h>
#include<stdlib.h>
#define MAX 4
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
int pop(){
    int value;
    if(top==-1){
        printf("Stack Underflow");
        exit(1);
    }
    value=stack_arr[top];
    top=top-1;
    return value;
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
    int data;
    push(4);
    push(8);
    push(3);
    push(7);
    push(5);
    data=pop();
    print();
return 0;
}