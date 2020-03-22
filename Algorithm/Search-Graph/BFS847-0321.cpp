#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

/*����ģ��ͼ���ڽӱ�洢*/
int idx, e[N], ne[N], h[N];
/*
q[N]��һ�����У�ÿһ�δ洢�����뵱ǰ�ڵ����ڵı�
d[i]������Ǵӽڵ�1��i����̾���
*/
int q[N], d[N];
int n, m;

/*ͷ�巨*/
void insert(int k, int x)
{
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx++;
}

/*���ؽڵ�1��n����̾���*/
int bfs()
{
	/*��ʼ�����е�ͷ��β���*/
	int tt = 0, hh = 0;
	memset(d, -1, sizeof d);
	q[0] = 1;
	d[0] = 0;
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if(d[j] == -1)
			{
				/*�����һ���ڵ�û�б���������������Ұ�����1�ľ���+1*/
				d[j] = d[t] + 1;
				q[++tt] = j;
			}
		}
	}
	return d[n];
}

int main()
{
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	for (int i = 0; i < m; i++)
	{
		int k, x;
		scanf("%d%d", &k, &x);
		insert(k, x);
	}

	cout << bfs() << endl;
	return 0;
}