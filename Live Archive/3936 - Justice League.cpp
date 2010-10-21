#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int H,R,U[100000],V[100000],pos[50000],cont[50000];
    pair<int, int> P[50000];
    
    while(true){
        scanf("%d %d",&H,&R);
        if(H==0 && R==0) break;
        
        for(int i = 0;i<H;++i){
            P[i].second = i;
            P[i].first = 0;
        }
        
        
        for(int i = 0;i<R;++i){
            scanf("%d %d",&U[i],&V[i]);
            --U[i]; --V[i];
            ++P[U[i]].first;
            ++P[V[i]].first;
        }
        
        sort(P,P+H);
        
        for(int i = 0;i<H;++i) pos[P[i].second] = i;
        
        memset(cont,0,sizeof(cont));
        
        for(int i = 0;i<R;++i){
            if(pos[U[i]]<pos[V[i]])
                ++cont[U[i]];
            else
                ++cont[V[i]];
        }
        
        int M = 0;
        
        for(int i = H-1;i>=0;--i){
            if(cont[P[i].second]!=H-1-i) break;
            ++M;
        }
        
        bool valid = true;
        
        for(int i = 0;i<R && valid;++i)
            if(pos[U[i]]<H-M && pos[V[i]]<H-M)
                valid = false;
        
        printf("%c\n",valid? 'Y' : 'N');
    }
    
    return 0;
}
