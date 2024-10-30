#include<bits/stdc++.h>
using namespace std;
string nearest(string str)
{
    int n,carry,cur_digit,i;
    n=str.length();
    if((str[n-1]-'0')<=5)
    {
        str[n-1]='0';
    }
    else
    {
        str[n-1]='0';
        carry=1;
        i=n-2;
        while(i>=0 && carry==1)
        {
            cur_digit=str[i]-'0';
            cur_digit+=carry;
            if(cur_digit>9)
            {
                cur_digit=0;
                carry=1;
            }
            else
            {
                carry=0;
            }
            str[i]=cur_digit+'0';
            if(carry==1)
            {
                cout<<carry;
            }
            return str;
        }
    }
}
int main()
{
   string str;
   cout<<"Enter string:";
   cin>>str;
   string modified_str=nearest(str);
   cout<<"Nearest to 10 string is:"<<modified_str;
   return 0;
}