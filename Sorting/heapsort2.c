#include<stdio.h>

void swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

void maxHeapify(int arr[],int n,int i){
  int largest=i;
  int l=2*i+1;
  int r=2*i+2;

  if(l<n && arr[l]>arr[largest]){
    largest=l;
  }
  if(r<n && arr[r]>arr[largest]){
    largest=r;
  }

  if(largest !=i){
    swap(&arr[i],&arr[largest]);
    maxHeapify(arr,n,largest);
  }
}

void heapSort(int arr[],int n){
  for(int i=n/2-1;i>=0;i--){
    maxHeapify(arr,n,i);
  }
  for(int i=n-1;i>=0;i--){
    swap(&arr[0],&arr[i]);
    maxHeapify(arr,i,0);
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
    printf("Enter the number of Element: ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the data %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    heapSort(arr,n);

    printf("Sorted Array is: ");
    printArray(arr,n);

    return 0;
}