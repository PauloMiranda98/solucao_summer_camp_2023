
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

const int K = 2;
int B = 30;

struct Vertex {
  int next[K];
  int leaf;
  int count;
  Vertex() {
    fill(begin(next), end(next), -1);
    leaf = 0;
    count = 0;
  }
};

struct Trie{
  vector<Vertex> trie;
  Trie(){
    trie.emplace_back();
  }
  void add(int x) {
    int v = 0;
    trie[v].count++;
    
    for(int b=B; b>=0; b--){
      int c = (x >> b)&1;
      if (trie[v].next[c] == -1) {
        trie[v].next[c] = trie.size();
        trie.emplace_back();
      }
      v = trie[v].next[c];
      trie[v].count++;
    }
    trie[v].leaf++;
  }
  void rem(int x) {
    int v = 0;
    trie[v].count--;
    
    for(int b=B; b>=0; b--){
      int c = (x >> b)&1;
      if (trie[v].next[c] == -1) {
        trie[v].next[c] = trie.size();
        trie.emplace_back();
      }
      v = trie[v].next[c];
      trie[v].count--;
    }
    trie[v].leaf--;
  }

  int maxXor(int x) {
    int v = 0;
    int ans = 0;
    
    for(int b=B; b>=0; b--){
      int c = (x >> b)&1;
      if (canGo(v, !c)){
		v = trie[v].next[!c];  
		ans |= (1<<b);
	  }else{
		v = trie[v].next[c];  
	  }
    }
    return ans;
  }
  bool canGo(int v, int c){
	return trie[v].next[c] != -1 and trie[trie[v].next[c]].count > 0;
  }
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int q;
	cin >> q;
	
	Trie trie;
	trie.add(0);
	
	while(q--){
		char op;
		int x;
		cin >> op >> x;
		if(op == '+')
			trie.add(x);
		else if(op == '-')
			trie.rem(x);
		else
			cout << trie.maxXor(x) << endl;
	}
	
	return 0;
}
