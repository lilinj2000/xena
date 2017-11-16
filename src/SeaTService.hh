// Copyright (c) 2010
// All rights reserved.

#ifndef XENA_SEA_TSERVICE_HH
#define XENA_SEA_TSERVICE_HH

#include <map>
#include "TService.hh"
#include "sea/TraderService.hh"

namespace xena {

typedef std::map<int, int> TokenRecords;

class SeaTService :
      public sea::TraderCallback,
      public TService {
 public:
  SeaTService(
      const rapidjson::Document& doc,
      TServiceCallback* callback);

  virtual ~SeaTService();

  virtual void onOrderAccept(
      const std::string& theAccept);

  virtual void onOrderReject(
      const std::string& theReject);

  virtual void onOrderMarketReject(
      const std::string& theReject);

  virtual int32_t orderInsert(
      const std::string& instru,
      double price,
      int volume);

 private:
  std::unique_ptr<sea::TraderService> service_;
  TokenRecords tokens_;

  TServiceCallback* callback_;
};

};  // namespace xena

#endif  // XENA_SEA_TSERVICE_HH
