// PROBLEM LINK --- https://www.spoj.com/problems/AGGRCOW/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/aggressive-cows/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559

#include <bits/stdc++.h>
using namespace std;

bool canPlaceCows(vector<int> &stalls,int n , int cows , int dist){
    int coordinate = stalls[0] , cnt = 1 ;
    // COORDINATE IS THE FIRST COWS PLACED INITIALLY AT FIRST STALL 
    // CNT IS COUNT OF NUMBER OF COWS INITIALLY PLACES 
    for(int i=1 ; i<n ; i++){
        if(dist <= stalls[i]-coordinate){
            coordinate = stalls[i] ;
            cnt ++ ;
        }
        if(cnt == cows) return true ;
    }
    return false ;
}

int solve(int n, int k, vector<int> &stalls) {
    // FIRST WE HAVE TO SORT THE STALLS 
    sort(stalls.begin() , stalls.end()) ;
    int low = 1 , high = stalls[n-1] - stalls[0] ;
    
    while(low <= high){
        int mid = (low + high) >> 1 ;
        if(canPlaceCows(stalls,n,k,mid)){
            low = mid+1 ;
        }
        else high = mid-1 ;
    }
    return high ;
}

int main() {
    int t ; cin >> t ;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> stalls(n);
        for (int i = 0; i < n; i++) cin >> stalls[i];
        cout << solve(n, k, stalls) << endl;
    }
    return 0;
}
