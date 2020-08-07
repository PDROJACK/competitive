#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;


int lis(vector<int> arr){
    int n = arr.size();
    int memo[n+1];

    for(int i=0;i<n;i++){
        memo[i]=1;
        //lis = max(lis, memo[i]);
    }


    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i] && memo[i]<memo[j]+1){
                memo[i] = memo[j]+1;
            }
        }
    }
    

    int lis = INT_MIN;
    for(int i=0;i<n;i++){
        //cout<<memo[i]<<" ";
        lis = max(lis, memo[i]);
    }
    //cout<<endl;

    return lis;
}

int main(){
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    cout<<lis(arr);
    return 0;
}