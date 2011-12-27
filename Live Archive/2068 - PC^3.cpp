#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main(){
    int tc,P,T,R;
    int val[13];
    map<int, int> sc;
    set< pair<int, int> > S;
    
    while(true){
        scanf("%d %d %d %d",&tc,&P,&T,&R);
        if(tc == 0 && P == 0 && T == 0 && R == 0) break;
        
        for(int i = 1;i <= P;++i)
            scanf("%d",&val[i]);
        
        sc.clear();
        S.clear();
        
        for(int i = 0,tm,p,t,st;i < R;++i){
            scanf("%d %d %d %d",&tm,&p,&t,&st);
            
            if(st == 0 && S.find(make_pair(tm,p)) == S.end()){
                S.insert(make_pair(tm,p));
                sc[tm] += val[p];
            }
        }
        
        int mx = 0;
        
        for(map<int, int> :: iterator it = sc.begin();it != sc.end();it++)
            mx = max(mx,it -> second);
        
        printf("Contest %d Winner: ",tc);
        
        bool first = true;
        
        for(map<int, int> :: iterator it = sc.begin();it != sc.end();it++){
            if(it -> second == mx){
                if(!first) printf(" and ");
                first = false;
                
                printf("Team %d",it -> first);
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
