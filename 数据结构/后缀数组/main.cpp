#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
char s[maxn];
int x[maxn],y[maxn],c[maxn],sa[maxn],rk[maxn],height[maxn],n,m;
void get_sa()
{
	for(int i=1;i<=n;i++)	++c[x[i]=s[i]];//初始第一关键字就是自己
	for(int i=2;i<=m;i++)	c[i] += c[i-1];//得到每个关键字的最后一名
	for(int i=n;i>=1;i--)	sa[c[x[i]]--] = i;//排名为c[x[i]]的是i
	for(int k=1;k<=n;k<<=1)//k是第一,二关键字的步长 
	{
		int num = 0;
		for(int i=n-k+1;i<=n;i++)	y[++num] = i;
		//y表示第二关键字排名为num的数第一关键字的位置 
		//[n-k+1,n]是没有第二关键字的,排名在最前面 
		for(int i=1;i<=n;i++)	if( sa[i]>k )	y[++num] = sa[i]-k;
		//上一次排名为i的数,如果下标大于k,那么这次可以作为下标为i-k的第二关键字
		for(int i=1;i<=m;i++)	c[i] = 0;
		for(int i=1;i<=n;i++)	++c[x[i]];//上一次循环算出来的第一关键字,直接加
		for(int i=2;i<=m;i++)	c[i] += c[i-1]; 
		for(int i=n;i>=1;i--)	sa[c[x[y[i]]]--] = y[i], y[i] = 0;
		//x[y[i]]表示的是第二关键字排民为i的第一关键字是什么,那么c[]--就是计算排名
		swap(x,y);
		x[sa[1]] = 1, num = 1;//根据y生成下一次的x
		for(int i=2;i<=n;i++)
			x[sa[i]] = ( y[sa[i]]==y[sa[i-1]] && y[sa[i]+k]==y[sa[i-1]+k] )?num:++num; 
		//意思是,只有当第一关键字和第二关键字都相等是,下一次的第一关键字排名才和本次相等	
		if( num==n )	break;
		m = num;//只有这么多种类型 
	}
	for(int i=1;i<=n;i++)	printf("%d ",sa[i] ); 
}
int main()
{
	scanf("%s",s+1);
	n = strlen( s+1 ); m = 122;
	get_sa();	
} 
