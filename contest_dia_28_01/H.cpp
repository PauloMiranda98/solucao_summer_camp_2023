#include <bits/stdc++.h>

#define F first
#define S second
#define EB emplace_back
#define all(x) x.begin(),x.end()
#define endl '\n'
#define W(x) cerr << "\033[31m"<<  #x << " = " << x << "\033[0m" << endl;

using namespace std;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

using ll = long long;
using pii = pair<int, int>;

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1000000007;
const int MAXN = 500010;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int n, m, d;
vector<vector<int>> vis;
vector<vector<char>> mat;

void bfs1(){
	vector<vector<int>> dist(n, vector<int>(m, INF));	
	vis.resize(n, vector<int>(m, false));	
	queue<pii> q;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(mat[i][j] == 'M'){
				dist[i][j] = 0;
				vis[i][j] = true;
				q.push(pii(i, j));
			}
		}
	}
	while(!q.empty()){
		pii u = q.front(); q.pop();
		if(dist[u.F][u.S] >= d)
			break;
		for(int k=0; k<4; k++){
			pii to(u.F + dx[k], u.S + dy[k]);
			if(to.F>=0 and to.F<n and to.S>=0 and to.S<m){
				if(!vis[to.F][to.S]){
					vis[to.F][to.S] = true;
					dist[to.F][to.S] = dist[u.F][u.S] + 1;
					q.push(to);
				}
			}
		}
	}
}

int bfs2(){
	vector<vector<int>> dist(n, vector<int>(m, INF));	
	queue<pii> q;
	int x=0, y=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(mat[i][j] == 'S'){
				dist[i][j] = 0;
				if(!vis[i][j])
					q.push(pii(i, j));
			}else if(mat[i][j] == 'F'){
				x = i; y = j;
			}
			
		}
	}
	while(!q.empty()){
		pii u = q.front(); q.pop();
		for(int k=0; k<4; k++){
			pii to(u.F + dx[k], u.S + dy[k]);
			if(to.F>=0 and to.F<n and to.S>=0 and to.S<m){
				if(!vis[to.F][to.S]){
					vis[to.F][to.S] = true;
					dist[to.F][to.S] = dist[u.F][u.S] + 1;
					q.push(to);
				}
			}
		}
	}
	int ans = dist[x][y];
	if(ans >= INF)	
		ans = -1;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> d;		
	mat.resize(n, vector<char>(m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mat[i][j];
		}
	}
	bfs1();
	cout << bfs2() << endl;
	
	return 0;
}