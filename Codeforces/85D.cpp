#include <iostream>
#include <cstring>
#include <string>

using namespace std;

long long seed = 47;

long long treap_rand(){
    seed = (seed * 279470273) % 4294967291LL;
    return seed;
}

typedef int treap_type;

class treap{
    public:
    
    treap_type value;
    long long priority;
    treap *left, *right;
    int sons;
    long long sum[5];
    
    treap(){}
    
    treap(treap_type value) : left(NULL), right(NULL), value(value), sons(0){
        priority = treap_rand();
        memset(sum,0,sizeof sum);
        sum[0] = value;
    }
    
    ~treap(){
        if(left) delete left;
        if(right) delete right;
    }
};

treap* find(treap* t, treap_type val){
    if(!t) return NULL;
    if(val == t->value) return t;

    if(val < t->value) return find(t->left, val);
    if(val > t->value) return find(t->right, val);
}

inline void rotate_to_right(treap* &t){
    treap* n = t->left;
    t->left = n->right;
    n->right = t;
    t = n;
}

inline void rotate_to_left(treap* &t){
    treap* n = t->right;
    t->right = n->left;
    n->left = t;
    t = n;
}

void fix_augment(treap* t){
    if(!t) return;
    t->sons = (t->left ? t->left->sons + 1 : 0) +
        (t->right ? t->right->sons + 1 : 0);
    
    int n = (t->left? 1 + t->left->sons : 0);
    
    for(int i = 0;i < 5;++i)
        t->sum[i] = (t->left? t->left->sum[i] : 0) + (t->right? t->right->sum[((i - n - 1) % 5 + 5) % 5] : 0)
                + (n % 5 == i % 5? t->value : 0);
}

void insert(treap* &t, treap_type val){
    if(!t) t = new treap(val);
    else insert(val <= t->value ? t->left : t->right, val);
    
    if(t->left && t->left->priority > t->priority)
        rotate_to_right(t);
    else if(t->right && t->right->priority > t->priority)
        rotate_to_left(t);
    
    fix_augment(t->left);
    fix_augment(t->right);
    fix_augment(t);
}

inline long long get_priority(treap* t){
    return t ? t->priority : -1;
}

void erase(treap* &t, treap_type val){
    if(!t) return;

    if(t->value != val) erase(val < t->value ? t->left : t->right, val);
    else{
        if(!t->left && !t->right){
            delete t;
            t = NULL;
        }else{
            if(get_priority(t->left) < get_priority(t->right))
                rotate_to_left(t);
            else
                rotate_to_right(t);
            
            erase(t, val);
        }
    }
    
    if(t){
        fix_augment(t->left);
        fix_augment(t->right);
        fix_augment(t);
    }
}

treap *T;

int main(){
    ios::sync_with_stdio(false);
    
    int n;
    string op;
    
    cin >> n;
    
    for(int i = 0,x;i < n;++i){
        cin >> op;
        
        if(op[0] == 'a'){
            cin >> x;
            
            insert(T,x);
        }
        
        if(op[0] == 'd'){
            cin >> x;
            
            erase(T,x);
        }
        
        if(op[0] == 's'){
            cout << (T? T->sum[2] : 0) << '\n';
        }
    }
    
    return 0;
}
