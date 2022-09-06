#include<stdio.h>

void bubble_sort(int* nums, int len) {
        for(int i = 0;i < len;i++){
            for(int j = 0;j < len - i - 1;j++){
                if(nums[j] > nums[j + 1]){
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
}

int main() {
        int arr[] = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
        int len = (int) sizeof(arr) / sizeof(*arr);
        bubble_sort(arr, len);
        for (int i = 0; i < len; i++)
                printf("%d ", arr[i]);
        return 0;
}