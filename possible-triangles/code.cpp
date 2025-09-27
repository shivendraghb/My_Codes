/* array 4 6 3 7*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int a[]={8,3,2,4,7,6,5};
    int n=sizeof(a)/sizeof(a[0]);

    int count=0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]+a[j]>a[k] && a[i]+a[k]>a[j] && a[j]+a[k]>a[i]){
                    count++;
                }
            }
        }
    }
    cout<<count<<endl;

    return 0;
}
