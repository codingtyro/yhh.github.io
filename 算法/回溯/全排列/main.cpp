#include<iostream>

using namespace std;

template<class T>
void perm(T list[],int k,int m){//产生list[k:m]的所有排列
    if(k == m){
        for(int i = 0;i <= m;i++){
            cout << list[i];
        }
        cout << endl;
    }else{
        for(int i = k;i <= m;i++){
            swap(list[k],list[i]);
            perm(list,k + 1,m);
            swap(list[k],list[i]);
        }
    }
} 

template<class T>
void swap(T &a,T &b){
    T temp = a;
    a = b;
    b = temp;
}

int main(){
    int list[3] = {1,2,3};
    perm(list,0,2);
}