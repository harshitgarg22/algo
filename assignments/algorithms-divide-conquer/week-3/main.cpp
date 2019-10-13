#include<iostream>
#include<fstream>
#include<sstream>
#include "../../../array_ops/quicksort.h"

using namespace std;

int main(int argc, char **argv){

  int method = 2;

  if(argc==1){
    cout<<"Which method of partitioning would you like to use? ";
    cin>>method;
  }

  else {
    istringstream methodInput(argv[1]);
    methodInput>>method;
  }

  ifstream QuickSort;
  // QuickSort.open("./QuickSort.txt");
  string fileName = "./input_dgrcode_05_5.txt";
  QuickSort.open(fileName);

  int num_lines = 0;

  {
    ifstream countLines;
    countLines.open(fileName);

    string s;

    while(getline(countLines, s)){
      num_lines++;
    }
  }

  vector<int> arr;
  int var;

  for(int i=0; i<num_lines; ++i){
    QuickSort>>var;
    arr.push_back(var);
  }

  unsigned long int count = 0;
  count = quicksort(arr, method);

  cout<<"The count of comparisons is: "<<count<<endl;
}
