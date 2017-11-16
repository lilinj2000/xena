node=`uname -n`
home_3rd=~/3rd/${node}
home_boost=$home_3rd/boost
home_fmt=$home_3rd/fmt

home_fema_all=$home_3rd/FemasAllFuturesAPI_1.01_20170526_linux64

export LD_LIBRARY_PATH=$home_boost/lib:$home_fema_all/lib:$home_fmt/lib



