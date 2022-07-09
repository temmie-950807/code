#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma comment(linker, "/STACK:1024000000")
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int long long
#define MAX_SIZE (int)1e6+5
using namespace std;

// declare
int t, n, cnt, total, output;
vector<int> prime(MAX_SIZE, 1), primes, factor();

signed main(void){
	fastio;
	
    // pre-process
    prime[0]=0;
    prime[1]=0;
    for (int i=2 ; i<MAX_SIZE ; i++){
        if (prime[i]==0) continue;
        primes.push_back(i);
        for (int j=2 ; i*j<MAX_SIZE ; j++){
            prime[i*j] = 0;
        }
    }

	// input
	cin >> t;
	while (t--){
        // init
        output = 1;
        total = 0;
        cnt = 0;

        // input
		cin >> n;
        
        // process
        int i=0;
        while (i<primes.size()){
            if (n%primes[i]==0){
                n/=primes[i];
                total++;
                cnt++;
                output *= total;
                output /= cnt;
            }else{
                cnt=0;
                i++;
            }
        }

        // output
        cout << output << "\n";
	}
    return 0;
}