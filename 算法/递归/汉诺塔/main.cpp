#include<bits/stdc++.h>
using namespace std;

void hanoi(int n,char a,char b,char c){
    if(n < 1)return ;
    hanoi(n - 1,a,c,b);
    cout << a << "-->" << c << endl;
    hanoi(n - 1,b,a,c);
}
int main(){
    //请输入n的值,n的值代表盘子的个数
    int n;
    cout << "请输入n的值:" << endl;
    cin >> n;
    hanoi(n,'a','b','c');
    return 0;
}