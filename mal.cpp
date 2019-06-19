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
mal_type::mal_type() {

  this->data = sIn; 
}


// base destructor
mal_type::~mal_type() {

}


mal_list::mal_list(string sIn) {

  this->data.push_back(sIn);
}

// get data function
list<mal_type>
mal_list::get_data() {

  return data;
}
