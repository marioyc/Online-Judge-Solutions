#include <cassert>
#include <cstdio>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100

int X;

struct MatrixWithPow{
    int n;
    int M[2 * MAXN][2 * MAXN],M2[2 * MAXN][2 * MAXN];

    MatrixWithPow(int _n){
        n = _n;
        memset(M,0,sizeof M);
    }

    void operator *= (MatrixWithPow &a){
        for(int i = 0;i < n;++i){
            for(int j = 0;j < n;++j){
                long long aux = 0;

                for(int k = 0;k < n;++k){
                    aux += (long long)M[i][k] * a.M[k][j];
                }

                if(aux >= X) aux %= X;
                M2[i][j] = aux;
            }
        }

        memcpy(M,M2,sizeof(int) * (2 * MAXN * n));
    }

    MatrixWithPow pow(long long b){
        MatrixWithPow ret(n),aux = *this;

        for(int i = 0;i < n;++i)
            ret.M[i][i] = 1;

        while(b){
            if(b & 1) ret *= aux;
            aux *= aux;
            b >>= 1;
        }

        return ret;
    }
};

int ways[MAXN][MAXN];

void count_ways(int n, int ne, long long k){
    MatrixWithPow M(2 * n);

    for(int i = 0,u,v;i < ne;++i){
        scanf("%d %d",&u,&v);
        --u; --v;
        ++M.M[u][v];
        ++M.M[v][u];
    }

    for(int i = 0;i < n;++i){
        M.M[n + i][n + i] = 1;

        for(int j = 0;j < n;++j)
            M.M[n + i][j] = M.M[i][j];
    }

    M = M.pow(k);

    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            ways[i][j] = M.M[n + j][i];
        }
    }
}

const int B = 100000;
const int Blen = 5;

struct BigInteger{
    vector<long long> d;
    int sign;

    BigInteger(){
        d.reserve(800);
        d.push_back(0);
        sign = 1;
    }

    void clean(){
        int n = d.size();
        while(n > 1 && d.back() == 0){
            d.pop_back();
            --n;
        }
    }

    BigInteger(long long x){
        d.clear();

        if(x < 0){
            sign = -1;
            x = -x;
        }else{
            sign = 1;
        }

        if(x == 0) d.push_back(0);
        else{
            while(x != 0){
                d.push_back(x % B);
                x /= B;
            }
        }
    }

	long long &operator [](int x){ return(d[x]);}
	const long long &operator [](int x)const { return(d[x]);}

    // ignores signs
    bool _geq(BigInteger &y){
        if(d.size() > y.d.size()) return true;
        if(d.size() < y.d.size()) return false;

        int n = d.size();

        for(int i = n - 1;i >= 0;--i){
            if(d[i] > y.d[i]) return true;
            if(d[i] < y.d[i]) return false;
        }

        return true;
    }

    // ignores signs
    bool _leq(BigInteger &y){
        if(d.size() > y.d.size()) return false;
        if(d.size() < y.d.size()) return true;

        int n = d.size();

        for(int i = n - 1;i >= 0;--i){
            if(d[i] > y.d[i]) return false;
            if(d[i] < y.d[i]) return true;
        }

        return true;
    }

    bool operator >= (BigInteger &y){
        if(sign == 1){
            if(y.sign == -1) return true;
            return _geq(y);
        }

        if(y.sign == 1) return false;
        return _leq(y);
    }

    bool operator == (BigInteger &y){
        if(sign != y.sign) return false;
        return d == y.d;
    }

    // ignores signs
    BigInteger _add(BigInteger &y){
        int n = d.size(),ny = y.d.size();
        BigInteger ret;
        ret.d.resize(max(n,ny) + 1,0);

        for(int i = 0,c = 0;i < n || i < ny || c > 0;++i){
            int sum = c;
            if(i < n) sum += d[i];
            if(i < ny) sum += y.d[i];
            if(sum >= B){
                sum -= B;
                c = 1;
            }else{
                c = 0;
            }
            ret.d[i] = sum;
        }

        ret.clean();
        return ret;
    }

    // ignores signs, and >= y
    BigInteger _sub(BigInteger &y){
        int n = d.size(),ny = y.d.size();
        BigInteger ret;
        ret.d.resize(n,0);

        for(int i = 0,c = 0;i < n;++i){
            int sum = d[i] - c;
            if(i < ny) sum -= y.d[i];

            if(sum < 0){
                sum += B;
                c = 1;
            }else{
                c = 0;
            }

            ret.d[i] = sum;
        }

        ret.clean();
        return ret;
    }

