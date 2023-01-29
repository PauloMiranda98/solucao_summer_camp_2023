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
using pvv = pair<vector<int>, vector<int>>;

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1000000007;
int n;
vector<int> comma;
vector<int> ans;
string str;

vector<int> getVector(int i, int j){
	vector<int> v;
	string num;	
	while(i<=j){
		if(str[i]>='0' and str[i]<='9'){
			num += str[i];
		}else if(num.size()){
			v.push_back(stoi(num));
			num.clear();
		}
		i++;
	}
	return v;
}

vector<int> sort_and_erase_inf(vector<int> v){
	sort(all(v));

	while(v.size() > 0 and v.back() == INF)
		v.pop_back();

	return v;
}

void getExpression(int i, int j){
	if(str[i] == '['){
		for(int x: getVector(i, j))
			ans.push_back(x);
	}else{
		string op;	
		while(str[i] != '(')
			op += str[i++];
		if(op == "sorted"){
			auto aux = getVector(i, j);
			aux = sort_and_erase_inf(aux);

			for(int x: aux)
				ans.push_back(x);
		}else if(op == "shuffle"){
			auto aux = getVector(i, j);
			aux = sort_and_erase_inf(aux);

			if(aux[0] != aux.back()){
				ans.push_back(INF);
				for(int &x: aux)
					ans.push_back(x);
				ans.push_back(INF);
			}else{
				for(int &x: aux)
					ans.push_back(x);
			}
		}else{
			getExpression(i+1, comma[i]-1);
			getExpression(comma[i]+1, j-1);
		}
	}
}
vector<int> getExpression(string s){
	comma.resize(s.size());
	ans.clear();
	stack<int> st;	
	for(int i=0; i<(int)s.size(); i++){
		if(s[i] == '(' or s[i] == '['){
			st.push(i);
		}else if(s[i] == ')' or s[i] == ']'){			
			st.pop();
		}else if(s[i] == ','){
			if(s[st.top()] == '(')
				comma[st.top()] = i;			
		}
	}
	str = s;
	ans.clear();
	getExpression(0, s.size()-1);
	return ans;
}

char buffer[1000010];
int main() {
	string s, t;
	scanf("%s", buffer);
	s = buffer;
	scanf("%s", buffer);
	t = buffer;	
	vector<int> v1 = getExpression(s);
	vector<int> v2 = getExpression(t);

	if(v1 == v2)
		puts("equal\n");
	else
		puts("not equal\n");
	return 0;
}