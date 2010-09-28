#include <cstdio>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(){
    int T,n,b;
    scanf("%d",&T);
    
    char tp[21],nm[21];
    int p,q;
    map<string, vector< pair<int,int> > > M; map<string, vector< pair<int,int> > > :: iterator it;
    int lo,hi,mi,P;
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d %d",&n,&b);
        
        M.clear();
        
        for(int i=0;i<n;i++){
            scanf("%s %s %d %d",tp,nm,&p,&q);
            M[tp].push_back(make_pair(p,q));
        }
        
        lo=0;hi=1000000000;
        
        while(lo!=hi){
            mi=(lo+hi+1)>>1;
            P=0;
            
            for(it=M.begin();it!=M.end();it++){
                p=b+1;
                for(int i=(*it).second.size()-1;i>=0;i--)
                    if((*it).second[i].second>=mi) p<?=(*it).second[i].first;
                P+=p;
            }
            
            if(P<=b) lo=mi;
            else hi=mi-1;
        }
        
        printf("%d\n",lo);
    }
    
    return 0;
}
