#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;

/*�ڽӾ���洢ͼ*/
int g[N][N];

/*dist[N]���ϱ�ʾ��ǰ�Ѿ�����ͨ������е�*/
int dist[N];
bool st[N];

int prim()
{
	memset(dist, 0x3f, sizeof dist);

	/*��ǰ�����·����*/
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		/*�������нڵ㵽��"����"�о�����̵ĵ�
		����ļ�����ָ��ǰ�Ѿ�����ͨ���е����е�
		*/
		for (int j = 1; j <= n; j++)
		{
			if (st[j] == false && (t == -1 || dist[t] > dist[j]))
				t = j;
		}
		/*�������һ���ڵ㵽"����"�ľ���ΪINF�����ͼΪ����ͨͼ*/
		if (i && dist[t] == INF) return INF;
		if (i) res += dist[t];

		/*��ʱt�ǵ����Ͼ�����̵ĵ㣬������tΪ���������dist����*/
		for (int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);

		st[t] = true;
	}
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	memset(g, 0x3f, sizeof g);

	while (m--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a][b] = g[b][a] = min(g[a][b], c);
	}
	int t = prim();
	if (t == INF) puts("impossible");
	else printf("%d\n", t);
	return 0;
}