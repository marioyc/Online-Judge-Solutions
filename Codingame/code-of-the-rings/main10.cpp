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
    int len,posSol;
    string sol;

    bool moves;

    int le,ri,diff;
    bool noBraces;

    State(){}
}S[500];
int nS = 0;

int val(char c){
    if(c == ' ') return 0;
    return c - 'A' + 1;
}

int moves(int s, int e, int n){
    int pos,neg;
    if(s <= e){
        pos = e - s;
        neg = n - pos;
    }else{
        neg = s - e;
        pos = n - neg;
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

string concatSol(int s, int n){
    string ret;

    for(int i = 0;i < n;++i)
        ret += S[s + i].sol;

    return ret;
}

bool canCompressWithMovesDiff0(int pos, pair<int, int> &rep, int &curZone, int &loopZone){
    if(S[pos].le > ZONES - 1 || S[pos].ri > ZONES - 1)
        return false;

    for(int i = 1,diff = 0,le = 0,ri = 0,len = 0;i < nS && pos + i <= nS;++i){
        le = min(le,diff + S[pos + i - 1].le);
        ri = max(ri,diff + S[pos + i - 1].ri);
        diff += S[pos + i - 1].diff;
        len += S[pos + i - 1].len;
        if(diff != 0) continue;

        string aux = concatSol(pos,i);
        int p = pos + i;
        rep.first = 1;
        rep.second = i;
        curZone = S[pos + i - 1].curZone;

        while(p + i <= nS && concatSol(p,i) == aux && rep.first < 26){
            p += i;
            ++rep.first;
        }

        int loopZoneLe = (curZone + le - 1) % ZONES;
        if(loopZoneLe < 0) loopZoneLe += ZONES;
        int loopZoneRi = (curZone + ri + 1) % ZONES;
        int tmpLe = S[pos].pos[loopZoneLe];
        int tmpRi = S[pos].pos[loopZoneRi];
        int mLe = moves(tmpLe,rep.first,27) + moves(0,tmpLe,27) + 4 * moves(curZone,loopZoneLe,30);
        int mRi = moves(tmpRi,rep.first,27) + moves(0,tmpRi,27) + 4 * moves(curZone,loopZoneRi,30);

        if(mLe < mRi) loopZone = loopZoneLe;
        else loopZone = loopZoneRi;

        if(len == 1 && rep.first >= 17) return true;
        if(len == 2 && rep.first >= 8) return true;
        if(len == 3 && rep.first >= 6) return true;
        if(len == 4 && rep.first >= 4) return true;
        if(len == 5 && rep.first >= 3) return true;
        if(len >= 6 && rep.first > 2) return true;
    }

    return false;
}

string improve(string &sol){
    int curZone;
    pair<int, int> repeated;

    for(int i = 1;i < nS;++i){
        int len = S[i].posSol - S[i - 1].posSol;
        S[i].len = len;
        S[i].sol = sol.substr(S[i - 1].posSol,len);
        
        S[i].moves = false;
        S[i].noBraces = true;
        S[i].le = 0; S[i].ri = 0; S[i].diff = 0;

        for(int j = 0,p = 0;j < len;++j){
            char c = S[i].sol[j];

            if(c == '<' || c == '>')
                S[i].moves = true;

            if(c == '[' || c == ']')
                S[i].noBraces = false;

            if(c == '<') --p;
            if(c == '>') ++p;

            S[i].le = min(S[i].le,p);
            S[i].ri = max(S[i].ri,p);
            S[i].diff = p;
        }

        //cout << i << " | " << S[i].sol << " " << S[i].moves << " " << S[i].diff << endl;
    }

    string sol2 = "";
    int loopZone;

    for(int i = 1;i < nS;){
        //assert(sol2.size() <= S[i - 1].posSol);
        if(canCompressWithMovesDiff0(i,repeated,curZone,loopZone)){
            //cout << "i = " << i << ", " << repeated.first << " " << repeated.second << endl;
            int tmp = S[i].pos[loopZone];
            string loopToCur = "",curToLoop = "";

            int m = moves(curZone,loopZone,30);

            if(m > 0){
                for(int j = 0;j < m;++j){
                    loopToCur += "<";
                    curToLoop += ">";
                }
            }else{
                for(int j = 0;j < -m;++j){
                    loopToCur += ">";
                    curToLoop += "<";
                }
            }

            sol2 += curToLoop;

            m = moves(tmp,repeated.first,27);

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
            sol2 += loopToCur;
            sol2 += concatSol(i,repeated.second);
            sol2 += curToLoop;
            sol2 += "-]";

            m = moves(0,tmp,27);

            if(m > 0){
                for(int j = 0;j < m;++j){
                    sol2 += '+';
                }
            }else{
                for(int j = 0;j < -m;++j){
                    sol2 += '-';
                }
            }

            sol2 += loopToCur;
            i += repeated.first * repeated.second;
        }else{
            sol2 += S[i].sol;
            ++i;
        }
    }

    //assert(sol2.size() <= sol.size());
    return sol2;
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

    S[nS].curZone = 0;
    S[nS].posSol = 0;

    for(int i = 0;i < ZONES;++i)
        S[nS].pos[i] = 0;

    ++nS;
    
    for(int i = 0;i < magicPhrase.size();){
        //cout << "i = " << i << endl;
        if(foundRepeated(magicPhrase,i,repeated)){
            //cout << repeated.first << " " << repeated.second << endl;
            //cout << magicPhrase.substr(i,repeated.second) << endl;

            for(int j = 0;j < curZone;++j)
                ans[j] = curZone - j;
            for(int j = curZone;j < ZONES;++j)
                ans[j] = j - curZone;

            for(int j = 0;j < ZONES;++j)
                for(int k = 0;k < repeated.second;++k)
                    ans[j] += abs(moves(pos[(j + k) % ZONES],val(magicPhrase[i + k]),27));

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
                    ans2[j] += abs(moves(pos[(j + ZONES - k) % ZONES],val(magicPhrase[i + k]),27));

            for(int j = 0;j < ZONES;++j){
                if(ans2[j] < aux){
                    aux = ans2[j];
                    best = j;
                    dir = -1;
                }
            }

            int mBest = moves(curZone,best,30);

            if(mBest > 0){
                for(int j = 0;j < mBest;++j)
                    sol += ">";
            }else{
                for(int j = 0;j < mBest;++j)
                    sol += "<";
            }

            curZone = best;

            int loopZone = (dir == 1? (curZone + repeated.second) % ZONES : (curZone + ZONES - repeated.second) % ZONES);
            int mLoop = moves(curZone,loopZone,30);
            string curToLoop = "",loopToCur = "";

            if(mLoop > 0){
                for(int j = 0;j < mLoop;++j){
                    curToLoop += ">";
                    loopToCur += "<";
                }
            }else{
                for(int j = 0;j < -mLoop;++j){
                    curToLoop += "<";
                    loopToCur += ">";
                }
            }

            for(int j = 0;j < repeated.second;++j){
                int want = val(magicPhrase[i + j]);
                int m = moves(pos[curZone],want,27);
                
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

                int m = moves(pos[curZone],want,27);

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

                sol += loopToCur;

                for(int j = 0;j < repeated.second;++j){
                    //sol += curToLoop;
                    if(dir == 1) sol += ".>";
                    else sol += ".<";
                }

                sol += "-]";
            }

            i += repeated.first * repeated.second;
            pos[curZone] = 0;
        }else{
            int want = val(magicPhrase[i]);

            for(int j = 0;j < curZone;++j){
                ans[j] = curZone - j + abs(moves(pos[j],want,27));
            }

            for(int j = curZone;j < ZONES;++j){
                ans[j] = j - curZone + abs(moves(pos[j],want,27));
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

            int m = moves(pos[curZone],want,27);
            
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

    string sol2 = improve(sol);
    string finalSol = sol2;

    sol = "";
    nS = 1;
    curZone = 0;
    memset(pos,0,sizeof pos);

    for(int i = 0;i < magicPhrase.size();++i){
        int want = val(magicPhrase[i]);

        for(int j = 0;j < curZone;++j){
            ans[j] = curZone - j + abs(moves(pos[j],want,27));
        }

        for(int j = curZone;j < ZONES;++j){
            ans[j] = j - curZone + abs(moves(pos[j],want,27));
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

        int m = moves(pos[curZone],want,27);
        
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

        S[nS].curZone = curZone;
        S[nS].posSol = sol.size();

        for(int i = 0;i < ZONES;++i)
            S[nS].pos[i] = pos[i];

        ++nS;
    }

    string sol3 = improve(sol);

    for(int it = 1;it <= 26;++it){
        //sol = "+[>-]";
        pos[0] = 0;
        if(it <= 13){
            sol = "";
            for(int i = 0;i < it;++i)
                sol += "+";
            sol += "[>-]";
        

            for(int i = 1;i < ZONES;++i)
                pos[i] = 26 - it + 1;
        }else{
            sol = "";
            for(int i = 0;i < it - 13;++i)
                sol += "-";
            sol += "[>+]";

            for(int i = 1;i < ZONES;++i)
                pos[i] = it - 13;
        }

        nS = 1;
        curZone = 0;
        //memset(pos,0,sizeof pos);

        for(int i = 0;i < magicPhrase.size();++i){
            int want = val(magicPhrase[i]);

            for(int j = 0;j < curZone;++j){
                ans[j] = curZone - j + abs(moves(pos[j],want,27));
            }

            for(int j = curZone;j < ZONES;++j){
                ans[j] = j - curZone + abs(moves(pos[j],want,27));
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

            int m = moves(pos[curZone],want,27);
            
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

            S[nS].curZone = curZone;
            S[nS].posSol = sol.size();

            for(int i = 0;i < ZONES;++i)
                S[nS].pos[i] = pos[i];

            ++nS;
        }

        string sol4 = sol;//improve(sol);
        if(sol4.size() < finalSol.size()) finalSol = sol4;
    }

    if(sol3.size() < finalSol.size()) finalSol = sol3;
    
    cout << finalSol << endl;
}