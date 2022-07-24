#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
ll n,m,i;
cin >> n >> m;
ll arr[10000],cnt=0;
arr[0]=0;
for (i=1;i<=7;i++) {
    cin >> arr[i];
    cnt+=arr[i];
}
ll week=n/cnt;
ll tmp=n%cnt;
ll day=8;
while (tmp>0) {
    if (tmp<=0) break;
    if (day==1) break;
    tmp-=arr[day-1];
    day--;
}
week=m-week;
if (day==8) {
    week++;
    day=1;
}
if (m*cnt<n)
    cout << "-1\n";
else
    cout << week << " " << day << "\n";
return 0;
}