package 算法.递归.阶乘;

public class Main {
    public  static int factorial(int n){
        if(n == 0)return 1;
        return factorial(n - 1) * n;
    }
    public static void main(String[] args) {
        System.out.println(factorial(3));
    }
}
