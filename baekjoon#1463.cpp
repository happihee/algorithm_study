/////////////////////////////////////
//categorie : Dynamic Programming ///
//question num : beakjoon.1463   ////
//using language : c++          ////
/////////////////////////////////////

#include <cstdio>
#include<iostream>
using namespace std;
long long number;

int visit[1000001] = { 0, };
int resultnum = 12345;


bool VisitCheck(int num, int new_check)
{
	if (visit[num] != 0 && visit[num] > new_check) return true;
	else if (visit[num] == 0)                      return true;
	else                                        return false;
}
void MakeNumOne(long long num, int check)
{
	if (num >= 2)
	{
		if (num % 3 == 0 && VisitCheck(num / 3, check) == true)
		{
			visit[num / 3] = check + 1;
			MakeNumOne(num / 3, check + 1);
		}
		if (num % 2 == 0 && VisitCheck(num / 2, check) == true)
		{
			visit[num / 2] = check + 1;
			MakeNumOne(num / 2, check + 1);
		}
		if (num >= 2 && VisitCheck(num - 1, check) == true)
		{
			visit[num - 1] = check + 1;
			MakeNumOne(num - 1, check + 1);
		}
	}
}
int main()
{
	cin >> number;
	MakeNumOne(number, 0);

	cout << visit[1] << endl;
}