#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
    int N;
    string note[100],ans[77];
    int h[] = {4,3,2,1,7,6,5};
    
    while(true){
        cin >> N;
        if(N == -1) break;
        
        int lines = (N + 15) / 16;
        
        for(int i = 0;i < lines;++i){
            for(int j = 0;j < 11;++j){
                int num = 11*i + j;
                string &s = ans[num];
                
                s.clear();
                
                if(i == 0) s += "||";
                else s += " |";
                
                for(int k = 0;k < 4;++k){
                    if(j % 2 == 0) s += string(24,' ');
                    else s += string(24,'-');
                    s  += '|';
                }
                
                if(i == lines-1) s += '|';
            }
        }
        
        for(int i = 0,j = 0;i < N;++i){
            cin >> note[i];
            
            int pos = 2 + (i % 16) / 4 + 6 * (i % 16),num = 11 * j + h[note[i][0]-'A'];
            
            ans[num][pos + 2] = '|';
            ans[num][pos + 3] = '\\';
            ans[num + 1][pos + 2] = '|';
            ans[num + 2][pos + 1] = 'x';
            ans[num + 2][pos + 2] = '|';
            
            if(note[i].size() == 2) ans[num + 2][pos] = '#';
            if(i % 16 == 15) ++j;
        }
        
        for(int i = 0;i < lines*11;++i) puts(ans[i].c_str());
        puts("");
    }
    
    return 0;
}
