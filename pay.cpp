#include "person.cpp"
#include <iostream>
#include <fstream>
#include <string> 
#include <vector>

using namespace std;

void readData(const char* f, vector<Person> &e);
void writeData(const char* f, vector<Person> &e);

int main() {

  vector<Person> employees;

  readData("input.txt", employees);
  writeData("output.txt", employees);

  return 0;
}

void readData(const char* f, vector<Person> &e) {
  ifstream inData;
  inData.open(f);
  string fname;
  string lname;
  string line;
  float hours;
  float pay;
  while (!inData.eof()) {
    inData >> fname;
    inData >> lname;
    inData >> hours;
    inData >> pay; 
    e.emplace_back(fname, lname, pay, hours);
    getline(inData, line);
  }
  inData.close();  
}

void writeData(const char* f, vector<Person> &e) {
  ofstream file;
  file.open(f);
  for (int i = 0; i < e.size()-1; i++) { 
    file << e[i].fullName() << " " << e[i].totalPay() << endl;
  }
  file.close();
}
