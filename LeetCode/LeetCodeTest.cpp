#include<iostream>
#include<vector>
#include<algorithm>   ///
using namespace std;

int main(int argc, char* argv[]){

	vector<int> v{ 1, 2, 2 };
	v.resize(4);
	//v.push_back(3);
	v[3] = 7;
	//remove(v.begin(), v.end(), 2);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		cout << *it << endl;
	}

	return 0;
}