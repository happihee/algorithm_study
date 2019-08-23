#include <iostream>
using namespace std;
/////////////////////////////
// 사용언어 : c++ 			//
//입력한 숫자 N에 따라 		//
//3kg , 5kg 각각의 포대를  //
//활용하여 최소 포대 개수   //
//구하는 문제 			   //
///////////////////////////
int N;
int realcount= 12345;
bool visit[9999] = { false, };
void DeliverSugar(int count, int remainsugar)
{
	count++;
	if (remainsugar - 5 == 0)
	{
		if (realcount > count)
		{
			realcount = count;
			return;
		}
	}
	else if (remainsugar - 5 > 0 && visit[remainsugar-5] == false)
	{
		visit[remainsugar - 5] = true;
		DeliverSugar(count, remainsugar - 5);
	}
	if (remainsugar - 3 == 0)
	{
		if (realcount > count)
		{
			realcount = count;
			return;
		}
	}
	else if (remainsugar - 3 > 0 && visit[remainsugar - 3] == false)
	{
		visit[remainsugar - 3] = true;
		DeliverSugar(count, remainsugar - 3);
	}
}
int main()
{
	cin >> N; //설탕 양 입력
	DeliverSugar(0, N);
	if (realcount == 12345) cout << -1;
	else cout << realcount;
	return 0;
}
