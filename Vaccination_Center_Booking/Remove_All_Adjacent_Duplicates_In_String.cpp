#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int i,n;

    n= s.length();
    cout<<"\nlength of string :"<<n;
    cout<<"\nhello";
    for(i=1;i<n-1;i++)
    {
        while(s[i]==s[i+1])
        {
            s.erase(i,2);

            cout<<"\ni-"<<i<<"-str-"<<s[i];
           // i++;

        }
        while(s[i]==s[i-1] && i>1)
        {

            cout<<"\ni-"<<i<<"-str-"<<s[i]<<"- (i-1)="<<s[i-1];
            s.erase(i-1,2);
            i--;

        }


        cout<<"\n"<<s<<" - "<<i ;
    }
    /*for(i=1;i<n-1;i++)
    {
            while(s[i]==s[i+1])
            {
                s.erase(i,2);
            }
            while(s[i]==s[i-1] && i>0)
            {
                s.erase(i-1,2);
                i--;
            }
    }*/
    cout<<s;
}


