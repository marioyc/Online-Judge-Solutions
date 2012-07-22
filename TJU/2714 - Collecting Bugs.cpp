#include <cstdio>

using namespace std;

double dp[1001][1001];

int main(){
    int n,s;
    
    scanf("%d %d",&n,&s);
    
    for(int i = n;i >= 0;--i){
        for(int j = s;j >= 0;--j){
            if(i == n && j == s) dp[i][j] = 0;
            else{
                dp[i][j] = n * s;
                
                if(j != s) dp[i][j] += i * (s - j) * dp[i][j + 1];
                if(i != n) dp[i][j] += (n - i) * j * dp[i + 1][j];
                if(i != n && s != j) dp[i][j] += (n - i) * (s - j) * dp[i + 1][j + 1];
                
                dp[i][j] /= n * s - i * j;
            }
        }
    }
    
    printf("%.4f\n",dp[0][0]);
    
    return 0;
}
