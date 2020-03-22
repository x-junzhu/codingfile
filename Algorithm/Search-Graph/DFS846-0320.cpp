#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 2 * N;

/*����ģ������ͼ���ڽӱ�洢
idx ��ǰ���ô洢�ڵ�ֵ���±�
e[i] ���Ľڵ�ֵ
ne[i] ��i���ڵ����һ���ڵ�洢λ��
h[i] �ڵ�i��ͷ���
*/
int idx, e[M], ne[M], h[N];
int n;

/*��ǵ�k���ڵ��Ƿ񱻱�����*/
bool st[N];

/*ɾ���ڵ�x�������ͨ��ڵ���Ŀ���ֵ����Сֵ*/
int ans = N;

/*ͷ�巨*/
void insert(int k, int x)
{
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx++;
}

/*������uΪ���ڵ�������е������*/
int dfs(int u)
{
	st[u] = true;

	int sum = 1, res = 0;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (st[j] == false)
		{
			int s = dfs(j);
			res = max(res, s);
			sum += s;
		}
	}
	res = max(res, n - sum);
	ans = min(ans, res);
	return sum;
}

int main()
{
	scanf("%d", &n);
	memset(h, -1, sizeof h);
	for (int i = 0; i < n - 1; i++)
	{
		int k, int x;
		scanf("%d%d", &k, &x);
		insert(k, x);
		insert(x, k);
	}
	dfs(1);
	cout << ans << endl;
}