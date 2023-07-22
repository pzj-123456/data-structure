#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
typedef long long i64;
typedef pair<int, int> PII;
const int mod = 1e9 + 7;

const int N = 1e5 + 10;
int tr[N][26], idx = 0, ans = 0;
bool cnt[N];

void insert(string s)
{
	int p = 0;
	for (int i = 0; i < (int)s.length(); i++)
	{
		int t = s[i] - 'a';
		if (!tr[p][t])
			tr[p][t] = ++idx;
		p = tr[p][t];
	}
	if (!cnt[p])
		cnt[p] = 1, ans++;
}

void solve()
{
	string str, s;
	while (getline(cin, str))
	{
		if (str == "#")
			break;
		idx = ans = 0;
		memset(tr, 0, sizeof tr);
		memset(cnt, 0, sizeof cnt);
		stringstream ss(str);
		while (ss >> s)
		{
			insert(s);
		}
		cout << ans << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve();
	return 0;
}