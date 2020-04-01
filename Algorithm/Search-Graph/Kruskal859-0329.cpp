#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, m;
int p[N];

struct Edge
{
	int a, b, w;
	bool operator< (const Edge& W) const
	{
		return w < W.w;
	}
}edges[N];

/*���鼯�ж�������֮���Ƿ��й�ͬ�����ȣ����Ƿ���ͨ*/
int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		edges[i] = { a, b, w };
	}

	sort(edges, edges + m);

	for (int i = 0; i < m; i++) p[i] = i;
	//res��ʾ��С�����������·���ĳ��ȣ� cnt��ʾ��ǰ�����˶�������
	int res = 0, cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		a = find(a), b = find(b);
		if (a != b)
		{
			p[a] = b;
			res += w;
			cnt++;
		}
	}
	/*����ж����n����֮��ı���С��n-1���������ͼΪ����ͨͼ*/
	if (cnt < n - 1) puts("impossible");
	else printf("%d\n", res);
	return 0;
}