// Copyright (c) 2010
// All rights reserved.

#include "XtraTService.hh"
#include "soil/Log.hh"

namespace xena {

XtraTService::XtraTService(
    const rapidjson::Document& doc,
    TServiceCallback* callback) :
    callback_(callback) {
  SOIL_FUNC_TRACE;

  service_.reset(
      xtra::TraderService::create(
          doc,
          this));
}

XtraTService::~XtraTService() {
  SOIL_FUNC_TRACE;
}

void XtraTService::onRspOrderInsert(
    const std::string& rsp,
    const std::string& err_info,
    int req_id,
    bool is_last) {
  SOIL_FUNC_TRACE;

  rapidjson::Document doc;
  doc.Parse(rsp);

  std::string key
      = "/CXeleFtdcInputOrderField/OrderLocalID";

  std::string order_local_id;
  soil::json::get_item_value(
      &order_local_id,
      doc,
      key);

  int32_t local_id = std::stoi(order_local_id);

  if (callback_) {
    callback_->t2Update(local_id);
  }
}

void XtraTService::onErrRtnOrderInsert(
    const std::string& rtn,
    const std::string& err_info) {
  SOIL_FUNC_TRACE;

  rapidjson::Document doc;
  doc.Parse(rtn);

  std::string key
      = "/CXeleFtdcInputOrderField/OrderLocalID";

  std::string order_local_id;
  soil::json::get_item_value(
      &order_local_id,
      doc,
      key);

  int32_t local_id = std::stoi(order_local_id);

  if (callback_) {
    callback_->t2Update(local_id);
  }
}

int32_t XtraTService::orderInsert(
    const std::string& instru,
    double price,
    int volume) {
  SOIL_FUNC_TRACE;

  int32_t local_id = service_->openBuyOrderFOK(
      instru,
      price,
      volume);

  return local_id;
}

};  // namespace xena
