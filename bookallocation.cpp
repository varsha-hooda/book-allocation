#include<iostream>
#include<vector>
using namespace std;
int isvalid( vector<int> &arr, int n , int m , int maxallowedpages){
    int student = 1; int pages = 0;
    for (int i = 0; i < n; i++)
    {
      if(arr[i] > maxallowedpages)
      return false;
      if(pages + arr[i] <= maxallowedpages){
        pages+=arr[i];
      }
      else {
        student ++;
        pages= arr[i];
    }
    
}
return student >m ? false:true;
}
int allocation(vector<int> &arr, int n , int m){
    if(m>n){
        return -1;
    }
    int sum = 0;
for (int i = 0; i < n; i++)
{
    sum += arr[i];
}
int ans = -1;
   int start = 0; int end = sum;
   while (start<=end)
   {
    int mid = start + (end-start)/2;
    if(isvalid (arr,n,m,mid)){
       ans = mid;
        end = mid-1;
    }
    else{
    start = mid + 1;
    }

   }
   
return ans;
}

int main(){
    vector<int>arr = {2,1,3,4};
    int n = 4;
     int m= 2;
     cout << allocation(arr, n,m) << endl;
     return 0;
}