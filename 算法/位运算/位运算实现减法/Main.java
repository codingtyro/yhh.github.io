package 算法.位运算.位运算实现减法;

public class Main {
    public static int bitAdd(int a,int b) {
        int sum = 0;
        while(b != 0) {
            sum = a ^ b;
            b = (a & b) << 1;
            a = sum;
        }
        return sum;
    }

    public static int bitSub(int a,int b) {
        return bitAdd(a,~b+1);
    }
    public static void main(String[] args) {
        System.out.println(bitSub(1, 2));
    }
}
