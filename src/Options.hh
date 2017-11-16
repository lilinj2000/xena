// Copyright (c) 2010
// All rights reserved.

#ifndef XENA_OPTIONS_HH
#define XENA_OPTIONS_HH

#include <string>
#include "soil/json.hh"

namespace xena {

class Options {
 public:
  explicit Options(
      const rapidjson::Document& doc);

  std::string instru;
  double price;
  int volume;
  int interval;
  int count;

  // 1: only t1
  // 2: only t2
  // 3: both
  int ts_flag;

  enum {
    ONLY_T1 = 1,
    ONLY_T2 = 2,
    BOTH = 3
  };

  std::string data_file;
};

};  // namespace xena

#endif
