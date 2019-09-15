#include <vector>
#include <iostream>

using namespace std;

class graph {

public: vector<vector<int> > vertex;

};

int main(int argc, char **argv){
  graph sample;
  cout<<"Hello, this program will generate a graph for you.\n";

  int no_vertices;
  cout<<"Enter the number of vertices that you'd like to add: ";
  cin>>no_vertices;

  cout<<"Write in the form for nth vertex: \n"
      <<"[n]= <input vertices of outgoing edges> (Type 0 to end input)\n\n";

  sample.vertex.resize(no_vertices);
	int val;

  for(int i=0; i<no_vertices; i++){
    cout<<"["<<i+1<<"]= ";

		do{
				cin>>val;
				if(val==0) break;
				sample.vertex[i].push_back(val);
		}while(val!=0);

  }

	for(int i=0; i<sample.vertex.size(); i++){
			cout<<"["<<i+1<<"]= {";
			for(int j=0; j<sample.vertex[i].size(); j++){
					cout<<sample.vertex[i][j]<<',';
					}
			if(sample.vertex[i].size()!=0){
					cout<<"\b";
			}
			cout<<"}\n";
	}

}
