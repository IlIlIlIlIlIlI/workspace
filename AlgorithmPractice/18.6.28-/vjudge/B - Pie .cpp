/*#include <iostream>
#include <cstdio>
#include <algorithm>
#define maxn 10005
#define PI 3.14159
using namespace std;

double pie[maxn];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,f;
        cin>>n>>f;
        f++;
        for(int i = 0;i<n;i++)
        {
            int tmp;
            cin>>tmp;
            pie[i] = PI*tmp*tmp;
        }
        sort(pie,pie+n);

        double cnt;
        double ans = 0;
        double l = 0,r = pie[n-1],mid;
        while((r-l) > 1e-5)
        {
            cnt = 0;
            mid = (l+r)/2;
            for(int i = 0;i<n;i++)
            {
                cnt += pie[i]/mid;
            }
            if(cnt >= f)
            {
                ans = max(ans,cnt);
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        printf("%.4lf\n",ans);
    }
    return 0;
}*/

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#define pi acos(-1.0)
using namespace std;

double pie[11000];
int main(){
    int T,n,f,r;
    double mmax;
    cin>>T;
    while(T--){
        mmax = 0;
        cin>>n>>f;
        f++;
        for(int i=0;i<n;++i){
                //cout<<pi<<endl;
            cin>>r;
            pie[i] = r*r*pi;
        }
        sort(pie,pie+n);
        int cnt;
        double mid,l = 0,r = pie[n-1];
        while((r-l) > 1e-5){
            cnt = 0;
            mid = (l + r) / 2;
            for(int i=0;i<n;++i){
                cnt += pie[i]/mid;
            }
            if(cnt >= f){
                mmax = max(mmax,mid);
                l = mid;
            }
            else    r = mid;
        }
        printf("%.4lf\n",mmax);
    }
    return 0;
}

