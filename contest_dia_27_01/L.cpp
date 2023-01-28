#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef pair<char, int> pci;
const int INF = 0x3f3f3f3f;
const int MAXN = 200010;

vector<pci> adj[MAXN];
vector<pci> adjRev[MAXN];
int n, m;
int pai[MAXN];
bool used[MAXN];

vector<int> bfs(int s){	
	vector<int> dist(n+1, INF);
		
	dist[s] = 0;
	queue<int> q;	
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(pci p: adj[u]){
			int to = p.second;
			if(dist[u]+1 < dist[to]){
				dist[to] = dist[u] + 1;				
				q.push(to);
			}
		}
	}
	
	return dist;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;	
	for(int i=0; i<m; i++){
		int a, b; char c;
		cin >> a >> b >> c;
		adj[a].push_back(pci(c, b));
		adj[b].push_back(pci(c, a));
	}	
	vector<int> dist_1 = bfs(1);
	vector<int> dist_n = bfs(n);
	
	string ans;
	vector<int> curr, next;	
	curr.push_back(1);
	used[1] = true;
	pai[1] = -1;
	for(int i=0; i<=dist_1[n]; i++){
		char minChar = 'z' + 1;
		for(int u: curr){
			for(pci p: adj[u]){
				char edge = p.first;  
				int to = p.second;
				if(dist_1[u]+1 == dist_1[to] and dist_n[to]+1 == dist_n[u])
					minChar = min(minChar, edge);				
			}	
		}
		while(!curr.empty()){
			int u = curr.back();
			curr.pop_back();
			for(pci p: adj[u]){
				char edge = p.first;  
				int to = p.second;
				if(edge != minChar or used[to])
					continue;
				if(dist_1[u]+1 == dist_1[to] and dist_n[to]+1 == dist_n[u]){
					pai[to] = u;
					next.push_back(to);
					used[to] = true;
				}
			}	
		}
		ans += minChar;		
		curr.swap(next);		
	}
	vector<int> vans;
	int u = n;
	while(u != -1){
		vans.push_back(u);
		u = pai[u];
	}
	reverse(vans.begin(), vans.end());
		
	ans.pop_back();
	cout << ans.size() << endl;
	for(int x: vans)
		cout << x << " ";
	cout << endl;
	cout << ans << endl;	
	return 0;
}