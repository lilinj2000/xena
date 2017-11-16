node=`uname -n`
home_3rd=~/3rd/${node}
home_boost=$home_3rd/boost
home_fmt=$home_3rd/fmt

home_fema_all=$home_3rd/FemasAllFuturesAPI_1.01_20170526_linux64
home_rem=$home_3rd/rem_api_2.0.1.34

LD_LIBRARY_PATH=$home_boost/lib:$home_fmt/lib
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$home_fema_all/lib
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$home_rem/lib/trade/C++/linux64:$home_rem/lib/quote/C++/linux64

export LD_LIBRARY_PATH



