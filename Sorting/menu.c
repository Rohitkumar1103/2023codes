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
                swap(&arr[j],&arr[j+1]);
            }
        }
        if(flag==1){
        break;}
    }
}

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            swap(&arr[j],&arr[j+1]);
            j--;
        }
        arr[j+1]=temp;
    }
}

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
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

int partition(int arr[],int lb,int ub){
    int pivot=arr[lb];
    int start=lb;
    int end=ub;

    while(start<end){
        while(arr[start]<=pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<end){
        swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[lb],&arr[end]);
    return end;
}
void quickSort(int arr[],int lb,int ub){
    if(lb<ub){
        int loc=partition(arr,lb,ub);
        quickSort(arr,lb,loc-1);
        quickSort(arr,loc+1,ub);
    }
}

void merge(int arr[], int lb, int mid, int ub){
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

void mergeSort(int arr[],int lb,int ub){
    if(lb<ub){
        int mid=(lb+ub)/2;
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}

void maxHeapify(int arr[],int n,int i){
    int largest=i;
    int left = (2*i)+1;
    int right = (2*i)+2;

    while(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    while(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
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
    int n,choice;
    printf("Enter the number of element: ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the %d data: ",i+1);
        scanf("%d",&arr[i]);
    }
    while(1){
    printf("\nMenu:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Selection Sort\n");
    printf("4. Quick Sort\n");
    printf("5. Merge Sort\n");
    printf("6. Heap Sort\n");
    printf("7. Exit\n");
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
        quickSort(arr,0,n-1);
        printf("Quick Sorted Array: \n");
        printArray(arr,n);
        break;

        case 5: 
        mergeSort(arr,0,n-1);
        printf("Merge Sorted Array: \n");
        printArray(arr,n);
        break;

        case 6:
        heapSort(arr,n);
        printf("Heap Sorted Array: \n");
        printArray(arr,n);
        break;

        case 7:
        printf("Exiting.....\n");
        exit(0);
        
        default:
            printf("INVALID CHOICE!!");

    }
}
    return 0;
}