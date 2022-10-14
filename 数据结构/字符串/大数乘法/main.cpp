#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

// 按结果的每一位进行计算
std::string multiplyTwoStrings(const std::string & s1, const std::string& s2) {
    int len1 = s1.length();
    int len2 = s2.length();
    int sum = 0;
    std::string res;
    for (int k = 0; k < len1 + len2; ++k) {  // 最终乘积的结果最大长度为 len1 + len2 ，分别计算每一位
        // 第 k 位 应该为 s1 的第 0 位乘以 s2 的第 k - 0 位加上
        //               s1 的第 1 位乘以 s2 的第 k - 1 位加上
        //               s1 的第 i 位乘以 s2 的第 k - i 位 ......
        for (int i = 0; i <= k; ++i) {       
            if (i < len1 & k - i < len2) {
                sum += (s1[len1 - i -1] - '0') * (s2[len2 - 1 - k + i] - '0');
            }
        }
        // 上面所得的结果是逆序的，即第 len1 + len2 位为低位（个位），所以在插入字符串时是往前插
        res.insert(0, 1, sum % 10 + '0');  
        sum /= 10;
    }
    return res[0] == '0' ? &res[1] : res;
}

// 按过程的每一位进行计算
std::string multiply(const std::string& s1, const std::string& s2) {
    if (s1.empty() || s2.empty()) {
        return "0";
    }
    int lenOfs1 = s1.length();
    int lenOfs2 = s2.length();
    // res 用于存储中间的计算值，是最终结果的逆序存储，即数字的高位存在 vector 的前面
    std::vector<int> res(lenOfs1 + lenOfs2, 0);
    
    int idxOfs1 = 0, idxOfs2 = 0;  // 用于标记 s1 中的哪一位与 s2 中的哪一位乘
    for (int i = lenOfs1 - 1; i >=0; --i) {
        int carry = 0;
        int num1 = s1[i] - '0';
        idxOfs2 = 0;
        for (int j = lenOfs2 - 1; j >= 0; --j) {
            int num2 = s2[j] - '0';
            int sum = num1 * num2 + carry + res[idxOfs1 + idxOfs2];  // multiply of two numbers & carry & number pre cacl
            res[idxOfs1 + idxOfs2] = sum % 10;  // 对应位的乘积会保存到对应位置
            carry = sum / 10;
            idxOfs2++;
        }

        if (carry > 0) {
            res[idxOfs1 + idxOfs2] += carry;
        }

        idxOfs1++;
    }

    auto it = std::find_if(res.rbegin(), res.rend(), [](int& x){ return x != 0; });  // 去掉前置 0，即找到逆序数组中后面第一个不为 0 的位置，例如 12 * 34 得到的 vector 为 8040，则 it 指向 4 的位置
    std::string s;
    std::for_each(it, res.rend(), [&](int x) { s += std::to_string(x); });  // 反向将数字插入到字符中
    return s;
}

int main() {
    std::string s1 ;
    std::string s2 ;
    std::cin >> s1 ;
    std::cin >> s2;
    bool nflag1 = s1[0] == '-';
    bool nflag2 = s2[0] == '-';
    std::string res = (nflag1 ^ nflag2) ? "-" : "";  // 符号处理，异或用于简便检测结果的正负，
    res += multiplyTwoStrings(nflag1 ? s1.substr(1): s1, nflag2 ? s2.substr(1) : s2);  // 传入字符串时只传入数字部分
    std::cout << "(" << s1 << ") * (" << s2 << ") = " << res << '\n';
    res = (nflag1 ^ nflag2) ? "-" : "";
    res += multiply(nflag1 ? s1.substr(1): s1, nflag2 ? s2.substr(1) : s2);
    std::cout << "(" << s1 << ") * (" << s2 << ") = " << res << '\n';
    return 0;
}
