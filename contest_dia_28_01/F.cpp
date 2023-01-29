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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;

ll dist[102][102][102];

struct Edge{
	int x, y;
	ll cost;
	ll km;
	Edge(){}
	Edge(int a, int b, ll c, ll d){
		x = a;
		y = b;
		cost = c;
		km = d;
	}
};

struct classcomp {
    bool operator() (const Edge& lhs, const Edge& rhs) const{
		if(lhs.cost == rhs.cost)
			return lhs.km > rhs.km;
		return lhs.cost > rhs.cost;
	}
};
ll my_sqrt(ll x){
	ll ans = max(1LL, (ll)sqrt(x)-2);
	while(ans*ans < x)
		ans++;
	return ans;
}
ll cost(int a, int b, int c, int d, ll _cost){
	return _cost*my_sqrt((c-a)*(c-a) + (d-b)*(d-b));
}

vector<Edge> adj[110][110];
int xd, yd, b;
ll ci[110];
pii v[1010];
vector<pii> aux[1010];

ll dijkstra(int x, int y){
	memset(dist, 0x3f, sizeof(dist));
	priority_queue<Edge, vector<Edge>, classcomp> pq;
	pq.push(Edge(x, y, 0LL, 0LL));	
	dist[x][y][0] = 0;
	
	while(!pq.empty()){
		Edge u = pq.top();
		pq.pop();
		for(Edge to : adj[u.x][u.y]){
			ll new_km = u.km + to.km;
			if(new_km > b)
				continue;
			if(dist[to.x][to.y][new_km] > u.cost + to.cost){
				dist[to.x][to.y][new_km] = u.cost + to.cost; 
				pq.push(Edge(to.x, to.y, dist[to.x][to.y][new_km], new_km));
			}
		}
	}
	ll ans = INFLL;
	for(int i=0; i<=b; i++)
		ans = min(ans, dist[xd][yd][i]);	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int xs, ys;
	cin >> xs >> ys;
	cin >> xd >> yd;
	cin >> b;
	cin >> ci[0];
	int t;
	cin >> t;
	for(int i=1; i<=t; i++)
		cin >> ci[i];
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		int l;
		cin >> v[i].F >> v[i].S >> l;
		aux[i].resize(l);
		for(int j = 0; j < l; j++)
			cin >> aux[i][j].F >> aux[i][j].S;				
	}

	for(int i=0; i<n; i++){
		int l = aux[i].size();
		adj[v[i].F][v[i].S].emplace_back(xd, yd, cost(v[i].F, v[i].S, xd, yd, ci[0]), cost(v[i].F, v[i].S, xd, yd, 1));
		adj[xs][ys].emplace_back(v[i].F, v[i].S, cost(v[i].F, v[i].S, xs, ys, ci[0]), cost(v[i].F, v[i].S, xs, ys, 1));
		for(int j = 0; j < l; j++){
			int m = aux[i][j].F, tp = aux[i][j].S;
			adj[v[i].F][v[i].S].emplace_back(v[m].F, v[m].S, cost(v[i].F, v[i].S, v[m].F, v[m].S, ci[tp]), cost(v[i].F, v[i].S, v[m].F, v[m].S, 1));
			adj[v[m].F][v[m].S].emplace_back(v[i].F, v[i].S, cost(v[i].F, v[i].S, v[m].F, v[m].S, ci[tp]), cost(v[i].F, v[i].S, v[m].F, v[m].S, 1));
		}		
	}
	adj[xs][ys].emplace_back(xd, yd, cost(xs, ys, xd, yd, ci[0]), cost(xs, ys, xd, yd, 1));
	ll ans = dijkstra(xs, ys);
	if(ans < INFLL)
		cout << ans << endl;
	else
		cout << -1 << endl;

	return 0;
}