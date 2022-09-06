package 算法.排序.冒泡排序;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] nums = { 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70 };
        bubble_sort(nums);
        System.out.println(Arrays.toString(nums));
    }
    public static void bubble_sort(int[] nums){
        int n = nums.length;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n - i - 1;j++){
                if(nums[j] > nums[j + 1]){
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }
}
