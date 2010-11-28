#include <cstdio>
#include <algorithm>

using namespace std;

struct interval{
    int s,e;
    
    interval(){}
    
    bool operator < (interval X)const{
        return e<X.e;
    }
}I[100000];

int main(){
    int N;
    scanf("%d",&N);
    
    for(int i = 0;i<N;++i) scanf("%d %d",&I[i].s,&I[i].e);
    sort(I,I+N);
    
    int last = 0,ans = 0;
    
    for(int i = 0;i<N;++i){
        if(I[i].s>last){
            last = I[i].e;
            ++ans;
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
