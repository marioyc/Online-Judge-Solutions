#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

const int ZONES = 30;

struct State{
    int curZone,pos[ZONES];
    int posSol;
    bool moves;
    string sol;

    State(){}
}S[500];
 
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
    int ans[ZONES],ans2[ZONES];

    memset(pos,0,sizeof pos);

    pair<int, int> repeated;
    int nS = 0;

    S[nS].curZone = 0;
    S[nS].posSol = 0;

    for(int i = 0;i < ZONES;++i)
        S[nS].pos[i] = 0;

    ++nS;
    
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

            int best = 0,dir = 1;

            for(int j = 1;j < ZONES;++j){
                if(ans[j] < ans[best]){
                    best = j;
                }
            }

            int aux = ans[best];

            for(int j = 0;j < curZone;++j)
                ans2[j] = curZone - j;
            for(int j = curZone;j < ZONES;++j)
                ans2[j] = j - curZone;

            for(int j = 0;j < ZONES;++j)
                for(int k = 0;k < repeated.second;++k)
                    ans2[j] += abs(moves(pos[(j + ZONES - k) % ZONES],val(magicPhrase[i + k])));

            for(int j = 0;j < ZONES;++j){
                if(ans2[j] < aux){
                    aux = ans2[j];
                    best = j;
                    dir = -1;
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

                if(dir == 1){
                    sol += ">";
                    curZone = (curZone + 1) % ZONES;
                }else{
                    sol += "<";
                    curZone = (curZone + ZONES - 1) % ZONES;
                }
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

                for(int j = 0;j < repeated.second;++j){
                    if(dir == 1) sol += "<";
                    else sol += ">";
                }

                for(int j = 0;j < repeated.second;++j){
                    if(dir == 1) sol += ".>";
                    else sol += ".<";
                }

                sol += "-]";
            }

            i += repeated.first * repeated.second;
            pos[curZone] = 0;

            /*cout << sol << endl;

            cout << "curZone = " << curZone << endl;

            for(int j = 0;j < ZONES;++j)
                cout << pos[j] << " ";
            cout << endl;*/
            //cout << sol << endl;
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
            ++i;
        }

        S[nS].curZone = curZone;
        S[nS].posSol = sol.size();

        for(int i = 0;i < ZONES;++i)
            S[nS].pos[i] = pos[i];

        ++nS;
    }

    //cout << sol << endl;

    for(int i = 1;i < nS;++i){
        /*cout << S[i].curZone << " | ";

        for(int j = 0;j < ZONES;++j)
            cout << S[i].pos[j] << " ";*/

        int len = S[i].posSol - S[i - 1].posSol;
        S[i].sol = sol.substr(S[i - 1].posSol,len);
        S[i].moves = false;

        for(int j = 0,p = S[i - 1].posSol;j < len;++j)
            if(sol[p + j] == '<' || sol[p + j] == '>')
                S[i].moves = true;

        //cout << "| " << S[i].posSol << " | " << sol.substr(S[i - 1].posSol,len) << " " << S[i].moves << endl;
    }

    string sol2 = "";

    for(int i = 1;i < nS;){
        if(!S[i].moves){
            int e = i;

            while(e < nS && e - i < 26 && S[e].sol == S[i].sol) ++e;

            if(e - i > 4 && S[i].sol.size() > 1){
                curZone = S[i].curZone;
                int tmp = S[i].pos[(curZone + 1) % ZONES];
                int tmp2 = S[i].pos[(curZone + ZONES - 1) % ZONES];

                int m = moves(tmp,e - i);
                int m2 = moves(tmp2,e - i);
                int aux = abs(m) + abs(moves(0,tmp)),aux2 = abs(m2) + abs(moves(0,tmp2));
                char a = '>',b = '<';

                if(aux2 < aux){
                    swap(m,m2);
                    swap(tmp,tmp2);
                    swap(a,b);
                }

                sol2 += a;

                if(m > 0){
                    for(int j = 0;j < m;++j){
                        sol2 += '+';
                    }
                }else{
                    for(int j = 0;j < -m;++j){
                        sol2 += '-';
                    }
                }

                sol2 += "[";
                sol2 += b;
                sol2 += S[i].sol;
                sol2 += a;
                sol2 += "-]";

                m = moves(0,tmp);

                if(m > 0){
                    for(int j = 0;j < m;++j){
                        sol2 += '+';
                    }
                }else{
                    for(int j = 0;j < -m;++j){
                        sol2 += '-';
                    }
                }

                sol2 += b;
                i = e;
            }else{
                sol2 += S[i].sol;
                ++i;
            }
        }else{
            sol2 += S[i].sol;
            ++i;
        }
    }

    assert(sol2.size() <= sol.size());
    cout << sol2 << endl;
}