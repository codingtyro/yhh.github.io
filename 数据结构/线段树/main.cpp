#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
 
int n , L , R , ans , m ;
 
struct node{
    int l , r ;
    bool  cv;
};
 
node Tree[1600005];
 
void build( int i , int l , int r )
{
    int mid = ( l + r ) / 2 ;
    Tree[i].l = l ;
    Tree[i].r = r ;
    Tree[i].cv = 0 ;
    if( l == r )
        return ;
    build( i * 2 , l , mid );
    build( i * 2 + 1 , mid + 1 , r );
}
 
void iinsert(int i , int  l , int r )
{
    if( r < Tree[i].l || l > Tree[i].r )
        return ;
    if( l <= Tree[i].l && r >= Tree[i].r )
    {
        Tree[i].cv = 1;
        return ;
    }
    iinsert( 2 * i , l , r );
    iinsert( 2 * i + 1 , l , r );
}
 
int sum(int i)
{
    if(Tree[i].cv == 1 )
        return Tree[i].r - Tree[i].l + 1 ;
    else
    {
        if( Tree[i].l == Tree[i].r )
            return 0;
        else
        {
            return sum(i * 2) + sum(i * 2 + 1); 
        }
    }
}
 
int main()
{
    scanf("%d%d%d", &L , &R , &n );
    if( L < 0 )
        m = - L ;
    L += m ;
    R += m ;
    build( 1 , L , R - 1 );
    for(int i = 1 ; i <= n ; ++ i)
    {
        int ll , rr;
        scanf("%d%d", &ll , &rr );
        ll += m ;
        rr += m ;
        iinsert( 1 , ll , rr - 1  );
    }
    ans = sum(1);
    printf("%d", ans );
}