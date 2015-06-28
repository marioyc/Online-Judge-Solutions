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
    
    for(int i = 0;i < magicPhrase.size();){
        int want = val(magicPhrase[i]);
        int e = i;

        while(e < magicPhrase.size() && magicPhrase[e] == magicPhrase[i] && e - i < 26) ++e;

        if(e - i >= 17){
            int m = moves(pos[curZone],want);

            if(m > 0){
                for(int j = 0;j < m;++j){
                    sol += '+';
                }
            }else{
                for(int j = 0;j < -m;++j){
                    sol += '-';
                }
            }
            
            pos[curZone] = want;

            curZone = (curZone + 1) % ZONES;
            sol += ">";

            int want2 = e - i;
            int m2 = moves(pos[curZone],want2);

            if(m2 > 0){
                for(int j = 0;j < m2;++j){
                    sol += '+';
                }
            }else{
                for(int j = 0;j < -m2;++j){
                    sol += '-';
                }
            }

            sol += "[<.>-]";
            i = e;
        }else{
            for(int j = 0;j < curZone;++j){
                ans[j] = curZone - j + abs(moves(pos[j],want));
            }

            for(int j = curZone;j < ZONES;++j){
                ans[j] = j - curZone + abs(moves(pos[j],want));
            }

            int best = 0;

            for(int j = 1;j < ZONES;++j){
                if(ans[j] < ans[best]){
                    best = j;
                }
            }

            if(curZone < best){
                for(int j = 0;j < best - curZone;++j){
                    sol += ">";
                }
            }else{
                for(int j = 0;j < curZone - best;++j){
                    sol += "<";
                }
            }

            curZone = best;

            int m = moves(pos[curZone],want);
            
            if(m > 0){
                for(int j = 0;j < m;++j){
                    sol += '+';
                }
            }else{
                for(int j = 0;j < -m;++j){
                    sol += '-';
                }
            }
            
            pos[curZone] = want;

            sol += '.';
            ++i;
        }
    }
    
    cout << sol << endl;
}