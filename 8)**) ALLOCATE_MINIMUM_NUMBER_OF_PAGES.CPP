// PROBLEM LINK --- https://www.interviewbit.com/problems/allocate-books/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// PROBLEM LINK --- https://www.codingninjas.com/codestudio/problems/allocate-books_1090540?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;
    
bool allocationIsPossible(int A[] , int N , int M , int barrier){
    int studentsAllocated = 0 , pages = 0 ;
    for(int i=0 ; i<N ; i++){
        if(A[i] > barrier) return false ;
        if(pages + A[i] > barrier){
            studentsAllocated++ ;
            pages = A[i] ;
        }
        else pages += A[i] ;
    }
    if(studentsAllocated < M) return true ;
    return false ;
}

//Function to find minimum number of pages.
int findPages(int A[], int N, int M) 
    {
    //code here
    // EDGE CASE 
    if(M > N) return -1 ;
    int low = A[0] , high = 0 ;
    for(int i=0 ; i<N; i++){
        low = min(low , A[i]) ; 
        high += A[i] ;
    }

    while(low <= high){
        int mid = (low + high) >> 1 ;
        if(allocationIsPossible(A,N,M,mid)) high = mid-1 ;
        else low = mid+1 ;
    }
    return low ;
}

int main() {
    int t ; cin >> t ;
    while(t--){
        int n ; cin >> n ;
        int A[n] ;
        for(int i=0;i<n;i++) cin >> A[i] ;
        int m ; cin >> m ;
        cout << findPages(A, n, m) << endl;
    }
    return 0;
}
