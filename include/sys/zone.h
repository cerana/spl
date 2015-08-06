/*****************************************************************************\
 *  Copyright 2015 OmniTI Computer Consulting, Inc. All rights reserved.
 *  Copyright (C) 2007-2010 Lawrence Livermore National Security, LLC.
 *  Copyright (C) 2007 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Brian Behlendorf <behlendorf1@llnl.gov>.
 *  UCRL-CODE-235197
 *
 *  This file is part of the SPL, Solaris Porting Layer.
 *  For details, see <http://zfsonlinux.org/>.
 *
 *  The SPL is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation; either version 2 of the License, or (at your
 *  option) any later version.
 *
 *  The SPL is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 *  for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with the SPL.  If not, see <http://www.gnu.org/licenses/>.
\*****************************************************************************/

#ifndef _SPL_ZONE_H
#define _SPL_ZONE_H

#include <sys/byteorder.h>
#include <linux/atomic.h>

#define	GLOBAL_ZONEID	0

#define	INGLOBALZONE(p)	\
    (crgetzoneid(rcu_dereference_protected(p->cred, 1)) == GLOBAL_ZONEID)

typedef unsigned long zoneid_t;
typedef struct cred cred_t;

extern zoneid_t crgetzoneid(const cred_t *cred);

extern int zone_dataset_visible(const char *dataset, int *writable);

int spl_zone_init(void);
void spl_zone_fini(void);

#endif /* SPL_ZONE_H */
