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
int main(){
    push(4);
    push(8);
    push(3);
    push(7);
return 0;
}