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
#include "src/ufo_tservice.h"

namespace xena {

UfoTService::UfoTService(const rapidjson::Document &doc,
                         TServiceCallback *callback)
    : callback_(callback) {
  SOIL_FUNC_TRACE;

  service_.reset(ufo::TraderService::create(doc, this));
}

UfoTService::~UfoTService() { SOIL_FUNC_TRACE; }

void UfoTService::onAnsOrderInsert(const std::string &rsp,
                                   const std::string &err_info) {
  SOIL_FUNC_TRACE;

  SOIL_DEBUG_PRINT(rsp);
  SOIL_DEBUG_PRINT(err_info);

  rapidjson::Document doc;
  doc.Parse(rsp);

  std::string key = "/tagUftAnsOrderInsertField/OrderRef";

  int32_t order_local_id;
  soil::json::get_item_value(&order_local_id, doc, key);

  if (callback_) {
    callback_->t1Update(order_local_id);
  }
}

int32_t UfoTService::orderInsert(const std::string &instru, double price,
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
