/**
 * 生活不是为了赶路，而是为了感受路。“求不得”是常态，“不圆满”是生活，
 * 所求非所得，未必是遗憾，也许会以另一种方式得以实现。
 * 我们穷极一生追求的幸福，不过是当下的眼中景，碗中餐，身边人。
 */


#include<stdio.h>
#include<string.h>

int a[10005];
int c[10005];
int n;

int lowbit(int x){
    return x&(-x);
}

int getSum(int x){
    int ans = 0;
    while(x > 0){
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}

void update(int x, int value){
    a[x] += value;
    while(x <= n){
        c[x] += value;
        x += lowbit(x);
    }
}

int main(){
    while(scanf("%d", &n)!=EOF){
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            update(i, a[i]);
        }
        int ans = getSum(n-1);
        printf("%d\n", ans);
    }   
    return 0;
} 
