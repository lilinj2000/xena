node=`uname -n`
home_3rd=~/3rd/${node}
home_boost=$home_3rd/boost
home_fmt=$home_3rd/fmt

home_fema_all=$home_3rd/FemasAllFuturesAPI_1.01_20170526_linux64
home_rem=$home_3rd/rem_api_2.0.1.34
home_xele=$home_3rd/xeletrade-traderapi-1.1.68
home_xone=$home_3rd/XOne_api_v1.5.3.4/XOne/linux64/
home_xspeed=$home_3rd/XOne_api_v1.5.3.4/XSpeed/libs/linux64_api
home_nst=$home_3rd/NSTAPI-BL2018-20180914-V1
home_ctp=$home_3rd/v6.3.15_20190220_api_tradeapi_se_linux64
home_yd=$home_3rd/20190629_yd.client/yd.client/linux/
home_es=$home_3rd/TapAPI_20190606_V9/esapi/


LD_LIBRARY_PATH=$home_boost/lib:$home_fmt/lib
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$home_fema_all/lib
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$home_rem/lib/trade/C++/linux64:$home_rem/lib/quote/C++/linux64
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$home_xele
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$home_xone
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$home_xspeed
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$home_ctp
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$home_nst/lib
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$home_yd
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$home_es/lib/linux

export LD_LIBRARY_PATH



