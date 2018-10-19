// Copyright 2017 The Xena Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// -----------------------------------------------------------------------------
// File: [file_name]
// -----------------------------------------------------------------------------
//
// [file_descrition]
//
// Example:
//
//   ... ...
//
//

#ifndef SRC_OPTIONS_H_
#define SRC_OPTIONS_H_

#include <string>
#include "soil/json.h"

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

#endif  // SRC_OPTIONS_H_
