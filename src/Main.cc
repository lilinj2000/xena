#include <memory>
#include "XenaConfig.hh"
#include "TraderServer.hh"

int main(int argc, char* argv[])
{

  std::unique_ptr<xena::XenaConfig> config;
  config.reset(new xena::XenaConfig(argc, argv));

  xena::XenaOptions* xena_options = config->xenaOptions();

  std::unique_ptr<xena::TraderServer> server;
  server.reset(new xena::TraderServer(xena_options, config->xtraTraderOptions()));

  server->run();
  
  return 0;
}
