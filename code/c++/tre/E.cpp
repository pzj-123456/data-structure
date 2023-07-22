#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
typedef long long i64;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;

const int N = 1e4 + 10;
int tr[N * 10][10], idx = 0;
bool cnt[N * 10], flag;

void insert(string s)
{
	int p = 0;
	for (int i = 0; i < (int)s.length(); i++)
	{
		int t = s[i] - '0';
		if (tr[p][t] && i == (int)s.length() - 1)
			flag = 1;
		if (!tr[p][t])
			tr[p][t] = ++idx;
		p = tr[p][t];
		if (cnt[p])
			flag = 1;
	}
	cnt[p] = 1;
}

void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		insert(s);
	}
	if (flag)
		cout << "NO\n";
	else
		cout << "YES\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		solve();
		memset(tr, 0, sizeof tr);
		memset(cnt, 0, sizeof cnt);
		idx = 0, flag = 0;
	}
	return 0;
}