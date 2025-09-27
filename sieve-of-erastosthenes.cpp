#include<iostream>
#include<vector>
using namespace std;

void sieve(int n){
    vector<bool> isprime(n+1,true);
    isprime[0]=isprime[1]=false;

    for(int i=2;i*i<=n;i++){
        if(isprime[i]){
            for(int j=i*i;j<=n;j+=i){
                isprime[j]=false;
            }
        }
    }

    cout<<"prime numbers upto "<<n<<" are:\n";
    for(int i=2;i<=n;i++){
        if(isprime[i]) cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"enter the range(0-n): ";
    cin>>n;

    sieve(n);

    return 0;
}
