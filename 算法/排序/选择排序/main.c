#include<stdio.h>

/*
* nums为数组,n为数组的长度
*/
void sort(int* nums,int n){
    for(int i = 0;i < n;i++){
        int mi = i;
        for(int j = i + 1;j < n;j++){
            if(nums[j] < nums[mi]){
                mi = j;
            }
        }
        if(mi != i){
            int temp = nums[i];
            nums[i] = nums[mi];
            nums[mi] = temp;
        }
    }
}

int main(){
    int nums[] = { 8, 9, 1, 7, 2, 3, 5, 4, 6, 0 };
    sort(nums,10);
    for(int i = 0;i < 10;i++){
        printf("%d ",nums[i]);
    }
    return 0;
}