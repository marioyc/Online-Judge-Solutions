#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int n;
    
    scanf("%d",&n);
    
    pair<int, int> s[n];
    int pos[n];
    
    for(int i = 0;i < n;++i){
        scanf("%d",&s[i].first);
        s[i].second = i;
    }
    
    sort(s,s + n);
    
    for(int i = 0;i < n;++i)
        pos[ s[i].second ] = i;
    
    int k = (n + 2) / 3;
    
    int a[n],b[n];
    
    for(int i = 0,j = 0;i < n && j < k;++i){
        a[i] = i;
        b[i] = s[i].first - i;
    }
    
    for(int i = k,j = 0;i < n && j < k;++i){
        b[i] = i;
        a[i] = s[i].first - i;
    }
    
    for(int i = n - 1;i >= 2 * k;--i){
        b[i] = n - 1 - i;
        a[i] = s[i].first - n + 1 + i;
    }
    
    printf("YES\n");
    
    for(int i = 0;i < n;++i) printf("%d ",a[ pos[i] ]);
    printf("\n");
    for(int i = 0;i < n;++i) printf("%d ",b[ pos[i] ]);
    printf("\n");
    
    return 0;
}
