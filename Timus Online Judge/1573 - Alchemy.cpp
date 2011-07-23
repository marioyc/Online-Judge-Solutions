#include <cstdio>

using namespace std;

int main(){
    int B,R,Y;
    
    scanf("%d %d %d",&B,&R,&Y);
    
    int N,ans = 1;
    char s[7];
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i){
        scanf("%s",s);
        
        if(s[0] == 'B') ans *= B;
        if(s[0] == 'R') ans *= R;
        if(s[0] == 'Y') ans *= Y;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
