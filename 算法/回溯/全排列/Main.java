package 算法.回溯.全排列;

// import java.util.Arrays;

class Main{
    public static void main(String[] args) {
        int[] list = {1,2,3};
        perm(list,0,2);
    }
    public static void perm(int[] list,int k,int m){
        if(k == m){
            for(int i = 0;i <= m;i++){
                System.out.print(list[i]);
            }
            System.out.println();
        }else{
            for(int i = k;i <= m;i++){
                swap(list, k, i);
                perm(list, k + 1, m);
                swap(list, k, i);
            }
        }
    }
    public static void swap(int[] list,int a,int b){//传递过来的a,b是下标。
        int temp = list[a];
        list[a] = list[b];
        list[b] = temp;
    }
}