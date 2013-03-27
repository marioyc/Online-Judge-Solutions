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

vector<int> L[100005];

double dfs(int cur, int p, int cont){
    double ret = 1.0 / cont;
    
    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];
        
        if(to != p)
            ret += dfs(to,cur,cont + 1);
    }
    
    return ret;
}

int main(){
    int n;
    
    scanf("%d",&n);
    
    for(int i = 1,a,b;i < n;++i){
        scanf("%d %d",&a,&b);
        L[a].push_back(b);
        L[b].push_back(a);
    }
    
    printf("%.10f\n",dfs(1,0,1));
    
    return 0;
}
