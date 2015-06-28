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

bool foundRepeated(string &s, int pos, pair<int, int> &rep){
    int len = s.size();

    for(int i = 1;i <= ZONES - 1 && pos + i <= len;++i){
        string aux = s.substr(pos,i);
        int p = pos + i;
        rep.first = 1;
        rep.second = i;

        while(p + i <= len && s.substr(p,i) == aux){
            p += i;
            ++rep.first;
        }
        
        if(i == 1 && rep.first >= 17){
            if(rep.first % 26 < 17)
                rep.first -= rep.first % 26;
            return true;
        }

        if(i == 2 && rep.first >= 8) return true;
        if(i == 3 && rep.first >= 6) return true;
        if(i == 4 && rep.first >= 4) return true;
        if(i == 5 && rep.first >= 4) return true;
        if(i >= 6 && rep.first > 2) return true;
    }

    return false;
}

int main()
{
    string magicPhrase;
    getline(cin, magicPhrase);
    
    string sol;
    int pos[ZONES],curZone = 0;
    int ans[ZONES];

    memset(pos,0,sizeof pos);

    pair<int, int> repeated;
    
    for(int i = 0;i < magicPhrase.size();){
        if(foundRepeated(magicPhrase,i,repeated)){
            //cout << repeated.first << " " << repeated.second << endl;
            for(int j = 0;j < curZone;++j)
                ans[j] = curZone - j;
            for(int j = curZone;j < ZONES;++j)
                ans[j] = j - curZone;

            for(int j = 0;j < ZONES;++j)
                for(int k = 0;k < repeated.second;++k)
                    ans[j] += abs(moves(pos[(j + k) % ZONES],val(magicPhrase[i + k])));

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

            for(int j = 0;j < repeated.second;++j){
                int want = val(magicPhrase[i + j]);
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
            }

            int have = repeated.first;

            while(have > 0){
                int want = min(26,have);
                have -= want;

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

                sol += "[";

                for(int j = 0;j < repeated.second;++j)
                    sol += "<";

                for(int j = 0;j < repeated.second;++j)
                    sol += ".>";

                sol += "-]";
            }

            i += repeated.first * repeated.second;
            pos[curZone] = 0;

            /*cout << sol << endl;

            cout << "curZone = " << curZone << endl;

            for(int j = 0;j < ZONES;++j)
                cout << pos[j] << " ";
            cout << endl;*/
            cout << sol << endl;
        }else{
            int want = val(magicPhrase[i]);

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

            /*cout << "i = " << i << " -> " << sol << endl;
            if(i == 52){
                cout << "curZone = " << curZone << endl;

                for(int j = 0;j < ZONES;++j)
                    cout << pos[j] << " ";
                cout << endl;
            }*/
            ++i;
        }
    }
    
    cout << sol << endl;
}