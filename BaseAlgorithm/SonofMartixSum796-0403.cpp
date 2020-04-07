#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m, q;
int a[N][N], s[N][N];

int main()
{
    scanf("%d%d%d", &n, &m, &q);

    for(int i = 1; i <=n; i++)
        for(int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    
    /*预处理子矩阵*/
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];

    while(q--)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1]);
    }
    system("pause");
    return 0;
}