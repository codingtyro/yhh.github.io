#include<iostream>
#include<vector>

using namespace std;

//nums为数组
void insertSort(vector<int>& nums){
    int n = nums.size();
    for(int i = 1;i < n;i++){
        int j;
        if(nums[i] < nums[i - 1]){
            int temp = nums[i];
            for(j = i - 1;j >= 0 && temp < nums[j];j--){
                nums[j + 1] = nums[j];
            }
            nums[j + 1] = temp;
        }
    }
}

int main(){
    vector<int> nums= {1,4,2,5,3};
    insertSort(nums);
    return 0;
}