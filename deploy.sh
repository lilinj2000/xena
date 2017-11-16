#! /bin/sh

node=`uname -n`
home_app=~/app/${node}

home_xena=${home_app}/xena

./configure --prefix=${home_xena}

if test -d ${home_xena}; then
    rm -rf ${home_xena}
fi

make install

make distclean
