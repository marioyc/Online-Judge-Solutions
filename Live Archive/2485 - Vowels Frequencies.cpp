#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

bool comp(pair<char, int> A, pair<char, int> B){
    return A.second>B.second;
}

int main(){
    char s[205];
    
    while(true){
        fgets(s,205,stdin);
        int L = strlen(s);
        
        if(L==2 && s[0]=='#') break;
        
        pair<char, int> P[5];
        
        P[0].first = 'a'; P[1].first = 'e';
        P[2].first = 'i'; P[3].first = 'o';
        P[4].first = 'u';
        
        for(int i = 0;i<5;++i) P[i].second = 0;
        
        for(int i = 0;i<L;++i){
            if(s[i]=='a' || s[i]=='A') ++P[0].second;
            if(s[i]=='e' || s[i]=='E') ++P[1].second;
            if(s[i]=='i' || s[i]=='I') ++P[2].second;
            if(s[i]=='o' || s[i]=='O') ++P[3].second;
            if(s[i]=='u' || s[i]=='U') ++P[4].second;
        }
        
        stable_sort(P,P+5,comp);
        
        for(int i = 0;i<5;++i){
            if(i>0) putchar(' ');
            putchar(P[i].first);
            putchar(':');
            printf("%d",P[i].second);
        }
        
        puts(".");
    }
    
    return 0;
}
