#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;
#define MAXN 100010

const int hash_p = 31;
//const int hash_p = 53;
const int hash_mod = 1e9 + 9;

ll power[MAXN];

ll compute_hash(string s) {
    ll hash_value = 0;
    ll p_pow = 1LL;
    
    for(char c : s){
        hash_value = (hash_value + ll(c - 'a' + 1LL) * p_pow) % hash_mod;
        p_pow = (p_pow * (ll)hash_p) % hash_mod;
    }
    
    return hash_value;
}

struct Node{
	ll hash;
	ll r_hash;
	int size;	
	Node(){
		hash = r_hash = 0;
		size = 0;
	}

	Node(ll a, ll b, int c){
		hash = a;
		r_hash = b;
		size = c;
	}
};

struct SegTree{

	#define NSeg MAXN
	 
	int n, *v;
	
	Node tree[4*NSeg];
	Node neutral;

	Node join(Node a, Node b){
		ll new_hash = (((a.hash * power[b.size]) % hash_mod) + b.hash) % hash_mod;
		ll new_rhash = (((b.r_hash * power[a.size]) % hash_mod) + a.r_hash) % hash_mod;

		return Node(new_hash, new_rhash, a.size + b.size);
	}

	//Build: O(4*n) -> O(n); call -> build(1, 1, n)
	void build(int node, int i, int j){
		if(i == j){
			tree[node] = Node(v[i], v[i], 1);
			return;
		}
		int m = (i+j)/2;
		
		int l = (node<<1);
		int r = l + 1;
		
		build(l, i, m);
		build(r, m+1, j);
		
		tree[node] = join(tree[l], tree[r]);
	}

	//Query: O(log(n)); call -> query(1, 1, n, a, b)
	Node query(int node, int i, int j, int a, int b){
		if( (i>b) or (j<a) )
			return neutral;
		if( (a<=i) and (j<=b) )
			return tree[node];
			
		int m = (i+j)/2;
		
		int l = (node<<1);
		int r = l + 1;
		
		return join( query(l, i, m, a, b), query(r, m+1, j, a, b));
	}

	//Update: O(log(n)); call -> update(1, 1, n, index, value)
	void update(int node, int i, int j, int index, int value){
		if(i == j){
			v[index] = value;
			tree[node] = Node(v[index], v[index], 1);
			return;
		}		
		int m = (i+j)/2;
		
		int l = (node<<1);
		int r = l + 1;
		
		if(index <= m)
			update(l, i, m, index, value);
		else
			update(r, m+1, j, index, value);		
		
		tree[node] = join(tree[l], tree[r]);
	}
	
	void build(int _v[], int _n){
		n = _n;
		v = _v;
		build(1, 1, n);
	}
	
	int query(int a, int b){
		Node no = query(1, 1, n, a, b);
		
		return no.hash == no.r_hash;
	}
	
	void update(int i, int value){
		update(1, 1, n, i, value);
	}
};

SegTree st;
int n, q, v[MAXN];

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	power[0] = 1LL;	
	for(int i=1; i<MAXN; i++)
		power[i] = (power[i-1]*hash_p)%hash_mod;
	
	int t;	
	cin >> t;
	while(t--){
		cin >> n >> q;	

		for(int i=1; i<=n; i++){
			char c;
			cin >> c;
			v[i] = int(c - 'a' + 1);		
		}
		
		st.build(v, n);
				
		for(int i=0; i<q; i++){
			int op;			
			cin >> op;
			
			if(op == 1){
				int index;
				char c;
				cin >> index >> c;
				st.update(index, c - 'a' + 1);	
			}else{
				int a, b;
				cin >> a >> b;
				if(st.query(a, b))
					cout << "Adnan Wins" << endl;
				else
					cout << "ARCNCD!" << endl;
			}
		}
	}
	return 0;
	
}