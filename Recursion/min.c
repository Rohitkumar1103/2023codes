#include<stdio.h>
int main(){
        int n;
        printf("Enter the size of the array: ");
        scanf("%d",&n);

        int arr[n];
        for(int i=0;i<=n-1;i++){
        printf("Enter the %d element: ",i);
        scanf("%d",&arr[i]);
        }

        int min= arr[0];
        for(int i=0;i<=n-1;i++){
            if(min > arr[i]){
                min = arr[i]; 
            }
        }
            printf("%d",min);
return 0;
}