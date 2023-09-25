#include <bits/stdc++.h>
using namespace std;

/*
GCD 最大公约数 (logn)
gcd(a,0) = a;
gcd (a,b) = gcd(b,a%b)

lcm(a,b) = abs(a*b)/gcd(a,b)

*/

//gcd  
//gcd(a,0)=a;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}

int lcm(int a,int b){
    return abs(a * b)/gcd(a,b);
}