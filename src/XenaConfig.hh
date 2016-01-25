#ifndef XENA_CONFIG_HH
#define XENA_CONFIG_HH

#include <string>
#include <memory>
#include "soil/Config.hh"

namespace xena
{

namespace po = boost::program_options;

class XenaOptions : public soil::Options
{
 public:

  XenaOptions();
  
  virtual ~XenaOptions();

  virtual po::options_description* configOptions();

  std::string instrument_id;
  double price;
  int volume;
  bool is_buy;

  int order_counter;
  int order_interval;

  std::string log_cfg;

  std::string timestamp_file;

 private:
  boost::program_options::options_description config_options_;
};

class XenaConfig
{
 public:
  
  XenaConfig(int argc=0, char* argv[]=NULL);
  ~XenaConfig();

  XenaOptions* xenaOptions()
  {
    return xena_options_.get();
  }

  soil::Options* xtraTraderOptions()
  {
    return xtra_trader_options_.get();
  }

 private:
  std::unique_ptr<XenaOptions> xena_options_;
  
  std::unique_ptr<soil::Options> xtra_trader_options_;

};

}  


#endif 
