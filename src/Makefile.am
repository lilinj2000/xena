AUTOMAKE_OPTIONS = foreign

SUBDIRS = 

bin_PROGRAMS = xena

xena_SOURCES = \
	time_stamp_data_file.cc \
	options.cc \
	server.cc \
	main.cc \
	foal_tservice.cc \
	sea_tservice.cc \
	xtra_tservice.cc \
	xmas_tservice.cc \
	ufo_tservice.cc \
	yet_tservice.cc \
	cata_tservice.cc \
	tservice.cc

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
		$(XTRA_CPPFLAGS) \
		$(XMAS_CPPFLAGS) \
		$(UFO_CPPFLAGS) \
		$(CATA_CPPFLAGS) \
		$(YET_CPPFLAGS)

xena_LDADD = \
	$(BOOST_LIBADD) \
	$(SOIL_LIBADD) \
	$(FMT_LIBADD) \
	$(FOAL_LIBADD) \
	$(SEA_LIBADD) \
	$(XTRA_LIBADD) \
	$(XMAS_LIBADD) \
	$(UFO_LIBADD) \
	$(CATA_LIBADD) \
	$(YET_LIBADD)

xena_LDFLAGS = $(LIBADD_DL) -Wl,--no-as-needed -pthread -luuid

# header files
noinst_HEADERS = \
		time_stamp_data_file.h \
		options.h \
		server.h \
		tservice.h \
		foal_tservice.h \
		sea_tservice.h \
		xtra_tservice.h \
		ufo_tservice.h \
		cata_tservice.h \
		yet_tservice.h
 
EXTRA_DIST = fema.json rem.json xele.json xone.json nst.json yet.json yd.txt cata.json

xenadir = $(bindir)
xena_DATA = $(EXTRA_DIST)
