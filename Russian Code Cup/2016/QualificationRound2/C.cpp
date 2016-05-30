#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solved;
vector<string> sol;
string s;
int L;

bool check(){
    int k = sol.size();

    for(int i = 0;i < k;++i){
        for(int j = i + 1;j < k;++j){
            if(sol[i] == sol[j]) return false;
        }
    }

    return true;
}

void solve(int k, int pos){
    if(pos == L) return;
    if(k == 0){
        sol.push_back(s.substr(pos,L - pos));
        if(check()){
            solved = true;
            return;
        }
        sol.pop_back();
    }

    for(int i = pos;i < L;++i){
        sol.push_back(s.substr(pos,i - pos + 1));
        solve(k - 1,i + 1);
        if(solved) return;
        sol.pop_back();
    }
}

int main(){
    int t,k;

    cin >> t;

    while(t--){
        cin >> s >> k;
        L = s.size();

        if(L >= k * (k + 1) / 2){
            cout << "YES\n";
            for(int i = 0,p = 0;i < k;++i){
                int len = i + 1;
                if(i == k - 1) len = L - p;
                cout << s.substr(p,len) << "\n";
                p += len;
            }
        }else{
            sol.clear();
            solved = false;
            solve(k - 1,0);

            if(!solved) cout << "NO\n";
            else{
                cout << "YES\n";
                for(string s : sol){
                    cout << s << "\n";
                }
            }
        }
    }

    return 0;
}
