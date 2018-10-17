#include <iostream>
#define maxn 100005
using namespace std;
int a[maxn];

int main()
{
    int t;
    cin>>t;
    int k = 0;
    while(t--)
    {
        int cost;
        int n;
        cin>>n;
        for(int i = 0;i<n;i++)
        {
            cin>>a[i];
        }



        cout<<"Case #"<<++k<<":"<<endl<<cost<<endl;
    }
    return 0;
}
