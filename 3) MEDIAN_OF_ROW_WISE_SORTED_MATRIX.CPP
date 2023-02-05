// PROBLEM LINK --- https://www.interviewbit.com/problems/matrix-median/
// PROBLEM LINK --- https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

#include <bits/stdc++.h>
using namespace std;

int countSmallerThanEqualToMid(vector<int> &knnc,int mid){
    int low = 0 , high = knnc.size()-1 ;
    while(low <= high){
        int m = (low+high) >> 1 ;
        if(knnc[m] <= mid) low = m+1 ;
        else high = m-1 ;
    }
    return low ;
}

int median(vector<vector<int>> &matrix, int R, int C){
    // BRUTEFORCE   TC --- 0(N*M) + O(N*M LOG(N*M))
    /*
    vector<int> knnc ;
    for(int i=0 ; i<R ; i++)
        for(int j=0 ; j<C ; j++)
            knnc.emplace_back(matrix[i][j]) ;
    sort(knnc.begin() , knnc.end()) ;
    return knnc[((R*C)/2)] ;
    */
    
    // OPTIMIZED APPROACH --- BINARY SEARCH 
    int low = 1 , high = 1e9 ;
    while(low <= high){
        int mid = (low+high)/2 ;
        int cnt = 0 ;
        for(int i=0 ; i<R ; i++)
            cnt += countSmallerThanEqualToMid(matrix[i],mid) ;
        if(cnt <= (R*C)/2) low = mid+1 ;
        else high = mid-1 ;
    }
    return low ;
}

int main()
{
    int t ; cin >> t ;
    while(t--){
        int r, c;
        cin >> r >> c ; 
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        cout << median(matrix, r, c) << endl;        
    }
    return 0;
}
