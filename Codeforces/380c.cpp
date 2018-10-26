//$ time g++ -c -std=c++11 vec.cpp -fconstexpr-depth=600
//OPT COMPILER:global compiler c++11
//{
#include<bits/stdc++.h>
#define ll                  long long
#define rep(i,n)            for(auto i=0;i<(n);++i)
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define sz(v)               v.size()
#define all(v)              std::begin(v), std::end(v)
#define vi                  vector<int>
#define hell                1000000007LL
#define StringToInt(s,n)    if ( ! (istringstream(s) >> n) ) n = 0;
#ifdef ONLINE_JUDGE
#define o(x)				;
#else
#define o(x)				cerr << #x << " = " << x << endl;
#endif // ONLINE_JUDGE
using namespace std;

ll gcd(ll p,ll q){return q==0?p:gcd(q,p%q);}
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}
inline int read() {
	int x=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
//}

int const sq = 7000;
map< pair<int,int> , int > m;
string s;
//memo*****************************************
int f(int a, int b){

auto it=m.find( mp(a,b));
if (it!=m.end()) return it->se;

//cas vide
if (a>=b) return 0;
int mx = 0;
//cas on considere el (/)
if (s[a]=='('){
for(int i=a+1; i<=b;++i){
        if (s[i]==')')
            mx = max(mx, 2+f(a+1,i-1)+f(i+1,b)  );
}
}
// cas na7groha
mx = max(mx, f(a+1,b));


return mx;
}
int main() {
#ifndef ONLINE_JUDGE
freopen("a.txt", "r", stdin);
#endif // ONLINE_JUDGE
	ios::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	//cout << fixed << setprecision(9);




    getline(cin, s);
//	cout<<s;

int m,a,b;
cin>>m;
rep(i,m){
cin>>a>>b;
cout<<f(a-1,b-1)<<"\n";
}



	return 0;}
