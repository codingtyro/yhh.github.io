/**
 * 用数组模拟队列
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1000000+10;
int a[N];
int q[N];
int n,k;
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    // 第一行输出，从左至右，每个位置滑动窗口中的最小值
    int hh=0,tt=-1;//hh栈头，tt栈尾
    for(int i=0;i<n;i++)
    {
        if(hh<=tt&&i-k+1>q[hh])hh++;          // 若队首出窗口，hh加1，弹出队首
        
        while(hh<=tt&&a[q[tt]]>=a[i])tt--;    // 若队尾不单调递增，tt减1，弹出队尾
        
        q[++tt]=i;                            // 下标加到队尾
        if(i>=k-1)printf("%d ",a[q[hh]]);     // 输出结果
    }
    printf("\n");
    
    
    
    
    
    hh=0,tt=-1;
    for(int i=0;i<n;i++)
    {
        if(hh<=tt&&i-k+1>q[hh])hh++; 
        //第二行输出，从左至右，每个位置滑动窗口中的最大值
        while(hh<=tt&&a[q[tt]]<=a[i])tt--;
        q[++tt]=i;
        if(i>=k-1)printf("%d ",a[q[hh]]);
    }
    printf("\n");
    
    
    
}
