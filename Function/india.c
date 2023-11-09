#include<stdio.h>
void england(){
        printf("England\n");
        return;
}
void australia()
    {
        printf("Australia\n");
        england();
        return;
    }
void india()
    {
        printf("India\n");
        australia();
        return;
    }
int main(){
    india();
        return 0;
}