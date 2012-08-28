#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char,string> M1;
map<string,char> M2;

int main(){
    char a[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_,.?";
    string b[30] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
        "....", "..", ".---", "-.-", ".-..", "--", "-.",
        "---", ".--.", "--.-", ".-.", "...", "-", "..-",
        "...-", ".--", "-..-", "-.--", "--..",
        "..--", ".-.-", "---.", "----"
    };
    
    for(int i = 0;i < 30;++i){
        M1[ a[i] ] = b[i];
        M2[ b[i] ] = a[i];
    }
    
    int T;
    char s[101];
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%s",s);
        
        int L = strlen(s);
        
        vector<int> v;
        string aux;
        
        for(int i = 0;i < L;++i){
            string x = M1[ s[i] ];
            aux += x;
            v.push_back(x.size());
        }
        
        reverse(v.begin(),v.end());
        
        string ans;
        
        for(int i = 0,pos = 0;i < L;++i){
            string x;
            
            for(int j = 0;j < v[i];++j)
                x += aux[pos++];
            
            ans += M2[x];
        }
        
        printf("%d: %s\n",tc,ans.c_str());
    }
    
    return 0;
}
