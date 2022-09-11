package 算法.排序.桶排序;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * 算法实现：
 * 1.找出待排序数组中的最大值和最小值
 * 使用动态数组作为桶，桶的数量为（max - min） / nums.length + 1;
 * 遍历数组，将数组中的值分配到各个桶
 * 每个桶各自排序
 * 遍历桶数组，将排好序的元素放入输出数组。
 */

/**
 * 总结：划分多个相同的区域，每个区间各自排序，再合并
 * 当元素比较集中的时候，桶排序失效。
 */

public class Main {
    public static void main(String[] args) {
        int[] nums = new int[] {11,18,28,45,23,50};
        bucketSort(nums);
        System.out.println(Arrays.toString(nums));
    }

    /**
     * 桶排序
     * @param nums
     */
    public static void bucketSort(int[] nums){
        //遍历数组，找到数组中的最大值、最小值
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        for(int num : nums){
            max = Math.max(max,num);
            min = Math.min(min,num);
        }


        //计算桶的数量
        int bucketNum = (max - min) / nums.length + 1;

        //遍历数组，外层循环从桶的第一位开始
        List<List<Integer>> bucketArr = new ArrayList<>();

        for(int i = 0;i < bucketNum;i++){
            bucketArr.add(new ArrayList<>());
        }

        //将每个元素放入桶中
        for(int i = 0;i < nums.length;i++){
            int num = (nums[i] - min) / (nums.length);
            bucketArr.get(num).add(nums[i]);
        }

        //对每个桶排序
        for(int i = 0;i < bucketArr.size();i++){
            Collections.sort(bucketArr.get(i));
        }
        int index = 0;
        for(int i = 0;i < bucketArr.size();i++){
            for(int j = 0;j < bucketArr.get(i).size();j++){
                nums[index++] = bucketArr.get(i).get(j);
            }
        }
    }
}
