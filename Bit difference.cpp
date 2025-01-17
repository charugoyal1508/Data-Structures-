#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int countBits(int n, long long int a[])
    {
        long long one = 1;
        
        int mod = 1000000007;
        
        int bit[64];  memset(bit,0,sizeof(bit));
        
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < 64 ; j++)
            if(a[i] & (one << j))
            bit[j] = (bit[j] + 1) % mod;
        }
        int sum = 0;
        
        for(int i = 0 ; i < 64 ; i++)
        sum = (sum % mod +  (2 * (bit[i] % mod) * ((n - bit[i] + mod) % mod) ) % mod ) % mod;
        
        return sum;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    }
    return 0;
}
