#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct car {
	string name;
	int price;
	char walluet[200];
};

void fillout_this(car buy , ofstream &file) {

	cout << "Name :" << endl;
	cin >> buy.name;
	cout << "Price :" << endl;
	cin >> buy.price;
	cout << "Walluet :" << endl;
	cin >> buy.walluet;
	cout << "Rate :" << endl;
	cout << "Name  -" <<buy.name<< "\n"<<endl;
	cout << "Price -" <<buy.price<< "\n"<<  endl;
	cout << "Walluet -" << buy.walluet << "\n"<<  endl << endl;

	cout << "Edit Data? \n 1.Yes 2.No"<< endl;
	 int b =0 ;
	cin >>  b;
	if (b == 1) {
		fillout_this(buy , file);
	}
	else {
		cout << "Saving...."<< endl;
		file.open(buy.name + ".txt");

		file <<"Name - " << buy.name;
		file <<"Price - " << buy.price;
		file <<"Walluet - " <<buy.walluet;

		cout << "file successfull saving!" << endl;
		file.close();
		
	
	}
}
void find_this(string name, car buy, ofstream &file) {
	ofstream file_2;
	file_2.open(name, ofstream::in);
	if (!file_2.is_open()) {
		cout << "Not Found!" << endl;
		cout << "Create new file ? \n 1.Yes 2.No" << endl;
		int a;
		cin >> a;
		if (a == 1) {
			fillout_this(buy, file);
		}
	}
	else {
		cout << "succes open file"<<endl;
	}
}


int main() {
	car buy;
	ofstream file_1;
	ofstream &file = file_1;
	string name;

	cout << "1. Add car \n2. Find file of car " << endl;
	int a;
	cin >> a;
		if (a == 1) {

			fillout_this(buy, file);
		}
		else {
			cout << "input name file : " << endl;
			cin >> name;
			find_this(name, buy , file_1);

		}
	system("pause");
	return 0;
}
