/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Candies
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=3159
*       ID             : 3159
*       Date           : 9/10/2009
*       Time           : 10:20:13
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<list>
#include<stack>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

#define MAXN 30001
#define INF 0x7fffffff

struct QNode
{
	int v,d;
	int next;
};

int lin1[MAXN];
QNode e[2*MAXN];

bool inq[MAXN];
int dis[MAXN];

queue<int> q;

int n,m,t,cnt;

int SPFA(int lin[])
{
	for(int i=1;i<=n;++i)
	{
		dis[i]=INF;
	}
	memset(inq,false,sizeof(inq));
	dis[1]=0;
	inq[1]=true;
	q.push(1);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		inq[u]=false;
		for(int i=lin[u];i!=-1;i=e[i].next)
		{
			int &v=e[i].v;
			int &d=e[i].d;
			if(dis[v]>dis[u]+d)
			{
				dis[v]=dis[u]+d;
				if(!inq[v])
				{
					inq[v]=true;
					q.push(v);
				}
			}
		}
	}
	return dis[n];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_3159.txt","r",stdin);
#endif

	scanf("%d%d",&n,&m);
	memset(lin1,-1,sizeof(lin1));
	cnt=0;
	while(m--)
	{
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		e[cnt].next=lin1[u];
		e[cnt].d=d;
		e[cnt].v=v;
		lin1[u]=cnt;
		cnt++;
	}
	printf("%d\n",SPFA(lin1));

	return 0;
}
