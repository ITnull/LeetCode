#include<iostream>
#include<vector>
#include<algorithm>   ///
using namespace std;


vector<vector<int>> generate(int numRows){
	vector<vector<int>> result;
	result.resize(numRows);	//�������ǳ���Ҫ,û�лᵼ��vector subscript out of range ����

	for (size_t i = 1; i < numRows + 1; i++){
		for (size_t j = 0; j < i; j++){
			if (j == 0 || j == (i - 1)){

				result[i - 1].resize(i);	////�������ǳ���Ҫ

				result[i - 1][j] = 1;	

			}
			else{
				result[i - 1][j] = result[i - 2][j - 1] + result[i - 2][j];
			}

		}
	}
	return result;
}

int main(int argc, char* argv[]){

	vector<vector<int>> result = generate(5);

	for (int i = 0; i < result.size(); i++){
		for (int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}