//$ time g++ -c -std=c++11 vec.cpp -fconstexpr-depth=600
//#pragma comment(linker, "/STACK:36777216")
//OPT COMPILER:global compiler c++11
//Lex MOD-0 ver. 2.3 (19/06/2018)
//la ilaha illallah
//{
#include<bits/stdc++.h>
#define ll                  long long
#define rep(i,n)            for(auto i=0;i<(n);++i)
#define pb                  push_back
#define mp                  make_pair
#define f                   first
#define s                   second
#define sz(v)               v.size()
#define all(v)              std::begin(v), std::end(v)
#define vi                  vector<int>
#define mod                 1000000007LL

#define StringToInt(s,n)    if ( ! (istringstream(s) >> n) ) n = 0;
using namespace std;
template <typename T>
string NumberToString ( T Number )
{
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}

#ifdef ONLINE_JUDGE
#define line
#define o(x)
#else
#define line                cerr<<'\n';
#define o(x)				cerr << __LINE__ << " $" << #x << " = " << x << "\n";
#endif // ONLINE_JUDGE

ll qpow(ll p,ll q)
{
    ll f=1;
    while(q) {
        if(q&1)
            f=f*p%mod;
        p=p*p%mod;
        q>>=1;
    }
    return f;
}
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9') {
        if (ch=='-')
            f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
//}


int const N = 100053;
int n;
ll tab[N];
ll cum[N];
int main()
{
    ll tot = 0 ;
#ifndef ONLINE_JUDGE
//n = N-53;
//srand (time(NULL));
//for(int i = 0 ; i<n ; i++){
//        tab[i]=rand() ;
//        tot+= tab[i];
//		cum[i]=tot;
//    }

freopen("a.txt","r",stdin);
#else
#endif // ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >>  n ;
    rep(i,n){
        cin >> tab[i] ;
        tot+= tab[i];
        cum[i]=tot;
    }

    if(tot&1LL || n==1) {
        cout<< "NO";
        cerr<<1;
        return 0;
    }
    auto chtar = tot/2;
    if (binary_search(begin(cum),begin(cum)+n-1,chtar) ) {
        cout << "YES";
        cerr<<2;
        exit(0) ;
    }
    rep(i,n) {
        if (  binary_search(begin(cum)+i,begin(cum)+n,chtar+tab[i])          ) {
            cout << "YES";
            exit(0) ;
        }
    }
    for(int i=1; i<n;++i) {
        if (  binary_search(begin(cum),begin(cum)+i-1,chtar-tab[i])          ) {
            cout << "YES";

            o(chtar)
            o(chtar-tab[i])
            o(tab[i])
            o(i)
            exit(0) ;
        }
    }
    cout<< "NO";
    return 0 ;
}
