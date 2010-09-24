#include <cstdio>
#include <cstring>
#include <deque>
#include <string>

using namespace std;

int main(){
    int N,M,K;
    deque<string> Q; int cont;
    char s[4];
    bool dir=0; //dir=0 -> pop_back() , dir=1 -> pop_front()
    char L[140000][4]; int sz = 0;
    char op[9];
    
    scanf("%d %d %d\n",&N,&M,&K);
    
    if(N>K){
        for(int i = 0;i<K;++i){
            scanf("%s\n",s);
            Q.push_back(s);
        }
        cont=K;
        
        for(int i = N-K-1;i>=0;--i){
            ++sz;
            scanf("%s\n",L[i]);
        }
    }else{
        for(int i = 0;i<N;++i){
            scanf("%s\n",s);
            Q.push_back(s);
        }
        cont = N;
    }
    
    for(int i = 0;i<M;++i){
        scanf("%s\n",op);
        
        if(op[0]=='R') dir ^= 1;
        else{
            memset(s,0,sizeof(s));
            for(int j = 4;op[j]!=')';++j) s[j-4] = op[j];
            
            if(K!=0){
                if(cont==K){
                    if(dir==0){
                        memcpy(L[sz++],Q.back().c_str(),4);
                        Q.pop_back();
                    }else{
                        memcpy(L[sz++],Q.front().c_str(),4);
                        Q.pop_front();
                    }
                }else ++cont;
                
                if(dir==0) Q.push_front(s);
                else Q.push_back(s);
            }else memcpy(L[sz++],s,4);
        }
    }
    
    if(dir==0){
        for(int i = 0;i<cont;++i){
            memcpy(L[sz],Q.back().c_str(),4);
            ++sz;
            Q.pop_back();
        }
    }else{
        for(int i = 0;i<cont;++i){
            memcpy(L[sz],Q.front().c_str(),4);
            ++sz;
            Q.pop_front();
        }
    }
    
    for(int i = sz-1;i>=0;--i) printf("%s\n",L[i]);
    
    return 0;
}
