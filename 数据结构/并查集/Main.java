package 数据结构.并查集;

/**
 * 目前没有想到比较好的实例，先放个模板在这里吧。
 */

public class Main {
    //根据实际结点个数去调整数组的大小。
    int[] p = new int [10005];
    public static void main(String[] args) {
        
    }
    //并查集初始化，一开始，令每个结点的父节点都是自己。
    public void init(int n){//n 是从题目或者场景中得到的。
        for(int i = 0;i < n;i++){
            p[i] = i;
        }
    }
    //寻找根结点
    public int find(int x){
        if(p[x] != x){
            int t = find(p[x]);//寻找祖宗结点
            p[x] = t; //路径压缩
        }
        return p[x];
    }
    
    //合并两个结点。
    public void join(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY){
            p[rootX] = rootY;
        }
    }
    //判断两个结点是有相同的根节点。
    public boolean same(int x,int y){
        return find(x) == find(y);
    }
}
