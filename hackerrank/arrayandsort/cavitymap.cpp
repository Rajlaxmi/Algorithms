#include <iostream>
#include <string>
int sq[101][101];
#define check(i,j) ((sq[i-1][j]<sq[i][j])&&(sq[i+1][j]<sq[i][j])&&(sq[i][j-1]<sq[i][j])&&(sq[i][j+1]<sq[i][j]))
using namespace std;
int main() {
    int n, i, j, len;
    string str;
    cin>>n;
    for(i = 0; i<n; i++) {
        cin>>str;
        len = str.length();
        for(j = 0; j<len; j++)
            sq[i][j]=str.at(j)-48;
    }
    
    for(i = 0; i<n; i++) {
        for(j = 0; j<n; j++) {
            if(i!=0 && i!=n-1 && j!=0 && j!=n-1) {
                if(check(i,j)==1)
                    cout<<"X";
                 
            }
            else
                cout<<sq[i][j];
        }
        cout<<endl;
    }
    return 0;
}
    
