//////////////////////////////////
//		algorithm : BFS			//
//////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<queue>
#include <algorithm>
#include<cstdio>
using namespace std;
int N;
int board[30][30] = { 0, };
bool visit[30][30] = { 0, };
int resultTable[5005] = { 0, };
int index = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue < pair<int, int> > q;
void FindAptComplex(int xcur, int ycur)
{
	int Nxcur = 0;
	int Nycur = 0;
	int count = 0;
	q.push(make_pair(xcur, ycur));
	visit[xcur][ycur] = true;
	while (!q.empty())
	{
		xcur = q.front().first;
		ycur = q.front().second;
		q.pop();
		if (board[xcur][ycur] == 1)
		{
			count++;
		}
		for (int i = 0; i < 4; i++)
		{
			Nxcur = xcur + dx[i];
			Nycur = ycur + dy[i];
			if (Nxcur < 0 || Nycur < 0 || Nxcur > N - 1 || Nycur > N - 1)
				continue;

			else if (board[Nxcur][Nycur] == 1 && visit[Nxcur][Nycur] == false)
			{
				q.push(make_pair(Nxcur, Nycur));
				visit[Nxcur][Nycur] = true;
			}
		}
	}
	resultTable[index] = count;
	index++;
}

int main()
{
	int arrSize = 0;
	freopen("input1.txt", "r", stdin);
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf_s("%1d", &board[i][j]);
		}
	} //map 기본설정

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 1 && visit[i][j] == false)
				FindAptComplex(i, j);
		}
	}
	for (int i = 0;; i++)
	{
		if (resultTable[i] == 0)
			break;
		else
			arrSize++;
	}
	cout << arrSize << endl;
	sort(resultTable, resultTable + arrSize);
	for (int i = 0; i < arrSize; i++)
	{
		cout << resultTable[i] << endl;
	}
}