#include<bits/stdc++.h>

using namespace std;


// given an array of values you can pick first or last value then other players turn, you have to maximize your value you play first

int gamePlaying(int arr[], int i, int j){
    // i, i
    if(i==j) return arr[i];
    
    // i, i+1
    if(i+1==j) return max(arr[i], arr[j]);

    // i, j
    return max( 
                gamePlaying(arr, i+1, j)+min(gamePlaying(arr, i+2, j), 
                gamePlaying(arr, i+1, j-1)), 
                gamePlaying(arr, i, j-1) + min(gamePlaying(arr, i+1, j-1),
                gamePlaying(arr, i,j-2))
            );
}



int main(){
    int n;
    cin>>n;;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[n];
    }

    cout<<gamePlaying(arr, 0, n)<<endl;

    return 0;
}