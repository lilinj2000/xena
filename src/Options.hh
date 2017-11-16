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

  bool only_t1;

  std::string data_file;
};

};  // namespace xena

#endif
