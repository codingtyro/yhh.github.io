package 算法.排序.选择排序;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] arr = { 8, 9, 1, 7, 2, 3, 5, 4, 6, 0 };
        sort(arr);
        System.out.println(Arrays.toString(arr));
    }

    public static void sort(int arr[])
   {
       for(int i=0;i<arr.length;i++){
           int min = i;//最小元素的下标
           for(int j=i+1;j<arr.length;j++){
               if(arr[j] < arr[min]){
                   min = j;//找最小值
               }
           }
           //交换位置
           int temp = arr[i];
           arr[i] = arr[min];
           arr[min] = temp;
       }
   }
}
