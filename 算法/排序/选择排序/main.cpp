#include<iostream>
#include<vector>

using namespace std;

void sort(vector<int>& nums){
    for(int i = 0;i < nums.size();i++){
        int mi = i;
        for(int j = i + 1;j < nums.size();j++){
            if(nums[j] < nums[mi]){
                mi = j;
            }
        }
        if(mi != i){
        swap(nums[mi],nums[i]);
        }
    }
}

int main(){
    vector<int>nums = { 8, 9, 1, 7, 2, 3, 5, 4, 6, 0 };
    sort(nums);
    for(int num:nums){
        cout << num << " ";
    }
}