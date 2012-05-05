#include <cstdio>
#include <algorithm>

using namespace std;

char ans1[1000001],ans2[1000001];

int main(){
    int t[181];
    
    for(int i = 1;i <= 180;++i)
        t[i] = i * (i + 1) * (i + 2) / 6;
    
    ans1[0] = ans2[0] = 0;
    
    for(int i = 1;i <= 1000000;++i){
        ans1[i] = 5;
        ans2[i] = 40;
    }
    
    for(int i = 1;i <= 180;++i)
        for(int j = i;j <= 180 && t[i] + t[j] <= 1000000;++j)
            for(int k = j;k <= 180 && t[i] + t[j] + t[k] <= 1000000;++k)
                ans1[ t[i] + t[j] + t[k] ] = 3;
    
    for(int i = 1;i <= 180;++i)
        for(int j = i;j <= 180 && t[i] + t[j] <= 1000000;++j)
            ans1[ t[i] + t[j] ] = 2;
    
    for(int i = 1;i <= 180;++i)
        ans1[ t[i] ] = 1;
    
    for(int i = 1;i <= 1000000;++i){
        if(ans1[i] == 3){
            for(int j = 1;j <= 180 && i + t[j] <= 1000000;++j)
                if(ans1[i + t[j]] == 5) ans1[i + t[j]] = 4;
        }
    }
    
    for(int i = 1;i <= 180;++i){
        int x = t[i];
        
        if(x & 1)
            for(int j = x;j <= 1000000;++j)
                if(1 + ans2[j - x] < ans2[j]) ans2[j] = 1 + ans2[j - x];
    }
    
    int n;
    
    while(true){
        scanf("%d",&n);
        
        if(n == 0) break;
        
        printf("%d %d\n",ans1[n],ans2[n]);
    }
    
    return 0;
}
