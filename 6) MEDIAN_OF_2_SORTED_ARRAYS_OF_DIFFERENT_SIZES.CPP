// PROBLEM LINK --- https://leetcode.com/problems/median-of-two-sorted-arrays/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/median-of-two-sorted-arrays_985294

#include <bits/stdc++.h>
using namespace std;

double MedianOfArrays(vector<int>& array1, vector<int>& array2)
{
    // Your code goes here
    // TRY TO DO BINARY SEARCH FOR SMALLER SIZE ARRAY 
    if(array1.size() > array2.size()) return MedianOfArrays(array2,array1) ;
    int n1 = array1.size() , n2 = array2.size() ;
    // WE KNOW AT MIN USE CHOOSE 0 ELEMENTS AT MAX WE CHOOSE N1 ELEMENTS
    int low = 0 , high = n1 ;
    while(low <= high){
        // CUT1 IS CUTTING THE ARRAY FOR ARRAY1 AND CUT2 FOR ARRAY2
        int cut1 = (low + high) >> 1 ;
        int cut2 = (n1 + n2 + 1)/2 - cut1 ;
        
        int left1 = (cut1 == 0) ? INT_MIN : array1[cut1-1] ;
        int left2 = (cut2 == 0) ? INT_MIN : array2[cut2-1] ;
        
        int right1 = (cut1 == n1) ? INT_MAX : array1[cut1] ;
        int right2 = (cut2 == n2) ? INT_MAX : array2[cut2] ;
        
        if(left1 <= right2 && left2 <= right1){
            if((n1 + n2)%2 == 0){
                return (max(left1,left2) + min(right1,right2))/2.0 ;
            }
            else{
                return max(left1 , left2) ;
            }
        }
        else if(left1 > right2) high = cut1 - 1 ;
        else  low = cut1 + 1 ;
    }
    return 0.0 ;
}

int main()
{
    int t; cin >> t ;
    while(t--){
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin >> n ;
        vector<int> array2(n) ;
        for (int i = 0; i < n; ++i) cin >> array2[i] ;
        cout << MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}
