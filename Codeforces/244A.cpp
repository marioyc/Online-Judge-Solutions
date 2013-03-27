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
    
    int n,k;
    
    scanf("%d %d",&n,&k);
    
    int a[k];
    bool done[n * k + 1];
    memset(done,false,sizeof done);
    
    for(int i = 0;i < k;++i){
        scanf("%d",&a[i]);
        done[ a[i] ] = true;
    }
    
    for(int i = 0;i < k;++i){
        printf("%d",a[i]);
        
        for(int j = 0;j < n - 1;++j){
            for(int k = 1;k <= n*k;++k){
                if(!done[k]){
                    printf(" %d",k);
                    done[k] = true;
                    break;
                }
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
