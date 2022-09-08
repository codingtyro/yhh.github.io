#include <bits/stdc++.h>
using namespace std;
// N 为数据个数，MAX 为数据上限 
const int N = 1e4, MAX = 1e5 + 1;

int main(void)
{
	// 设置 cout printf 这些输出流都输出到 test.in 里面去
    freopen("test.in", "w", stdout);
    // 随机生成 N 个数
    for (int i = 0; i < N; i++)
		// 数据的范围在 [0, MAX-1] 之间
    	printf("%d\n", rand() % MAX);
    
    // 关闭输出流
    fclose(stdout);
    
    return 0;
}
