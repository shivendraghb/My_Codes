class Solution {
    using ll=long long;
public:
    long long countGood(vector<int>& nums, int k) {
        ll n=nums.size();
        ll left=0,right=0;
        ll count=0;
        unordered_map<ll,ll> freq;
        ll pairs=0;

        while(left<n){
            while(right<n && pairs<k){
                freq[nums[right]]++;
                if(freq[nums[right]]>=2)
                    pairs += freq[nums[right]]-1;
                right++;
            }
            if(pairs>=k)
                count += n-right+1;

            //remove left item
            freq[nums[left]]--;
            if(freq[nums[left]]>0)
                pairs -= freq[nums[left]];
            left++;
        }
        return count;
    }
};
