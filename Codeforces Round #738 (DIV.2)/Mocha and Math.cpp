//   " @gagan2001 " 
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define LB lower_bound
#define UB upper_bound
#define sort_decrease(arr) sort(arr.begin(),arr.end(),greater<ll>())
#define p_q       priority_queue<ll>pq
#define p_q_inc   priority_queue < ll , vector<ll> , greater<ll> > pq

typedef long long ll;

template <typename T> T countDigit(T n) { return ( (n==0) ? 1 : floor( log10(n) + 1 ) ) ; }
template <typename T> T GCD(T a,T b) { return ( (b%a==0)? a : GCD(b%a,a) );} 

long long mod_by= LLONG_MAX ;

long long binpow(long long a, long long b)
{   a %= mod_by;
    long long res = 1;
   while (b > 0)
   { 
      if (b & 1) 
        res = res * a % mod_by;  
        a = a * a % mod_by; b >>= 1;
   } 
     return res;
}

bool sortcol( const vector<ll>& v1, const vector<ll>& v2 ) {return v1[1] < v2[1];} 


bool isPrime(ll n)
{
    if (n <= 1) return false;
    if (n <= 3)return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i = i + 6) if (n % i == 0 || n % (i + 2) == 0)   return false;
    return true;
}

pair<ll,ll> comman_range( pair<ll,ll> p1 , pair<ll,ll> p2 ) 
{
   ll a = max( p1.F , p2.F ) , b= min ( p1.S , p2.S ) ;
     return ( a > b) ? MP(-1ll,-1ll) : MP( a , b);
}


/*-----------Solution--is--here------------*/

// std::vector<ll> all_divisors;
// void Divisors(ll n)
// {
    
//     for (ll i = 1; i <= sqrt(n); i++) {
//         if (n % i == 0) {
 
//            if (n / i == i)
//               all_divisors.push_back(i);
//         else{
//               all_divisors.push_back(i);
//               all_divisors.push_back(n / i);
//             }
//         }
//     }

// }
  std::vector< vector<long double>> xy;


std::vector<long double>  find_Centroid()
{
    //cout<< fixed << setprecision(10);


    std::vector<long double>  ans(2,0);
      
    int n = xy.size();
     long double signedArea = 0;
      
   
    for (int i = 0; i < xy.size(); i++) {
          
        long double x0 = xy[i][0], y0 = xy[i][1];
       long  double x1 = xy[(i + 1) % n][0], y1 = 
                            xy[(i + 1) % n][1];
                              
     
         long double A = (x0 * y1) - (x1 * y0);
        signedArea += A;
          
    
        ans[0] += (x0 + x1) * A;
        ans[1] += (y0 + y1) * A;
    }
  
    signedArea *= 0.5;
    ans[0] = (ans[0]) / (6 * signedArea);
    ans[1] = (ans[1]) / (6 * signedArea);
  
    return ans;
}
  




void solve()
{
  cout<< fixed << setprecision(10);

  ll t, case_ ;
  cin>>t;
 // t=1;
  case_ = t;

  while(t--) 
  { 
     
   ll n,y;
   cin>>n;
   cin>>y;
   ll ans=y;
   for (int i = 1; i < n; ++i)
   {
     ll x;
     cin>>x;
     ans= (ans&x);
   }
   
   cout<<ans<<endl;

  }

}


// for kick // cout<<"Case #"<< case_-t <<": "<< ans <<endl;

int main()
{ 
     ios_base::sync_with_stdio(false); 
     cin.tie(NULL);
     solve();

    // cout << fixed << setprecision(10) <<ans<<endl;
  return 0;
}
 
