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
        int product=1;
        for(int i=0;i<=4;i++){
                product = product * arr[i];
        }
        printf("%d",product);
    return 0;
}