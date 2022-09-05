#include<stdio.h>

//nums为数组，n为数组的长度
void insertSort(int* nums,int n){
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
    int nums[] = {1,4,2,5,3};
    insertSort(nums,5);
}