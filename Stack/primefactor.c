#include<stdio.h>
#include<stdlib.h>
#define MAX 6
int stack_arr[MAX];
int top=-1;

int isFull(){
    if(top==MAX-1)
        return 1;
    else
        return 0;
}

int isEmpty(){
    if(top==-1)
        return 1;
    else    
        return 0;
}

void push(int n){
    if(isFull()){
        printf("Stack Overflow");
    exit(1);
    }
    top++;
    stack_arr[top]=n;
}

int pop(){
    int val;
    if(isEmpty()){
        printf("Stack Underflow");
        exit(1);
    }
    val=stack_arr[top];
    top--;
    return val;
}

void prime_fact(int num){
    int i=2;
    while(num!=1){
        while(num%i==0){
            push(i);
            num=num/i;
        }
        i++;
    }
    printf("Prime factor of the number  in descending order are as follows: ");
    while(top!=-1){
        printf("%d ",pop());
    }
}

int main(){
    int number;
    printf("Enter the positive number: ");
    scanf("%d",&number);

    prime_fact(number);
    return 0;
}
