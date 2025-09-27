#include<iostream>
#include<vector>
using namespace std;

void reversed(vector<int>& a,int start,int end){
    if(start>=end) return;

    swap(a[start],a[end]);

    reversed(a,start+1,end-1);
}

int main(){
    vector<int> a={7,3,4,8,5};
    cout<<"before reversing:\n";
    for(int element:a){
        cout<<element<<" ";
    }
    cout<<'\n';

    reversed(a,0,a.size()-1);

    cout<<"after reversing:\n";
    for(int element:a){
        cout<<element<<" ";
    }
    cout<<'\n';

    return 0;
}
