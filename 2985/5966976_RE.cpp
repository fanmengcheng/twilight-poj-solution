/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : The k-th Largest Group
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=2985
*       ID             : 2985
*       Date           : 10/7/2009
*       Time           : 10:18:26
*       Computer Name  : EVERLASTING-AMD
*		Wizard Version : 20090522P
*******************************************************************************/
#include<iostream>
#include<string>
#include<math.h>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

#define MAXN 300001

int n,m,l,r,mid,k,op;
int C[MAXN],p[MAXN],cnt[MAXN];

inline int LowBit(int x)
{
	return x&(-x);
}

void Modify(int i,int delta)
{
	while(i<=n)
	{
		C[i]+=delta;
		i+=LowBit(i);
	}
}

int Sum(int i)
{
	int res=0;
	while(i>0)
	{
		res+=C[i];
		i-=LowBit(i);
	}
	return res;
}

int FindSet(int x)
{
	int r=x,t;
	while (r!=p[r])
	{
		r=p[r];
	}
	while (r!=x)
	{
		t=p[x];
		p[x]=r;
		x=t;
	}
	return r;
}

inline void Union(int x,int y)
{
	p[x]=y;
}

inline void Link(int x,int y)
{
	Union(FindSet(x),FindSet(y));
}

bool Check(int mid)
{
	return Sum(mid)>=n-k+1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_2985.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	memset(C,0,sizeof(C));
	Modify(1,n);
	for(int i=1;i<=n;++i)
	{
		p[i]=i;
		cnt[i]=1;
	}
	while(m--)
	{
		scanf("%d",&op);
		if(op==0)
		{
			int u,v,fu,fv;
			scanf("%d%d",&u,&v);
			fu=FindSet(u);
			fv=FindSet(v);
			Union(fu,fv);
			Modify(cnt[fu],-1);
			Modify(cnt[fv],-1);
			cnt[fv]+=cnt[fu];
			Modify(cnt[fv],1);
			n--;
		}
		else
		{
			scanf("%d",&k);
			l=1;
			r=n;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if(Check(mid))
				{
					r=mid-1;
				}
				else
				{
					l=mid+1;
				}
			}
			printf("%d\n",l);
		}
	}
	return 0;
}
