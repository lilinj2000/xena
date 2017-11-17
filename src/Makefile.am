AUTOMAKE_OPTIONS = foreign

SUBDIRS = 

bin_PROGRAMS = xena

xena_SOURCES = \
	TimeStampDataFile.cc \
	Options.cc \
	Server.cc \
	Main.cc \
	FoalTService.cc \
	SeaTService.cc \
	XtraTService.cc \
	TService.cc

xena_CPPFLAGS = -I$(top_srcdir) \
		$(BOOST_CPPFLAGS) \
		$(RAPIDJSON_CPPFLAGS) \
		$(FMT_CPPFLAGS) \
		$(SPDLOG_CPPFLAGS) \
		$(READERWRITERQUEUE_CPPFLAGS) \
		$(ARGS_CPPFLAGS) \
		$(SOIL_CPPFLAGS) \
		$(FOAL_CPPFLAGS) \
		$(SEA_CPPFLAGS) \
		$(XTRA_CPPFLAGS)

xena_LDADD = \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(FMT_LIBADD) \
	$(FOAL_LIBADD) \
	$(SEA_LIBADD) \
	$(XTRA_LIBADD)

xena_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread

# header files
noinst_HEADERS = \
		TimeStampDataFile.hh \
		Options.hh \
		Server.hh \
		TService.hh \
		FoalTService.hh \
		SeaTService.hh \
		XtraTService.hh

EXTRA_DIST = env.sh 

xenadir = $(bindir)
xena_DATA = $(EXTRA_DIST)
