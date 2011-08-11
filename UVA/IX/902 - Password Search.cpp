#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

char s[1000001];

int main(){
    int N;
    map<long long, int> cont;
    
    while(scanf("%d %s",&N,s) == 2){
        int L = strlen(s);
        cont.clear();
        
        for(int i = 0;i + N <= L;++i){
            long long aux = 0;
            
            for(int j = 0;j < N;++j)
                aux = aux*26 + (s[i+j]-'a');
            
            cont[aux]++;
        }
        
        long long ans_hash;
        int best = -1;
        
        for(map<long long, int> :: iterator it = cont.begin();it != cont.end();it++){
            if(it->second > best){
                ans_hash = it->first;
                best = it->second;
            }
        }
        
        string ans;
        
        for(int i = 0;i < N;++i){
            ans = (char)(ans_hash % 26 + 'a') + ans;
            ans_hash /= 26;
        }
        
        puts(ans.c_str());
    }
    
    return 0;
}
