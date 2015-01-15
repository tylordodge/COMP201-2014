#include <iostream>
#include <fstream>
#include <cstring>	//this library allows for char * for command line!
using namespace std;

int main(int argc, char *argv[]){

	
	ifstream  inf;
	ofstream outf;
	int sum, value;
	sum = 0;
	
	
	
	inf.open(argv[1]);
	if (inf.fail()){
		cout << "The file failed to open!" << endl;
		}
		
	outf.open("output.txt");
	if (outf.fail()){
		cout << "The output file failed to open!" << endl;
		}
		
	outf << "x\t" << "x^2\t" << "Current Sum" << endl;
	outf << "=\t" << "===\t" << "===========" << endl;

	while (inf >> value){
		sum = sum + value;
		outf << value << "\t" << value * value << "\t" << sum << endl;
	}

	inf.close();
	outf.close();

	return 0;
}