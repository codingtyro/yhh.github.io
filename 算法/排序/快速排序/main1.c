#include<stdio.h>


void swap(int* x,int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(&q[i], &q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

int main(){
    int nums[] = {1,3,5,6,4,0,2};
    quick_sort(nums,0,6);
    for(int i = 0;i < 7;i++){
        printf("%d ",nums[i]);
    }
    return 0;
}