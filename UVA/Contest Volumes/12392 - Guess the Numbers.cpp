#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

char s[100];
int L,val[256];

pair<int, int> eval(int pos){
    int ret = 0;
    
    if(s[pos] == '('){
        ++pos;
        
        pair<int, int> p1 = eval(pos);
        pair<int, int> p2 = eval(p1.second + 1);
        
        pos = p1.second;
        
        if(s[pos] == '+') ret = p1.first + p2.first;
        if(s[pos] == '-') ret = p1.first - p2.first;
        if(s[pos] == '*') ret = p1.first * p2.first;
        
        pos = p2.second + 1;
    }else{
        ret = val[ s[pos] ];
        ++pos;
    }
    
    return make_pair(ret,pos);
}

int main(){
    int N,v[5],M;
    bool used[26];
    char var[5];
    
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        
        for(int i = 0;i < N;++i)
            scanf("%d",&v[i]);
        
        scanf("%d %s",&M,s);
        
        memset(used,false,sizeof used);
        L = strlen(s);
        
        for(int i = 0;i < L;++i)
            if(s[i] >= 'a' && s[i] <= 'z')
                used[ s[i] - 'a' ] = true;
        
        for(int i = 0,j = 0;i < 26;++i)
            if(used[i]) var[j++] = 'a' + i;
        
        sort(v,v + N);
        
        bool found = false;
        
        do{
            for(int i = 0;i < N;++i)
                val[ var[i] ] = v[i];
            
            if(eval(0).first == M){
                found = true;
                break;
            }
        }while(next_permutation(v,v + N));
        
        puts(found? "YES" : "NO");
    }
    
    return 0;
}
