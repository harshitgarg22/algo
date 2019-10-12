#include<iostream>
#include<vector>
#include<ctime>
#include "quicksort.h"

using namespace std;

int main(){

  vector<int> arr;

  int inp;

  cout<<"Enter the array (input 0 to stop): ";
  cin>>inp;

  while(inp!=0){
    arr.push_back(inp);
    cin>>inp;
  }

  cout<<"The array you entered is: ";
  for(int i=0; i<(int)arr.size(); i++){
    cout<<arr.at(i);
  }

  cout<<endl;

  clock_t execTime = clock();
  quicksort(arr);
  execTime = clock() - execTime;

  cout<<"The sorted array is: ";
  for(int i=0; i<(int)arr.size(); i++){
    cout<<arr.at(i);
  }

  cout<<fixed<<"\nSorting took "<<(double)execTime/CLOCKS_PER_SEC<<" seconds.";
  cout<<endl;

  return 0;
}
