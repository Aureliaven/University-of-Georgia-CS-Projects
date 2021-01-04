#include "proj1.h"
#include <string>
#include <iostream>
using namespace std;

// universal variable for number of valid expressions
int count = 0;

// accepts a pointer to an array containing a permutation
// of the 5 integers and compares them to the int to be
// evaluated to
void operate(string mode, int * permutation, int e) {

  // tries every combination of 4 out of 5 operators,
  // wherein order matters and operators may be repeated
  int result = 0;
  if (mode == "-a") {
    string operators[5] = {"+", "-", "*", "/", "%"};
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
	for (int k = 0; k < 5; k++) {
	  for (int l = 0; l < 5; l++) {
	    if (i == 0) {
	      result = *permutation + *(permutation + 1);
	    } // if
	    if (i == 1) {
	      result = *permutation - *(permutation + 1);
	    } // if
	    if (i == 2) {
	      result = *permutation * *(permutation + 1);
	    } // if
	    if (i == 3) {
	      result = *permutation / *(permutation + 1);
	    } // if
	    if (i == 4) {
	      result = *permutation % *(permutation + 1);
	    } // if
	    if (j == 0) {
	      result += *(permutation + 2);
	    } // if
	    if (j == 1) {
	      result -= *(permutation + 2);
	    } // if
	    if (j == 2) {
	      result *= *(permutation + 2);
	    } // if
	    if (j == 3) {
	      result /= *(permutation + 2);
	    } // if
	    if (j == 4) {
	      result %= *(permutation + 2);
	    } // if
	    if (k == 0) {
	      result += *(permutation + 3);
	    } // if
	    if (k == 1) {
	      result -= *(permutation + 3);
	    } // if
	    if (k == 2) {
	      result *= *(permutation + 3);
	    } // if
	    if (k == 3) {
	      result /= *(permutation + 3);
	    } // if
	    if (k == 4) {
	      result %= *(permutation + 3);
	    } // if
	    if (l == 0) {
	      result += *(permutation + 4);
	    } // if
	    if (l == 1) {
	      result -= *(permutation + 4);
	    } // if
	    if (l == 2) {
	      result *= *(permutation + 4);
	    } // if
	    if (l == 3) {
	      result /= *(permutation + 4);
	    } // if
	    if (l == 4) {
	      result %= *(permutation + 4);
	    } // if

	    // prints the expression if it evaluates to the int
	    // and increments the count variable
	    if (result == e) {
	      count++;
	      cout << "(((" << *permutation << operators[i]
		   << *(permutation + 1) << ")" << operators[j]
		   << *(permutation + 2) << ")" << operators[k]
		   << *(permutation + 3) << ")" << operators[l]
		   << *(permutation + 4) << endl;
	    } // if  
	  } // for l
	} // for k
      } // for j
    } // for i 
  } // if

  // same as arithmetic with different operators
  else if (mode == "-b") {
    string operators[5] = {"<<", ">>", "&", "|", "^"};
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
	for (int k = 0; k < 5; k++) {
	  for (int l = 0; l < 5; l++) {
	    if (i == 0) {
	      result = *permutation << *(permutation + 1);
	    } // if
	    if (i == 1) {
	      result = *permutation >> *(permutation + 1);
	    } // if
	    if (i == 2) {
	      result = *permutation & *(permutation + 1);
	    } // if
	    if (i == 3) {
	      result = *permutation | *(permutation + 1);
	    } // if
	    if (i == 4) {
	      result = *permutation ^ *(permutation + 1);
	    } // if
	    if (j == 0) {
	      result <<= *(permutation + 2);
	    } // if
	    if (j == 1) {
	      result >>= *(permutation + 2);
	    } // if
	    if (j == 2) {
	      result &= *(permutation + 2);
	    } // if
	    if (j == 3) {
	      result |= *(permutation + 2);
	    } // if
	    if (j == 4) {
	      result ^= *(permutation + 2);
	    } // if
	    if (k == 0) {
	      result <<= *(permutation + 3);
	    } // if
	    if (k == 1) {
	      result >>= *(permutation + 3);
	    } // if
	    if (k == 2) {
	      result &= *(permutation + 3);
	    } // if
	    if (k == 3) {
	      result |= *(permutation + 3);
	    } // if
	    if (k == 4) {
	      result ^= *(permutation + 3);
	    } // if
	    if (l == 0) {
	      result <<= *(permutation + 4);
	    } // if
	    if (l == 1) {
	      result >>= *(permutation + 4);
	    } // if
	    if (l == 2) {
	      result &= *(permutation + 4);
	    } // if
	    if (l == 3) {
	      result |= *(permutation + 4);
	    } // if
	    if (l == 4) {
	      result ^= *(permutation + 4);
	    } // if
	    if (result == e) {
	      count++;
	      cout << "(((" << *permutation << operators[i]
		   << *(permutation + 1) << ")" << operators[j]
		   << *(permutation + 2) << ")" << operators[k]
		   << *(permutation + 3) << ")" << operators[l]
		   << *(permutation + 4) << endl;
	    } // if  
	  } // for l
	} // for k
      } // for j
    } // for i
  } // else if
  
} // operate

// creates permutations of the 5 integers and then calls the operate
// function on each permutation
void search(string mode, int int1, int int2, int int3, int int4,
	    int int5, int e) {

  int v[5] = {int1, int2, int3, int4, int5};
  int permutation[5];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
	for (int l = 0; l < 5; l++) {
	  for (int m = 0; m < 5; m++) {
	    if (i != j && i != k && i != l && i != m && j != k && j != l &&
		j != m && k != l && k != m && l != m) {
	      permutation[0] = v[i];
	      permutation[1] = v[j];
	      permutation[2] = v[k];
	      permutation[3] = v[l];
	      permutation[4] = v[m];
	      operate(mode, permutation, e); // call operate on the permutation
	    } // if
	  } // for m
	} // for l
      } // for k
    } // for j
  } // for j

  // print count, the number of expressions that evaluate to the number
  string longMode;
  if (mode == "-a") {
    longMode = " arithmetic ";
  } // if
  else if (mode == "-b") {
    longMode = " bitwise ";
  } // else if
  cout << count << longMode << "expressions found that evaluate to "
       << e << endl;
  
} // search