    BigInteger operator + (BigInteger &y){
        BigInteger ret;
        if(sign == y.sign){
            ret = _add(y);
            if(sign == -1) ret.sign = -1;
        }else{
            if(_geq(y)){
                ret = _sub(y);
                if(sign == -1 && !ret.is_zero()) ret.sign = -1;
            }else{
                ret = y._sub(*this);
                if(sign == 1 && !ret.is_zero()) ret.sign = -1;
            }
        }
        return ret;
    }

    BigInteger operator - (BigInteger y){
        BigInteger ret;
        if(sign != y.sign){
            ret = _add(y);
            if(sign == -1) ret.sign = -1;
        }else{
            if(_geq(y)){
                ret = _sub(y);
                if(sign == -1 && !ret.is_zero()) ret.sign = -1;
            }else{
                ret = y._sub(*this);
                if(sign == 1 && !ret.is_zero()) ret.sign = -1;
            }
        }
        return ret;
    }

    void mult(int y){
        int n = d.size();
        for(int i = 0;i < n;++i){
            d[i] = d[i] * y;
        }
        for(int i = 0;i < n;++i){
            if(d[i] >= B){
                d[i + 1] += d[i] / B;
                d[i] %= B;
            }
        }
    }

    BigInteger operator * (long long y){
        int n = d.size();
        BigInteger ret = *this;
        for(int i = 0;i < n;++i)
            ret.d[i] *= y;
        for(int i = 0;i < n;++i){
            if(ret.d[i] >= B){
                if(i + 1 < n)
                    ret.d[i + 1] += ret.d[i] / B;
                else{
                    ret.d.push_back(ret.d[i] / B);
                    ++n;
                }
                ret.d[i] %= B;
            }
        }
        ret.clean();
        return ret;
    }

    BigInteger operator * (BigInteger &y){
        int n = d.size(),ny = y.d.size();
        BigInteger ret;
        ret.d.resize(n + ny);

        for(int i = 0;i < n;++i){
            for(int j = 0;j < ny;++j){
                ret.d[i + j] += d[i] * y.d[j];
            }
        }

        int nret = ret.d.size();

        for(int i = 0;i < nret;++i){
            if(ret.d[i] >= B){
                if(i == nret - 1){
                    ret.d.push_back(ret.d[i] / B);
                    ++nret;
                }else{
                    ret.d[i + 1] += ret.d[i] / B;
                }
                ret.d[i] %= B;
            }
        }

        ret.sign = sign * y.sign;
        ret.clean();
        return ret;
    }

    void _vec_by_dig(vector<long long> &v, int b, vector<long long> &ret){
        int n = v.size();
        for(int i = 0;i < n;++i)
            ret[i] = v[i] * b;
        for(int i = 0;i + 1 < n;++i){
            ret[i + 1] += ret[i] / B;
            ret[i] %= B;
        }
    }

    bool _geq_vec(vector<long long> &a, vector<long long> &b){
        int n = a.size();
        for(int i = n - 1;i >= 0;--i){
            if(a[i] > b[i]) return true;
            if(a[i] < b[i]) return false;
        }
        return true;
    }

    void div(int y){
        int n = d.size();
        long long aux = 0;
        for(int i = n - 1;i >= 0;--i){
            aux = aux * B + d[i];
            d[i] = aux / y;
            aux %= y;
        }
        clean();
    }

    BigInteger operator / (BigInteger &y){
        int n = d.size(),ny = y.d.size();
        BigInteger ret;
        if(n < ny) return ret;

        ret.d.resize(n - ny + 1);
        vector<long long> aux = d,prod(ny),prefix(ny);

        for(int i = n - ny;i >= 0;--i){
            for(int j = 0;j < ny;++j){
                prefix[j] = aux[i + j];
            }

            int lo = 0,hi = B - 1,mi;

            while(lo < hi){
                mi = lo + ((hi - lo + 1) >> 1);
                _vec_by_dig(y.d,mi,prod);
                if(_geq_vec(prefix,prod)) lo = mi;
                else hi = mi - 1;
            }

            _vec_by_dig(y.d,lo,prod);
            ret.d[i] = lo;

            for(int j = 0;j < ny;++j){
                aux[i + j] -= prod[j];
            }

            for(int j = 0;j + 1 < ny;++j){
                if(aux[i + j] < 0){
                    aux[i + j] += B;
                    --aux[i + j + 1];
                }
            }

            if(i > 0)
                aux[i + ny - 2] += aux[i + ny - 1] * B;
        }

        ret.sign = sign * y.sign;
        ret.clean();
        return ret;
    }

