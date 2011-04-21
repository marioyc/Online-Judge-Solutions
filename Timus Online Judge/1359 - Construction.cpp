#include <cstdio>
#include <math.h>

using namespace std;

int main(){
    int W,H;
    double dp[51][51];
    
    scanf("%d %d",&W,&H);
    
    for(int i = 0;i <= H;++i)
        for(int j = 0;j <= W;++j)
            dp[i][j] = -1;
    
    dp[0][0] = 0;
    
    for(int h1 = 0;h1 < H;++h1){
        for(int x1 = 0;x1 <= W;++x1){
            for(int h2 = h1+1,dh = 1;h2 <= H;++h2, ++dh){
                for(int x2 = x1,dx = 0;x2 <= W;++x2, ++dx){
                    if(dp[h1][x1] > -0.5){
                        double v = sqrt((double)20 * h1);
                        double x = sqrt((double)dh * dh + dx * dx);
                        double a = 10 * dh / x;
                        double t = (-v + sqrt(v * v + 2 * a * x)) / a + dp[h1][x1];
                        
                        if(dp[h2][x2] < -0.5 || t < dp[h2][x2]) dp[h2][x2] = t;
                    }
                }
            }
        }
    }
    
    printf("%.4f\n",dp[H][W]);
    
    return 0;
}
