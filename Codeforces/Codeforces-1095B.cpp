#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n+10];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr,arr+n);

    int ans = min(arr[n-1]-arr[1],arr[n-2]-arr[0]);
    cout << ans << endl;
    return 0;
}
