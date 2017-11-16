// Copyright (c) 2010
// All rights reserved.

#include "fmt/format.h"
#include "TimeStampDataFile.hh"
#include "soil/Log.hh"

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
