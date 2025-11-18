class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i=m-1,j=n-1,k=m+n-1;
      while(i>=0 && j>=0){
        if(nums1[i]>nums2[j]) nums1[k--]=nums1[i--];
        else nums1[k--]=nums2[j--];
      }
      while(j>=0){
        nums1[k--]=nums2[j--];
      }
    }
};

int main() {
    Solution sol;

    int n1, m, n2, n;
    cin >> n1 >> m >> n2 >> n;

    vector<int> v1(n1), vector<int> v2(n2);
    
    for(int i = 0; i < n1; i++)
        cin >> v1[i];

    for(int j = 0; j < n2; j++)
        cin >> v2[j];

    sol.merge(v1, )
}