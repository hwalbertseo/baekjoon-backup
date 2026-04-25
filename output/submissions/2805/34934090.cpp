#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin >>arr[i];
    }
    sort(arr, arr+n);
    int left = 1;
    int right = arr[n-1];
    while(left < right){
        int sum = 0;
        int sum2 = 0;
        int sum3 = 0;
        int mid = (left+right)/2;
        int mid2 = mid-1;
        int mid3 = mid+1;
        //cout << "mid " << mid << "\n";
        for(int i = 0;i< n;i++){
            int temp = arr[i]-mid;
            sum += (temp >= 0) ? temp : 0;
            temp = arr[i]-mid2;
            sum2 += (temp >= 0) ? temp : 0;
            temp = arr[i]-mid3;
            sum3 += (temp >= 0) ? temp : 0;
        }
        //cout << "sum " << sum  << " " << k << "\n";
        if(sum == k){
            //cout << " a\n";
            if(sum3 == k){
                left = mid+1;
                continue;
            }
            else{
                cout << mid;
                return 0;
            }
        }
        else if(sum < k){
            //cout << " a\n";
            right = mid-1;
        }
        else if(sum > k){
            if(sum2 == k){
                //cout << " c\n";
                cout << mid2;
                return 0;
            }
            else if(sum2 > k){
                //cout << " d\n";
                if(sum3 >= k){
                    //cout << " e\n";
                    left = mid+1;
                }
                else if(sum3 < k){
                    //cout << " f\n";
                    cout << mid;
                    return 0;
                }
            }
        }
    }
    cout << right;
}
