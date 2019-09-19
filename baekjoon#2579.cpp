/////////////////////////////////////////
//알고리즘 분류 : Dynamic Programming // 
////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int StairNum = 0;
int Stair[301] = { 0, };
int Score[301] = { 0, };
int nScore = 0;
void FindHighScore()
{
	for (int i = 0; i < StairNum; i++)
	{
		if (Score[i - 2] + Stair[i] > Score[i - 3] + Stair[i - 1] + Stair[i])
		{
			Score[i] = Score[i - 2] + Stair[i];
		}
		else
			Score[i] = Score[i - 3] + Stair[i - 1] + Stair[i];
	}
}
int main()
{
	freopen("input1.txt", "r", stdin);
	cin >> StairNum;

	for (int i = 0; i < StairNum; i++)
	{
		cin >> Stair[i];
	} //계단 정보 삽입
	FindHighScore();
	cout << Score[StairNum-1];
}