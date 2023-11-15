#include<stdio.h>
int main(){
        int i, marks[10];
        
        for(i=0;i<=9;i++){
            printf("Enter the marks of the student %d: ",i+1);
            scanf("%d",&marks[i]);
        }

        for(i=0;i<=9;i++){
        if(marks[i]<30)
        {
            printf("%d ",i);
        }
        }

        return 0;
}
