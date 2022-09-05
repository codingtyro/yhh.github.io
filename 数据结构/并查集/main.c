#include<stdio.h>
//bool的头文件，可能是当前我的C/C++版本比较低
#include<stdbool.h>

//应该根据实际节点的个数去调整P数组的大小
int p[10005] = {0};

//并查集初始化，一开始，令每个结点的父节点都是自己。
    void init(int n){
        for(int i = 0;i < n;i++){//n 是从题目或者场景中得到的。
            p[i] = i;
        }
    }
    //寻找根结点
    int find(int x){
        if(p[x] != x){
            int t = find(p[x]);//寻找祖宗结点
            p[x] = t; //路径压缩
        }
        return p[x];
    }
    
    //合并两个结点。
    void join(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY){
            p[rootX] = rootY;
        }
    }
    //判断两个结点是有相同的根节点。
    bool same(int x,int y){
        return find(x) == find(y);
    }

    int main(){
        return 0;
    }