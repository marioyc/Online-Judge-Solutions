#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXQ 100000

int N,Q;
int op[MAXQ],arg[MAXQ];
int a[MAXQ],na,ntop,bit_pos[MAXQ];

int bit[300005],sum[300005];
int b[MAXQ + 1];

void update(int idx, int val){
    for(int x = idx;x < 300005;x += x & -x)
        bit[x] += val;
}

int query(int idx){
    int ret = 0;
    
    for(int x = idx;x > 0;x -= x & -x)
        ret += bit[x];
    
    return ret;
}

int find_a_pos(int x){
    int lo = 0,hi = na - 1,mi;
    
    while(lo < hi){
        mi = (lo + hi) >> 1;
        
        if(a[mi] < x) lo = mi + 1;
        else hi = mi;
    }
    
    if(a[lo] != x) return -1;
    return lo;
}

int main(){
    int T;
    char s[6];
    
    scanf("%d",&T);
    
    for(int tc = 1;tc <= T;++tc){
        scanf("%d %d",&N,&Q);
        
        ntop = 0;
        
        for(int i = 0;i < Q;++i){
            scanf("%s %d",s,&arg[i]);
            
            if(s[0] == 'T'){
                op[i] = 0;
                a[ntop++] = arg[i];
            }else if(s[0] == 'Q') op[i] = 1;
            else op[i] = 2;
        }
        
        printf("Case %d:\n",tc);
        
        if(ntop > 0){
            sort(a,a + ntop);
            na = unique(a,a + ntop) - a;
            
            memset(sum,0,sizeof sum);
            memset(bit,0,sizeof bit);
            
            int pos = ntop + 1;
            
            if(a[0] > 1){
                sum[pos] = sum[pos - 1] + a[0] - 1;
                ++pos;
            }
            
            for(int i = 0;i < ntop;++i){
                sum[pos] = sum[pos - 1] + 1;
                bit_pos[i] = pos;
                ++pos;
                
                if(i + 1 < ntop && a[i + 1] - a[i] > 1){
                    sum[pos] = sum[pos - 1] + a[i + 1] - a[i] - 1;
                    ++pos;
                }
            }
            
            if(a[ntop - 1] < N){
                sum[pos] = sum[pos - 1] + N - a[ntop - 1];
                ++pos;
            }
            
            for(int i = 0,top = ntop;i < Q;++i){
                if(op[i] == 0){
                    b[top] = arg[i];
                    update(top,1);
                    
                    int aux = find_a_pos(arg[i]);
                    update(bit_pos[aux],-1);
                    bit_pos[aux] = top;
                    
                    --top;
                }else if(op[i] == 1){
                    int aux = find_a_pos(arg[i]);
                    
                    if(aux != -1) printf("%d\n",sum[ bit_pos[aux] ] + query(bit_pos[aux]));
                    else{
                        int lo = ntop + 1,hi = pos - 1,mi;
                        
                        while(lo < hi){
                            mi = (lo + hi + 1) >> 1;
                            
                            if(sum[mi] >= arg[i]) hi = mi - 1;
                            else lo = mi;
                        }
                        
                        printf("%d\n",arg[i] + query(lo));
                    }
                }else{
                    int lo = 0,hi = pos - 1,mi;
                    
                    while(lo < hi){
                        mi = (lo + hi + 1) >> 1;
                        
                        if(sum[mi] + query(mi) >= arg[i]) hi = mi - 1;
                        else lo = mi;
                    }
                    
                    if(lo + 1 <= ntop) printf("%d\n",b[lo + 1]);
                    else{
                        int have = sum[lo] + query(lo);
                        printf("%d\n",sum[lo] + arg[i] - have);
                    }
                }
            }
        }else{
            for(int i = 0;i < Q;++i)
                if(op[i] >= 1) printf("%d\n",arg[i]);
        }
    }
    
    return 0;
}
