#! /bin/sh

home_app=~/app

if test -d /llj/app ; then
   home_app=/llj/app
fi

home_xena=${home_app}/xena

./configure --prefix=${home_xena}

if test -d ${home_xena}; then
    rm -rf ${home_xena}
fi

make install

make distclean
