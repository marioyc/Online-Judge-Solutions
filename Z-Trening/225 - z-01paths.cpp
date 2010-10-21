#include <cstdio>
#include <cstring>

using namespace std;

int e;
long long memo[51][4];

int next[8] = {2,1,3,0,0,3,1,2};

long long count(int n, int pos){
    if(n==0) return (pos==e);
    
    long long &ret = memo[n][pos];
    if(ret!=-1) return ret;
    
    ret = count(n-1,next[2*pos])+count(n-1,next[2*pos+1]);
    return ret;
}

int main(){
    char R;
    int n,k;
    
    scanf("%c %d %d",&R,&n,&k);
    e = R-'A';
    
    memset(memo,-1,sizeof(memo));
    
    if(count(n,0)<k) printf("impossible\n");
    else{
        for(int i = 0,pos = 0;i<n;++i){
            long long aux = count(n-1-i,next[2*pos]);
            
            if(aux>=k){
                printf("0");
                pos = next[2*pos];
            }else{
                printf("1");
                pos = next[2*pos+1];
                k -= aux;
            }
        }
        printf("\n");
    }
    
    return 0;
}
