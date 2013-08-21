#include <cstdio>
#include <cstring>

using namespace std;

// Implicit treap start

typedef long long ptype;

ptype seed = 47;

ptype my_rand(){
    seed = (seed * 279470273) % 4294967291LL;
    return seed;
}

struct item{
    char value;
    ptype prior;
    item *l,*r;
    int sons;
    
    item(){}
    
    item(char value) : value(value), l(NULL), r(NULL), sons(0){
        prior = my_rand();
    }
};

void fix(item* t){
    if(!t) return;
    t->sons = (t->l ? t->l->sons + 1 : 0) + (t->r ? t->r->sons + 1 : 0);
}


void merge(item* &t, item* l, item* r){
    if(!l || !r)
        t = l ? l : r;
    else if(l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    
    fix(t);
}

void split(item* t, item* &l, item* &r, int key, int add = 0){
    if (!t) l = r = NULL;
    else{
        int cur_key = add + (t->l? 1 + t->l->sons : 0);
        
        if(key <= cur_key)
            split(t->l, l, t->l, key, add), r = t;
        else
            split(t->r, t->r, r, key, cur_key + 1), l = t;
        
        fix(t);
    }
}

void insert(item* &t, item* &it, int key, int add = 0) {
    if(!t) t = it;
    else{
        int cur_key = add + (t->l? 1 + t->l->sons : 0);
        
        if(it->prior > t->prior){
            split(t, it->l, it->r, key, add), t = it;
        }else{
            if(key <= cur_key) insert(t->l, it, key, add);
            else insert(t->r, it, key, cur_key + 1);
        }
        
        fix(t);
    }
}

char get(item* &t, int key){
    int cur_key = (t->l? 1 + t->l->sons : 0);
    
    if(key == cur_key) return t->value;
    else if(key < cur_key) return get(t->l,key);
    else return get(t->r,key - cur_key - 1);
}

void print(item* t){
    if(!t) return;
    print(t->l);
    putchar(t->value);
    print(t->r);
}

// Implicit treap end

#define MAXL 3000005
#define MAXQ 5005

int L,K,Q;
char s[MAXL];
int l[MAXQ],r[MAXQ];
item *t,*t2;

void solve(int pos, int k){
    if(pos == 0){
        t = new item(s[0]);
        
        for(int i = 1;i < k;++i){
            item* it = new item(s[i]);
            insert(t,it,i + 1);
        }
    }else{
        int x;
        
        if(r[pos - 1] + 1 > k) x = 0;
        else if(2*r[pos - 1] - l[pos - 1] + 1 <= k) x = r[pos - 1] - l[pos - 1] + 1;
        else x = k - r[pos - 1];
        
        solve(pos - 1,k - x);
        
        if(x){
            int cur = 0;
            bool first = true;
            
            for(int i = l[pos - 1] + 1;i <= r[pos - 1] && x;i += 2,--x,++cur){
                if(first){
                    t2 = new item(get(t,i - 1));
                    first = false;
                }else{
                    item* it = new item(get(t,i - 1));
                    insert(t2,it,cur);
                }
            }
            
            for(int i = l[pos - 1];i <= r[pos - 1] && x;i += 2,--x,++cur){
                if(first){
                    t2 = new item(get(t,i - 1));
                    first = false;
                }else{
                    item* it = new item(get(t,i - 1));
                    insert(t2,it,cur);
                }
            }
            
            item *tl,*tr;
            split(t,tl,tr,r[pos - 1]);
            merge(t,tl,t2);
            merge(t,t,tr);
        }
    }
}

int main(){
    scanf("%s %d %d",s,&K,&Q);
    L = strlen(s);
    
    for(int i = 0;i < Q;++i)
        scanf("%d %d",&l[i],&r[i]);
    
    solve(Q,K);
    print(t);
    putchar('\n');
    
    return 0;
}
