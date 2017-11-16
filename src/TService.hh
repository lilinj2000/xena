// Copyright (c) 2010
// All rights reserved.

#ifndef XENA_TSERVICE_HH
#define XENA_TSERVICE_HH

#include <string>
#include "soil/json.hh"

namespace xena {

class TServiceCallback {
 public:
  virtual void t1Update(int32_t local_id) = 0;

  virtual void t2Update(int32_t local_id) = 0;

  virtual ~TServiceCallback() {
  }
};

class TService {
 public:
  virtual int32_t orderInsert(
      const std::string& instru,
      double price,
      int volume) = 0;

  static TService* create(
      const rapidjson::Document& doc,
      TServiceCallback* callback);
};

}  // namespace xena

#endif  // XENA_TSERVICE_HH
