// Copyright (c) 2010
// All rights reserved.

#ifndef XENA_SERVER_HH
#define XENA_SERVER_HH

#include <map>
#include <string>
#include "Options.hh"
#include "soil/STimer.hh"
#include "TimeStampDataFile.hh"
#include "TService.hh"

namespace xena {

typedef std::map<
  int32_t,
  std::shared_ptr<TimeStampData> > TimeStampRecords;

class Server :
      public TServiceCallback {
 public:
  explicit Server(
      const rapidjson::Document& doc);

  virtual ~Server();

  virtual void t1Update(int32_t local_id);

  virtual void t2Update(int32_t local_id);

 protected:
  void run();

  void updateT(
      int32_t order_ref,
      bool is_t1 = true);

  void wait(int ms = -1) {
    cond_->wait(ms);
  }

  void notify(bool is_last) {
    if (is_last) {
      cond_->notifyAll();
    }
  }

 private:
  std::unique_ptr<Options> options_;
  std::unique_ptr<TService> tservice_;

  TimeStampRecords records_;
  std::unique_ptr<TimeStampDataFile> data_file_;

  std::unique_ptr<soil::STimer> cond_;
};

}  // namespace xena

#endif