    int operator % (int y){
        long long ret = 0;
        int n = d.size();

        for(int i = n - 1;i >= 0;--i){
            ret = (ret * B + d[i]) % y;
        }

        if(sign == -1 && ret != 0){
            ret = -ret + y;
        }
        return ret;
    }

    BigInteger operator % (BigInteger y){
        BigInteger q = (*this) / y * y;
        return *this - q;
    }

    bool is_zero(){
        return d.size() == 1 && d[0] == 0;
    }

    void print(){
        int n = d.size();
        if(sign == -1) printf("-");
        printf("%d",(int)d[n - 1]);
        for(int i = n - 2;i >= 0;--i){
            printf("%0*d",Blen,(int)d[i]);
        }
        printf("\n");
    }
};

// a*x + b*y = gcd(a,b)
long long ext_gcd(long long  a, long long b, long long &x, long long &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }

    long long g = ext_gcd(b,a % b,y,x);
    y -= a / b * x;
    return g;
}

BigInteger ext_gcd(BigInteger  a, BigInteger b, BigInteger &x, BigInteger &y){
    if(b.is_zero()){
        x = 1;
        y = 0;
        return a;
    }

    BigInteger g = ext_gcd(b,a % b,y,x);
    y = y - a / b * x;
    return g;
}

// ASSUME: gcd(a, m) == 1
long long mod_inv(long long a, long long m){
    long long x,y;
    ext_gcd(a, m, x, y);
    return (x % m + m) % m;
}

BigInteger mod_inv(BigInteger a, BigInteger m){
    BigInteger x,y;
    ext_gcd(a, m, x, y);
    return (x % m + m) % m;
}

BigInteger chinese_remainder(vector<int> &rem, vector<int> &mod){
    BigInteger ans = rem[0],m = mod[0];
    int n = rem.size();

    for(int i = 1;i < n;++i){
        int p = mod[i];
        int a = mod_inv(m % p,p);
        BigInteger b = mod_inv(p,m);
        BigInteger aux = m * rem[i] * a;
        ans = (ans * b * p + aux);
        m = m * p;
        ans = ans % m;
        if(ans.sign == -1){
            ans = ans + m;
        }
    }

    return ans;
}

long long det[MAXN][MAXN],det2[MAXN][MAXN];

int calc_determinant(int n, int p){
    long long ret = 1;

    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            det2[i][j] = det[i][j] % p;
        }
    }

    for(int i = 0;i < n;++i){
        if(det2[i][i] == 0){
            bool found = false;

            for(int j = i + 1;j < n && !found;++j){
                if(det2[j][i] != 0){
                    found = true;
                    for(int k = i;k < n;++k){
                        swap(det2[i][k],det2[j][k]);
                    }
                }
            }

            if(!found) return 0;
        }

        if(det2[i][i] < 0)
            det2[i][i] += p;

        ret = ret * det2[i][i] % p;
        int inv = mod_inv(det2[i][i],p);

        for(int k = i;k < n;++k){
            det2[i][k] = det2[i][k] * inv % p;
        }

        for(int j = i + 1;j < n;++j){
            if(det2[j][i] != 0){
                for(int k = i + 1;k < n;++k){
                    det2[j][k] -= det2[i][k] * det2[j][i];
                    det2[j][k] %= p;
                }
            }
        }
    }

    return ret;
}

bool is_prime(int n){
    for(int i = 3;i <= n / i;i += 2){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int N,M;
    long long K;

    scanf("%d %d %d %lld",&N,&M,&X,&K);

    count_ways(N,M,K);

    for(int i = 1;i < N;++i){
        long long sum = 0;
        for(int j = 0;j < N;++j){
            if(j != i){
                if(j > 0) det[i - 1][j - 1] = -ways[i][j];
                sum += ways[i][j];
            }
        }
        det[i - 1][i - 1] = sum;
    }

    vector<int> mod,rem;
    mod.push_back(2);
    int i = 1000000007;

    while(mod.size() < 99){
        if(is_prime(i)){
            mod.push_back(i);
        }
        i += 2;
    }

    int nmod = mod.size();

    for(int i = 0;i < nmod;++i){
        rem.push_back(calc_determinant(N - 1,mod[i]));
    }

    chinese_remainder(rem,mod).print();

    return 0;
}
