//欧拉筛
//快速筛选出一定上限内的素数
#include<bits/stdc++.h>
using namespace std;
bool isPrime[100000010];
int Prime[6000010],cnt=0;
//Prime存质数，isPrime[i]==1表示是i是素数
void GetPrime(int n)
{
    memset(isPrime,1,sizeof(isPrime));
    isPrime[1]=0;//1不是素数
    for(int i=2;i<=n;i++)
    {
        if(isPrime[i])
            Prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*Prime[j]<=n;j++)
        {
            isPrime[i*Prime[j]]=0;
            if(i%Prime[j]==0)
                break;
        }
    }
}
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    GetPrime(n);
    while(q--)
    {
        int k;
        scanf("%d",&k);
        printf("%d\n",Prime[k]);
    }
    system("pause");
}
