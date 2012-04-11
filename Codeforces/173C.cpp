#include <cstdio>
#include <cstring>
#include <climits>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int sum[501][501];

int get_sum(int r1, int c1, int r2, int c2){
    return sum[r2 + 1][c2 + 1] - sum[r2 + 1][c1] - sum[r1][c2 + 1] + sum[r1][c1];
}

int main(){
    int n,m;
    
    scanf("%d %d",&n,&m);
    
    int M[n][m];
    
    for(int i = 0;i < n;++i)
        for(int j = 0;j < m;++j)
            scanf("%d",&M[i][j]);
    
    memset(sum,0,sizeof sum);
    
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j)
            sum[i][j] = M[i - 1][j - 1] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
    
    int ans = -9000;
    
    for(int r = 1;r + 1 < n;++r){
        for(int c = 1;c + 1 < m;++c){
            int s1 = get_sum(r - 1,c - 1,r + 1, c + 1) - M[r][c] - M[r][c - 1],s2 = M[r][c] + M[r][c - 1];
            
            ans = max(ans,s1);
            
            for(int L = 2,aux = 0;r >= L && r + L < n && c >= L && c + L < m;++L, aux ^= 1){
                if(aux == 0){
                    s2 += get_sum(r - L,c - L,r + L,c + L) - get_sum(r - (L - 1),c - (L - 1),r + (L - 1),c + (L - 1)) - M[r - L + 1][c - L];
                    s1 += M[r - L + 1][c - L];
                    ans = max(ans,s2);
                }else{
                    s1 += get_sum(r - L,c - L,r + L,c + L) - get_sum(r - (L - 1),c - (L - 1),r + (L - 1),c + (L - 1)) - M[r - L + 1][c - L];
                    s2 += M[r - L + 1][c - L];
                    ans = max(ans,s1);
                }
            }
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
