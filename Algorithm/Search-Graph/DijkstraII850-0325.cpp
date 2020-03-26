#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;
typedef pair<int, int> PII;

int n, m;

/*��Ȩ�ص�ͼ���ڽӱ�洢*/
int idx, e[N], w[N], ne[N], h[N];

bool st[N];

/*dist[i]��ʾ��1->i����̾���*/
int dist[N];

/*ͷ�巨*/
void insert(int x, int y, int c)
{
	e[idx] = y;
	w[idx] = c;
	ne[idx] = h[x];
	h[x] = idx++;
}

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;

	/*���ȶ���:С����*/
	priority_queue<PII, vector<PII>, greater<PII>> hq;

	/*��һ��������*/
	hq.push({ 0, 1 });

	while (hq.size())
	{
		auto t = hq.top();
		hq.pop();

		int ver = t.second, distance = t.first;

		//if (st[ver]) continue;y�ܸ��İ汾��д��st[N],��ϸ����һ�´����в�û�жԸ�������в���

		for (int i = h[ver]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				hq.push({ dist[j], j });
			}
		}
	}

	if (dist[n] == 0x3f3f3f) return -1;
	return dist[n];
}

int main()
{
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	while (m--)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		insert(x, y, w);
	}

	printf("%d\n", dijkstra());

	return 0;
}
