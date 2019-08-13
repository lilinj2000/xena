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

#include "src/esau_tservice.h"
#include "soil/log.h"

namespace xena {

EsauTService::EsauTService(const rapidjson::Document &doc,
                           TServiceCallback *callback)
    : callback_(callback) {
  SOIL_FUNC_TRACE;

  service_.reset(esau::TraderService::create(doc, this));
}

EsauTService::~EsauTService() { SOIL_FUNC_TRACE; }

void EsauTService::onRtnOrder(const std::string &theUserNo,
                              const std::string &thenRequestID,
                              const std::string &theRtnInfo) {
  SOIL_FUNC_TRACE;

  SOIL_DEBUG_PRINT(theUserNo);
  SOIL_DEBUG_PRINT(thenRequestID);
  SOIL_DEBUG_PRINT(theRtnInfo);

  // rapidjson::Document doc;
  // doc.Parse(rsp);

  // std::string key = "/CUstpFtdcInputOrderField/UserOrderLocalID";

  // std::string order_local_id;
  // soil::json::get_item_value(&order_local_id, doc, key);

  int32_t order_ref = std::stoi(thenRequestID);

  if (callback_) {
    callback_->t1Update(order_ref);
  }
}

int32_t EsauTService::orderInsert(const std::string &instru, double price,
                                  int volume, bool fok) {
  SOIL_FUNC_TRACE;

  int32_t order_ref = -1;
  if (fok) {
    order_ref = service_->openBuyOrderFOK(instru, price, volume);
  } else {
    order_ref = service_->openBuyOrderFAK(instru, price, volume);
  }

  return order_ref;
}

}; // namespace xena
