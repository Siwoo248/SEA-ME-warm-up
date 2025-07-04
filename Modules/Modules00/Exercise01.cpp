#include<iostream>
#include<string>
using namespace std;

int main(int argc, char* argv[]){
	if(argc < 3){
		cout<<"./convert {up|down} {string}"<<endl;
		return 1;
	}

	string input;

	for(int i = 2; i < argc; i++){
		input += argv[i];
		if(i < argc - 1) input += " ";
	}

	if(argv[1] == string("up")){
		for(char& c : input) c = toupper(c);

	}
	else if(argv[1] == string("down")){
		for(char& c : input) c = tolower(c);

	}
	else{
		cout<<"Invalid option. Use 'up' or 'down'."<<endl;
		return 1;
	}

	cout << input << endl;
	return 0;
}
