
#ifndef REPL

#define REPL

#include <string>
#include <list>

using namespace std;


class mal_type {

  private:
    string data;
  
  public:
    string toString() { 
      return data; 
    }

    mal_type(string sIn);

    ~mal_type();
};

class mal_list {
  private:
    list<mal_type> data;
};

#endif