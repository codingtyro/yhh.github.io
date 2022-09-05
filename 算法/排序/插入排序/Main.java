package 算法.排序.插入排序;

import java.util.Arrays;

/**
 * 基本思想：每一趟将一个待排序的记录，
 * 按其关键字的大小插入到已经排好序的一组记录的适当位置上，
 * 直到全部待排序记录全部插入为止。
 */

public class Main {
    public static void main(String[] args) {
        int[] nums = {1,4,5,2,3};
        insertSort(nums);
        System.out.println(Arrays.toString(nums));
    }
    public static void insertSort(int[] nums){
        int length = nums.length;
        for(int i = 1;i < length;i++){
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
}
