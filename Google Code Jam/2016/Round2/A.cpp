#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 0 : P
// 1 : R
// 2 : S

int need[13][3][3];
string symbol[] = {"P", "R", "S"};
string order[13][3];
vector<string> ans;

int main(){
    ios::sync_with_stdio(0);

    memset(need,0,sizeof need);

    for(int i = 0;i < 3;++i){
        need[0][i][i] = 1;
        order[0][i] = symbol[i];
    }

    for(int i = 1;i <= 12;++i){
        for(int j = 0;j < 3;++j){
            int opponent = (j + 1) % 3;

            for(int k = 0;k < 3;++k){
                need[i][j][k] = need[i - 1][j][k] + need[i - 1][opponent][k];
            }
            if(order[i - 1][j] < order[i - 1][opponent])
                order[i][j] = order[i - 1][j] + order[i - 1][opponent];
            else
                order[i][j] = order[i - 1][opponent] + order[i - 1][j];
        }
    }

    int T,N,R,P,S;

    cin >> T;

    for(int tc = 1;tc <= T;++tc){
        cin >> N >> R >> P >> S;

        ans.clear();

        for(int i = 0;i < 3;++i){
            if(need[N][i][0] == P && need[N][i][1] == R && need[N][i][2] == S){
                ans.push_back(order[N][i]);
            }
        }

        cout << "Case #" << tc << ": ";

        if(ans.empty()){
            cout << "IMPOSSIBLE\n";
        }else{
            sort(ans.begin(),ans.end());
            cout << ans[0] << "\n";
        }
    }

    return 0;
}
