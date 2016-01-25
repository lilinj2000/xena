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
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(XTRA_LIBADD) \
	$(AIR_LIBADD)


xena_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = XenaConfig.hh \
		XenaLog.hh \
		TraderServer.hh


EXTRA_DIST = env.sh.example xena.cfg.example log.cfg.example

xenadir = $(bindir)
xena_DATA = $(EXTRA_DIST)
