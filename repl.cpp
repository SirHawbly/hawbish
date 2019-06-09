#include <iostream>
#include <string>

#include "repl.h"

int
sExpression::read() {
  
  string sIn;
  cin >> sIn;

  this->s = sIn;

  return 0;
}


int
sExpression::eval() {

  return 0;
}


int
sExpression::print() {
  
  return 0;
}


int 
sExpression::repl() {
  
  return 0;
}


sExpression::sExpression() {
  
  this->s = "";

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


/*
list <sExpression> 
sExpression::getQueue() {

  return this->argqueue;
}
*/

int
isIn(char cIn, string dIn) {

  bool ret = false;

  for (int j = 0; j < dIn.size(); j++) {    
    if (cIn == dIn[j]) {
      ret = true;
    }
  }

  return ret;
}

int 
sExpression::splitExpression() {
  
  // string parens = "()";
  // string whites = " ";
  
  int len = this->s.size();
  char *data = this->s.data();

  string st = "(", en = ")";
  string sp = " ";

  // bool delim;
  // char cur;

  cout << data << " " << len << endl;

  splitExpression(data, len, 0);

  // for (int i = 0; i < this->s.size(); i++) {
    
    // cur = this->s[i];

    // delim = isIn(cur, parens) || isIn(cur, whites);

    // if (!delim) 
      // cout << this->s[i];
    // else
      // cout << ' ';

  // }

  return 0;
}

int 
sExpression::splitExpression(char* sIn, int len, int depth) {

  string st = "(", en = ")";
  string sp = " ";

  // bool delim;
  char cur;

  cout << this->s << endl;

  for (int i = 0; i < this->s.size(); i++) {
    
    cur = this->s[i];

  }

  return 0;
}


int
sExpression::NewSplitExpression() {

  list <char *> breaks;
  char *data = this->s.data();
  char *c, d;

  cout << this->s << " size " << this->s.size() << endl;

  for (int i = 0; i < this->s.size(); i++) {
    for (int j = 0; j < this->delims.size(); j++) {

      c = &data[i];
      d = this->delims[j];

      if (*c == d)
        breaks.push_back(c);
      
    }
  }

  cout << breaks.size();
  
  return 0;
}


int
splitExpression(string sIn) {

  auto tree = new list <string>;
  cout << sIn << endl;
  tree->push_back(sIn);
  cout << sIn.size();

  return 0;
}