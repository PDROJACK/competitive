#include<bits/stdc++.h>
typedef long long int li;
using namespace std;
li mod;

li fastexp(li a, li b, li mod){
    li res = 1;

    if(a==0 && b==0) return 1;
    if(a==0) return 0;
    if(b==0) return 1;

    while(b>0){

        // if b is odd
        if(b&1) {
            // mutilpy result by a 
            res = (res%mod * a%mod)%mod;
        }

        // reduce b by half
        b = b>>1;
        a = (a*a)%mod;
    }

    return res;
}

int main(){
    li t;
    cin>>t;
    mod = (li)1e9+7;
    
    while(t--){
        li a,b,c;
        cin>>a>>b>>c;

        //  b
        // a
        cout<<(li)fastexp(a, b, mod)<<endl;
    
    
        //
        //   c
        //  b
        // a
        cout<<(li)fastexp(a,fastexp(b,c, mod-1), mod)<<endl;
    
    }
    return 0;
}