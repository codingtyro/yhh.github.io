package 算法.排序.希尔排序;

import java.util.Arrays;


/**
 * 希尔排序是插入排序的一种，又称缩小增量排序。是改进版的插入排序
 * 
 * 希尔排序的原理
 * 选定一个增长量h，按照增长量h作为数据分组的依据，对数据进行分组；
 * 对分好组的每一组数据完成插入排序；
 * 减小增长量，最小减为1，重复第二步操作
 */

public class Main {
    public static void main(String[] args) {
 
		int[] arr = { 8, 9, 1, 7, 2, 3, 5, 4, 6, 0 };
 
		System.out.println("排序前");
		System.out.println(Arrays.toString(arr));
 
		shellSort(arr);
 
		System.out.println("排序前");
		System.out.println(Arrays.toString(arr));
 
	}
 
	/***
	 * 当gap=5时：
	 *    1：当i=5时，arr[5]和arr[0]做了比较，这里用的是插入法比较
	 *    2：当i=6时，arr[6]和arr[1]做了比较，这里用的是插入法比较
	 *    3：当i=7时，arr[7]和arr[2]做了比较，这里用的是插入法比较
	 *    .......................
	 * 当gap=2时：
	 * 当gap=1时：
	 * @param arr
	 */
	// 对交换式的希尔排序进行优化->移位法
	public static void shellSort(int[] arr) {
		// 增量gap, 并逐步的缩小增量
		for (int gap = arr.length / 2; gap > 0; gap /= 2) {
			// 从第gap个元素，逐个对其所在的组进行直接插入排序
			for (int i = gap; i < arr.length; i++) {
				int j = i;
				int temp = arr[j];
				if (arr[j] < arr[j - gap]) {
					while (j - gap >= 0 && temp < arr[j - gap]) {
						// 移动
						arr[j] = arr[j - gap];
						j -= gap;
					}
					// temp 比 arr[j - gap] 大，所以需要插入在 j 的位置
					arr[j] = temp;
				}
 
			}
		}
	}
}
