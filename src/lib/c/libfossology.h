/* **************************************************************
Copyright (C) 2010-2013 Hewlett-Packard Development Company, L.P.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
version 2 as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

************************************************************** */

#ifndef LIBFOSSOLOGY_H
#define LIBFOSSOLOGY_H

#include <stdio.h>
#include "libfossscheduler.h"
#include "libfossrepo.h"
#include "libfossdb.h"
#include "libfossagent.h"
#include "sqlCopy.h"
#include "fossconfig.h"

#define PERM_NONE 0
#define PERM_READ 1
#define PERM_WRITE 3
#define PERM_ADMIN 10

#define PLUGIN_DB_NONE 0
#define PLUGIN_DB_READ 1
#define PLUGIN_DB_WRITE 3
#define PLUGIN_DB_ADMIN 10

#endif /* LIBFOSSOLOGY_H */
