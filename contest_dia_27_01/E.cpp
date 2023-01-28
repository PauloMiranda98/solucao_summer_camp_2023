#include <bits/stdc++.h>

using namespace std;

#define DEBUG false
#define dbf if (DEBUG) printf

#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())
#define endl '\n'
#define mdc(a, b) (__gcd((a), (b)))
#define mmc(a, b) (( (a)/__gcd((a), (b)) )*(b))

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

const int MAXNODE = 4;
struct Node{
	Node* p[MAXNODE];
	int v[MAXNODE];

	Node(){
		for(int i=0; i<MAXNODE; i++){
			p[i] = nullptr;
			v[i] = 0;
		}
	}	

	Node* findChild(int value){
		for(int i=1; i <= v[0]; i++)
			if(value < v[i])
				return p[i-1];		
		return p[v[0]];
	}
};

struct Tree_2_3_4{
	Node* root;
	Tree_2_3_4(){
		root = new Node();
	}
	
	void push(Node *node, int value, Node *child){
		int pos = ++(node->v[0]);
		node->v[pos] = value;
		node->p[pos] = child;		
		while( (pos > 1) and (node->v[pos-1] > node->v[pos]) ){
			swap(node->v[pos-1], node->v[pos]);
			swap(node->p[pos-1], node->p[pos]);
			pos--;
		}			
		
	}
		
	pair<int, Node*> _insert(Node *node, int value){
		if(node->v[0] == 3){
			Node* newNode = new Node;
			newNode->v[0] = 1;
			newNode->p[0] = node->p[2];
			newNode->v[1] = node->v[3];
			newNode->p[1] = node->p[3];

			int middle = node->v[2];
			node->v[0] = 1;
			for(int i=2; i<MAXNODE; i++){
				node->v[i] = 0;
				node->p[i] = nullptr;
			}
			
			return make_pair(middle, newNode);
		}

		if(node->p[0] == nullptr){
			push(node, value, nullptr);	
			return make_pair(0, nullptr);
		}else{
			pair<int, Node*> ret = _insert(node->findChild(value), value);
			while(ret.second != nullptr){
				push(node, ret.first, ret.second);
				ret = _insert(node->findChild(value), value);
			}			
			return make_pair(0, nullptr);
		}
		
	}
	
	void insert(int value){
		pair<int, Node*> ret = _insert(root, value);

		while(ret.second != nullptr){
			Node* newRoot = new Node();
			newRoot->v[0] = 1;
			newRoot->v[1] = ret.first;
			newRoot->p[0] = root;
			newRoot->p[1] = ret.second;

			root = newRoot;
			ret = _insert(root, value);
		}

	}
	
	void _preOrder(Node *node){
		if(node == nullptr)
			return;
		for(int i=1; i<=node->v[0]; i++){
			if(i > 1)
				cout << " ";
			cout << node->v[i];
		}
		cout << endl;

		for(int i=0; i<=node->v[0]; i++)
			_preOrder(node->p[i]);		
	}
	
	void preOrder(){
		_preOrder(root);
	}

	void _inOrder(Node *node){
		if(node == nullptr)
			return;
		_inOrder(node->p[0]);		
		for(int i=1; i<=node->v[0]; i++){
			cout << node->v[i] << endl;			
			_inOrder(node->p[i]);		
		}
	}
	
	void inOrder(){
		_inOrder(root);
	}

};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	for(int k=1; k<=t; k++){
		int n;
		cin >> n;
		Tree_2_3_4 tree;
		for(int i=0; i<n; i++){
			int x;
			cin >> x;
			tree.insert(x);
		}
		cout << "Case #" << k << ":\n";
 		tree.preOrder();
	}
	return 0;
}