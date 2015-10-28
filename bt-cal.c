/**
  @file bt-cal.c

  Copyright (C) 2012 Jonathan Wilson

  @author Jonathan wilson <jfwfreo@tpgi.com.au>

  This prorgam is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License version 2.1 as
  published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
  General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this library; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/
#include <stdio.h>
#include <string.h>
#include <cal.h>
int main()
{
	struct cal *c;
	char *data;
	unsigned long size;
        cal_init(&c);
	cal_read_block(c,"cert-npc",(void **)&data,&size,0);
	cal_finish(c);
	data += 0x94;
        int count = data[0] | data[1] << 8 | data[2] << 16 | data[3] << 24;
	data += 4;
        for (int i = 0;i < count;i++)
	{
		if (!strcmp(data,"BT_ID"))
		{
			data += 8;
			FILE *f = fopen("/sys/devices/platform/hci_h4p/bdaddr","wt");
			fprintf(f,"%02x:%02x:%02x:%02x:%02x:%02x",data[5],data[4],data[3],data[2],data[1],data[0]);
			fclose(f);
			data += 32;
		}
		else
		{
			data += 40;
		}
	}
	return 0;
}
