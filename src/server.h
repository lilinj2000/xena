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


#ifndef SRC_SERVER_H_
#define SRC_SERVER_H_

#include <map>
#include <string>
#include "src/options.h"
#include "soil/s_timer.h"
#include "src/time_stamp_data_file.h"
#include "src/tservice.h"

namespace xena {

typedef std::map<
  int32_t,
  std::shared_ptr<TimeStampData> > TimeStampRecords;

class Server :
      public TServiceCallback {
 public:
  explicit Server(
      const rapidjson::Document& doc);

  virtual ~Server();

  virtual void t1Update(int32_t local_id);

  virtual void t2Update(int32_t local_id);

 protected:
  void run();

  void updateT(
      int32_t order_ref,
      bool is_t1 = true);

  void wait(int ms = -1) {
    cond_->wait(ms);
  }

  void notify(bool is_last) {
    if (is_last) {
      cond_->notifyAll();
    }
  }

 private:
  std::unique_ptr<Options> options_;
  std::unique_ptr<TService> tservice_;

  TimeStampRecords records_;
  std::unique_ptr<TimeStampDataFile> data_file_;

  std::unique_ptr<soil::STimer> cond_;
};

}  // namespace xena

#endif
