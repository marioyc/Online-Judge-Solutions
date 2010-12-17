#include <cstdio>

using namespace std;

int main(){
    int n,x;
    
    while(scanf("%d %d",&n,&x)==2){
        --x;
        
        int r = x/n,c = x%n;
        
        if(r<c){
            r = 0;
            c = c-r;
        }else{
            r = r-c;
            c = 0;
        }
        
        while(r<n && c<n){
            if(r>0 && c>0) putchar(' ');
            printf("%lld",(long long)r*n+c+1);
            ++r; ++c;
        }
        
        putchar('\n');
    }
    
    return 0;
}
