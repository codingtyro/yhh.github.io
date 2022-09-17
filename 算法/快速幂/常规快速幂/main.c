#include<stdio.h>

int fastpow (int base,int pow) {
	int ans = 1;
	while(pow) {
		if(pow&1)//此处等价于if(power%2==1)
			ans *= base;
		 pow >>= 1;//此处等价于pow=pow/2
         base = base * base;
	}
	return ans;
}


int main(){
    printf("%d\n",fastpow(2,10));
    return 0;
}