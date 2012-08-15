#include <cstdio>

using namespace std;

int a[800000];
bool have[1000001];
long long cont[800001];

void readInt(int &n){
    int sign = 1;
    char c;
    bool found = false;
    n = 0;
    
    while(true){
      c = getc(stdin);
      
        switch(c){
            case '-' :
                sign = -1;
                found = true;
                break;
            case ' ':
                if(found) goto jump;
                break;
            case '\n':
                if(found) goto jump;
                break;
            default:
                if(c>='0' && c<='9'){
                    n = n*10+c-'0';
                    found = true;
                }else goto jump;
                break;
        }
    }
    
    jump:
        n *= sign;
}

int main(){
    int N;
    
    scanf("%d",&N);
    
    for(int i = 0;i < N;++i)
        readInt(a[i]);
    
    for(int i = 0,j = 0;i < N;++i){
        while(j < N && !have[ a[j] ]){
            have[ a[j] ] = true;
            ++j;
        }
        
        have[ a[i] ] = false;
        ++cont[j - i];
    }
    
    for(int i = N - 1;i >= 1;--i) cont[i] += cont[i + 1];
    for(int i = 1;i <= N;++i) cont[i] += cont[i - 1];
    
    int Q,a,b;
    
    scanf("%d",&Q);
    
    while(Q--){
        scanf("%d %d",&a,&b);
        printf("%lld\n",cont[b] - cont[a - 1]);
    }
    
    return 0;
}
