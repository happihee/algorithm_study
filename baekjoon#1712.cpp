#include<iostream>
using namespace std;
/////////////////////////////
// 사용언어 : c++ 			//
//	손익분기점이 발생하는    //
// 판매 개수를 출력하는 문제 //
////////////////////////////
int main()
{
	double a = 0; //고정비용(변하지않음)
	double b = 0; //가변비용
	double c = 0; //물건을 팔때 발생하는 이익

	double num = 1; //손익분기점까지의 개수를 저장
	int flag = 0;

	/* 정보를 입력받음 */
	cin >> a >> b >> c;

	if (c <= b)
		cout << -1;
	else
	{
		flag = a / (c - b) + 1;
		cout << flag;
	}

	return 0;
}
