// Copyright (c) 2010
// All rights reserved.

#ifndef XENA_XTRA_TSERVICE_HH
#define XENA_XTRA_TSERVICE_HH

#include "TService.hh"
#include "xtra/TraderService.hh"

namespace xena {

class XtraTService :
      public xtra::TraderCallback,
      public TService {
 public:
  XtraTService(
      const rapidjson::Document& doc,
      TServiceCallback* callback);

  virtual ~XtraTService();

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
  std::unique_ptr<xtra::TraderService> service_;

  TServiceCallback* callback_;
};

};  // namespace xena

#endif  // XENA_XTRA_TSERVICE_HH
