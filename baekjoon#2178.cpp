//////////////////////////////////
//	algorithm : BFS		//
//////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
int board[105][105] = { 0, };
int visit[105][105] = { 0, };
int N;
int M;
int dx[4] = { 0,0 ,1, -1 };
int dy[4] = { 1, -1, 0,0 };
queue<pair<int, int> > q;

void FindMiro(int xcur, int ycur)
{
	long long Nxcur = 0;
	long long Nycur = 0;
	q.push(make_pair(xcur, ycur));
	visit[xcur][ycur] = 1;
	while (!q.empty())
	{
		xcur = q.front().first;
		ycur = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			Nxcur = xcur + dx[i];
			Nycur = ycur + dy[i];
			if (Nxcur < 0 || Nycur < 0 || Nxcur > N - 1 || Nycur > M - 1)
				continue;

			if (board[Nxcur][Nycur] == 1 && visit[Nxcur][Nycur] == 0) //갈 수 있는 길일 때
			{
				q.push(make_pair(Nxcur, Nycur));
				visit[Nxcur][Nycur] = visit[xcur][ycur] + 1;
			}
			else //갈 수 없는 길일 때
			{
				continue;
			}

		}
	}
}
int main()
{
	freopen("input1.txt", "r", stdin);
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &board[i][j]);
		}
	} //board 구성
	FindMiro(0, 0);

	cout << visit[N - 1][M - 1];
}
