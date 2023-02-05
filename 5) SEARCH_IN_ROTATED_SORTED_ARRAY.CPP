// PROBLEM LINK --- https://leetcode.com/problems/search-in-rotated-sorted-array/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_1082554?leftPanelTab=0

#include <bits/stdc++.h>
using namespace std;

int search(int A[], int l, int h, int key){
    // l: The starting index
    // h: The ending index, you have to search the key in this range
    
    //complete the function here
    // OPTIMIZED APPROACH  --- BINARY SEARCH 
    // TC --- O(LOG N)  SC --- O(1)
    while(l <= h){
        // STEP 1 IS TO CHECK IF MIDDLE VALUE EQUAL TO TARGET 
        int mid = (l+h)/2 ;
        if(A[mid] == key) return mid ;
        // STEP 2 IS TO CHECK EITHER WHICH SIDE OF ARRAY IS SORTED
        if(A[l] <= A[mid]){
            if(A[l] <= key && A[mid] >= key) h = mid ;
            else l = mid+1 ;
        }
        // HERE RIGHT HALF IS SORTED
        else{
            if(A[mid] <= key && A[h] >= key) l = mid ;
            else h = mid-1 ;
        }
    }
    return -1 ;
}

int main() {
    int t ; cin >> t ;
    while(t--){
        int n ; cin >> n ;
        int A[n] ;
        for(int i = 0; i < n; i++) cin >> A[i];
        int key ; cin >> key ;
        cout << search(A, 0, n - 1, key) << endl;
    }
return 0;
}
