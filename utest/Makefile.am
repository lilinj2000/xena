AUTOMAKE_OPTIONS = foreign

SUBDIRS = 

noinst_PROGRAMS = unittest

unittest_SOURCES = \
	TraderServiceTest.cc


unittest_CPPFLAGS = -I$(top_srcdir) \
		$(BOOST_CPPFLAGS) \
		$(GTEST_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(XTRA_CPPFLAGS)


unittest_LDADD = \
	$(GTEST_LIBADD) \
	$(XTRA_LIBADD) \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD)


unittest_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = 

EXTRA_DIST = env.sh xtra.cfg log.cfg

