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

#include "src/sea_tservice.h"
#include "soil/log.h"

namespace xena {

SeaTService::SeaTService(const rapidjson::Document &doc,
                         TServiceCallback *callback)
    : callback_(callback) {
  SOIL_FUNC_TRACE;

  service_.reset(sea::TraderService::create(doc, this));
}

SeaTService::~SeaTService() { SOIL_FUNC_TRACE; }

void SeaTService::onOrderAccept(const std::string &theAccept) {
  SOIL_FUNC_TRACE;

  rapidjson::Document doc;
  if (doc.Parse(theAccept).HasParseError()) {
    throw std::runtime_error(soil::json::get_parse_error(doc, theAccept));
  }

  int clientOrderToken = -1;
  soil::json::get_item_value(&clientOrderToken, doc,
                             "/EES_OrderAcceptField/m_ClientOrderToken");
  SOIL_DEBUG_PRINT(clientOrderToken);

  int marketOrderToken = -1;
  soil::json::get_item_value(&marketOrderToken, doc,
                             "/EES_OrderAcceptField/m_MarketOrderToken");
  SOIL_DEBUG_PRINT(marketOrderToken);

  tokens_[marketOrderToken] = clientOrderToken;

  if (callback_) {
    callback_->t1Update(clientOrderToken);
  }
}

void SeaTService::onOrderReject(const std::string &theReject) {
  SOIL_FUNC_TRACE;

  rapidjson::Document doc;
  if (doc.Parse(theReject).HasParseError()) {
    throw std::runtime_error(soil::json::get_parse_error(doc, theReject));
  }

  int clientOrderToken = -1;
  soil::json::get_item_value(&clientOrderToken, doc,
                             "/EES_OrderRejectField/m_ClientOrderToken");

  if (callback_) {
    callback_->t1Update(clientOrderToken);
  }
}

void SeaTService::onOrderMarketReject(const std::string &theReject) {
  SOIL_FUNC_TRACE;

  rapidjson::Document doc;
  if (doc.Parse(theReject).HasParseError()) {
    throw std::runtime_error(soil::json::get_parse_error(doc, theReject));
  }

  int marketOrderToken = -1;
  soil::json::get_item_value(&marketOrderToken, doc,
                             "/EES_OrderMarketRejectField/m_MarketOrderToken");
  SOIL_DEBUG_PRINT(marketOrderToken);

  auto it_token = tokens_.find(marketOrderToken);

  if (it_token != tokens_.end()) {
    int client_order_token = it_token->second;
    tokens_.erase(it_token);

    if (callback_) {
      callback_->t2Update(client_order_token);
    }
  } else {
    SOIL_ERROR("unexpected token: {}", marketOrderToken);
  }
}

int32_t SeaTService::orderInsert(const std::string &instru, double price,
                                 int volume) {
  SOIL_FUNC_TRACE;

  int32_t local_id = service_->openBuyOrderFOK(instru, price, volume);

  return local_id;
}

};  // namespace xena
