package 算法.位运算.位运算实现乘法;

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
    public static int bitMul(int a,int b) {
        int sum = 0;
        while(b != 0) {
            if((b & 1) != 0) {
                sum += a;
            }
            a <<= 1;
            b >>>= 1;
        }
        return sum;
    }
    public static void main(String[] args) {
        System.out.println(bitMul(1, 2));
    }
}
