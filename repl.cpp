/*
 * Copyright (c) 2019 Christopher Bartlett
 * [This program is licensed under the "MIT License"]
 * Please see the file LICENSE in the source
 * distribution of this software for license terms.
 */

#include <iostream>
#include "string.h"
#include <vector>

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


// helper function for testing chars in strings.
int
isIn(char cIn, string dIn) {

  bool ret = false;

  // loop through all chars in the string,
  // return out if you find it or not.
  for (int j = 0; j < dIn.size(); j++) {    
    if (cIn == dIn[j]) {
      ret = true;
    }
  }

  return ret;
}

// base constructor
int
sExpression::splitExpression() {
  
  int len = this->s.size();
  char *data = this->s.data();

  cout << data << " -- " << len << endl;

  splitExpression(data, len, 0, len);

  return 0;
}


// unused display function for 2d vectors.
void display (const vector<vector<string> >& vy)
{  for (int i = 0; i < vy.size(); i++)       // loops through each row of vy
   {  for (int j = 0; j < vy[i].size(); j++) // loops through each element of each row 
          cout << ":" << vy[i][j] << ": ";   // prints the jth element of the ith row
      cout << endl;
   }
} 


vector <vector <string>> 
sExpression::splitExpression(char* sIn, int len, int start, int end) {

  char curChar;
  vector<vector<string>> argsVector;
  vector<string> args;
  string curString = "";
  int unmatched = 0; 
  int argc = 0;


  // if the current string is "()" return nil instead.
  if ((end - start) == 1) {
    curString = "nil";
    args.push_back(curString);
    argsVector.push_back(args);
    return argsVector; 
  }

  // if end is past len, start is greater than end, or they
  // are equal, return out with a bad bounds message.
  if (end > len || start > end || start == end) {
    cout << "bad bounds: " << endl;
    cout << "```" << start << "->" << end << "```\n";
    return argsVector;
  }

  // if the provided string isnt bound by parens 
  if (! (sIn[start] == '(') && (sIn[end] == ')') ) {
    cout << endl << "bad format: " << start << "->" << end;
    cout << "```" << sIn[start] << "->" << sIn[end-1] << "```\n";
    return argsVector;
  }

  /*
  for (int i = start; i < end; i++) {
    if (sIn[i] == '(') unmatched += 1;
    else if (sIn[i] == ')') unmatched -= 1;
    cout << unmatched;
  }
  */

  // print starting message
  cout << endl << "scanning string: ```";
  for (int i = start; i <= end; i++)
      cout << sIn[i];
  cout << "```" << endl;

  // print starting paren.
  cout << "s(" << endl;

  cout << endl << "arg" << argc++ << ": ```";

  // loop through the string, we need to recurse on hitting
  // a paren, so find the matching pair of parens if that 
  // happens.
  for (int i = start+1; i < end; i++) {
    
    curChar = sIn[i];

    if (curChar == ' ') {

      cout << "```" << endl << "arg" << argc++ << ": ```";
      //curString += curChar;
      args.push_back(curString);
      curString = "";
      //cout << endl << i << ":" << curChar << endl;

    } else if (curChar == '(') {

      // cout << "UNMATCHED PARENS";
      // cout << "[," << endl;
      cout << "--- parens ---";

      // scan into the input string, gotta grab the other
      // paren that matches not '(()', but '(())'
      for (int j = i; j < end-1; j++) {
        
        // cout the characters and the depth we are looking at
        cout << endl << "\t" << j << ", depth=" << unmatched 
              << ", '" << sIn[j] << "' ";

        // if we hit an open paren, we need to go deeper.
        if (sIn[j] == '(') {

          unmatched += 1;
          cout << "-> open -> " << unmatched;
        
        // if we hit a close paren, we can check to see if
        // we have found the correct paren, if not we can
        // keep going.
        } else if(sIn[j] == ')') {

          // decrement the matched value, and check its val.
          unmatched -= 1;
          cout << " -> close -> " << unmatched;

          // if we are at 0, we are done...
          if (unmatched == 0) {
            
            cout << endl << "--- matched parens ---";

            // print out the bounds and the substring.
            cout << endl << "ending range: "<< i << " to " << j << "," << endl << " -> ";
            
            cout << "final substring: " << "```";
            for (int k = i; k <= j; k++) 
              cout << sIn[k];
            cout << "```";

            // recurse deeper with the bounds.
            vector<vector<string>> temp = splitExpression(sIn, len, i, j);
            for (auto a : temp)
              argsVector.push_back(a);

            i = j + 1;
            // cout << endl << "]" << endl;
          }
        }
      }

      // if we have an uneven paren situation ```( ( )``` 
      // assert false.
      if (unmatched != 0) {

        cout << endl << "UNMATCHED PARENS: " << i << endl;
        assert(false);
        return argsVector;
      }

    // if we have hit a close paren, we have something that
    // is unbalanced ```( ) )``` we skip the first and last.
    } else if (curChar == ')' && i < len) {
      
      cout << endl << "UNMATCHED PARENS: " << i << ":" << end << endl;
      assert(false);

    // else we print out the character.
    } else {

      if (i != end-1) {

        cout << curChar;
        curString += curChar;
      
      } else {

        cout << curChar << "```" << endl;
        curString += curChar;
        args.push_back(curString);
        //argsVector.push_back(args);
      }
    }
  }

  // print out the ending paren.  
  cout << endl << ")e" << endl;
  
  // argsVector.insert(argsVector.front(), args);
  argsVector.push_back(args);
  cout << argsVector.size() << " lists of args in: " << endl;

  cout << "```";
  for (int i = 0; i < len; i++)
    cout << sIn[i];

  cout << "```" << endl;

  for (auto i  : argsVector) {

    for (auto j : i)
      cout << "[" << j << "]" << ", ";
    
    cout << endl;
  }

  return argsVector;
}


int
splitExpression(string sIn) {

  auto tree = new list <string>;
  cout << sIn << endl;
  tree->push_back(sIn);
  cout << sIn.size();

  return 0;
}