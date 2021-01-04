#include <iostream>

using namespace std;

/**
 * Represents a Student with first and last name and student id
 * Has setters and getters for those variables
 */
class Student {
  char firstName[20];
  char lastName[20];
  unsigned int studentId;
public:
  Student(char * f, char * l, unsigned int id) {
    for (unsigned int i = 0; i < sizeof(f); i++) {
      firstName[i] = *(f+i);
    }
    for (unsigned int i = 0; i < sizeof(l); i++) {
    lastName[i] = *(l+i);
    }
    studentId = id;
  } // constructor
  char * getFirstName() {
    return firstName;
  }
  char * getLastName() {
    return lastName;
  }
  int getStudentId() {
    return studentId;
  }
  void setFirstName(char * f) {
    for (unsigned int i = 0; i < sizeof(f); i++) {
      firstName[i] = *(f+i);
    }
  }
  void setLastName(char * l) {
    for (unsigned int i = 0; i < sizeof(l); i++) {
    lastName[i] = *(l+i);
    }
  }
  void setStudentId(int id) {
    studentId = id;
  }
}; // Student

/**
 * Overloads the << operator for printing Student
 */
ostream& operator<<(ostream& os, Student s) {
  os << s.getFirstName() << " " << s.getLastName() << " " << s.getStudentId();
  return os;
}

int main() {
  char Alice[] = "Alice";
  char Smith[] = "Smith";
  char Bob[] = "Bob";
  char Jane[] = "Jane";
  char John[] = "John";
  char Doe[] = "Doe";
  Student alice(Alice, Smith, 10020);
  Student bob(Bob, Smith, 20304);
  Student jane(Jane, Doe, 30405);
  Student john(John, Doe, 30030);
  cout << alice << endl;
  cout << bob << endl;
  cout << jane << endl;
  cout << john << endl;
} // main
