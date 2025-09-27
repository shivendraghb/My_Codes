#include<iostream>
#include<vector>
using namespace std;

vector<int> CircularArrayRotation(vector<int>& a,int k,vector<int>& queries){
    int n=a.size();
    k=k%n;

    vector<int> rotated(n);
    for(int i=0;i<n;i++){
        rotated[(i+k)%n]=a[i];
    }

    vector<int> result;
    for(int q:queries){
        result.push_back(rotated[q]);
    }

    return result;
}

int main()
{
    vector<int> a={1,2,3,4,5,6,7};
    vector<int> queries={0,1,2,3};
    int k=2;

    cout<<"Original Array:\n";
    for(int element:a){
        cout<<element<<" ";
    }
    cout<<'\n';

    vector<int> result=CircularArrayRotation(a,k,queries);

    cout<<"Queries Output:\n";
    for(int element:result){
        cout<<element<<" ";
    }
    cout<<'\n';

    return 0;
}
