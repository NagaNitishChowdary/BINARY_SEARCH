// PROBLEM LINK --- https://leetcode.com/problems/single-element-in-a-sorted-array/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/find-the-element-that-appears-once-in-sorted-array0624/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/unique-element-in-sorted-array_1112654

#include<bits/stdc++.h>
using namespace std;

int findOnce(int arr[], int n)
{
    // APPROACH 1 --- USING XOR 
    // TC --- O(N)   SC --- O(1) 
    /*
    int xo = 0 ;
    for(int i=0 ; i<n ; i++) xo ^= arr[i] ;
    return xo ;
    */
    // APPROACH 2 --- BINARY SEARCH 
    // TC --- O(LOG N)  SC --- O(1)
    
    // IN ORDER TO CHECK FOR THE LEFT HALF 
    // 1ST INSTANCE --- EVEN INDEX I NEED TO CHECK ON THE RIGHT IF THE 2ND INSTANCE 
    //                  OF THAT NUMBER IS THERE OR NOT
    // 2ND INSTANCE --- ODD INDEX I NEED TO CHECK ON THE LEFT IF THE 1ST INSTANCE
    //                  OF THAT NUMBER IS THERE OR NOT
    // EDGE CASE
    if(n == 1) return arr[0] ;
    int low = 0 , high = n-2 ;
    while(low <= high){
        int mid = (low+high) >> 1 ;
        if(arr[mid] == arr[mid^1]) low = mid+1 ;
        // ARR[MID^1] MEANS IT IS LEFT BEFORE ITS INDEX FOR EVEN MID VALUE
        // ARR[MID^1] MEANS IT IS RIGHT AFTER ITS INDEX FOR ODD MID VALUE
        else high = mid-1 ;
    }
    return arr[low] ;
}

int main()
{
    int t ; cin >> t ;
    while (t--){
        int n ; cin >> n ;
        int A[n] ;
        for(int i=0 ; i<n; i++) cin >> A[i] ;
        int res = findOnce(A,n);
        cout << res << endl;
    } 
    return 0;
}
