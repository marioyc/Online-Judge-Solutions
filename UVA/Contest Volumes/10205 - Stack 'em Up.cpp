#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;

int main(){
    int T,N,K;
    int p[100][52];
    int cur[52],nxt[52];
    string line;
    char s1[][6] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
    char s2[][9] = {"Clubs","Diamonds","Hearts","Spades"};
    bool first = true;
    
    cin >> T;
    
    while(T--){
        cin >> N;
        
        for(int i = 0;i < N;++i){
            for(int j = 0;j < 52;++j){
                cin >> p[i][j];
                --p[i][j];
            }
        }
        
        for(int i = 0;i < 52;++i) cur[i] = i;
        
        getline(cin,line);
        
        while(getline(cin,line)){
            if(line.empty()) break;
            
            istringstream is(line);
            is >> K;
            --K;
            
            for(int i = 0;i < 52;++i) nxt[i] = cur[p[K][i]];
            for(int i = 0;i < 52;++i) cur[i] = nxt[i];
        }
        
        if(!first) printf("\n");
        first = false;
        
        for(int i = 0;i < 52;++i)
            printf("%s of %s\n",s1[cur[i] % 13],s2[cur[i] / 13]);
    }
    
    return 0;
}
