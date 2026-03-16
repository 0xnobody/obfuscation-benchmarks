#include<stdio.h>
#include "../annotations.h"
#define MAX 50

void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);

int POLARIS_ANNOTATE main(int argc, char* argv[]) {
    BACKEND_OBFU;
    if (argc < 11) return 1;
    int merge[10],i;

//    printf("Enter the total number of elements: ");
//    scanf("%d",&n);

//    printf("Enter the elements which to be sort: ");
//    for(i=0;i<n;i++){
//         scanf("%d",&merge[i]);
//    }
    for(i=1;i<argc;i++)
        merge[i-1] = argv[i][0];

    partition(merge,0,argc-1);

    printf("After merge sorting elements are: ");
    for(i=0;i<argc-1;i++){
         printf("%d ",merge[i]);
    }

   return 0;
}

void POLARIS_ANNOTATE partition(int arr[],int low,int high) {
    BACKEND_OBFU;

    int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}

void POLARIS_ANNOTATE mergeSort(int arr[],int low,int mid,int high) {
    BACKEND_OBFU;

    int i,m,k,l,temp[MAX];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}
