#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int flag=0;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            flag=1;
        }
    }
        if(flag==0)
        break;
    }
}

void printArray(int arr[],int n){
    printf("[");
    for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
    printf("]");
}
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
    }
}
void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(&arr[i],&arr[min]);
        }
    }
}
int main(){
    int n,choice;
    printf("Enter the number of element: ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the %d data: ",i+1);
        scanf("%d",&arr[i]);
    }
    while(1){
    printf("Menu:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice){
        case 1:
        bubbleSort(arr,n);
        printf("Bubble Sorted Array: \n");
        printArray(arr,n);
        break;

        case 2:
        insertionSort(arr,n);
        printf("Insertion Sorted Array: \n");
        printArray(arr,n);
        break;

        case 3:
        selectionSort(arr,n);
        printf("Selection Sorted Array: \n");
        printArray(arr,n);
        break;

        case 4:
        printf("Exiting.....\n");
        exit(0);
        
        default:
            printf("INVALID CHOICE!!");

    }
}
    return 0;
}