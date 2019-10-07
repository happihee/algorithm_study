#include<iostream>
#include<queue>
using namespace std;
int ResultMin;
int step;
int N;
int K;
int state;
bool visit[100003] = { false, };
queue < pair<int, int> > q;
void FindSister()
{
	int nstate = N + 1; //state +1
	int bstate = N - 1;// state -1
	int mstate = N * 2;// state*2
	q.push(make_pair(state, 0));
	visit[state] = true;
	while (!q.empty())
	{
		state = q.front().first;
		step = q.front().second;
		q.pop();
		if (state == K)
		{
			ResultMin = step;
			break;
		}
		nstate = state + 1;
		bstate = state - 1;
		mstate = state * 2;
		if (mstate <= 100000 && visit[mstate] == false )
		{
			visit[mstate] = true;
			q.push(make_pair(mstate, step + 1));
		}
		if (bstate >= 0 && visit[bstate] == false)
		{
			visit[bstate] = true;
			q.push(make_pair(bstate, step + 1));
		}
		if (nstate <= 100000 && visit[nstate] == false)
		{
			visit[nstate] = true;
			q.push(make_pair(nstate, step + 1));
		}
	}
}
int main()
{
	cin >> N >> K;
	state = N;
	FindSister();

	cout << ResultMin;
	return 0;
}