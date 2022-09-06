#include<iostream>
#include<vector>

using namespace std;

void bubble_sort(vector<int>& nums){
    int n = nums.size();
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n - i - 1;j++){
            if(nums[j] > nums[j + 1])swap(nums[j],nums[j + 1]);
        }
    }
}

int main(){
    vector<int>nums = { 22, 34, 2, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
    bubble_sort(nums);
    for(int i = 0;i < nums.size();i++){
        cout << nums[i] << " ";
    }
    return 0;
}