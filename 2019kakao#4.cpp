#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string QueryStr;
	string WordStr;
	int flag = 0;
	int index = 0;
	vector<string> queries;
	vector<string> Nqueries;
	vector<string> words;
	vector<string> cwords;
	vector<int> result;
	words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
	queries = { "fro??", "????o","fr???", "fro???", "pro?" };

	cwords = words;
	for (int i = 0; i < queries.size(); i++)
	{
		QueryStr = queries.at(i);

	}
	for (int i = 0; i < queries.size(); i++)
	{
		QueryStr = queries.at(i);
		cwords = words;
		while (!cwords.empty())
		{
			WordStr = cwords.back();
			cwords.pop_back();
			if (QueryStr.size() != WordStr.size())
			{
				flag = 1;
			}
			else
			{
				for (int k = 0; k < WordStr.size(); k++)
				{
					if (QueryStr[k] == '?')
					{
						continue;
					}
					else if (QueryStr[k] == WordStr[k])
					{
						continue;
					}
					else if (QueryStr[k] != WordStr[k])
					{
						flag = 1;
						break;
					}
				}
			}
			if (flag == 1)
			{
				flag = 0;
			}
			else
			{
				index = index + 1;
			}
		}
		result.push_back(index);
		index = 0;
	}
	for (int i = 0; i < queries.size(); i++)
	{
		cout << result[i] << " ";
	}
}