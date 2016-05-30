#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 100

bool have[MAXN];

int get_kth(int x){
    int pos = 0;

    while(x > 0){
        if(have[pos]) --x;
        ++pos;
    }

    return pos;
}

int main(){
    int T,N,Q,x;
    char op[2];

    scanf("%d",&T);

    while(T--){
        scanf("%d %d",&N,&Q);

        memset(have,true,sizeof have);

        while(Q--){
            scanf("%s %d",op,&x);

            if(op[0] == '-'){
                --x;
                have[x] = have[N - 1 - x] = false;
            }else if(op[0] == '?'){
                printf("%d\n",get_kth(x));
            }
        }
    }

    return 0;
}
