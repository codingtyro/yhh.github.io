package 算法.位运算.位运算实现加法;


class Main{
    public static void main(String[] args) {
        System.out.println(bitAdd(1, 2));
    }

    public static int bitAdd(int a,int b) {
        int sum = 0;
        while(b != 0) {
            sum = a ^ b;
            b = (a & b) << 1;
            a = sum;
        }
        return sum;
    }

}