
#ifndef MAL

#define MAL

#include <string>
#include <vector>

using namespace std;

int isInMal(char cIn, string dIn);

class mal_type {

  private:
    string data;
  
  public:

    mal_type(string sIn);
    ~mal_type();
  
    string toString() { 
      return data; 
    }
};


class mal_list {

  private:
    
    // 
    vector<mal_type*> data_list;
    int size;

  public:
    
    // constructor
    mal_list();
    mal_list(string sIn);
    mal_list(vector<string> vIn);
    
    // destructor
    ~mal_list();

    vector<mal_type*> get_data();

    void output();

};

#endif