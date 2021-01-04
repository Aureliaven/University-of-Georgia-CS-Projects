#include <string>

using namespace std;

class Customer {
 public:
  Customer();
  Customer(string n, int a, int s, int w);
  string getName();
  void setName(string n);
  int getArrival();
  void setArrival(int a);
  int getService();
  void setService(int s);
  int getWait();
  void setWait(int w);
  friend ostream & operator<<(ostream& out, const Customer& c);
 private:
  string name;
  int arrival;
  int service;
  int wait;
};
