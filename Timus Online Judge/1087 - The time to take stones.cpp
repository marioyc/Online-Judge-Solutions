#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    
    int a[50];
    for(int i = 0;i<m;++i) scanf("%d",&a[i]);
    
    bool win[10001];
    win[0] = true;
    
    for(int i = 1;i<=n;++i){
        win[i] = false;
        
        for(int j = 0;j<m;++j)
            if(i>=a[j] && !win[i-a[j]])
                win[i] = true;
    }
    
    if(win[n]) putchar('1');
    else putchar('2');
    
    return 0;
}
