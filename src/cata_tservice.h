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

#ifndef SRC_CATA_TSERVICE_H_
#define SRC_CATA_TSERVICE_H_

#include <string>

#include "cata/trader_service.h"
#include "src/tservice.h"

namespace xena {

class CataTService : public cata::TraderCallback, public TService {
public:
  CataTService(const rapidjson::Document &doc, TServiceCallback *callback);

  virtual ~CataTService();

  virtual void onRtnOrder(const std::string &theOrder);

  virtual int32_t orderInsert(const std::string &instru, double price,
                              int volume, bool fok);

private:
  std::unique_ptr<cata::TraderService> service_;

  TServiceCallback *callback_;
};

}; // namespace xena

#endif // SRC_CATA_TSERVICE_H_
