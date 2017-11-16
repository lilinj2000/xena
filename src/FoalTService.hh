// Copyright (c) 2010
// All rights reserved.

#ifndef XENA_FOAL_TSERVICE_HH
#define XENA_FOAL_TSERVICE_HH

#include "TService.hh"
#include "foal/TraderService.hh"

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

#endif  // XENA_FOAL_TSERVICE_HH
