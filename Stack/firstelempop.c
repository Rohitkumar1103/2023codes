#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack_arr[MAX];
int first=-1;
void push(int data){
    first=first+1;
    for(int i=first;i>0;i--){
        stack_arr[i]=stack_arr[i-1];
    }
    stack_arr[0]=data;
}
int pop(){
    int value,i;
    value=stack_arr[0];
    for(i=0;i<first;i++){
        stack_arr[i]=stack_arr[i+1];
    }
    first=first-1;
    return value;
}
void print(){
    if(first==-1){
        printf("Stack Underflow\n");
        return ;
    }
    for(int i=0;i<=first;i++){
        printf(" %d ",stack_arr[i]);
    }
    printf("\n");
}
int main(){
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    print();
    int data=pop();
    print();
    return 0;
}