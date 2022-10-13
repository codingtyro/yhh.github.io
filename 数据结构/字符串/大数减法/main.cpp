#include <iostream>
#include <sstream>
using namespace std;
string Subtraction(string num1,string num2)
{
    //fushu用来判断最后结果是否是负数
    bool fushu = false;
    //如果被减数位数小于减数，那么结果是负数，同时两个字符串交换顺序，大的数减小的数
    if(num1.size()<num2.size())
    {
        string temp = num1;
        num1 = num2;
        num2 = temp;
        fushu = true;
    }
    //两个数长度一样，这个时候，需要判断哪个数更大，如果被减数小于减数，那么结果是负数，同时两个字符串交换顺序，大的数减小的数
    else if(num1.size() == num2.size())
    {
        int len = num1.size();
        for(int i=0;i<len;++i)
        {
            if(num1[i] == num2[i])
                continue;
            if(num1[i]>num2[i])
                break;
            if(num1[i]<num2[i])
            {
                string temp = num1;
                num1 = num2;
                num2 = temp;
                fushu = true;
            }
        }
    }
    int lenNum1 = num1.size();
    int lenNum2 = num2.size();

    //用来保存结果
    int* result = new int[lenNum1];
    int index = 0;
    //num1 31 num2 29 result 1,3
    //把被除数的结果先放到result中
    for(int i=lenNum1-1;i >=0;--i)
        result[index++]=num1[i]-'0';

    //进行减法操作
    index = 0;
    for(int i=lenNum2-1;i>=0;--i)
    {
        int num = num2[i]-'0';
        //如果减数 大于 被减数，则需要退位
        if(num>result[index])
        {
            result[index+1] -=1;
            result[index] = 10+result[index] - num;
        }
        //直接相减
        else
            result[index] = result[index] - num;

        ++index;
    }
    //清除result尾部的0,index从右到左遍历，直到第一个不是0为止
    index = lenNum1-1;
    while(result[index] == 0)
        --index;


    //使用stringstream流，方便把数组输出到字符串中
    ostringstream osstr;
    //判断是否结果是负数
    if(fushu == true)
        osstr<<'-';
    for(int i=index;i>=0;--i)
        osstr<<result[i];
    delete result;
    return osstr.str();
}
int main()
{

    string num1,num2;
    cin>>num1>>num2;
    cout<<Subtraction(num1,num2)<<endl;
    return 0;
}