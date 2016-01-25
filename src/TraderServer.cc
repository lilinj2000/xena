#include "TraderServer.hh"
#include "XenaLog.hh"

#include "soil/STimer.hh"

namespace xena
{

TraderServer::TraderServer(XenaOptions* xena_options, soil::Options* trader_options):
    xena_options_(xena_options)
{
  XENA_TRACE <<"TraderServer::TraderServer()";

  trader_service_.reset( xtra::TraderService::createService(trader_options, this) );

  if( !xena_options->timestamp_file.empty() )
    timestamp_file_.reset( new air::TimeStampDataFile(xena_options->timestamp_file) );

}

TraderServer::~TraderServer()
{
  XENA_TRACE <<"TraderServer::~TraderServer()";
}

void TraderServer::onRspError(int errord_id, const std::string& error_msg)
{
  XENA_TRACE <<"TraderServer::onRspError()";
}

void TraderServer::onRspOrderInsert(int order_ref, bool is_success)
{
  XENA_TRACE <<"TraderServer::onRspOrderInsert()";

  XENA_DEBUG <<"order_ref: " <<order_ref
             <<" success: " <<std::boolalpha <<is_success;

  auto it = records_.find(order_ref);

  if( it!=records_.end() )
  {
    it->second->updateT2();
    
    timestamp_file_->putData( it->second );

    records_.erase( it );
  }
  else
  {
    XENA_ERROR <<"unexpected the rtn order, the order ref is " <<order_ref;
  }

}

void TraderServer::onErrRtnOrderInsert(int order_ref)
{
  XENA_TRACE <<"TraderServer::onErrRtnOrderInsert()";

  XENA_DEBUG <<"order_ref: " <<order_ref;
}

void TraderServer::onRtnOrder(int order_ref, const std::string& order_status, const std::string& status_msg)
{
  XENA_TRACE <<"TraderServer::onRtnOrder()";

  XENA_DEBUG <<"order_ref = " <<order_ref
             <<"; order_status = " <<order_status
             <<"; status_msg = " <<status_msg;

}

void TraderServer::onRtnTrade(int order_ref, double price, int volume)
{
  XENA_TRACE <<"TraderServer::onRtnTrade()";

  XENA_DEBUG <<"order_ref = " <<order_ref
             <<"; price = " <<price
             <<"; volume = " <<volume;
}

void TraderServer::run()
{
  XENA_TRACE <<"TraderServer::run()";

  int counter = 0;

  std::unique_ptr<soil::STimer> cond;
  cond.reset( soil::STimer::create() );


  do
  {
    int order_ref = -1;

    if( xena_options_->is_buy )
    {
      order_ref = trader_service_->orderOpenBuyFOK(
          xena_options_->instrument_id,
          xena_options_->price,
          xena_options_->volume);

      
    }
    else
    {
      order_ref = trader_service_->orderOpenSellFOK(
          xena_options_->instrument_id,
          xena_options_->price,
          xena_options_->volume);
    }

    records_[order_ref] = new air::TimeStampData(order_ref);
    
    ++counter;

    if( xena_options_->order_counter>0 && counter>=xena_options_->order_counter )
      break;
      
    cond->wait(xena_options_->order_interval);
      
  }while(true);

  cond->wait(1000);
}

};
