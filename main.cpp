#include<iostream>
#include<queue>
#include<iomanip>
using namespace std;
const int maxn = 201;
int map[maxn][maxn];
int n, m, hhh[8][2] = { {1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1} };
struct point
{
    int x, y, n;
} p;
queue<point> q;
int main()
{
    int i, j;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            map[i][j] = -1;
    cin >> p.x >> p.y;
    p.x--;
    p.y--;
    map[p.x][p.y] = 0;
    q.push(p);
    while (!q.empty())
    {
        point temp;
        for (i = 0; i < 8; i++)
        {
            temp = q.front();
            int x = temp.x + hhh[i][0];
            int y = temp.y + hhh[i][1];
            if (x<0 || x>n || y<0 || y>m || map[x][y] != -1)
                continue;
            temp.x += hhh[i][0];
            temp.y += hhh[i][1];
            temp.n++;
            q.push(temp);
            map[temp.x][temp.y] = temp.n;
        }
        q.pop();
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            cout << setiosflags(ios::left) << setw(5) << map[i][j];
        cout << endl;
    }
    return 0;
}
