#include<stdio.h>
 int main(){
        int n;
        printf("Enter the size of the array: ");
        scanf("%d",&n);

        int arr[n];
        for(int i=0;i<=n-1;i++){
            printf("Enter the %d elements: ",i);
            scanf("%d",&arr[i]);
        }
        int max = arr[0];
        for(int i=0;i<=n-1;i++){
            if(max < arr[i]){
                max = arr[i];
            }
        }
            printf("%d",max);
return 0;
}