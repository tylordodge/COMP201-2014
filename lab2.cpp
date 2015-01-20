#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main(){

	vector<int> num;
	string input;
	int left, right, convert;
	char *end;
	
	cout << "Enter the string:" << endl;
	
	while (cin >> input){
		
			if (input == "+"){
				right = num.back();
				num.pop_back();
				left = num.back();
				num.pop_back();
			
				num.push_back(left + right);
			}
			else if (input == "-"){
				right = num.back();
				num.pop_back();
				left = num.back();
				num.pop_back();
			
				num.push_back(left - right);
			}
			else if (input == "*"){
				right = num.back();				
				num.pop_back();
				left = num.back();
				num.pop_back();
				
				num.push_back(left * right);		
			}
			else if (input == "/"){
				right = num.back();
				num.pop_back();
				left = num.back();
				num.pop_back();
				
				num.push_back(left / right);		
			}
			else if (input == ".") {
				cout << num[0] << endl;
				break;
			}
			else {
				convert = strtol(input.c_str(), &end, 10);
				num.push_back(convert);
			}
			
	}
	return 0;	
}