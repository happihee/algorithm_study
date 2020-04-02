////////////////////////////////
// date : 2020.04.02	     ///
// problem num : baekjoon9465 //
// algorithm type : DP        //
////////////////////////////////

#include<iostream>
#include<algorithm>
using namespace std;
int arr[2][100001] = { 0, };
int dp[2][100001] = { 0, };
int testcase = 0;
int len = 0;
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> len;
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < len; k++) {
				cin >> arr[j][k];
			}
		}
		int result = 0;
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = dp[1][0] + arr[0][1];
		dp[1][1] = dp[0][0] + arr[1][1];

		for (int k = 2; k < len; k++) {
			dp[0][k] = arr[0][k] + max(dp[1][k - 1], dp[1][k - 2]);
			dp[1][k] = arr[1][k] + max(dp[0][k - 1], dp[0][k - 2]);
		}
		result = max(dp[0][len - 1], dp[1][len - 1]);
		cout << result << endl;
	}

}
