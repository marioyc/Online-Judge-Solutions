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
    
    int n,m;
    
    cin >> n >> m;
    
    char M[n][m + 1];
    
    for(int i = 0;i < n;++i)
        cin >> M[i];
    
    int sum[n + 1][m + 1];
    memset(sum,0,sizeof sum);
    
    for(int i = 0;i < n;++i)
        for(int j = 0;j < m;++j)
            sum[i + 1][j + 1] = M[i][j] - '0' + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
    
    int ans = 0;
    
    for(int r = 1;r <= n;++r)
        for(int c = 1;c <= m;++c){
            for(int i = 0;i + r <= n;++i)
                for(int j = 0;j + c <= m;++j){
                    int aux = sum[i + r][j + c] - sum[i + r][j] - sum[i][j + c] + sum[i][j];
                    if(aux == 0) ans = max(ans,2 * (r + c));
                }
        }
    
    cout << ans << endl;
    
    return 0;
}
