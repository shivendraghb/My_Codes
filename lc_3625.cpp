#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll countTrapezoids(vector<pair<int,int>>& p) {
    int n = p.size();

    auto norm = [&](int dx, int dy) {
        if (dx == 0) return make_pair(0, 1);
        if (dy == 0) return make_pair(1, 0);
        int g = gcd(abs(dx), abs(dy));
        dx /= g; dy /= g;
        if (dx < 0) { dx = -dx; dy = -dy; }
        else if (dx == 0 && dy < 0) { dy = -dy; }
        return make_pair(dx, dy);
    };

    auto encode = [&](pair<int,int> s) {
        return ((ll)s.first << 32) ^ (unsigned int)s.second;
    };

    unordered_map<ll, vector<pair<ll,ll>>> mp;
    mp.reserve(n * n);

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int dx = p[j].first - p[i].first;
            int dy = p[j].second - p[i].second;

            auto slope = norm(dx, dy);
            ll key = encode(slope);

            ll intercept = (ll)p[i].second * slope.first - (ll)p[i].first * slope.second;
            ll midx2 = (ll)p[i].first + p[j].first;
            ll midy2 = (ll)p[i].second + p[j].second;
            ll midEnc = midx2 ^ (midy2 << 32);

            mp[key].push_back({intercept, midEnc});
        }
    }

    ll totalPairs = 0;
    ll para = 0;

    for (auto &it : mp) {
        auto &v = it.second;
        int m = v.size();
        if (m < 2) continue;

        totalPairs += (ll)m * (m - 1) / 2;

        unordered_map<ll,int> freq;
        freq.reserve(m);

        for (auto &seg : v)
            freq[seg.second]++;

        for (auto &f : freq) {
            int c = f.second;
            if (c >= 2) para += (ll)c * (c - 1) / 2;
        }
    }

    return totalPairs - para / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int,int>> pts(n);
    for (auto &pp : pts) cin >> pp.first >> pp.second;

    cout << countTrapezoids(pts) << "\n";
    return 0;
}

// class Solution {
// public:
//     using ll=long long;
//     using int2=pair<int,int>;
//     using int4=pair<int2,int2>;

//     static inline int cntShapes(int total, const vector<int>& Line){
//         int sum=0;
//         for(int x : Line) sum+=x*(total-x);
//         return sum;
//     }
//     static int countTrapezoids(vector<vector<int>>& points) {
//         const int n=points.size(), n2=n*(n-1)/2;

//         int4* slope_inter=(int4*)alloca(n2*sizeof(int4));
//         int4* midPt_slope=(int4*)alloca(n2*sizeof(int4));

//         for (int i=0, k=0; i<n-1; i++) {
//             const int x0=points[i][0], y0=points[i][1];
//             for (int j=i+1; j<n; j++, k++) {
//                 const int x1=points[j][0], y1=points[j][1];

//                 int a=y1-y0;
//                 int b=x0-x1;
//                 int c=y0*x1-y1*x0;

//                 if (a==0 && b<0) { b=-b; c=-c; }
//                 else if (a<0) { a=-a; b=-b; c=-c; }

//                 int gm=gcd(a, b), gc=gcd(gm, c);
                
//                 const int2 slope={ a/gm, b/gm };
//                 const int2 intercept={ c/gc, gm/gc };
//                 const int2 midPt={ x0+x1, y0+y1 };

//                 slope_inter[k]={ slope, intercept };
//                 midPt_slope[k]={ midPt, slope };
//             }
//         }

//         sort(slope_inter, slope_inter+n2);
//         sort(midPt_slope, midPt_slope+n2);

//         int cnt=0;

//         {
//             vector<int> B;
//             auto& [slope, inter]=slope_inter[0];
//             int sameM=1, sameB=1;

//             for (int i=1; i<n2; i++) {
//                 auto& [m, b]=slope_inter[i];
//                 if (m==slope) {
//                     sameM++;
//                     if (b==inter) sameB++;
//                     else {
//                         B.push_back(sameB);
//                         sameB=1;
//                         inter=b;
//                     }
//                 } 
//                 else {
//                     B.push_back(sameB);
//                     cnt+=cntShapes(sameM, B)/2;

//                     B.clear();
//                     slope=m;
//                     inter=b;
//                     sameM=sameB=1;
//                 }
//             }
//             B.push_back(sameB);
//             cnt+=cntShapes(sameM, B)/2;
//         }

//         {
//             vector<int> L;
//             auto& [midPt, slope]=midPt_slope[0];
//             int sameMid=1, sameM=1;

//             for (int i=1; i<n2; i++) {
//                 auto& [mid, m]=midPt_slope[i];
//                 if (mid==midPt) {
//                     sameMid++;
//                     if (m==slope) 
//                         sameM++;
//                     else {
//                         L.push_back(sameM);
//                         sameM=1;
//                         slope=m;
//                     }
//                 } 
//                 else {
//                     L.push_back(sameM);
//                     cnt-=cntShapes(sameMid, L)/2;

//                     L.clear();
//                     slope=m;
//                     midPt=mid;
//                     sameM=sameMid=1;
//                 }
//             }

//             L.push_back(sameM);
//             cnt-=cntShapes(sameMid, L)/2;
//         }
//         return cnt;
//     }
// };
