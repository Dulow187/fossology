# Copyright Siemens AG 2014
#
# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without any warranty.

TOP = ../../..
VARS = $(TOP)/Makefile.conf
include $(VARS)

# -Werror -Wextra
CXXFLAGS_LOCAL = $(FO_CXXFLAGS) -I. -Wall -Wextra -fopenmp
DEF = -DDATADIR='"$(MODDIR)"'
CONFDIR = $(DESTDIR)$(SYSCONFDIR)
CXXFLAGS_LINK = -lboost_regex -lboost_program_options $(ALL_CXXFLAGS) -lm -fopenmp $(FO_CXXLDFLAGS)

DEF_ID_COP = -DIDENTITY_COPYRIGHT
DEF_ID_ECC = -DIDENTITY_ECC

EXE_COP = copyright
EXE_ECC = ecc
EXE = $(EXE_COP) $(EXE_ECC)
EXE_COV = $(EXE_COP)_cov



OBJECTS = copyright.o regscan.o scanners.o regTypes.o cleanEntries.o
OBJECTS_COP = copyscan_cop.o copyrightUtils_cop.o copyrightState_cop.o database_cop.o
OBJECTS_ECC = copyrightUtils_ecc.o copyrightState_ecc.o database_ecc.o

HEADERS = $(OBJECTS:%.o=%.hpp) $(OBJECTS_COP:%_cop.o=%.hpp)

COVERAGE = $(OBJECTS:.o=_cov.o)
COVERAGE_COP = $(OBJECTS_COP:.o=_cov.o)

all: $(CXXFOLIB) $(EXE)

$(EXE_COP): $(CXXFOLIB) $(VARS) $(OBJECTS) $(OBJECTS_COP)
	$(CXX) $(OBJECTS) $(OBJECTS_COP) $(DEF_ID_COP) $(DEF) $(CXXFLAGS_LINK) -o $@

$(EXE_ECC): $(CXXFOLIB) $(VARS) $(OBJECTS) $(OBJECTS_ECC)
	$(CXX) $(OBJECTS) $(OBJECTS_ECC) $(DEF_ID_ECC) $(DEF) $(CXXFLAGS_LINK) -o $@

$(EXE_COV): $(CXXFOLIB) $(VARS) $(COVERAGE) $(COVERAGE_COP)
	$(CXX) $(COVERAGE) $(COVERAGE_COP) $(FLAG_COV) $(DEF_ID_COP) $(DEF) $(CXXFLAGS_LINK) -o $@

#######################
# library build rules #
#######################

$(CXXFOLIB):
	$(MAKE) -C $(CXXFOLIBDIR)

libcopyright.a: $(OBJECTS) $(OBJECTS_COP)
	ar cvr $@ $(OBJECTS) $(OBJECTS_COP)
	
libcopyright_cov.a: $(COVERAGE) $(COVERAGE_COP)
	ar cvr $@ $(COVERAGE) $(COVERAGE_COP)

######################
# object build rules #
######################

$(OBJECTS): %.o: %.cc $(HEADERS)
	$(CXX) -c $(CXXFLAGS_LOCAL) $(DEF) $<
	
$(OBJECTS_COP): %_cop.o: %.cc $(HEADERS)
	$(CXX) -c $(CXXFLAGS_LOCAL) $(DEF_ID_COP) $(DEF) -o $@ $<
	
$(OBJECTS_ECC): %_ecc.o: %.cc $(HEADERS)
	$(CXX) -c $(CXXFLAGS_LOCAL) $(DEF_ID_ECC) $(DEF) -o $@ $<
	
$(COVERAGE_COP): %_cop_cov.o: %.cc $(HEADERS)
	$(CXX) -c $< $(CXXFLAGS_LOCAL) $(FLAG_COV) $(DEF_ID_COP) $(DEF) $(DEFS) -o $@

$(COVERAGE): %_cov.o: %.cc $(HEADERS)
	$(CXX) -c $< $(CXXFLAGS_LOCAL) $(FLAG_COV) $(DEF_ID_COP) $(DEF) $(DEFS) -o $@

#######################
# install build rules #
#######################

install: $(EXE)
	for mod_name in $(EXE); do \
		$(INSTALL_PROGRAM) $$mod_name $(DESTDIR)$(MODDIR)/$$mod_name/agent/$$mod_name; \
	done

uninstall:
	for mod_name in $(EXE); do \
		rm -rf $(DESTDIR)$(MODDIR)/$$mod_name/agent; \
	done

clean:
	rm -f $(EXE) *.o *.a *.gcno *.gcda core

.PHONY: all install uninstall clean
