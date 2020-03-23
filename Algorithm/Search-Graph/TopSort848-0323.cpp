#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, m;
int idx, h[N], e[N], ne[N];
int q[N];

/*d[i]��ʾ��i���ڵ�����*/
int d[N];

/*ͷ�巨*/
void insert(int k, int x)
{
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx++;
}

bool topsort()
{
	int hh = 0, tt = -1;

	/*�������б�������Ϊ0�Ľڵ㿪ʼ����
	���Ƚ���Ϊ0�Ľڵ����*/
	for (int i = 1; i <= n; i++)
		if (d[i] != 0)
			q[++tt] = i;

	/*�����������ÿһ���ڵ�*/
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			d[j]--;
			if (d[j] == 0) q[++tt] = j;
		}
	}
	return tt == n - 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int k, x;
		scanf("%d%d", &k, &x);
		insert(k, x);

		/*��¼��i���ڵ����*/
		d[x]++;
	}
	if (topsort())
	{
		for (int i = 0; i < n; i++) printf("%d ", q[i]);
	}
	else puts("-1");
	return 0;
}