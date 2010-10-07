#include <cstdio>
#include <algorithm>

using namespace std;

struct cow{
    int s,e;
    
    cow(){}
    
    bool operator < (cow C)const{
        return e<C.e;
    }
};

int main(){
    int N;
    scanf("%d",&N);
    
    cow a[N];
    
    for(int i = 0;i<N;++i)
        scanf("%d %d",&a[i].s,&a[i].e);
    
    sort(a,a+N);
    
    int ans = 1,last = a[0].e;
    
    for(int i = 1;i<N;++i){
        if(a[i].s>=last){
            last = a[i].e;
            ++ans;
        }
    }
    
    printf("%d\n",ans);
    
    return 0;
}
