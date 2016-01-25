#ifndef XENA_TRADER_SERVER_HH
#define XENA_TRADER_SERVER_HH

#include "xtra/TraderService.hh"
#include "XenaConfig.hh"
#include "air/TimeStampDataFile.hh"

namespace xena
{

typedef std::map<int, air::TimeStampData*> TimeStampRecords;

class TraderServer : public xtra::TraderServiceCallback
{
 public:
  TraderServer(XenaOptions* xena_options, soil::Options* trader_options);
               
  virtual ~TraderServer();

  virtual void onRspError(int errord_id, const std::string& error_msg);
  
  virtual void onRspOrderInsert(int order_ref, bool is_success);

  virtual void onErrRtnOrderInsert(int order_ref);

  virtual void onRtnOrder(int order_ref, const std::string& order_status, const std::string& status_msg);

  virtual void onRtnTrade(int order_ref,
                          double price, int volume);

  void run();
  
 private:

  XenaOptions* xena_options_;
  
  std::unique_ptr<xtra::TraderService> trader_service_;

  TimeStampRecords records_;

  std::unique_ptr<air::TimeStampDataFile> timestamp_file_;
};

};

#endif
