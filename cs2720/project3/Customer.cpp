#include "Customer.h"

Customer::Customer() {
  name = "";
  arrival = 0;
  service = 0;
  wait = 0;
}
Customer::Customer(string n, int a, int s, int w) {
  name = n;
  arrival = a;
  service = s;
  wait = w;
}
string Customer::getName() {
  return name;
}
void Customer::setName(string n) {
  name = n;
}
int Customer::getArrival() {
  return arrival;
}
void Customer::setArrival(int a) {
  arrival = a;
}
int Customer::getService() {
  return service;
}
void Customer::setService(int s) {
  service = s;
}
int Customer::getWait() {
  return wait;
}
void Customer::setWait(int w) {
  wait = w;
}

ostream & operator<<(ostream& out, Customer& c) {
  out << c.getName() << " " << c.getWait() << " wait service "
      << c.getArrival() + c.getService();
  return out;
}
