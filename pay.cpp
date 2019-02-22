#include "person.cpp"
#include <iostream>
#include <fstream>
#include <string> 

using namespace std;

void readData(const char* f, Person e[], int s);
void writeData(const char* f, Person e[], int s);

int main() {

  const int SIZE = 20;
  Person employees[SIZE];

  readData("input.txt", employees, SIZE);
  writeData("output.txt", employees, SIZE);

  return 0;
}

void readData(const char* f, Person e[], int s) {
  ifstream inData;
  inData.open(f);
  string fname;
  string lname;
  string line;
  float hours;
  float pay;
  int index = 0;
  while (!inData.eof()) {
    if (index < s) {
      inData >> fname;
      inData >> lname;
      inData >> hours;
      inData >> pay; 
      if (index > 0 && fname != e[index-1].getFirstName() && lname != e[index-1].getLastName()) {
        e[index].setFirstName(fname);
        e[index].setLastName(lname);
        e[index].setHoursWorked(hours);
        e[index].setPayRate(pay);
      }
      index++;
      getline(inData, line);
    }
  }
  inData.close();  
}

void writeData(const char* f, Person e[], int s) {
  ofstream file;
  file.open(f);
  for (int i = 0; i < s; i++) { 
    if (e[i].totalPay() != 0) {
      file << e[i].fullName() << " " << e[i].totalPay() << endl;
    }
  }
  file.close();
}
