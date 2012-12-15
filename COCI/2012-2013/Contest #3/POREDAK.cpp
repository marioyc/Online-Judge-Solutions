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

int bit[2501];

int query(int idx){
    int ret = 0;
    
    for(int x = idx;x > 0;x -= x & -x)
        ret += bit[x];
    
    return ret;
}

void update(int idx, int val){
    for(int x = idx;x <= 2500;x += x & -x)
        bit[x] += val;
}

int main(){
    ios::sync_with_stdio(0);
    
    int N;
    
    cin >> N;
    
    map<string,int> id;
    string s;
    
    for(int i = 0;i < N;++i){
        cin >> s;
        id[s] = i + 1;
    }
    
    int ans = 0;
    
    for(int i = 0;i < N;++i){
        cin >> s;
        int a = id[s];
        ans += query(a);
        update(a,1);
    }
    
    printf("%d/%d\n",ans,N * (N - 1) / 2);
    
    return 0;
}
