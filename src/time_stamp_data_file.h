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


#ifndef SRC_TIMESTAMP_DATA_FILE_H_
#define SRC_TIMESTAMP_DATA_FILE_H_

#include <string>
#include <set>
#include <bitset>

#include "soil/data_file.h"
#include "soil/date_time.h"

namespace xena {

class TimeStampDataFile;

class TimeStampData :
      public soil::Data {
 public:
  explicit TimeStampData(int order_ref);

  int orderRef() const {
    return order_ref_;
  }

  const soil::DateTime T0() const {
    return t0_;
  }

  const soil::DateTime T1() const {
    return t1_;
  }

  const soil::DateTime T2() const {
    return t2_;
  }

  void updateT1();
  void updateT2();

  bool allUpdated() {
    return t_mask_.all();
  }

  virtual void writeToFile(std::ofstream* os) const;

 private:
  int order_ref_;
  // request order insert timestamp
  soil::DateTime t0_;
  // on rtn order, just from counter response
  soil::DateTime t1_;
  // on rtn order, from exchange response
  soil::DateTime t2_;

  std::bitset<2> t_mask_;
};

class TimeStampDataFile : public soil::DataFile {
 public:
  explicit TimeStampDataFile(const std::string& file_name);

  virtual ~TimeStampDataFile();
};

};  // namespace xena

#endif
