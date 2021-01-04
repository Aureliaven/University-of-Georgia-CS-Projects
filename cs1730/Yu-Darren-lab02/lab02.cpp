// Represents a DNA string with letters A, T, C, G represented as bit strings
// in binary. Compresses them into integers and decompresses integers back
// into an "A, T, C, G" format

#include <iostream>
#include <string>
using namespace std;

int main (int argc, char * argv[]) {

  // check if the argument is empty
  if (argv[1] == NULL) {
    cout << "Usage: ./lab02 [-c | -d] [DNA string | integer sequence]" << endl;
    return EXIT_SUCCESS;
  } // if

  // check the -c or -d option
  string option = argv[1];
  if (option == "-c") {
    string d = argv[2];
    cout << d.length();
    unsigned int i = 0;
    unsigned char b = 00000000;
    unsigned int count = 0;
    for (; i < d.length(); i++) {
      if (d[i] == 'A') {
	b |= 0;
      } // if
      else if (d[i] == 'T') {
	b |= 1;
      } // else if
      else if (d[i] == 'C') {
	b |= 2;
      } // else if
      else if (d[i] == 'G') {
	b |= 3;
      } // else if
      count++;
      if (count != 4) {
	b <<= 2;
      } // if
      else {
	int dec = (int) b;
	cout << " " << dec;
	b = 00000000;
	count = 0;
      } // else
      if (count != 4 && i == d.length() - 1) {
	if (count == 1) {
	  b <<= 2;
	  b <<= 2;
	} // if
	if (count == 2) {
	  b <<=2;
	} // if
	int dec = (int) b;
	cout << " " << dec;
      } // if
    } // for
    cout << endl;
  } // if
  
  else if (option == "-d") {
    unsigned int length = stoi(argv[2],nullptr,10);
    string d = "";
    unsigned int count;
    unsigned int i = 0;
    unsigned char b;
    unsigned char temp;
    int arg = 3;
    for (; arg < argc; arg++) {
      b = stoi(argv[arg],nullptr,10);
      for (count = 3; count >= 0; count--) {
	temp = b;
	temp >>= count * 2;
	if (count < 3) {
	  temp &= 3;
	} // if
	if (temp == 0) {
	  d += "A";
	} // if
	if (temp == 1) {
	  d += "T";
	} // if
	if (temp == 2) {
	  d += "C";
	} // if
	if (temp == 3) {
	  d += "G";
	} // if
	i++;
	if (count == 0) {
	  break;
	} // if
	if (i == length) {
       	  goto end;
	} // if
      } // for
    } // for
  end:
    cout << d << endl;
  } // else if
  
  else {
    cout << "Usage: ./lab02 [-c | -d] [DNA string | integer sequence]" << endl;
  } // else

  return EXIT_SUCCESS;
  
} // main
