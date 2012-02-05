#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

int N,pos;
string s;

vector<int> solve(int a, int b){
    vector<int> ret;
    
    if(b == a){
        ret.push_back(0);
        return ret;
    }
    
    int mi = (b - a - 1) / 2 + a;
    
    vector<int> v1 = solve(a,mi);
    vector<int> v2 = solve(mi + 1,b);
    vector<int> aux1,aux2;
    
    int sz1 = v1.size(),sz2 = v2.size();
    int p1 = 0,p2 = 0,n = 0;
    
    while(p1 < sz1 && p2 < sz2){
        if(s[pos] == '1'){
            aux1.push_back(n);
            ++p1;
        }else{
            aux2.push_back(n);
            ++p2;
        }
        
        ++pos; ++n;
    }
    
    while(p1 < sz1){
        aux1.push_back(n);
        ++p1; ++n;
    }
    
    while(p2 < sz2){
        aux2.push_back(n);
        ++p2; ++n;
    }
    
    vector<int> ret1(sz1),ret2(sz2);
    
    for(int i = 0;i < sz1;++i)
        ret1[i] = aux1[v1[i]];
    
    for(int i = 0;i < sz2;++i)
        ret2[i] = aux2[v2[i]];
    
    for(int i = 0;i < sz1;++i) ret.push_back(ret1[i]);
    for(int i = 0;i < sz2;++i) ret.push_back(ret2[i]);
    
    return ret;
}

const long long MOD = 1000003LL;

long long checksum(vector<int> &v){
    long long ret = 1;
    int n = v.size();
    
    for(int i = 0;i < n;++i)
        ret = (31 * ret + v[i] + 1) % MOD;
    
    return ret;
}

int main(){
    int T;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        cin >> N >> s;
        
        pos = 0;
        vector<int> p = solve(0,N - 1);
        
        printf("Case #%d: ",tc);
        cout << checksum(p);
        printf("\n");
    }
    
    return 0;
}
