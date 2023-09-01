//بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
//Author: Abrar_Rafi

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define mii map<ll,ll>
#define endl "\n"
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl;


//spf
const int N=1e6+7;
int spf[N];
vector<int> primes;
void sieve() {
  for(int i = 2; i < N; i++) {
    if (spf[i] == 0) spf[i] = i, primes.push_back(i);
    int sz = primes.size();
    for (int j = 0; j < sz && i * primes[j] < N && primes[j] <= spf[i]; j++) {
      spf[i * primes[j]] = primes[j];
    }
  }
}

vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}


//Extended Euclidean
int ext_gcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int d=ext_gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(y1*(a/b));
    return d;
}

//Linear Biophantine Equation:
bool linearDiophantine ( int A, int B, int C, int &x, int &y ) {
    int g = __gcd ( A, B );
    if ( C % g != 0 ) return false; //No Solution
 
    int a = A / g, b = B / g, c = C / g;
    ext_gcd( a, b, x, y ); //Solve ax + by = 1
 
    if ( g < 0 ) { //Make Sure gcd(a,b) = 1
        a *= -1; b *= -1; c *= -1;
    }
 
    x *= c; y *= c; //ax + by = c
    return true; //Solution Exists
}

//Binary Exponentiation:
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}


//Matrix multiplication:
struct matrix{
    int mat[4][4];
};

matrix mul_mat(matrix a,matrix b)
{
    matrix ans;
    for(int row=0;row<4;row++)
    {
        for(int col=0;col<4;col++)
        {
            int var=0;
            for(int i=0;i<4;i++)
            {
                var+=a.mat[row][i]*b.mat[i][col];
            }
            ans.mat[row][col]=var;
        }
    }
    return ans;
}
//Identity matrix:
matrix identity()
{
    matrix I;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            if(i==j)I.mat[i][j]=1;
            else I.mat[i][j]=0;
        }
    return I;
}


bitset<N> isprime;
vector<int>prime;

void primegen(int n)
{
    n+=100;
    isprime[2]=1;prime.push_back(2);
    for(int i=3;i<=n;i+=2)isprime[i]=1;

    for(int i=3;i<sqrt(n);i+=2)
    {
        if(isprime[i]==1)
        {
           for(int j=i*i;j<=n;j+=(i+i))isprime[j]=0;
        }
    }

    for(int i=3;i<=n;i+=2)
    {
        if(isprime[i])
        {
            prime.push_back(i);
        }
    }
}
//prime factorization(slow code and all factors)
vector<long long> prime_factors(long long n)
{
    vector<long long> ret;
    for(auto p:prime)
    {
        if(1LL*p*p>n)break;

        while(n%p==0)
        {
            ret.push_back(p);
            n/=p;
        }
    }
    if(n>1)ret.push_back(n);
    return ret;
}

//prime factorization using hamonic mean(fast code and unique factors)
vector<ll> primefactors[N];
void pfactors(int n)
{
    primegen(n);
    for(auto p:prime)
    {
        for(int i=p;i<=n;i+=p)
        {
            primefactors[i].push_back(p);
        }
    }
}

// Number of divisors(NOD)
int NOD(long long n)
{
    int ret=1;
    for(auto p:prime)
    {
    
        int cnt=0;
        if(1LL*p*p>n)break;

        while(n%p==0)
        {
            cnt++;
            n/=p;
        }
        ret*=(cnt+1);
    }
    if(n>1)ret*=2;
    return ret;
}

int main()
{
   pfactors(20);
   for(int i=1;i<=20;i++)
   {
    cout<<i<<": ";
    for(auto u:primefactors[i])cout<<u<<" ";
    cout<<endl;
   }
}
