#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<long long> bit;
    BIT(int n) : n(n), bit(n+2,0) {}
    void add(int i, long long x){
        for (++i;i<=n;i+=i&-i) bit[i]+=x;
    }
    long long query(int i){
        long long res=0;
        for (++i;i>0;i-=i&-i) res+=bit[i];
        return res;
    }
    long long query(int l,int r){
        return query(r)-query(l-1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;
    while(T--){
        int n,q; cin>>n>>q;
        vector<int> p(n),s(n);
        for(int i=0;i<n;i++) cin>>p[i];
        for(int i=0;i<n;i++) cin>>s[i];

        vector<int> b(n);
        for(int i=0;i<n;i++) b[i]=max(p[i],s[i]);

        // Coordinate compression
        vector<int> vals=b;
        sort(vals.begin(),vals.end());
        vals.erase(unique(vals.begin(),vals.end()),vals.end());
        auto getID=[&](int x){return lower_bound(vals.begin(),vals.end(),x)-vals.begin();};

        int m=vals.size();
        BIT bit(m);
        vector<int> freq(m,0);
        for(int i=0;i<n;i++){
            int id=getID(b[i]);
            freq[id]++;
            bit.add(id,1);
        }

        auto computePairs=[&](){
            long long ans=0;
            for(int id=0;id<m;id++){
                long long c=freq[id];
                long long s=bit.query(id);
                ans+=c*s;
            }
            return ans;
        };

        cout<<computePairs()<<"\n"; // initial total pairs before queries? optional

        for(int k=0;k<q;k++){
            int tp,i,j; cin>>tp>>i>>j; i--; j--;
            if(tp==1) swap(p[i],p[j]);
            else swap(s[i],s[j]);

            // update b[i] and b[j]
            for(int idx:{i,j}){
                int old_id=getID(b[idx]);
                bit.add(old_id,-1);
                freq[old_id]--;
                b[idx]=max(p[idx],s[idx]);
                int new_id=getID(b[idx]);
                bit.add(new_id,1);
                freq[new_id]++;
            }

            cout<<computePairs()<<"\n";
        }
    }
}
