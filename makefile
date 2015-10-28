bt-cal:
	gcc -o bt-cal bt-cal.c -lcal -std=gnu99

install:
	install -d $(DESTDIR)/etc/event.d
	install script/bt-cal $(DESTDIR)/etc/event.d
	install -d $(DESTDIR)/usr/sbin
	install bt-cal $(DESTDIR)/usr/sbin

clean:
	rm bt-cal

