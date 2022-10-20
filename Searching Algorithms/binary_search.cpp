#include<iostream>
using namespace std;

int Binary(int[],int,int);
int main()
{
int ar[50],size,item,i,pos;
cout<<"Enter number of elements=";
cin>>size;
cout<<"Enter Array's Elements=";
for(i=0;i<size;i++)
cin>>ar[i];
cout<<"Enter element which to be searched=";
cin>>item;

pos=Binary(ar,size,item);

if(pos==-1)
cout<<"Element not Found";
else
cout<<"Element Found at="<<(pos+1);

return 0;
}


int Binary(int ar[],int size,int item)
{
int low,high,mid;
low=0;
high=size-1;
while(low<=high)
{
mid=(low+high)/2;
if(item==ar[mid])
return mid;
else if(item<ar[mid])
high=mid-1;
else
 low=mid+1;
}    

return -1;
}