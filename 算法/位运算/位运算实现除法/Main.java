package 算法.位运算.位运算实现除法;

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
    public static int negNum(int n) {
        //转化为相反数
        return bitAdd(~n,1);
    }
    public static int minus(int a,int b) {
        //实现两个数相减
        return bitAdd(a,negNum(b));
    }
    public static boolean isNeg(int n) {
        //判断是否为负数
        return n < 0;
    }
    public static int bitDiv(int a,int b) {
        int x = isNeg(a) ? negNum(a) : a;
        int y = isNeg(b) ? negNum(b) : b;
        int res = 0;
        for (int i = 30; i >= 0 ; i = minus(i,1)) {
            if((x >> i) >= y) {
                res |= (1 << i);
                x = minus(x,y << i);
            }
        }
        return isNeg(a) != isNeg(b) ? negNum(res) : res;

    }
    public static void main(String[] args) {
        System.out.println(bitDiv(7, 2));
    }
}
