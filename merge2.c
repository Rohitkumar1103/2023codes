#include<stdio.h>

void merge(int arr[],int lb,int mid,int ub){
    int i=lb;
    int j=mid+1;
    int k=lb;
    int brr[k];
    while(i<=mid && j<=ub){
        if(arr[i]<=arr[j]){
            brr[k]=arr[i];
            i++;
        }
        else {
            brr[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            brr[k]=arr[j];
            j++;
            k++;
        }
    }
    else {
        while(i<=mid){
            brr[k]=arr[i];
            i++;
            k++;
        }
    }
    for(k=lb;k<=ub;k++){
        arr[k]=brr[k];
    }
} 

void printArray(int arr[],int n){
    printf("[");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("]");
}

void mergeSort(int arr[],int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}
int main(){
    int n;

    printf("Enter the Number of element: ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the %d data: ",i+1);
        scanf("%d",&arr[i]);
    }

    mergeSort(arr,0,n-1);
    printf("The Sorted Array: ");
    printArray(arr,n);

    return 0;
}