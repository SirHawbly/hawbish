/*
 * Copyright (c) 2019 Christopher Bartlett
 * [This program is licensed under the "MIT License"]
 * Please see the file LICENSE in the source
 * distribution of this software for license terms.
 */

#include <iostream> // used
#import <string> // used
#include <cstdlib> // not used
#include <array> // not used
#include <functional> // not used
#include <vector> // not used
// #include <editline> // not used
#include <algorithm>

#include "repl.h"
#include "mal.h"

using namespace std;


// function to get the amount of characters in a given string.
int
isIn(char cIn, string dIn) {

  // sum variable.
  int ret = 0;

  // loop through all chars in the string,
  // return out if you find it or not.
  for (int j = 0; j < dIn.size(); j++) {    
    if (cIn == dIn[j]) {
      ret += 1;
    }
  }

  // return the sum total of the matching chars.
  return ret;
}


void
print_header(string s) {

  // make a lambda that stores the logic for printing out
  // hyphens for a given length.
  auto print_bar = [](int len) {
  
    cout << endl;

    for (int i = 0; i < len; i++) 
      cout << "-";
  };

  // call the function with size, print the string, then 
  // print another bar.
  print_bar(s.size());

  cout << endl << s;

  print_bar(s.size());

  // cout an ending line.
  cout << endl;
}


int 
main(int argc, char **argv) {

  vector<string> input; // vector to store the entire input
  int parens = 0; // the sum value of the open/close parens
  int openc  = 0; // num of open parens 
  int closec = 0; // num of close parens 
  string lineIn = "start value"; // stores current line,
  string check  = lineIn; // string to check if exit needed

  // make an sExpression variable.
  // sExpression sExpr = sExpression();

  // print out we are starting main.
  print_header("STARTING MAIN");

  // cout the start message
  cout << "Lispy Version 0.0.0.0.1" << endl;
  cout << "Enter 'Quit' to Exit\n" << endl;

  // infinite loop
  for(;;) {

    // copy the string
    check = lineIn;

    // lower the string, so we can check if its "quit"
    // if so, we can return out.
    for (char& c : check) 
      c = tolower(c);
    
    // check if "check" = "quit", if so, return out
    if (check == "quit") 
      return 0;

    // call the split expression
    // sExpr.setS("(+ 611 7 (/ 9 3))");
    // sExpr.setS("(list a:(* (- 6 1) 2) b:(eq `asdf 7) c:())");
    // sExpr.splitExpression();

    // print prompt, wait for input, print the input back
    cout << "<lispy> ";
    cin >> lineIn;

    // push the line into the input array.
    input.push_back(lineIn);
    
    // cout << "```" << lineIn << "``` ";

    // set the opens and closes according to the two paren
    // characters
    openc = isIn('(', lineIn);
    closec =  isIn(')', lineIn);

    // update the parens value.
    parens = openc - closec;
    // cout << openc << "->" << closec << endl;
    
    // cout << parens << " ";

    // if we have encountered parens than we need to test 
    // them.
    if (parens > 0) {

      // while we have a positive paren count, there arent 
      // more or equal close parens to open,
      while (openc > closec) {
        
        // grab the line and add a space after.
        cin >> lineIn;      
        lineIn += " ";
        input.push_back(lineIn);

        // increment the opens and closes.
        openc += isIn('(', lineIn);
        closec +=  isIn(')', lineIn);
        // cout << openc << ":" << closec << ":" << openc-closec << endl;
      }

      // if open and close arent even, we need to clear 
      // input and current line, and print an error message
      /*
      if (openc != closec) {
       
        cout << endl << "ERROR 1:\nENTERED UNEVEN PARENS: "; 
        cout << openc << " open, to " << closec << " closed." << endl;

        lineIn = "";
        input.clear();
      }
      */

    // if we have reached the end of the input, and there 
    // are more close parens than open ones, we need to 
    // throw an error.
    } else if (parens < 0) {
    
      cout << endl << "ERROR 1:\nENTERED UNEVEN PARENS: "; 
      cout << openc << " open, to " << closec << " closed." << endl;
      cout << endl;

      lineIn = "";
      input.clear();

      continue;
    }  
    
    // Print out the entered array of strigs that we got, 
    // they should have matching parens if we have passed 
    // through the logic above.
    cout << endl << "Entered:" << endl;

    // create an indent value.
    int indent = 0;

    // for all strings in the input, print them out with 
    // corresponding tabs based on the level that it 
    // belongs.
    for (string& s : input) {

      /// cout << "```" << (s == input[0]) << "```";
      
      // if we are on any other line than the first, we need
      // to add some tabs to space the output.
      if (s != input[0]) {
        
        cout << endl;

        for (int i = 0; i < indent; i++) 
          cout << "    ";
      }

      // increment the indent value.
      indent += isIn('(', s) - isIn(')', s);

      // print out the string, stopping if the string 
      // contains a newline.
      // cout << "`";
      for (int i = 0; i < s.size(); i++) {
      
        cout << s[i];
      }
      // cout << "`";
      // end printout
    }

    // throw two end lines
    cout << endl << endl;

    cout << "printing out the inputted list of strings:" << endl;
    for (int i = 0; i < input.size(); i++) {
      cout << input[i] << ", ";
    }

    cout << endl;

    // clear the input lines, and clear the current line
    lineIn = "";
    input.clear();
  }

  // print that we are returing out of the system.
  print_header("EXITING MAIN");
  return 0;
}
