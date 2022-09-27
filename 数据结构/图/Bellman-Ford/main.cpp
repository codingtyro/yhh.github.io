#include <iostream>
#include <cstring>
using namespace std;
const int N=510,M=1e4+10,INF=0x3f3f3f3f;
struct Edge{
    int u,v,w;
}edges[M];
int d[N],backup[N];
int n,m,k;
int Bellman_ford(){
    memset(d,0x3f,sizeof d);
    d[1]=0;
    for(int i=0;i<k;i++){
        memcpy(backup,d,sizeof d);//备份数组
        for(int j=0;j<m;j++){
            int u=edges[j].u,v=edges[j].v,w=edges[j].w;
            d[v]=min(d[v],backup[u]+w);
        }
    }
    if(d[n]>INF/2) return -1;
    /*
    此处不能写d[n]==INF
    */
    return d[n];
}
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges[i]={u,v,w};
    }
    int t=Bellman_ford();
    if(t==-1) puts("impossible");
    else printf("%d",t);
    return 0;
}