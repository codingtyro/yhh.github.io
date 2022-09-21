#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> t;

    void dfs(int cur, vector<int>& nums) {
        if (cur == nums.size()) {
            vector<int>v = t;
            for(int i = 0;i < v.size();i++)cout << v[i] << " ";
            cout << endl;
            return ;
        }
        t.push_back(nums[cur]);
        dfs(cur + 1, nums);
        t.pop_back();
        dfs(cur + 1, nums);
    }

     void subsets(vector<int>& nums) {
        dfs(0, nums);
    }
};

int main(){
    Solution s;
    vector<int>nums = {1,2,3};
    s.subsets(nums);
    return 0;
}

