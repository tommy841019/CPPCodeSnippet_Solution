#include <iostream>
#include <deque> 
#include <algorithm>
#include <vector>
using namespace std;
void printKMax(int arr[], int n, int k){
    deque<int> dq; 
    int max=arr[0];
	dq.push_back(arr[0]);
    for(int i=1; i<k; ++i){
        dq.push_back(arr[i]);
        max = max>arr[i] ? max : arr[i];
    }
    for(int i=k, tmp; i<n; ++i){
        cout<<max<<" ";
        tmp = dq.front();
        dq.pop_front();
        if(tmp == max && !dq.empty()){
            max = *(max_element(dq.begin(), dq.end()));
        }
        dq.push_back(arr[i]);
        max = (dq.size()==1) ? arr[i] : max>arr[i] ? max : arr[i];   
    }
    cout<<max<<endl;
}
/*
int main(){
  
   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
	   n=7;
       int i;
       int arr[7];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}
*/