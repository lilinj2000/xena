// Copyright (c) 2010
// All rights reserved.

#include "FoalTService.hh"
#include "soil/Log.hh"

namespace xena {

FoalTService::FoalTService(
    const rapidjson::Document& doc,
    TServiceCallback* callback) :
    callback_(callback) {
  SOIL_FUNC_TRACE;

  service_.reset(
      foal::TraderService::create(
          doc,
          this));
}

FoalTService::~FoalTService() {
  SOIL_FUNC_TRACE;
}

void FoalTService::onRspOrderInsert(
    const std::string& rsp,
    const std::string& err_info,
    int req_id,
    bool is_last) {
  SOIL_FUNC_TRACE;

  rapidjson::Document doc;
  doc.Parse(rsp);

  std::string key
      = "/CUstpFtdcInputOrderField/UserOrderLocalID";

  std::string order_local_id;
  soil::json::get_item_value(
      &order_local_id,
      doc,
      key);

  int32_t order_ref = std::stoi(order_local_id);

  if (callback_) {
    callback_->t1Update(order_ref);
  }
}

void FoalTService::onErrRtnOrderInsert(
    const std::string& rtn,
    const std::string& err_info) {
  SOIL_FUNC_TRACE;

  rapidjson::Document doc;
  doc.Parse(rtn);

  std::string key
      = "/CUstpFtdcInputOrderField/UserOrderLocalID";

  std::string order_local_id;
  soil::json::get_item_value(
      &order_local_id,
      doc,
      key);

  int32_t order_ref = std::stoi(order_local_id);

  if (callback_) {
    callback_->t2Update(order_ref);
  }
}

int32_t FoalTService::orderInsert(
    const std::string& instru,
    double price,
    int volume) {
  SOIL_FUNC_TRACE;

  int32_t order_ref = service_->openBuyOrderFOK(
      instru,
      price,
      volume);

  return order_ref;
}

};  // namespace xena
