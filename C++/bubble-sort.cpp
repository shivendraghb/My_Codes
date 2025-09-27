#include<iostream>

void sort(int array[],int size);

int main(){
    int array[]={1,214,31,5,656,56,2025,56};
    int size=sizeof(array)/sizeof(array[0]);

    sort(array,size);

    for(int element:array){
        std::cout<<element<<" ";
    }
    std::cout<<'\n';
    return 0;
}
void sort(int array[],int size){

    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(array[j]>array[j+1])
            {
                int temp=array[j+1];
                array[j+1]=array[j];
                array[j]=temp;
            }
        }
    }
}
