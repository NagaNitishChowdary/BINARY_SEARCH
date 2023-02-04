// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/nth-root-of-m_1062679
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1

#include <bits/stdc++.h> 
using namespace std ;

double multiply(double mid,double n){
  double ans = 1.0 ;
  for(int i=1 ; i<=n ; i++) ans *= mid ;
  return ans ;
}

double findNthRootOfM(int n, int m) {
  // Write your code here.
  double low = 0 , high = m ;
  double eps = 1e-7 ;
  while((high-low) > eps){
    double mid = (low+high)/2.0 ;
    double mul = pow(mid , n) ;
    if(mul < m) low = mid ;
    else if(mul == m) return mid ;
    else high = mid ;
  }
  return high ;
}

int main(){
  int test ; cin >> test ;
  while(test--){
    int n, m ; cin >> n >> m ;
    cout << findNthRootOfM(n,m) << endl ;
  }
}
