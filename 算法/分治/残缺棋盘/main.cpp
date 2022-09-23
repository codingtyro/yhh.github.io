#include<iostream>
using namespace std;
int count=0;
int size=1;
int Board[8][8];
int main(){
	void Cover(int tr,int tc,int dr,int dc,int size);//填充棋盘的函数 
	void OutputBoard(int size);
	int x,y;
	int i;
	int k;
	//输入棋盘规模
	cout<<"请确认棋盘规模，输入k大小（2k×2k）:"<<endl ;
	cin>>k;
	for(i=1;i<=k;i++) size=size*2;
	cout<<"请输入残缺棋子位置（行号，列号）:"<<endl;
	cin>>x>>y;
	Cover(0,0,x,y,size);
	OutputBoard(size); 	
} 
	void Cover(int tr,int tc,int dr,int dc,int size){
		if(size<2) return;
		int t=count++;
		int s=size/2;
		//如果残缺在左上角
		if(dr<tr+s&&dc<tc+s){
			Cover(tr,tc,dr,dc,s);
			Board[tr+s-1][tc+s]=t;
			Board[tr+s][tc+s-1]=t;
			Board[tr+s][tc+s]=t;
			//返回，填充其他部分 
			Cover(tr,tc+s,tr+s-1,tc+s,s);
			Cover(tr+s,tc,tr+s,tc+s-1,s);
			Cover(tr+s,tc+s,tr+s,tc+s,s);
		}
		//右上角 
		else if(dr<tr+s&&dc>=tc+s) {
			Cover(tr,tc+s,dr,dc,s);
			Board[tr+s-1][tc+s-1]=t;
			Board[tr+s][tc+s-1]=t;
			Board[tr+s][tc+s]=t;
			//返回，填充其他部分 
			Cover(tr,tc,tr+s-1,tc+s-1,s);
			Cover(tr+s,tc,tr+s,tc+s-1,s);
			Cover(tr+s,tc+s,tr+s,tc+s,s);
		}
		else if(dr>=tr+s&&dc<tc+s){
			Cover(tr+s,tc,dr,dc,s);
			Board[tr+s-1][tc+s-1]=t;
			Board[tr+s-1][tc+s]=t;
			Board[tr+s][tc+s]=t;
			//返回，填充其他部分 
			Cover(tr,tc,tr+s-1,tc+s-1,s);
			Cover(tr,tc+s,tr+s-1,tc+s,s);
			Cover(tr+s,tc+s,tr+s,tc+s,s);
		}
		else if(dr>=tr+s&&dc>=tc+s){
			Cover(tr+s,tc+s,dr,dc,s);
			Board[tr+s-1][tc+s-1]=t;
			Board[tr+s-1][tc+s]=t;
			Board[tr+s][tc+s-1]=t;
			//返回，填充其他部分 
			Cover(tr,tc,tr+s-1,tc+s-1,s);
			Cover(tr,tc+s,tr+s-1,tc+s,s);
			Cover(tr+s,tc,tr+s,tc+s-1,s);
		}
		
}
void OutputBoard(int size){//输出棋盘的内容
			for(int i=0;i<size;i++){
				for(int j=0;j<size;j++){
					cout<<Board[i][j];
					
				}
				cout<<endl;
			}
		}
	
