#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n ; cin >> n ;
    int arr[n] ;
    for(int i=0 ; i<n ; i++) cin >> arr[i] ;
    int x ; cin >> x ;
    int ind = lower_bound(arr,arr+n,x) - arr ;
    if(ind < n && arr[ind] == x) cout << ind << endl ;
    else cout << -1 << endl ;
}

int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(0) ;
    LL testCases ; cin >> testCases ;
    while(testCases--) solve();
    return 0;  
}
