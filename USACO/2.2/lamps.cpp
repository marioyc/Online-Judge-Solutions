/*
ID:zion_ba1
LANG:C++
TASK:lamps
*/

#include <cstdio>
#include <string>
#include <set>

using namespace std;

int main(){
    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);
    
    int N,C;
    
    scanf("%d %d",&N,&C);
    
    int L1[N],L2[N],on=0,off=0,num;
    
    while(1){
        scanf("%d",&num);
        if(num==-1) break;
        L1[on++]=num-1;
    }
    
    while(1){
        scanf("%d",&num);
        if(num==-1) break;
        L2[off++]=num-1;
    }
    
    int state[N];
    bool impossible=true;
    set<string> S;
    
    for(int i1=0;i1<2;i1++){
        for(int i2=0;i2<2;i2++){
            for(int i3=0;i3<2;i3++){
                for(int i4=0;i4<2;i4++){
                    int m=i1+i2+i3+i4;
                    if(m>C || m%2!=C%2) continue;
                    
                    fill(state,state+N,1);
                    
                    if(i1) for(int i=0;i<N;i++) state[i]^=1;
                    if(i2) for(int i=0;i<N;i+=2) state[i]^=1;
                    if(i3) for(int i=1;i<N;i+=2) state[i]^=1;
                    if(i4) for(int i=0;i<N;i+=3) state[i]^=1;
                    
                    bool valid=true;
                    
                    for(int i=0;i<on;i++) if(state[L1[i]]==0) valid=false;
                    for(int i=0;i<off;i++) if(state[L2[i]]==1) valid=false;
                    
                    if(!valid) continue;
                    
                    impossible=false;
                    
                    string s;
                    for(int i=0;i<N;i++) s+=('0'+state[i]);
                    S.insert(s);
                }
            }
        }
    }
    
    if(impossible) printf("IMPOSSIBLE\n");
    else{
        set<string> :: iterator it;
        for(it=S.begin();it!=S.end();it++) printf("%s\n",(*it).c_str());
    }
    
    return 0;
}
