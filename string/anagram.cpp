#include <iostream>
#include <string>
#include <cmath>
#define loop(i, n) for(i=0; i<n; i++)
using namespace std;

int main()
{
    int t, i, n, sum;
    string str, str1;
    int cnt[256], cnt1[256];
    cin>>t;
    while(t--) {
        cin>>str;
        n = str.length();
        if(n % 2 == 1)
            cout<<"-1"<<endl;
        else {
			//cout<<str<<endl;
            str1 = str.substr(n/2);
            str = str.substr(0, n/2);
            
           //cout<<str<<" "<<str1<<endl;
            loop(i, 256) {
               cnt[i] = 0;
               cnt1[i] = 0;
            }
            cout<<str.length()<<endl;
            cout<<str1.length()<<endl;
            loop(i, n/2) {
                cnt[str.at(i)]++;
                cnt1[str1.at(i)]++;
                cout<<()cnt[str.at(i)]<<" ";
            }
            cout<<n<<endl;
            sum = 0;
            loop(i, 256) {
				if(cnt[i]!=0)
					cout<<1<<" "<<i<<" "<<(int)cnt[i]<<endl;
				if(cnt1[i]!=0)
					cout<<1<<" "<<i<<" "<<(int)cnt1[i]<<endl;
                sum+=abs(cnt[i] - cnt1[i]);
			}
            cout<<sum/2<<endl;
            
        }
    }
	return 0;
}
