AUTOMAKE_OPTIONS = foreign

SUBDIRS = 

bin_PROGRAMS = xena
xena_SOURCES = \
	XenaConfig.cc \
	TraderServer.cc \
	Main.cc 


xena_CPPFLAGS = -I$(top_srcdir) \
		$(BOOST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(XTRA_CPPFLAGS) \
		$(AIR_CPPFLAGS)


xena_LDADD = \
	$(XTRA_LIBADD) \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(AIR_LIBADD)


xena_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = XenaConfig.hh \
		XenaLog.hh \
		TraderServer.hh


EXTRA_DIST = env.sh xena.cfg log.cfg

xenadir = $(bindir)
xena_DATA = $(EXTRA_DIST)
