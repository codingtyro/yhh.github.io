#include<stdio.h>

void swap(int* x,int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
void quick_sort(int* nums,int left,int right){
    if(left >= right){
        return ;
    }
    int mid = nums[right];
    int l = left,r = right - 1;
    while(l < r){
        while(nums[l] < mid && l < r)l++;
        while(nums[r] >= mid && l < r)r--;
        swap(&nums[l],&nums[r]);
    }
    if(nums[l] >= nums[right]){
        swap(&nums[l],&nums[right]);
    }else{
        l++;
    }
    if(l){
        quick_sort(nums,left,l - 1);
    }
    quick_sort(nums,l + 1,right);
}
void sort(int nums[],int len){
    quick_sort(nums, 0 , len - 1);
}

int main(){
    int nums[] = {1,3,5,6,4,0,2};
    sort(nums,7);
    for(int i = 0;i < 7;i++){
        printf("%d ",nums[i]);
    }
    return 0;
}