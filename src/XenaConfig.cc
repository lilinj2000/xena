#include "XenaConfig.hh"
#include "XenaLog.hh"
#include "xtra/TraderService.hh"

#include <fstream>
#include <iostream>
#include <boost/program_options.hpp>

namespace xena
{

XenaOptions::XenaOptions():
    config_options_("XenaConfigOptions")
{

  namespace po = boost::program_options;

  config_options_.add_options()
      ("xena.instrument_id", po::value<std::string>(&instrument_id), 
       "instrument id")
      ("xena.price", po::value<double>(&price), 
       "price")
      ("xena.volume", po::value<int>(&volume), 
       "volume")
      ("xena.is_buy", po::value<bool>(&is_buy), 
       "is buy")

      ("xena.order_counter", po::value<int>(&order_counter), 
       "order counter")
      ("xena.order_interval", po::value<int>(&order_interval), 
       "order interval")

      ("xena.log_cfg", po::value<std::string>(&log_cfg), 
       "log config file")

      ("xena.timestamp_file", po::value<std::string>(&timestamp_file), 
       "timestamp file")
      ;

  return;
  
}

XenaOptions::~XenaOptions()
{
}

po::options_description* XenaOptions::configOptions()
{
  return &config_options_;
}

XenaConfig::XenaConfig(int argc, char* argv[])
{
  xena_options_.reset(new XenaOptions());
  xtra_trader_options_.reset( xtra::TraderService::createOptions() );
      
  std::unique_ptr<soil::Config> config( soil::Config::create() );
  config->registerOptions( xena_options_.get() );
  config->registerOptions( xtra_trader_options_.get() );

  config->configFile() = "xena.cfg";
  config->loadConfig(argc, argv);
  
  // init the log
  XENA_LOG_INIT( xena_options_->log_cfg );
  
  return;
}

XenaConfig::~XenaConfig()
{
}

};  
