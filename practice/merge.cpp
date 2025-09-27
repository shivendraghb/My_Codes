#include<iostream>
using namespace std;//may use vector also and declare L and R as vector

void merge(int a[],int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;

    int L[n1],R[n2];// vector<int> L(n1),R(n2);

    for(int i=0;i<n1;i++) L[i]=a[p+i];
    for(int j=0;j<n2;j++) R[j]=a[q+1+j];

    int i=0,j=0,k=p;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) a[k++]=L[i++];

        else a[k++]=R[j++];
    }

    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}

void mergesort(int a[],int p,int r){
    if(p<r){
        int q=p+(r-p)/2;
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        merge(a,p,q,r);
    }
}

int main()
{
    int a[]={9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,-5,-6,-7,-8,-9};
    int n=sizeof(a)/sizeof(a[0]);

    mergesort(a,0,n-1);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<'\n';
    return 0;
}
