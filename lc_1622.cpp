#include<bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9+7;

struct Fancy {
    vector<int> v;
    int a = 1, b = 0;

    int modpow(int x, int y){
        int res = 1;
        while(y){
            if(y&1) res = res*x%MOD;
            x = x*x%MOD;
            y >>= 1;
        }
        return res;
    }

    void append(int val){
        int inv = modpow(a, MOD-2);
        int x = ((val - b)%MOD + MOD)%MOD;
        x = x*inv%MOD;
        v.push_back(x);
    }

    void addAll(int inc){
        b = (b + inc)%MOD;
    }

    void multAll(int m){
        a = a*m%MOD;
        b = b*m%MOD;
    }

    int getIndex(int idx){
        if(idx >= v.size()) return -1;
        return (v[idx]*a%MOD + b)%MOD;
    }
};