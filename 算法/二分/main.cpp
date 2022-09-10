/**
 * 
 * 
    版本1
    当我们将区间[l, r]划分成[l, mid]和[mid + 1, r]时，
    其更新操作是r = mid或者l = mid + 1;，计算mid时不需要加1。

    版本2
    当我们将区间[l, r]划分成[l, mid - 1]和[mid, r]时，
    其更新操作是r = mid - 1或者l = mid;，此时为了防止死循环，计算mid时需要加1。

*/

#include<iostream>

using namespace std;


int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}

int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

bool check(int mid){
    /**
     * 暂时这个函数是没有实现的。
    */
    return true;
}

int main(){

}