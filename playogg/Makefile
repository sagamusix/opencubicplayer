TOPDIR=../
include $(TOPDIR)Rules.make

all: oggtype.o playogg$(LIB_SUFFIX)

clean:
	rm -f *.o *$(LIB_SUFFIX)

install:
	$(CP) playogg$(LIB_SUFFIX) "$(DESTDIR)$(LIBDIR)"

uninstall:
	rm -f "$(DESTDIR)$(LIBDIR)/playogg$(LIB_SUFFIX)"

playogg_so=cpiogginfo.o cpioggpic.o oggplay.o oggpplay.o
playogg$(LIB_SUFFIX): $(playogg_so)
	$(CC) $(SHARED_FLAGS) $(LDFLAGS) -o $@ $^ $(OGG_LIBS) $(MATH_LIBS) $(VORBIS_LIBS) $(VORBISFILE_LIBS)

cpiogginfo.o: cpiogginfo.c \
	../config.h \
	../types.h \
	../cpiface/cpiface.h \
	../stuff/poutput.h \
	oggplay.h
	$(CC) $< -o $@ $(VORBISFILE_CFLAGS) -c

cpioggpic.o: cpioggpic.c \
	../config.h \
	../types.h \
	../boot/psetting.h \
	../cpiface/cpiface.h \
	../stuff/poutput.h \
	oggplay.h
	$(CC) $< -o $@ $(VORBISFILE_CFLAGS) -c

oggtype.o: oggtype.c \
	../config.h \
	../types.h \
	../filesel/mdb.h \
	../stuff/cp437.h
	$(CC) oggtype.c -o $@ -c

oggplay.o: oggplay.c \
	../config.h \
	../types.h \
	../stuff/poll.h \
	../stuff/timer.h \
	../cpiface/gif.h \
	../cpiface/jpeg.h \
	../cpiface/png.h \
	../dev/player.h \
	../dev/deviplay.h \
	../dev/ringbuffer.h \
	../dev/plrasm.h \
	../stuff/imsrtns.h \
	oggplay.h
	$(CC) oggplay.c -o $@ $(OGG_CFLAGS) $(VORBIS_CFLAGS) $(VORBISFILE_CFLAGS) -c

oggpplay.o: oggpplay.c \
	../config.h \
	../types.h \
	../filesel/pfilesel.h \
	../filesel/mdb.h \
	../stuff/poutput.h \
	../dev/player.h \
	../boot/psetting.h \
	../boot/plinkman.h \
	oggplay.h \
	../stuff/sets.h \
	../stuff/compat.h \
	../stuff/err.h \
	../dev/deviplay.h \
	../cpiface/cpiface.h
	$(CC) oggpplay.c -o $@ $(OGG_CFLAGS) $(VORBIS_CFLAGS) $(VORBISFILE_CFLAGS) -c
