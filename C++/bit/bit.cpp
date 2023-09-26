#include<bits/stdc++.h>
using namespace std ;

/*
用法:返回括号内数的二进制表示数末尾0的个数
__builtin_ctz()/ __buitlin_ctzll()

用法:返回括号内数的二进制表示数前导0的个数
__buitlin_clz() / __buitlin_clzll()

返回二进制数中1的个数  
__builtin_popcount()

用法:判断括号中数的二进制表示数1的个数的奇偶性(偶数返回0 , 奇数返回1)
__builtin_parity()

用法:返回括号中数的二进制表示数的最后一个1在第几位(从后往前算)
__builtin_ffs()

用法:快速开平方
__builtin_sqrt()  / __builtin_sqrtf( )
*/

int main(){
    //返回二进制数中1的个数
    cout << __builtin_popcount(15) << endl;
    return 0 ;
}