// #include<stdio.h>

// void bubbleSort(int arr[],int n){
//     int flag, temp;
//     for(int i=0;i<n-1;i++){
//         flag=0;
//             for(int j=0;j<n-1-i;j++){
//                 if(arr[j]>arr[j+1]){
//                 temp=arr[j];
//                 arr[j]=arr[j+1];
//                 arr[j+1]=temp;
//                 flag=1;
//             }
//         }
//         if(flag==0){
//             break;
//         }
//     }
// }

// void printArray(int arr[],int n){
//     printf("[");
//     for(int i=0;i<n;i++){
//         printf("%d ",arr[i]);
//     }
//     printf("]");
// }

// int main(){
//     int arr[]={64, 34,90, 56, 78, 12, 23};
//     int n=sizeof(arr)/sizeof(arr[0]);

//     bubbleSort(arr,n);
//     printf("Bubble Sorted Array: ");
//     printArray(arr, n);
//     return 0;
// }

#include <stdio.h>

void bubbleSort(int arr[], int n)
 
{
    for (int i = 0; i < n - 1; i++) {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

void printArray(int arr[],int n){
    printf("[");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("]");
}

int main(){
    
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);
    printf("The Sorted Array is: ");
    printArray(arr,n);

    return 0;
}