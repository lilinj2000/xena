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

#include <string>

#include "soil/log.h"
#include "src/yet_tservice.h"

namespace xena {

YetTService::YetTService(const rapidjson::Document &doc,
                         TServiceCallback *callback)
    : callback_(callback) {
  SOIL_FUNC_TRACE;

  service_.reset(yet::TraderService::create(doc, this));
}

YetTService::~YetTService() { SOIL_FUNC_TRACE; }

void YetTService::notifyOrder(const std::string &theOrder,
                              const std::string &theInstrument,
                              const std::string &theAccount) {
  SOIL_FUNC_TRACE;

  SOIL_DEBUG_PRINT(theOrder);
  SOIL_DEBUG_PRINT(theInstrument);
  SOIL_DEBUG_PRINT(theAccount);

  rapidjson::Document doc;
  doc.Parse(theOrder);

  std::string key = "/YDOrder/YDInputOrder/OrderRef";

  int32_t order_local_id;
  soil::json::get_item_value(&order_local_id, doc, key);

  if (callback_) {
    callback_->t1Update(order_local_id);
  }
}

int32_t YetTService::orderInsert(const std::string &instru, double price,
                                 int volume, bool fok) {
  SOIL_FUNC_TRACE;

  int32_t order_ref = service_->openBuyOrderFAK(instru, price, volume);

  return order_ref;
}

}; // namespace xena
