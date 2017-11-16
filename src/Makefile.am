AUTOMAKE_OPTIONS = foreign

SUBDIRS = 

bin_PROGRAMS = fema rem

xena_SOURCES = \
	TimeStampDataFile.cc \
	Options.cc \
	Server.cc \
	Main.cc 

fema_SOURCES = \
	FoalTService.cc \
	$(xena_SOURCES)

rem_SOURCES = \
	SeaTService.cc \
	$(xena_SOURCES)

xena_CPPFLAGS = -I$(top_srcdir) \
		$(BOOST_CPPFLAGS) \
		$(RAPIDJSON_CPPFLAGS) \
		$(FMT_CPPFLAGS) \
		$(SPDLOG_CPPFLAGS) \
		$(READERWRITERQUEUE_CPPFLAGS) \
		$(ARGS_CPPFLAGS) \
		$(SOIL_CPPFLAGS) 

fema_CPPFLAGS = \
	$(xena_CPPFLAGS) \
	$(FOAL_CPPFLAGS)

rem_CPPFLAGS = \
	$(xena_CPPFLAGS) \
	$(SEA_CPPFLAGS)

xena_LDADD = \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(FMT_LIBADD)

fema_LDADD = \
	$(xena_LDADD) \
	$(FOAL_LIBADD)

rem_LDADD = \
	$(xena_LDADD) \
	$(SEA_LIBADD)


xena_ldflags = $(LIBADD_DL) -Wl,--no-as-needed -pthread

fema_LDFLAGS = $(xena_ldflags)
rem_LDFLAGS = $(xena_ldflags)

# header files
noinst_HEADERS = \
		TimeStampDataFile.hh \
		Options.hh \
		Server.hh \
		TService.hh \
		FoalTService.hh \
		SeaTService.hh

EXTRA_DIST = env.sh 

# xenadir = $(bindir)
# xena_DATA = $(EXTRA_DIST)
