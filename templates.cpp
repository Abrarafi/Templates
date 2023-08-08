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
const int N=1e5+7;
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

int main()
{
   
}
