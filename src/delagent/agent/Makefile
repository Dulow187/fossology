######################################################################
# Copyright (C) 2008-2011 Hewlett-Packard Development Company, L.P.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# version 2 as published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
######################################################################

TOP = ../../..
VARS = $(TOP)/Makefile.conf
DEPS = $(TOP)/Makefile.deps
include $(VARS)

CFLAGS_LOCAL = $(ALL_CFLAGS) -lpq -lssl -lcrypto
CONFDIR = $(DESTDIR)$(SYSCONFDIR)

EXE = delagent
HDRS = delagent.h

all: $(EXE)

$(EXE): %: %.c $(FOLIB) delagent.o $(VARS) $(HDRS)
	$(CC) $< delagent.o $(FO_LDFLAGS) $(CFLAGS_LOCAL) $(DEFS) -o $@

delagent.o: util.c $(HDRS)
	$(CC) -c $< $(CFLAGS_LOCAL) -o $@

delagent_cov.o: util.c $(HDRS)
	$(CC) -c $< $(FLAG_COV) $(CFLAGS_LOCAL) $(DEFS) -o $@

install: all
	$(INSTALL_PROGRAM) $(EXE) $(DESTDIR)$(MODDIR)/$(EXE)/agent/$(EXE)

uninstall:
	rm -rf $(DESTDIR)$(MODDIR)/$(EXE)/agent

clean:
	rm -f $(EXE) *.o core *.gc*

.PHONY: all install uninstall clean

include $(DEPS)
