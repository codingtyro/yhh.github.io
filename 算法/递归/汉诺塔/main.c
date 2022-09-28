#include<stdio.h>


//参数详解
/**
 * n为还有多少个盘从（char a）a柱上移动到（char c）c柱上
 * a为源柱，b为舔狗柱，c为目标柱
 * 
 * 最终的目的，是把a柱上的盘子全移动到c柱上。
*/
void hanio(int n,char a,char b,char c){
    if(n < 1)return ;
    hanio(n - 1,a,c,b);
    printf("%c-->%c\n",a,c);
    hanio(n - 1,b,a,c);
}

int main(){
    int n;
    printf("请输入n的值:\n");
    scanf("%d",&n);
    hanio(n,'a','b','c');
    return 0;
}