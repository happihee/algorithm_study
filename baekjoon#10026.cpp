#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<queue>
#include<string>
using namespace std;
int N = 0;
char map[100][100] = { 0, };
bool visit[100][100] = { false, };
int dy[4] = { 0,0,-1,1 }; //세로축
int dx[4] = { -1,1,0,0 }; //가로축
int Nxcur = 0;
int Nycur = 0;
int result = 0;
queue<pair<int, int>> q;

void ResetVisit() //visit table reset
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			visit[i][j] = false;
		}
	}
}
void NewMap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'G')
			{
				map[i][j] = 'R';
			}
		}
	}
}
void Check() 
{
	while (!q.empty())
	{
		int Xcur = q.front().first; //q에 저장된 요소 중 첫 번째
		int Ycur = q.front().second; //q에 저장된 요소 중 두 번째 
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			Nxcur = Xcur + dx[i];
			Nycur = Ycur + dy[i];
			if (Nxcur < 0 || Nycur < 0 || Nxcur >= N || Nycur >= N)
				continue;
			else
			{
				if (map[Nxcur][Nycur] == map[Xcur][Ycur] && visit[Nxcur][Nycur] == false)
				{
					visit[Nxcur][Nycur] = true;
					q.push(make_pair(Nxcur, Nycur));
				}
			}
		}
	}
	result++;
}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] == 'R' && visit[i][j] == false)
			{
				q.push(make_pair(i, j));
				Check();
			}
			else if (map[i][j] == 'G' && visit[i][j] == false)
			{
				q.push(make_pair(i, j));
				Check();
			}
			else if (map[i][j] == 'B' && visit[i][j] == false)
			{
				q.push(make_pair(i, j));
				Check();
			}
		}
	}
	cout << result << endl;

	result = 0;
	ResetVisit();
	NewMap();

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] == 'R' && visit[i][j] == false)
			{
				q.push(make_pair(i, j));
				Check();
			}
			else if (map[i][j] == 'B' && visit[i][j] == false)
			{
				q.push(make_pair(i, j));
				Check();
			}
		}
	}
	cout << result;

}