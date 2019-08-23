#include<iostream>
#include<string>
using namespace std;
char board[5][5] = { 'U','R','L','P','M',
					 'X','P','R','E','T',
					 'G','I','A','E','T',
					 'X','T','N','Z','Y',
					 'X','O','Q','R','S' }; //좌표
int dx[3] = { -1,0,1};
int dy[3] = { -1,0,1};
string word;
int num = 1;
int check = 1;
int flag = 0;

int hasword(int y, int x, char fword)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			/*if (dx[i] == 0 && dy[j] == 0)
				continue;
				*/
			if (board[y + dx[i]][x + dy[j]] == fword)
			{
				num++; //글자 뒤로 한칸
				check++;
				if (num == word.length())
				{
					flag = 1;
					return 0;
				}
				if (num > word.length())
					break;
				hasword(y + i, x + j, word.at(num));
			}
		}
	}
	if (flag == 1)
		return 0;
	else
		return -1;
}
int main()
{
	int c = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << board[i][j]<< " ";
		}
		cout << endl;
	}
	cout << "찾을 단어를 입력하세요:";
	getline(cin, word);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (word.at(0) == board[i][j])
			{
				c = hasword(i, j, word.at(1));
				if (c == -1)
				{
					cout << "fail to find word" << endl;
					continue;
				}
				else
				{
					cout << "success to find word " << word << endl;
					return 0;
				}
			}
		}
	}
}