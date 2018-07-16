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


#ifndef SRC_FOAL_TSERVICE_H_
#define SRC_FOAL_TSERVICE_H_

#include "src/tservice.h"
#include "foal/trader_service.h"

namespace xena {

class FoalTService :
      public foal::TraderCallback,
      public TService {
 public:
  FoalTService(
      const rapidjson::Document& doc,
      TServiceCallback* callback);

  virtual ~FoalTService();

  virtual void onRspOrderInsert(
      const std::string& rsp,
      const std::string& err_info,
      int req_id,
      bool is_last);

  virtual void onErrRtnOrderInsert(
      const std::string& rtn,
      const std::string& err_info);

  virtual int32_t orderInsert(
      const std::string& instru,
      double price,
      int volume);

 private:
  std::unique_ptr<foal::TraderService> service_;

  TServiceCallback* callback_;
};

};  // namespace xena

#endif  // SRC_FOAL_TSERVICE_H_
