/*
 * $Id$
 *
 * Copyright (C) 2007 Raphael Coeffic
 *
 * This file is part of sems, a free SIP media server.
 *
 * sems is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version
 *
 * For a license to use the ser software under conditions
 * other than those described here, or to purchase support for this
 * software, please contact iptel.org by e-mail at the following addresses:
 *    info@iptel.org
 *
 * sems is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _msg_hdrs_h
#define _msg_hdrs_h

#include "parse_header.h"
#include "parse_common.h"

inline int copy_hdr_len(sip_header* hdr)
{
    return hdr->name.len + hdr->value.len
	+ 4/* ': ' + CRLF */;
}

inline void copy_hdr_wr(char** c, sip_header* hdr)
{
    memcpy(*c,hdr->name.s,hdr->name.len);
    *c += hdr->name.len;
    
    *((*c)++) = ':';
    *((*c)++) = SP;
    
    memcpy(*c,hdr->value.s,hdr->value.len);
    *c += hdr->value.len;
    
    *((*c)++) = CR;
    *((*c)++) = LF;
}


#include <list>
using std::list;


int  copy_hdrs_len(const list<sip_header*>& hdrs);
void copy_hdrs_wr(char** c, const list<sip_header*>& hdrs);


#endif
