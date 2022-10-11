#include<bits/stdc++.h>
using namespace std;

    /**
     * 二维前缀和
     *
     * @param src 原数组
     * @return 二维前缀和
     */
     const int maxn = 100;
     int prefixSum[maxn][maxn];
    void twoDimen(int a[][], int n, int m) {//n和m分别代表二维原始数组的行列长度
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {//第0个，最左上角
                    prefixSum[i][j] = a[i][j];
                } else if (i == 0) {//第一行，最顶部一行
                    prefixSum[i][j] = prefixSum[i][j - 1] + a[i][j];
                } else if (j == 0) {//第一列，最左边一列
                    prefixSum[i][j] = prefixSum[i - 1][j] + a[i][j];
                } else {//其他
                    prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] + a[i][j] - prefixSum[i - 1][j - 1];
                }
            }
        }
    }

