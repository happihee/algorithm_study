#include<iostream>
using namespace std;
int result = 0;
int card[101] = { 0, };
int N;
int M;
int remainnum = 0;
int threecard = 0;
int main()
{
	freopen("input.txt", "r", stdin);
	/*N장의 카드와 카드정보*/
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> card[i];


	for (int i = 0; i < N-2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++)
			{
				if (card[i] + card[j] + card[k] <= M && M - (card[i] + card[j] + card[k]) < M - result)
					result = card[i] + card[j] + card[k];
			}
		}
	}
	cout << result;
	return 0;
}