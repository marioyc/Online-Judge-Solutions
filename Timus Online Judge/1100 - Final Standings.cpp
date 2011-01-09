#include <cstdio>
#include <algorithm>

using namespace std;

struct team{
    int id,solved;
    
    team(){}
    
    bool operator < (team X)const{
        return solved>X.solved;
    }
}a[150000];

int main(){
    int N;
    scanf("%d",&N);
    
    for(int i = 0;i<N;++i)
        scanf("%d %d",&a[i].id,&a[i].solved);    
    
    stable_sort(a,a+N);
    
    for(int i = 0;i<N;++i)
        printf("%d %d\n",a[i].id,a[i].solved);
    
    return 0;
}
