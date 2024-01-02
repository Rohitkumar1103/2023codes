#include<stdio.h>

int binarySearch(int arr[],int n,int data){
    int l=0,r=n-1,mid;
    while(l<=r){
        mid=(l+r)/2;

        if(data==arr[mid])
            return mid;
        else if(data<arr[mid])
            r=mid-1;
        else 
            l=mid+1;
    }
    return -1;
}

int main(){
    int n,data;
    printf("Enter the number of Element: ");
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter the Element %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("Enter the Element to search: ");
    scanf("%d",&data);
    int index=binarySearch(arr,n,data);

    
    if (index != -1) {
        printf("The element %d is found at index %d\n", data, index);
    } else {
        printf("The element %d is not found in the array\n", data);
    }

  return 0;
}