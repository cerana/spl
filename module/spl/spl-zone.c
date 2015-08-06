/*****************************************************************************\
 *  Copyright 2015 OmniTI Computer Consulting, Inc. All rights reserved.
 *  Written by Albert Lee <trisk@omniti.com>.
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
 *****************************************************************************
 *  Solaris Porting Layer (SPL) Zones Implementation.
\*****************************************************************************/

#include <sys/zone.h>
#include <linux/nsproxy.h>
#include <linux/user_namespace.h>
#include <linux/ns_common.h>

zoneid_t
crgetzoneid(const cred_t *cred)
{
	struct user_namespace *userns;

	userns = cred->user_ns;

	if (userns == &init_user_ns)
		return (0);

	if (userns->ns.inum == 0)
		return ((zoneid_t)-1);

	return ((zoneid_t) userns->ns.inum);
}
EXPORT_SYMBOL(crgetzoneid);

int
spl_zone_init(void)
{
	return (0);

}

void
spl_zone_fini(void)
{
	return;
}

