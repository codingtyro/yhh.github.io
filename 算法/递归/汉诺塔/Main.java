package 算法.递归.汉诺塔;

import java.util.Scanner;

class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("请输入n的值:");
        int n = input.nextInt();
        hanio(n, 'a', 'b', 'c');
        input.close();
    }
    /**
     * 
     * @param n：盘子的个数
     * @param a：源柱
     * @param b：舔狗柱
     * @param c：目标柱
     */
    public static void hanio(int n,char a,char b,char c){
        if(n < 1)return ;
        hanio(n - 1, a, c, b);
        System.out.print(a + "-->" + c + "\n");
        hanio(n - 1, b, a, c);
    }
}

