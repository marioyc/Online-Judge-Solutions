#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct node{
    int first,second,ind;
    
    node(){}
    
    bool operator < (node X)const{
        return first < X.first;
    }
};

int main(){
    int n;
    
    scanf("%d",&n);
    
    node a[n];
    
    for(int i = 0;i < n;++i){
        scanf("%d %d",&a[i].first,&a[i].second);
        a[i].ind = i + 1;
    }
    sort(a,a + n);
    
    int ans = 0;
    vector<int> sol;
    
    for(int i = 0;i < n;++i){
        int cure = 0;
        bool ok = true;
        
        for(int j = 0;j < n;++j){
            if(j != i){
                if(a[j].first >= cure) cure = a[j].second;
                else ok = false;
            }
        }
        
        if(ok){
            ++ans;
            sol.push_back(a[i].ind);
        }
    }
    
    sort(sol.begin(),sol.end());
    printf("%d\n",ans);
    for(int i = 0;i < ans;++i) printf("%d ",sol[i]);
    printf("\n");
    
    return 0;
}
