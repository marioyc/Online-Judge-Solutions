#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main(){
    int x,y,a,b;
    
    scanf("%d %d %d %d",&x,&y,&a,&b);
    
    vector< pair<int, int> > ans;
    
    for(int i = a;i <= x;++i)
        for(int j = b;j <= min(y,i - 1);++j)
            ans.push_back(make_pair(i,j));
    
    printf("%d\n",(int)ans.size());
    
    for(int i = 0;i < ans.size();++i)
        printf("%d %d\n",ans[i].first,ans[i].second);
    
    return 0;
}
