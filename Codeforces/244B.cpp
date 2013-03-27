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

int main(){
    ios::sync_with_stdio(0);
    
    int n;
    scanf("%d",&n);
    
    set<int> ans;
    if(n == 1000000000) ans.insert(1000000000);
    
    for(int mask = 0;mask < (1 << 9);++mask){
        for(int x = 0;x <= 9;++x){
            for(int y = 0;y <= 9;++y){
                long long aux = 0;
                
                for(int d = 0;d < 9;++d){
                    aux = aux * 10 + ((mask >> d & 1)? x : y);
                    if(aux > 0 && aux <= n) ans.insert(aux);
                }
            }
        }
    }
    
    printf("%d\n",(int)ans.size());
    
    return 0;
}
