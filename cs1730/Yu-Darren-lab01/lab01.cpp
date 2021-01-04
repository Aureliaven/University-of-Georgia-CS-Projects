// Computes the Hamming distance between 2 integers in the command line
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char * argv[]) {
  // read command line arguments and convert to integers
  int num1 = stoi(argv[1], nullptr, 10);
  int num2 = stoi(argv[2], nullptr, 10);
  string str1, str2 = "";

  // convert integers to bit strings
  while (num1 > 0) {
    str1 = to_string(num1 % 2) + str1;
    num1 /= 2;
  }
  while (num2 > 0) {
    str2 = to_string(num2 % 2) + str2;
    num2 /= 2;
  }

  // fill in leading zeros to make bit strings equal-length
  if (str1.length() > str2.length()) {
    string new_str = "";
    for (int i = 0; i < str1.length() - str2.length(); i++) {
      new_str += "0";
    }
    new_str += str2;
    str2 = new_str;
  }
  else {
    string new_str = "";
    for (int i = 0; i < str2.length() - str1.length(); i++) {
      new_str += "0";
    }
    new_str += str1;
    str1 = new_str;
  }

  // calculate Hamming distance by comparing each bit
  int hamming = 0;
  for (int i = 0; i < str1.length(); i++) {
    if (str1[i] != str2[i]) {
      hamming++;
    }
  }

  // print to standard output
  cout << str1 << " is the bit string for " << argv[1] << endl;
  cout << str2 << " is the bit string for " << argv[2] << endl;
  cout << hamming << " is the Hamming distance between the bit strings" << endl;
} // main
