#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAXN 100005

pair<int, int> a[MAXN];

int main(){
    int n;
    
    scanf("%d",&n);
    
    for(int i = 0;i < n;++i){
        scanf("%d",&a[i].first);
        a[i].second = i + 1;
    }
    
    sort(a,a + n);
    
    vector<int> t[2];
    
    for(int i = 0,aux = 0;i < n;++i,aux ^= 1)
        t[aux].push_back(a[i].second);
    
    printf("%d\n",(int)t[0].size());
    for(int i = 0;i < t[0].size();++i) printf("%d ",t[0][i]);
    printf("\n");
    
    printf("%d\n",(int)t[1].size());
    for(int i = 0;i < t[1].size();++i) printf("%d ",t[1][i]);
    printf("\n");
    
    return 0;
}
