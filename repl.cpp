#include <iostream>
#include <string>

#include "repl.h"

int
read() {
  
  string sIn;
  
  cin >> sIn;

  return 0;
}


int
eval() {

  return 0;
}


int
print() {
  
  return 0;
}


int 
repl() {
  
  return 0;
}

sExpression::sExpression(string sIn) {
  
  this->s = sIn;
}


sExpression::~sExpression() {

}


string 
sExpression::getS() {
  return this->s;
}


void
sExpression::setS(string sIn) {
  this->s = sIn;
}


void 
sExpression::printS() {
  cout << this->s << endl;
}


list <string> 
sExpression::getQueue() {

  return this->queue;
}

