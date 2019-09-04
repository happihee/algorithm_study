#include<iostream>
using namespace std;

int starship(int start, int end)
{
	long long count = 1;
	long long num = 1;
	long long beforenum = 1;
	long long  num2 = 1;

	long long  beforestore = 0;
	long long  store = 0;
	store = end - start;

	while (1)
	{
		beforenum = num2;
		num++;
		num2 = num*num;
		if (store < num2)
			break;
		else
			count = count + 2;
	} //기준 찾기 

	store = store - beforenum; //빼고 남은 숫자 확인
	num = num - 1;
	while (store != 0)
	{
		beforestore = store;
		store = store - num;
		if (store < 0)
		{
			num--;
			store = beforestore;
		}
		else
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int testcase = 0;
	long long start[5005]= { 0, };
	long long end[5005] = { 0, };
	long long result[5005] = { 0, };
	cin >> testcase; //테스트 케이스 입력

	for (int i = 0; i < testcase; i++)
	{
		cin >> start[i] >> end[i]; //시작 지점과 도착 지점 입력
		result[i] = starship(start[i], end[i]);
	}
	for (int i = 0; i < testcase; i++) {
		cout << result[i] << endl;
	}
	
	return 0;
}
