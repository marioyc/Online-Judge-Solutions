#include <cstdio>
#include <algorithm>

using namespace std;

struct toy{
    int id,J,P;
    
    toy(){}
    toy(int _id, int _j, int _p):
        id(_id), J(_j), P(_p){}
    
    bool operator < (toy t)const{
        return (long long)J * t.P < (long long)t.J * P;
    }
}T[25000];

int main(){
    int N;
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i){
        scanf("%d %d",&T[i].J,&T[i].P);
        T[i].id = i + 1;
    }
    
    sort(T,T + N);
    
    printf("%d\n",T[N - 1].P + T[N - 2].P + T[N - 3].P);
    
    for(int i = N - 1;i >= N - 3;--i)
        printf("%d\n",T[i].id);
    
    return 0;
}
