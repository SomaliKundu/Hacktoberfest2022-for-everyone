//1. wap a programme to compare tc of traditional merge sort and modified mergesort. 
//In modified mergesort your data divided into three parts in each iterations.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int arr[], int l, int mid, int r){
    int n1=mid-l+1;

    int n2=r-mid;

    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i]=arr[l+i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i]<b[i]){
            arr[k]=a[i];
            k++;
            i++;
        }
        else{
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++;i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++;j++;
    }
    
}
void mergesort(int arr[], int l, int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }
}
 void merge3part(int arr[], int l, int h, int mid1, int mid2){
    int n1=mid1-l+1;
    int n2=mid2-mid1+1;
    int n3=h-mid2;

    int a[n1];
    int b[n2];
    int c[n3];


    for (int i = 0; i < n1; i++)
    {
        a[i]=arr[l+i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i]=arr[mid1+1+i];
    }

    for (int i = 0; i < n3; i++)
    {
        c[i]=arr[mid2+1+i];
    }


    int i=0,j=0,m=0,k=l;
    while(i<n1 && j<n2 && m<n3){
        if(a[i]<b[i] && a[i]<c[i]){
            arr[k]=a[i];
            k++;
            i++;
        }
        if(b[j]<a[j] && b[j]<c[j]){
            arr[k]=b[j];
            k++;
            j++;
        }
         if(c[m]<a[m] && c[m]<b[m]){
            arr[k]=c[m];
            k++;
            m++;
        }
    }
    while(i<n1){
        arr[k]=a[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++;
        j++;
    }

    while(m<n3){
        arr[k]=c[m];
        k++;
        m++;
    }


 }

void mergesort3part(int arr[],int l, int h){
    if(l<h){

    int mid1 = l + ((h - l) / 3);
    int mid2 = mid1+((h-mid1)/2);
 
   
   mergesort3part(arr,l,mid1);
   mergesort3part(arr,mid1,mid2);
   mergesort3part(arr,mid2,h);

   merge3part(arr,l,mid1,mid2,h);
        
    }
}

int main(){
    int arr[]={5,4,3,2,1,6,0,3,7};
    int l1=clock();
    mergesort(arr,0,8);
    int h1=clock();

    int time_For_mergesort=h1-l1;

    int l2=clock();
    mergesort3part(arr,0,8);
    int h2=clock();

    int time_For_mergesort3part=h2-l2;


    printf("%d\n%d", time_For_mergesort, time_For_mergesort3part);


    
   
    return 0;
    
    
}
