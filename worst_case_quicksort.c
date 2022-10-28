#include<stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int arr[],int f,int l){
    int pivot = arr[l];
    int pi = f;
    for(int i = f; i < l;i++){
        if(arr[i] <= pivot){ 
            swap(&arr[pi],&arr[i]);
            pi++;
        }
    }
    swap(&arr[pi],&arr[l]);
    return pi;   
}

void QuickSort(int arr[],int f, int l){
    if(f < l){
        int pIndex = Partition(arr,f,l);
        //printf("\n%d\n" ,pIndex);
        QuickSort(arr,f,pIndex-1);
        QuickSort(arr,pIndex+1,l);
    }

}

int main(){
    int arr[] = {15,14,13,12,10}; // reverse sorted array
    //int arr[] = {1,1,1,1,1}; // same element array
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Before Sorting Array: ");
    for(int i = 0; i < n;i++){
        printf("%d ",arr[i]);
    }
    QuickSort(arr,0,n-1);
    printf("\nAfter Sorting Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}