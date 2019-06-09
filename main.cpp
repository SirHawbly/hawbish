#include <iostream> // used
#import <string> // used
#include <cstdlib> // not used
#include <array> // not used
#include <functional> // not used
#include <list> // not used
// #include <editline> // not used
#include <algorithm>

#include "repl.h"

using namespace std;

void
print_header(string s) {

  auto print_bar = [](int len) {
  
    cout << endl;

    for (int i = 0; i < len; i++) 
      cout << "-";
  };

  print_bar(s.size());

  cout << endl << s;

  print_bar(s.size());

  cout << endl;
}

int 
main(int argc, char **argv) {

  print_header("STARTING MAIN");

  cout << "Lispy Version 0.0.0.0.1" << endl;
  cout << "Enter 'Quit' to Exit\n" << endl;

  string lineIn = "start value";
  string check = lineIn;

  sExpression sExpr = sExpression();

  for(;;) {

    // copy the string
    check = lineIn;

    // lower the string, so we can check if its "quit"
    for (char& c : check) 
      c = tolower(c);

    // check for "quit", if so, free up the sExpr and ret 0
    if (check == "quit") 
      return 0;

    // call the split expression
    sExpr.setS("(+ (* (- 6 1) 2) (* 8 7))");
    sExpr.splitExpression();

    // I dont care to do a while true yet.
    return 0;

    // print prompt, wait for input, print the input back
    cout << "<lispy> ";
    cin >> lineIn;
    cout << endl << lineIn << endl;
  }

  print_header("EXITING MAIN");

  return 0;
}
