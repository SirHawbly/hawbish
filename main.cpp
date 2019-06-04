#include <iostream>
#import <string>

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

  cout << "things to come...\n";

  sExpression* test = 
    new sExpression("(+ (* (- 6 1) 2) (* 8 7))");
  test = 
    new sExpression("(+ (* (- 6 1) 2) (* 8 7))");

  // test->printS();
  // test->getS();

  print_header("EXITING MAIN");

  return 0;
}
