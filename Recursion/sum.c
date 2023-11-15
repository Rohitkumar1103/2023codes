#include<stdio.h>
int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<=n-1;i++){
        printf("Enter the element: ");
        scanf("%d",&arr[i]);
    }
    int sum=0;
    for(int i=0;i<=4;i++){
        sum = sum + arr[i];
    }
    printf("%d",sum);
return 0;
    }