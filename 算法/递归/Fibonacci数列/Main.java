package 算法.递归.Fibonacci数列;

/*
 * 无穷数列1,1,2,3,5,8,13,21,34.....被称为Fibonacci数列。
 */

public class Main {
    public int fibonacci(int n){
        if(n <= 1){
            return 1;
        }
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
