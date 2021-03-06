#ifndef __OGG_H
#define __OGG_H

/* ogg_int64_t */
#include <vorbis/vorbisfile.h>

struct ogginfo
{
	ogg_int64_t pos;
	ogg_int64_t len;
	uint32_t rate;
	uint8_t stereo;
	uint8_t bit16;
	int bitrate;
};

struct ogg_comment_t
{
	char *title;
	int value_count;
	char *value[];
};

struct ogg_picture_t
{
	uint32_t picture_type;
	char *description;

	uint16_t width;
	uint16_t height;
	uint8_t *data_bgra;

	uint16_t  scaled_width;
	uint16_t  scaled_height;
	uint8_t  *scaled_data_bgra;
};

extern struct ogg_comment_t __attribute__ ((visibility ("internal"))) **ogg_comments;
extern int                  __attribute__ ((visibility ("internal")))   ogg_comments_count;
extern struct ogg_picture_t __attribute__ ((visibility ("internal")))  *ogg_pictures;
extern int                  __attribute__ ((visibility ("internal")))   ogg_pictures_count;

extern int  __attribute__ ((visibility ("internal"))) oggOpenPlayer(FILE *);
extern void __attribute__ ((visibility ("internal"))) oggClosePlayer(void);
extern void __attribute__ ((visibility ("internal"))) oggIdle(void);
extern void __attribute__ ((visibility ("internal"))) oggSetLoop(uint8_t s);
extern char __attribute__ ((visibility ("internal"))) oggLooped(void);
extern void __attribute__ ((visibility ("internal"))) oggPause(uint8_t p);
extern void __attribute__ ((visibility ("internal"))) oggSetAmplify(uint32_t amp);
extern void __attribute__ ((visibility ("internal"))) oggSetSpeed(uint16_t sp);
extern void __attribute__ ((visibility ("internal"))) oggSetVolume(uint8_t vol, int8_t bal, int8_t pan, uint8_t opt);
extern void __attribute__ ((visibility ("internal"))) oggGetInfo(struct ogginfo *);
extern ogg_int64_t __attribute__ ((visibility ("internal"))) oggGetPos(void);
extern void __attribute__ ((visibility ("internal"))) oggSetPos(ogg_int64_t pos);

extern void __attribute__ ((visibility ("internal"))) OggInfoInit (void);
extern void __attribute__ ((visibility ("internal"))) OggInfoDone (void);

extern void __attribute__ ((visibility ("internal"))) OggPicInit (void);
extern void __attribute__ ((visibility ("internal"))) OggPicDone (void);

#endif
