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


#ifndef SRC_SEA_TSERVICE_H_
#define SRC_SEA_TSERVICE_H_

#include <string>
#include <map>

#include "src/tservice.h"
#include "sea/TraderService.h"

namespace xena {

typedef std::map<int, int> TokenRecords;

class SeaTService :
      public sea::TraderCallback,
      public TService {
 public:
  SeaTService(
      const rapidjson::Document& doc,
      TServiceCallback* callback);

  virtual ~SeaTService();

  virtual void onOrderAccept(
      const std::string& theAccept);

  virtual void onOrderReject(
      const std::string& theReject);

  virtual void onOrderMarketReject(
      const std::string& theReject);

  virtual int32_t orderInsert(
      const std::string& instru,
      double price,
      int volume);

 private:
  std::unique_ptr<sea::TraderService> service_;
  TokenRecords tokens_;

  TServiceCallback* callback_;
};

};  // namespace xena

#endif  // SRC_SEA_TSERVICE_H_
