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


#ifndef SRC_TSERVICE_H_
#define SRC_TSERVICE_H_

#include <string>
#include "soil/json.h"

namespace xena {

class TServiceCallback {
 public:
  virtual void t1Update(int32_t local_id) = 0;

  virtual void t2Update(int32_t local_id) = 0;

  virtual ~TServiceCallback() {
  }
};

class TService {
 public:
  virtual int32_t orderInsert(
      const std::string& instru,
      double price,
      int volume) = 0;

  virtual ~TService() {
  }

  static TService* create(
      const rapidjson::Document& doc,
      TServiceCallback* callback);
};

}  // namespace xena

#endif  // SRC_TSERVICE_H_
