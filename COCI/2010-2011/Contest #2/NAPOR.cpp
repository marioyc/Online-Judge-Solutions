#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool comp(string A, string B){
    int L1 = A.size(),L2 = B.size();
    if(L1!=L2) return L1<L2;
    return A<B;
}

int main(){
    int N;
    scanf("%d",&N);
    char s[101];
    
    vector<string> L;
    
    for(int i = 0;i<N;++i){
        scanf("%s",s);
        int M = strlen(s);
        
        for(int j = 0;j<M;){
            if(!(s[j]>='0' && s[j]<='9')){
                ++j;
                continue;
            }
            
            string num;
            bool start = true;
            
            while(j<M && (s[j]>='0' && s[j]<='9')){
                if(start && s[j]=='0'){
                    ++j;
                    continue;
                }else start = false;
                
                num += s[j];
                ++j;
            }
            
            if(start) num = "0";
            
            L.push_back(num);
        }
    }
    
    sort(L.begin(),L.end(),comp);
    
    for(int i = 0;i<L.size();++i) printf("%s\n",L[i].c_str());
    
    return 0;
}
