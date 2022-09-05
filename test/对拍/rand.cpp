#include<bits/stdc++.h>
using namespace std;
#define random(a,b) ((a)+rand()%((b)-(a)+1))

stringstream ss;

int main( int argc, char *argv[] )
{ 
    int seed=time(NULL);
    if(argc > 1)//如果有参数
    {
        ss.clear();
        ss<<argv[1];
        ss>>seed;//把参数转换成整数赋值给seed
    }
    srand(seed);
    //以上为随机数初始化，请勿修改
    //random(a,b)生成[a,b]的随机整数

    //以下写你自己的数据生成代码 
    // printf("start\n");
    int n=2;
    // 自己想要什么范围，自己改。

    // n代表当前测试这组数据 有多少个，m则代表这组数据的范围。

    int m=random(1,20);
    for(int i=0 ; i<n ; ++i)
    {
        printf("%d ",random(0,m));
    }
    printf("\n");
    return 0;
}
