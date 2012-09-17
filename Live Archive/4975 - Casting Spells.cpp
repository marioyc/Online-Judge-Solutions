#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define MAXL 300001
#define B 61
#define MOD 1000000009

char s[MAXL];

unsigned int H[MAXL],H2[MAXL],powB[MAXL];
long long H3[MAXL],H4[MAXL],powB2[MAXL];
int r[MAXL];

unsigned int get_hash1(int l, int r){
    return H[l] - powB[r - l + 1] * H[r + 1];
}

unsigned int get_hash2(int l, int r){
    return H2[r + 1] - powB[r - l + 1] * H2[l];
}

long long get_hash3(int l, int r){
    long long h = (H3[l] - powB2[r - l + 1] * H3[r + 1]) % MOD;
    if(h < 0) h += MOD;
    return h;
}

long long get_hash4(int l, int r){
    long long h = (H4[r + 1] - powB2[r - l + 1] * H4[l]) % MOD;
    if(h < 0) h += MOD;
    return h;
}

multiset<int> S;
multiset<int> :: iterator it;
vector< pair<int, int> > vq,in,out;

int main(){
    powB[0] = powB2[0] = 1;
    
    for(int i = 1;i < MAXL;++i){
        powB[i] = B * powB[i - 1];
        powB2[i] = B * powB2[i - 1] % MOD;
    }
    
    int T,L;
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%s",s);
        
        L = strlen(s);
        
        H[L] = H3[L] = 0;
        
        for(int i = L - 1;i >= 0;--i){
            H[i] = ((s[i] >= 'a' && s[i] <= 'z')? s[i] - 'a' : s[i] - 'A' + 26) + B * H[i + 1];
            H3[i] = (((s[i] >= 'a' && s[i] <= 'z')? s[i] - 'a' : s[i] - 'A' + 26) + B * H3[i + 1]) % MOD;
        }
        
        H2[0] = H4[0] = 0;
        
        for(int i = 0;i < L;++i){
            H2[i + 1] = ((s[i] >= 'a' && s[i] <= 'z')? s[i] - 'a' : s[i] - 'A' + 26) + B * H2[i];
            H4[i + 1] = (((s[i] >= 'a' && s[i] <= 'z')? s[i] - 'a' : s[i] - 'A' + 26) + B * H4[i]) % MOD;
        }
        
        for(int i = 0;i < L;++i){
            int lo = 0,hi = min(i + 1,L - i - 1),mi;
            
            while(lo < hi){
                mi = (lo + hi + 1) >> 1;
                
                if(get_hash3(i - mi + 1,i) != get_hash4(i + 1,i + mi)) hi = mi - 1;
                else lo = mi;
            }
            
            r[i] = lo;
        }
        
        int Q = 0;
        vq.clear();
        in.clear();
        out.clear();
        
        for(int i = 0;i < L;++i){
            if(r[i]){
                int r2 = r[i] / 2;
                
                vq.push_back(make_pair(i,i + 1 - r2));
                in.push_back(make_pair(i + 1,i));
                out.push_back(make_pair(i + r[i] + 1,i));
                ++Q;
            }
        }
        
        sort(vq.begin(),vq.end());
        sort(in.begin(),in.end());
        sort(out.begin(),out.end());
        
        S.clear();
        int ans = 0;
        
        for(int i = 0,p1 = 0,p2 = 0,p3 = 0;i < L;++i){
            while(p3 < Q && out[p3].first == i){
                it = S.find(out[p3].first - r[ out[p3].second ]);
                S.erase(it);
                ++p3;
            }
            
            while(p2 < Q && in[p2].first == i){
                S.insert(in[p2].first);
                ++p2;
            }
            
            while(p1 < Q && vq[p1].first == i){
                it = S.lower_bound( vq[p1].second );
                if(it != S.end()) ans = max(ans,i - *it + 1);
                ++p1;
            }
        }
        
        printf("%d\n",ans * 4);
    }
    
    return 0;
}
