/*
 * Copyright (c) 2019 Christopher Bartlett
 * [This program is licensed under the "MIT License"]
 * Please see the file LICENSE in the source
 * distribution of this software for license terms.
 */


#include <iostream>
#include "string.h"
#include <vector>

#include "mal.h"


// ---------------------------------------------------------
// Helper Functions
// ---------------------------------------------------------


// helper function for testing chars in strings.
int
isInMal(char cIn, string dIn) {

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


// ---------------------------------------------------------
// Constructor
// ---------------------------------------------------------


// constructor with a string
mal_type::mal_type(string sIn) {

  this->data = sIn;
}


// ---------------------------------------------------------
// Destructor
// ---------------------------------------------------------


// base destructor
mal_type::~mal_type() {

}

// ---------------------------------------------------------
// Mal_List Class Functions
// ---------------------------------------------------------


// constructor with a string
mal_list::mal_list(string sIn) {

  mal_type* temp = new mal_type(sIn);
  this->data_list.push_back(temp);
}

// constructor with a string
mal_list::mal_list(vector<string> vIn) {
  
  mal_type* temp;

  for (auto sIn : vIn) {
    temp = new mal_type(sIn);
    this->data_list.push_back(temp);
  }
}

// get data function
vector<mal_type*>
mal_list::get_data() {

  return data_list;
}


// base constructor
mal_list::mal_list() {

  // this->data_list = ""; 
}


// base destructor
mal_list::~mal_list() {

  for (auto mIn : this->data_list)
    delete mIn;
}


