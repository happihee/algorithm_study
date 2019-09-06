#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
using namespace std;

int map[8][8] = { 0 };
/*text영역으로 들어가기 때문에 공간낭비 저하*/
int N;
int M;
int safezonenum = 0;
/* 좌표 영역 */
int dx[4] = { -1, 1, 0 , 0 };
int dy[4] = { 0 ,0, -1 ,1 };
/* BFS에 사용되는 Queue */
int FindSafeZone(int m[8][8])
{
	int safezero = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (m[i][j] == 0)
				safezero++;
		}
	}
	return safezero;
}
void Virus()
{
	bool visit[8][8] = { false, };
	int cmap[8][8] = { 0, };
	int Xcur = 0;
	int Ycur = 0;
	int Nxcur = 0;
	int Nycur = 0;
	queue<pair<int, int> > q;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cmap[i][j] = map[i][j];
			if (cmap[i][j] == 2)
			{
				visit[i][j] = true;
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty())
	{
		Xcur = q.front().first;
		Ycur = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			Nxcur = Xcur + dx[i];
			Nycur = Ycur + dy[i];
			if (Nxcur < 0 || Nycur < 0 || Nxcur >= N || Nycur >= M || cmap[Nxcur][Nycur] == 1)
				continue;
			else if (cmap[Nxcur][Nycur] == 0 && visit[Nxcur][Nycur] == false)
			{
				visit[Nxcur][Nycur] = true;
				cmap[Nxcur][Nycur] = 2;
				q.push(make_pair(Nxcur, Nycur));
			}
		}
	}
	int z = FindSafeZone(cmap);
	if (z > safezonenum)
	{
		safezonenum = z;
	}

}

void NewMap(int Xcur, int Ycur, int step)
{
	if (step == 3)
	{
		Virus();
		return;
	}
	else
	{
		for (int i = Xcur; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (map[i][j] == 0)
				{
					map[i][j] = 1;
					NewMap(i, j, step + 1);
					map[i][j] = 0;
				}
			}
		}
	}
}
int main()
{
	/* 맵을 구성하는 부분 */
	//freopen("input1.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				NewMap(i, j, 1);
				map[i][j] = 0;
			}
		}
	}

	cout << safezonenum;
	return 0;
}