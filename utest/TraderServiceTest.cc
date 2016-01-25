#include "gtest/gtest.h"

#include "src/XenaLog.hh"
#include "xtra/TraderService.hh"

#include "soil/STimer.hh"

namespace xena
{

class TraderServiceTest : public ::testing::Test
{
 public:
  TraderServiceTest()
  {
  }
  
  void SetUp()
  {
    options_.reset( xtra::TraderService::createOptions() );

    std::auto_ptr<soil::Config> config( soil::Config::create() );
    config->configFile() = "xtra.cfg";
    config->registerOptions( options_.get() );
    config->loadConfig();

    XENA_LOG_INIT("log.cfg");

    cond_.reset( soil::STimer::create() );

    service_.reset( xtra::TraderService::createService(options_.get(), NULL) );

  }

  void TearDown()
  {
  }

 protected:
  std::auto_ptr<xtra::TraderService> service_;
  
  std::auto_ptr<soil::Options> options_;
  
  std::auto_ptr<soil::STimer> cond_;

};

TEST_F(TraderServiceTest, loginTest)
{
  ASSERT_TRUE( true );
}

TEST_F(TraderServiceTest, orderOpenBuyTest)
{

  std::string instru = "IF1510";
  double price = 2889;
  int volume = 1;
  
  service_->orderOpenBuy(instru, price, volume);

  cond_->wait(2000);

  ASSERT_TRUE(true);
}

TEST_F(TraderServiceTest, orderOpenBuyFAKTest)
{

  std::string instru = "IF1510";
  double price = 3000;
  int volume = 1;
  
  service_->orderOpenBuyFAK(instru, price, volume);

  cond_->wait(2000);

  ASSERT_TRUE(true);
}

TEST_F(TraderServiceTest, orderOpenBuyFOKTest)
{

  std::string instru = "cu1602";
  double price = 33050;
  int volume = 10;
  
  service_->orderOpenBuyFOK(instru, price, volume);

  cond_->wait(2000);

  ASSERT_TRUE(true);
}

TEST_F(TraderServiceTest, orderOpenSellFOKTest)
{

  std::string instru = "cu1602";
  double price = 42820;
  int volume = 10;
  
  service_->orderOpenSellFOK(instru, price, volume);

  cond_->wait(2000);

  ASSERT_TRUE(true);
}

TEST_F(TraderServiceTest, queryAccountTest)
{

  service_->queryAccount();

  cond_->wait(2000);

  ASSERT_TRUE(true);
}

}; 
