#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>> nextPermutation(vector<int>& nums){
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        res.push_back(nums);

        while(true){
            int i = nums.size() - 2;
            while(i >= 0 && nums[i] >= nums[i + 1])
                i--;
            if(i < 0)
                break;
            int j = nums.size() - 1;
            while(nums[j] <= nums[i])
                j--;

            swap(nums[i], nums[j]);

            reverse(nums.begin() + i + 1, nums.end());

            res.push_back(nums);
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1, 2, 3};
    Solution sol;
    vector<vector<int>> ans = sol.nextPermutation(nums);

    for(const auto& i : ans){
        for(int j : i)
            cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}
