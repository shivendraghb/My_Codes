#include<bits/stdc++.h>
// #include<iostream>
// #include<vector>
// #include<algorithm>

using namespace std;


class Solution {
    public:
        int countLargestGroup(int n) {
            vector<int> count(37,0);
            for(int i=1;i<=n;i++){
                int sum=0,temp=i;
                while(temp>0){
                    sum+=temp%10;
                    temp/=10;
                }
                count[sum]++;
            }
            int maxsize= *max_element(count.begin(),count.end());
            int res=count_if(count.begin(),count.end(),[maxsize](int c){
                return c==maxsize;
            });

            return res;
        }
    };
    int main(){
        Solution s;
        int n;
        cout<<"enter the number: ";
        cin>>n;
        cout<<s.countLargestGroup(n)<<endl;
        return 0;
    }
