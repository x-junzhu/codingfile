#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;

/*��Ȩ�ص�ͼ���ڽӱ�洢*/
int idx, e[N], ne[N], w[N], h[N];

/*cnt[N]Ϊͳ�Ƶ�ǰ�ڵ����*/
int dist[N], cnt[N];
bool st[N];

/*��Ȩ�ص�ͷ�巨*/
void insert(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}

bool spfa()
{
	queue<int> q;

	for (int i = 1; i <= n; i++)
	{
		st[i] = true;
		q.push(i);
	}

	while (q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;

		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;

				/*����ԭ��:ֻҪ�ߵ�����n���ڵ��ڵ�ĸ�����ͼ�оʹ��ڻ�*/
				if (cnt[j] >= n) return true;

				if (!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);

	while (m--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		insert(a, b, c);
	}

	if (spfa()) puts("Yes");
	else puts("No");

	return 0;
}