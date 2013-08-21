#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int n;
int a[10];
int L;

vector<string> sol;
int ans[12];
char ans2[20];

bool check(int l, int r){
    if(ans[l] == 0 && l < r) return false;
    int aux = 0;
    for(int i = l;i <= r;++i) aux = aux * 10 + ans[i];
    return aux < 256;
}

void generate(int l, int r, int mask){
    if(l > r){
        if(mask == (1 << n) - 1){
            for(int i = 1;i <= 3;++i)
                for(int j = 1;j <= 3 && i + j < L;++j)
                    for(int k = 1;k <= 3 && i + j + k < L;++k){
                        if(L - i - j - k <= 3 && check(0,i - 1) && check(i,i + j - 1) && check(i + j,i + j + k - 1) && check(i + j + k,L - 1)){
                            int pos = 0,pos2 = 0;
                            for(int x = 0;x < i;++x) ans2[pos2++] = ans[pos++] + '0';
                            ans2[pos2++] = '.';
                            for(int x = 0;x < j;++x) ans2[pos2++] = ans[pos++] + '0';
                            ans2[pos2++] = '.';
                            for(int x = 0;x < k;++x) ans2[pos2++] = ans[pos++] + '0';
                            ans2[pos2++] = '.';
                            for(int x = 0;x < L - i - j - k;++x) ans2[pos2++] = ans[pos++] + '0';
                            sol.push_back(ans2);
                        }
                    }
        }
    }else{
        for(int i = 0;i < n;++i){
            ans[l] = ans[r] = a[i];
            generate(l + 1,r - 1,mask | (1 << i));
        }
    }
}

int main(){
    scanf("%d",&n);
    
    for(int i = 0;i < n;++i)
        scanf("%d",&a[i]);
    
    for(int j = 4;j <= 12;++j){
        L = j;
        generate(0,j - 1,0);
    }
    
    printf("%d\n",(int)sol.size());
    
    for(int i = sol.size() - 1;i >= 0;--i)
        printf("%s\n",sol[i].c_str());
    
    return 0;
}
