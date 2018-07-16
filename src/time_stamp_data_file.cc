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


#include "fmt/format.h"
#include "src/time_stamp_data_file.h"
#include "soil/log.h"

namespace xena {

TimeStampData::TimeStampData(int order_ref):
    order_ref_(order_ref) {
  SOIL_TRACE("TimeStampData::TimeStampData()");
}

void TimeStampData::updateT1() {
  SOIL_TRACE("TimeStampData::updateT1()");

  t1_ = soil::DateTime::now();
  t_mask_.set(0);
}

void TimeStampData::updateT2() {
  SOIL_TRACE("TimeStampData::updateT2()");

  t2_ = soil::DateTime::now();
  t_mask_.set(1);
}

void TimeStampData::writeToFile(std::ofstream* os) const {
  SOIL_TRACE("TimeStampData::writeToFile()");

  std::chrono::system_clock::duration d1 = t1_ - t0_;
  std::chrono::system_clock::duration d2 = t2_ - t0_;

  (*os) <<fmt::format("{}\t{}\t{}\t{}\t{}\t{}",
                      order_ref_,
                      t0_,
                      t1_,
                      t2_,
                      d1.count(),
                      d2.count())
        <<std::endl;
}

TimeStampDataFile::TimeStampDataFile(const std::string& file_name):
    soil::DataFile(file_name) {
  SOIL_TRACE("TimeStampDataFile::TimeStampDataFile()");
}

TimeStampDataFile::~TimeStampDataFile() {
  SOIL_TRACE("TimeStampDataFile::~TimeStampDataFile()");
}

};  // namespace xena
