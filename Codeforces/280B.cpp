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

#define MAXN 100000

int a[MAXN],l[MAXN],r[MAXN];

int main(){
    int n;
    
    scanf("%d",&n);
    
    for(int i = 0;i < n;++i)
        scanf("%d",&a[i]);
    
    int ans = 0;
    
    for(int i = 0;i < n;++i){
        l[i] = i - 1;
        
        while(l[i] >= 0 && a[ l[i] ] < a[i])
            l[i] = l[ l[i] ];
        
        if(l[i] >= 0) ans = max(ans,a[i] ^ a[ l[i] ]);
    }
    
    for(int i = n - 1;i >= 0;--i){
        r[i] = i + 1;
        
        while(r[i] < n && a[ r[i] ] < a[i])
            r[i] = r[ r[i] ];
        
        if(r[i] < n) ans = max(ans,a[i] ^ a[ r[i] ]);
    }
    
    printf("%d\n",ans);
    
    return 0;
}
