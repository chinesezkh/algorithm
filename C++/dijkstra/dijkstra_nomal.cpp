/*
1.声明dis[],vis[],f[][]，dis用于记录从起点到i的最短路,vis标记是否用过,f用于存储前驱到后驱的权值
2.初始化dis[]为无穷大（INF）以及dis[起点]=0,用变量t=-1来表示距离起点最近且未标记的点
如果dist[j]<dist[t]，说明找到了距离起点更近的点，更新t，然后标记vis[t]
3. 比较距离找出最小的dis[]
*/
#include <bits/stdc++.h>
#define MOD 10000000007
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
LL dis[10005],vis[10005],f[10001][10001];//dis用于记录从起点到i的最短路,vis标记是否用过,f用于存储前驱到后驱的权值
 
//快读读入数值
inline int read() {
	int date=0,w=1;//date存数，w存符号
	char c;
	c=getchar();
	while(c<'0' || c>'9') {
		if(c=='-') w=-1;
		c=getchar();
	}
	while(c>='0' && c<='9') {
		date=date*10+(c-'0');
		c=getchar();	
	}
	return date*w;
}
 
 
void dijkstra(int s,int n) {
	//初始化
	memset(dis,INF,sizeof(dis));
	dis[s]=0;//起点到自己当然是0
	for(int i=1; i<=n; i++) {
		int t=-1;//用于找第一个未被标记的点
		for(int j=1; j<=n; j++)
			if(!vis[j] && (t==-1 || dis[j]<dis[t])) t=j;//未标记或找到更近的
		vis[t]=1;//标记，防止再次计算
		for(int j=1; j<=n; j++) {
			dis[j] = min(dis[j],dis[t]+f[t][j]);
		}
	}
}
 
int main() {
    int n,m,s,u,v,w;//n是顶点数，m是边数，s是起点
	memset(f,INF,sizeof(f));//初始化到无穷（求最短路）
	cin >> n >> m >> s;
	for(int i=1; i<=m; i++) {
		cin >> u >> v >> w;
		f[u][v]=w;//从u到v的花费为w
	}
 
	dijkstra(s,n);
 
	for(int i=1; i<=n; i++)
		cout<<dis[i]<<" ";
	return 0;
}