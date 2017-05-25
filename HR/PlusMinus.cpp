#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n, nP=0, nN=0, nZ=0;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
	   if(arr[arr_i]>0) nP++;
	   else if(arr[arr_i]==0) nZ++;
	   else nN++;
    }
	cout.precision(6);
	cout<<nP*1.0/n<<endl<<nN*1.0/n<<endl<<nZ*1.0/n;

    return 0;
}