#include <iostream>
#include <queue> //queue를 사용할 때 선언해줘야하는 stl
using namespace std;

queue<pair<int, int>> Q;
bool visit[5005] = { false, };
int main()
{
	int N = 0;
	int count = 12345;
	pair<int, int> sugar;
	pair<int, int> store;
	cin >> N; //묶을 설탕 양 입력

	sugar = make_pair(N, 0);
	Q.push(sugar);

	while (1)
	{
		store = Q.front();
		if (store.first == 0)
		{
			count = store.second;
			break;
		}
		else if (store.first > 0)
		{
			visit[store.first - 5] = true; //중복저장 막기 
			sugar = make_pair(store.first - 5, store.second + 1);
			Q.push(sugar);
			if (visit[store.first] == false)
			{
				sugar = make_pair(store.first - 3, store.second + 1);
				Q.push(sugar);
			}
		}
		Q.pop();
		if (Q.empty() == 1)
			break;
	}
	if (count == 12345) cout << -1;
	else
		cout << count;
	
	return 0;
}
