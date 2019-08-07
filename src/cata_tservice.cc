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

#include "src/cata_tservice.h"
#include "soil/log.h"

namespace xena {

CataTService::CataTService(const rapidjson::Document &doc,
                           TServiceCallback *callback)
    : callback_(callback) {
  SOIL_FUNC_TRACE;

  service_.reset(cata::TraderService::create(doc, this));
}

CataTService::~CataTService() { SOIL_FUNC_TRACE; }

void CataTService::onRtnOrder(const std::string &theOrder) {
  SOIL_FUNC_TRACE;

  SOIL_DEBUG_PRINT(theOrder);

  rapidjson::Document doc;
  doc.Parse(theOrder);

  std::string key = "/CThostFtdcOrderField/OrderRef";

  std::string order_local_id;
  soil::json::get_item_value(&order_local_id, doc, key);

  int32_t order_ref = std::stoi(order_local_id);

  if (callback_) {
    callback_->t1Update(order_ref);
  }
}

// void CataTService::onErrRtnOrderInsert(const std::string &rtn,
//                                        const std::string &err_info) {
//   SOIL_FUNC_TRACE;

//   SOIL_DEBUG_PRINT(rtn);
//   SOIL_DEBUG_PRINT(err_info);

//   rapidjson::Document doc;
//   doc.Parse(rtn);

//   std::string key = "/CUstpFtdcInputOrderField/UserOrderLocalID";

//   std::string order_local_id;
//   soil::json::get_item_value(&order_local_id, doc, key);

//   int32_t order_ref = std::stoi(order_local_id);

//   if (callback_) {
//     callback_->t2Update(order_ref);
//   }
// }

int32_t CataTService::orderInsert(const std::string &instru, double price,
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
