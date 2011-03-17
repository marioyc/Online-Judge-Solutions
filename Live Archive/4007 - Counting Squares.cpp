#include <cstdio>
#include <cstring>

using namespace std;

char s[1000001];
int x[1000001],y[1000001];

int main(){
    int T,n;
    
    scanf("%d",&T);
    
    for(int tc = 1;tc<=T;++tc){
        scanf("%s",s);
        
        n = strlen(s);
        
        x[0] = y[0] = 0;
        
        for(int i = 1;i<=n;++i){
            if(s[i-1] == 'U'){
                x[i] = x[i-1];
                y[i] = y[i-1]+1;
            }else if(s[i-1] == 'D'){
                x[i] = x[i-1];
                y[i] = y[i-1]-1;
            }else if(s[i-1] == 'L'){
                x[i] = x[i-1]-1;
                y[i] = y[i-1];
            }else{
                x[i] = x[i-1]+1;
                y[i] = y[i-1];
            }
        }
        
        int S = 0;
        
        for(int i = 0;i<n;++i)
            S += x[i]*y[i+1]-x[i+1]*y[i];
        
        S += x[n]*y[0]-x[0]*y[n];
        
        if(S<0) S = -S;
        S /= 2;
        
        printf("case %d: %d\n",tc,S);
    }
    
    return 0;
}
