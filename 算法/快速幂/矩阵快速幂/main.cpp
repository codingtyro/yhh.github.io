#include<bits/stdc++.h> //万能头 
using namespace std;//namespace  
typedef long long ll;//定义ll 为long long  方便使用 
#define N 111//最大数 
const int M  = 1e9+7;//Mod 需要模这个数 
#define mod(x) ((x)%M )//定义 mod的函数 
int n ;
struct mat{
	ll m[N][N];
}unit;//矩阵结构体 以及单位矩阵unit (主对角为1其余为0)
mat operator  * (mat a,mat b){ //重载operator 乘法  
	mat ret ;
	ll val,i,j;
	for(i =  0 ; i < n ; i++)
	{
		for(j= 0 ; j < n ; j++){
			val = 0;
			for(int k = 0 ; k < n;k++){
				val+= mod((ll)a.m[i][k]*b.m[k][j]);  //三个循环是求矩阵乘法 mod一下 
			}
			ret.m[i][j] = mod(val);//也需要mod 一下 都是为了防止数太大 
		}
		
	}
	return ret;//返回 俩个矩阵乘法的结果 
}
void init(){
	for(int i = 0 ; i < N ;i++){
		unit.m[i][i] = 1;
	} //init 单位矩阵 
}
mat quick_pow(mat  a, ll n){//快速矩阵幂  
	mat res = unit ;
	while(n){
		if(n&1)	res=res*a;
		a =  a*a;
		n>>=1;
	}
	return res;
}
int main(){ 
	cin >> n ;
	init();
	mat a,b;	
	cout<<"开始输入方阵："<<endl;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j <n ;j++){
			cin>>a.m[i][j];
		}
	}
	//写入 矩阵  
	mat ans  =	quick_pow(a,2);  //调用快速矩阵  2是幂 
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j <n ;j++){
			cout<<ans.m[i][j]<<"  ";
		}
		cout<<endl;
	}//输出结果 
	return 0;
}