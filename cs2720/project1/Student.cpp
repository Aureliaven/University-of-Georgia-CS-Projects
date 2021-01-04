#include<string>

using namespace std;

class Student {
private:
  int studentID;
  string studentName;
public:
  Student() {}
  Student(int id, string name) {
    studentID = id;
    studentName = name;
  }
  int getStudentID() {
    return studentID;
  }
  void setStudentID(int id) {
    studentID = id;
  }
  string getStudentName() {
    return studentName;
  }
  void setStudentName(string name) {
    studentName = name;
  }
  bool operator==(Student s) {
    if (studentID == s.studentID) {
      return true;
    }
    return false;
  }
};
