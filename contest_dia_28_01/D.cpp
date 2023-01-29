#include <bits/stdc++.h>

#define F first
#define S second
#define EB emplace_back
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define all(x) x.begin(),x.end()
#define endl '\n'
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;

using namespace std;

vector<int> z_function(string s) {
  int n = (int) s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; i++){
    if (i <= r)
      z[i] = min (r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      z[i]++;
    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string t, s;
	int n;

	getline(cin, t);	
	getline(cin, s);

	cin >> n;
	
	auto z = z_function(s + "#" + t);
	int sz = z.size();
	
	vector<int> f(sz + 1);
	for(int i=s.size() + 1; i < sz; i++){
		f[z[i]]++;
	}
	
	int sum = 0;
	for(int ans=sz; ans >= 1; ans--){
		sum += f[ans];
		if(sum >= n){
			cout << s.substr(0, ans) << endl;
			return 0;
		}
	}
	
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
