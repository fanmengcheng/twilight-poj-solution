/*******************************************************************************
*       Online Judge   : POJ
*       Problem Title  : Drainage Ditches
*		Problem URL    : http://acm.pku.edu.cn/JudgeOnline/problem?id=1273
*       ID             : 1273_SAP
*       Date           : 6/24/2009
*       Time           : 10:57:37
*       Computer Name  : EVERLASTING-PC
*		Wizard Version : 20090522P
*******************************************************************************/
#include <iostream>
bool flag;
long his[1025],pre[1025],dis[1025],vh[1025],di[1025],map[1025][1025],jl,min,flow,aug,j,m,n,tmp,a,b,c,i;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in_1273_SAP.txt","r",stdin);
#endif
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		memset(map,0,sizeof(map));
		memset(pre,0,sizeof(pre));
		memset(dis,0,sizeof(dis));
		memset(vh,0,sizeof(vh));
		memset(di,0,sizeof(di));
		flow=0;
		for (i=1;i<=m;i++) {scanf("%d%d%d",&a,&b,&c);map[a][b]+=c;}
		vh[0]=n;
		for (i=1;i<=n;i++) di[i]=1;
		i=1;
		aug=1<<30;
		while (dis[1]<n)
		{
			his[i]=aug;
			flag=false;
			for (j=di[i];j<=n;j++)
			{
				if ((map[i][j]>0)&&(dis[j]+1==dis[i]))
				{
					flag=true;
					di[i]=j;
					if (map[i][j]<aug) aug=map[i][j];
					pre[j]=i;
					i=j;
					if (i==n)
					{
						flow+=aug;
						while (i!=1)
						{
							tmp=i;
							i=pre[i];
							map[i][tmp]-=aug;
							map[tmp][i]+=aug; 
						} 
						aug=1<<30; 
					}
					break;
				}
			}
			if (flag) continue;
			min=n-1;
			for (j=1;j<=n;j++) {if ((map[i][j]>0)&&(dis[j]<min)) {jl=j;min=dis[j];}}
			di[i]=jl;
			vh[dis[i]]--;
			if (vh[dis[i]]==0) break;
			dis[i]=min+1;
			vh[dis[i]]++;
			if (i!=1) {i=pre[i];aug=his[i];}
		}
		printf("%d\n",flow);
	}
	return 0;
} 