/*
def isqrt_aux(c, n):
      if c == 0:
          return 1
      else:
          k = (c - 1) // 2
          a = isqrt_aux(c // 2, n >> 2*k + 2)
          return (a << k) + (n >> k+2) // a # (A)

  def isqrt(n):
      if n == 0:
          return 0
      else:
          a = isqrt_aux((n.bit_length() - 1) // 2, n)
          return a - 1 if n < a * a else a # (B)
*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cassert>
#include <functional>


using namespace std;
#define ll long long
#define LL __int128
#define MOD 998244353
#define ld long double
#define INF 2251799813685248
#define vall(A) A.begin(),A.end()
#define gridinput(vv,H,W) for (ll i = 0; i < H; i++){string T; cin >> T; for(ll j = 0; j < W; j++){vv[i][j] = {T[j]};}}
#define adjustedgridinput(vv,H,W) for (ll i = 1; i <= H; i++){string T; cin >> T; for(ll j = 1; j <= W; j++){vv[i][j] = {T[j-1]};}}
#define vin(A) for (ll i = 0, sz = A.size(); i < sz; i++){cin >> A[i];}
#define vout(A) for(ll i = 0, sz = A.size(); i < sz; i++){cout << A[i] << " \n"[i == sz-1];}
#define adjustedvin(A) for (ll i = 1, sz = A.size(); i < sz; i++){cin >> A[i];}
#define adjustedvout(A) for(ll i = 1, sz = A.size(); i < sz; i++){cout << A[i] << " \n"[i == sz-1];}
#define vout2d(A,H,W) for (ll i = 0; i < H; i++){for (ll j = 0; j < W; j++){cout << A[i][j] << " \n"[j==W-1];}}
#define encode(i,j) ((i)<<32)+j
#define decode(v,w) (w ? (v)%4294967296 : (v)>>32)
vector<ll> pow2ll{1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648,4294967296};
vector<ll> pow10ll{1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000,100000000000,1000000000000,10000000000000,100000000000000,1000000000000000,10000000000000000,100000000000000000,1000000000000000000};
vector<ll> di{0,1,0,-1};
vector<ll> dj{1,0,-1,0};

const std::vector<int> hash2pos{1, 2, 60, 3, 61, 41, 55, 4, 62, 33, 50, 42, 56, 20, 36, 5, 63, 53, 31, 34, 51, 13, 15, 43, 57, 17, 28, 21, 37, 24, 45, 6, 64, 59, 40, 54, 32, 49, 19, 35, 52, 30, 12, 14, 16, 27, 23, 44, 58, 39, 48, 18, 29, 11, 26, 22, 38, 47, 10, 25, 46, 9, 8, 7};

int bit_length(unsigned long long x){
  if (x == 0) return 0;
  x |= (x >> 1);x |= (x >> 2);x |= (x >> 4);x |= (x >> 8);x |= (x >> 16);x |= (x >> 32);x = x ^ (x >> 1);
  return hash2pos[(x * 0x03F566ED27179461UL) >> 58];
}

int bit_length_(unsigned long long x){
    return 64 - __builtin_clzll(x);
}

unsigned long long isqrt_aux(int c,unsigned long long n){
    if (c == 0){
        return 1;
    } else {
        int k = (c - 1) / 2;
        unsigned long long a = isqrt_aux(c / 2, n >> (2*k + 2));
        cout << (a << k) + (n >> (k+2)) / a << endl;
        return (a << k) + (n >> (k+2)) / a;
    }
}

unsigned long isqrt(unsigned long long n){
    if (n == 0){
        return 0;
    } else {
        unsigned long long a = isqrt_aux((bit_length_(n) - 1) / 2, n);
        return n < a * a ? a - 1 : a;
    }
}

// ===========================================

int main(){
    vector<unsigned long long> sample{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,100,1000,1024,314159265,4611686018427387903,4611686018427387904};
    for (int i=0;i < sample.size();i++){
        unsigned long long s,ss;
        s = sample[i];
        ss = isqrt(sample[i]);
        cout << s << " -> " << ss << "\n";
        cout << bit_length_(s) << "\n";
        cout << (ss*ss <= s) << " " << (s < (ss+1)*(ss+1)) << "\n";
    }
}
