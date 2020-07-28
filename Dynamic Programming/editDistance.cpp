#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;

// O(n*m) Space and Time
lli editDistance(string s1, string s2){
    int l1 = s1.size();
    int l2 = s2.size();

    lli memo[l1][l2];

    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            if(i==0){
                memo[i][j] = j; // Base cases when one string is of length 0
            } else if(j==0){
                memo[i][j] = i; // Base cases when one string is of length 0
            } else {
                if(s1[i-1] == s2[j-1]){ // Check is char are equal 
                    memo[i][j] = memo[i-1][j-1];
                } else {
                    memo[i][j] = 1 + min(min(
                                            memo[i-1][j], // Remove an element 
                                            memo[i][j-1]), // Add and element
                                            memo[i-1][j-1] // Replace element
                                             );
                }
            }
        }
    }

    return memo[l1][l2];
}

int main(){
    string s1 = "LOVE";
    string s2 = "MOVIE";
    cout<<editDistance(s1,s2)<<endl;
    return 0;
}