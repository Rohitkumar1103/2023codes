#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void insertHeap(int arr[],int n, int data){
    n=n+1;
    arr[n]=data;
    int i=n;

    while(i>1){
        int parent=i/2;
        if(arr[parent]<arr[i]){
            swap(&arr[parent],&arr[i]);
            i=parent;
        }
        else 
            return ;
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
    int n,data;
    printf("Enter the number of Element: ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the data %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter the data to add: ");
    scanf("%d",&data);
    insertHeap(arr,n,data);

    printf("Sorted Array is: ");
    printArray(arr,n);

    return 0;
}