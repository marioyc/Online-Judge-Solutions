#include <cstdio>
#include <string>
#include <map>

using namespace std;

map<string, int> vote;

int main(){
    int T,N;
    char name[21],sign;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d",&N);
        
        vote.clear();
        
        for(int i = 0;i < N;++i){
            scanf("%s %c\n",name,&sign);
            
            if(sign == '-') vote[name] = -1;
            else vote[name] = 1;
        }
        
        int ans = 0;
        
        for(map<string, int>::iterator it = vote.begin();it != vote.end();++it)
            ans += it -> second;
        
        printf("%d\n",ans);
    }
    
    return 0;
}
