#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include "d_sort.h"

using namespace std;

int main() {
	string line;
	string tem = "";
	vector<string> student;

	ifstream lab("Lab5.txt");
	while (getline(lab, line)) {
		size_t found = line.find_last_of(":");
		line = line.substr(found + 1);
		if (isdigit(line[1])) {
			size_t found = line.find_first_of(" ");
			tem += line.substr(0, found);
			tem += line.substr(found + 1);
		}
		else {
			size_t found = line.find_last_of(" ");
			tem += line.substr(found + 1);
			tem += line.substr(0, found);
		}
		cout << tem << endl;
		student.push_back(tem);
		tem = "";
		
	}
	lab.close();

	quicksort(student, 0, student.size());
	for (int i = 0; i < student.size()-1; i++) {
		for (int x = i++; x < student.size(); x++) {
			if (student[i].compare(student[x]) == 0) {
				student.erase(student.begin() + x);
			}
		}
	}
	string temp = "99999999 ";
	for (int i = 0; i < student.size(); i++) {
		if (student[i].rfind("2", 0) != 0) {
			temp += student[i];
			student[i] = temp;
		}
	}

	ofstream yokla("YoklamaListesi.txt");
	for (int i = 0; i < student.size(); i++) {
		yokla << student[i] << endl;
	}
	
}
