#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

vector<int> add(vector<int> &a, vector<int> &b){
    vector<int> ret;
    
    int la = a.size(),lb = b.size();
    
    for(int i = 0,c = 0;i < la || i < lb || c;++i){
        int aux = c;
        if(i < la) aux += a[i];
        if(i < lb) aux += b[i];
        c = aux / 10;
        ret.push_back(aux % 10);
    }
    
    return ret;
}

void mult(vector<int> &a, int b){
    int la = a.size();
    
    for(int i = 0;i < la;++i) a[i] *= b;
    
    for(int i = 0;i + 1 < la;++i){
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    
    while(a.back() > 10){
        int x = a.back();
        a.back() = x % 10;
        a.push_back(x / 10);
    }
}

int main(){
    ios::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    vector<int> d[1001];
    d[1].push_back(0);
    d[2].push_back(1);
    
    for(int i = 3;i <= n;++i){
        d[i] = add(d[i - 1],d[i - 2]);
        mult(d[i],i - 1);
    }
    
    for(int i = d[n].size() - 1;i >= 0;--i) cout << d[n][i];
    cout << '\n';
    
    return 0;
}
