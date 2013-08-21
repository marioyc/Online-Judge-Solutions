#include <cstdio>

using namespace std;

int main(){
    int N;
    
    scanf("%d",&N);
    
    if(N == 0) printf("0\n");
    else if(N == 1) printf("1\n");
    else{
        int ans = 1,x = 2,y = 2;
        
        for(int i = 2;i <= N;++i){
            ans += x * y;
            if(i & 1) ++x;
            else ++y;
        }
        
        printf("%d\n",ans);
    }
    
    return 0;
}
