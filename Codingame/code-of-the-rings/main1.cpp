#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

 const int ZONES = 30;
 
int val(char c){
    if(c == ' ') return 0;
    return c - 'A' + 1;
}

int moves(int s, int e){
    int pos,neg;
    if(s <= e){
        pos = e - s;
        neg = 27 - pos;
    }else{
        neg = s - e;
        pos = 27 - neg;
    }
    
    if(neg < pos) return -neg;
    else return pos;
}

int main()
{
    string magicPhrase;
    getline(cin, magicPhrase);
    
    string sol;
    int pos[ZONES],curZone = 0;
    int ans[ZONES];

    memset(pos,0,sizeof pos);
    
    for(int i = 0;i < magicPhrase.size();++i){
        int want = val(magicPhrase[i]);
        /*int m = moves(pos[curZone],want);
        
        if(m > 0){
            for(int i = 0;i < m;++i){
                ans += '+';
            }
        }else{
            for(int i = 0;i < -m;++i){
                ans += '-';
            }
        }
        
        pos[curZone] = want;*/

        for(int j = 0;j < curZone;++j){
            ans[j] = curZone - j + abs(moves(pos[j],want));
        }

        for(int j = curZone;j < ZONES;++j){
            ans[j] = j - curZone + abs(moves(pos[j],want));
        }

        int best = 0;

        for(int i = 1;i < ZONES;++i){
            if(ans[i] < ans[best]){
                best = i;
            }
        }

        if(curZone < best){
            for(int i = 0;i < best - curZone;++i){
                sol += ">";
            }
        }else{
            for(int i = 0;i < curZone - best;++i){
                sol += "<";
            }
        }

        curZone = best;

        int m = moves(pos[curZone],want);
        
        if(m > 0){
            for(int i = 0;i < m;++i){
                sol += '+';
            }
        }else{
            for(int i = 0;i < -m;++i){
                sol += '-';
            }
        }
        
        pos[curZone] = want;

        sol += '.';
    }
    
    cout << sol << endl;
}