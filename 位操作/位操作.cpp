#include<iostream>

using namespace std;

//������

void test(){
	int a = 0;
	int b = 1;
	//int c = a | b;
	cout << !(a^b) << endl;
}


int main(int argc, char* argv[]){
	test();
	return 0;
}