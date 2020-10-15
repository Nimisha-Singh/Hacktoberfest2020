#include<bits/stdc++.h>
using namespace std;
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int size;
	    cin>>size;
	    int a[size];
	    for(int i=0;i<size;i++)
	    {
	        cin>>a[i];
	    }
	    int temp[size];
	    int small=0;
	    int large=size-1;
	    bool flag=true;
	    for(int i=0;i<size;i++)
	    {
	        if(flag)
	        {
	            temp[i]=a[large--];
	        }
	        else
	        {
	            temp[i]=a[small++];
	        }
	        flag=!flag;
	    }
	    for(int i=0;i<size;i++)
	    {
	        a[i]=temp[i];
	    }
	    for(int i=0;i<size;i++)
	    {
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}