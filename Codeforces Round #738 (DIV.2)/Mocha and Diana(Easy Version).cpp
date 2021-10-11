//@gagan2001
#include <bits/stdc++.h>
using namespace std;
class DisjSet {
  int *rank, *parent, n;

public:
  // Constructor to create and
  // initialize sets of n items
  DisjSet(int n)
  {
    rank = new int[n];
    parent = new int[n];
    this->n = n;
    makeSet();
  }

  // Creates n single item sets
  void makeSet()
  {
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  // Finds set of given item x
  int find(int x)
  {
    // Finds the representative of the set
    // that x is an element of
    if (parent[x] != x) {

      // if x is not the parent of itself
      // Then x is not the representative of
      // his set,
      parent[x] = find(parent[x]);

      // so we recursively call Find on its parent
      // and move i's node directly under the
      // representative of this set
    }

    return parent[x];
  }

  // Do union of two sets represented
  // by x and y.
  void Union(int x, int y)
  {
    // Find current sets of x and y
    int xset = find(x);
    int yset = find(y);

    // If they are already in same set
    if (xset == yset)
      return;

    // Put smaller ranked item under
    // bigger ranked item if ranks are
    // different
    if (rank[xset] < rank[yset]) {
      parent[xset] = yset;
    }
    else if (rank[xset] > rank[yset]) {
      parent[yset] = xset;
    }

    // If ranks are same, then increment
    // rank.
    else {
      parent[yset] = xset;
      rank[xset] = rank[xset] + 1;
    }
  }
};

int main()
{

   int n,m1,m2;
   cin>>n>>m1>>m2;
  DisjSet obj1(n+1);

  DisjSet obj2(n+1);

   for (int i = 0; i < m1; ++i)
   {
     int x,y;
     cin>>x>>y;
     obj1.Union(x,y);
   }
   for (int i = 0; i < m2; ++i)
   {
     int x,y;
     cin>>x>>y;
     obj2.Union(x,y);
   }

std::vector<int> v1;
std::vector<int> v2;
   for (int i = 1; i <= n; ++i)
   {
      for (int j = i+1; j <= n; ++j)
      {
          if( (obj1.find(i)!= obj1.find(j) && obj1.find(i)!=n  )&& (obj2.find(i)!=obj2.find(j) && obj2.find(i)!=n) )
           {  obj2.Union(i,j);
             obj1.Union(i,j);
              v1.push_back(i);
              v2.push_back(j);
           }
      }
   }

  cout<<v1.size()<<endl;
  for (int i = 0; i < v1.size(); ++i)
  {
    cout<<v1[i]<<" "<<v2[i]<<endl;
  }
cout<<endl;
 
  return 0;
}