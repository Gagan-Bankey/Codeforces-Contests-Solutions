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

template <typename T> T countDigit(T n) { return ( (n==0) ? 1 : floor( log10(n) + 1) );}
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

int Knapsack(int w, int n, std::vector<int> &wt , std::vector<int> &val )
{
   int DP[n+1][w+1];

     for (int i = 0; i <= n ; ++i)
     { for (int j = 0; j <= w ; ++j)
        {  if( i==0 || j==0)
             DP[i][j]=0;
           else if( wt[i-1] <= j )
           {    DP[i][j] = max( DP[i-1][j] , val[i-1]+ DP[i-1][j-wt[i-1]] ); }
             else
             DP[i][j]= DP[i-1][j];
        }
     }  
     return DP[n][w];
}



//---------sum of digits of a num ------------------------------------------------

ll sumof(ll d)
{ ll ans=0; while(d!=0) {   ll x= d/10; ans+= d-(x*10); d=d/10; }  return ans; }


//------- primefactors-------------------------------------------------------------

std::set<int> prime_set;
int primefactor(int n)
{
  while( n%2 == 0 ){prime_set.insert(2); n/=2;}
  for (int i = 3; i*i <= n ; i+=2 ) { while( n%i == 0 ){ prime_set.insert(i); n=n/i;}}
  if(n>2) prime_set.insert(n);
}

//----------------------------------------------------------------------------------

bool sortcol( const vector<ll>& v1, const vector<ll>& v2 ) {return v1[2] < v2[2];} 

//----------------------------------------------------------------------------------

/*-----------Solution--is--here------------*/




void solve()
{
  int t, case_ ;
  t=1;
  cin>>t;
  case_ = t;

  cout<< fixed << setprecision(5);

while(t--) 
{ 
  
  ll n;
  cin>>n;

  std::vector<ll> v(n);

  std::vector<ll> a(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>v[i];
    a[i]=v[i];
  }
sort(a.begin(), a.end());

std::vector<std::vector<ll> >ans;
 for (int i = 0; i < n; ++i)
{
  if( a[i]!=v[i] )
  {
    int ind=-1;
    ll val ;
    for (int j = i; j < n; ++j)
    {
      if( v[j]==a[i] )
      {
        ind=j;
        val= v[j];
        break;    
      }
    }

    //cout<<val<<" l";
    for (int j = ind; j >i ; --j)
    {
       v[j]=v[j-1];
    }
    v[i]=val;
   // cout<<i<<" "<<ind<<" "<<ind-i<<" m"<<endl;
    ans.push_back({i+1,ind+1,ind-i});

    // for (int i = 0; i < n; ++i)
    // {
    //   cout<<v[i]<<" ";
    // }
    // cout<<endl;

    }
  }

cout<<ans.size()<<endl;
for (int i = 0; i < ans.size(); ++i)
{
   cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
}

 

}
}

int main()
{ 
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  solve();

  // cout << fixed << setprecision(10) <<ans<<endl;
  return 0;
}

//CS
// >> right , << left
