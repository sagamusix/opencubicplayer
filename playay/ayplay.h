#ifndef _AYPLAY_H
#define _AYPLAY_H

struct ayinfo
{
	unsigned char filever, playerver;
	int track;
	int numtracks;
	const char *trackname;
};

struct ay_driver_frame_state_t; /* sound.h */

extern int __attribute__ ((visibility ("internal"))) ayOpenPlayer(FILE *);
extern void __attribute__ ((visibility ("internal"))) ayClosePlayer(void);
extern void __attribute__ ((visibility ("internal"))) ayIdle(void);
extern void __attribute__ ((visibility ("internal"))) aySetLoop(uint8_t s);
extern int __attribute__ ((visibility ("internal"))) ayIsLooped(void);
extern void __attribute__ ((visibility ("internal"))) ayPause(uint8_t p);
/* extern void __attribute__ ((visibility ("internal"))) aySetAmplify(uint32_t amp); */
extern void __attribute__ ((visibility ("internal"))) aySetMute(int ch, int mute);

extern void __attribute__ ((visibility ("internal"))) aySetSpeed(uint16_t sp);
extern void __attribute__ ((visibility ("internal"))) aySetVolume(uint8_t vol, int8_t bal, int8_t pan, uint8_t opt);
extern void __attribute__ ((visibility ("internal"))) ayGetInfo(struct ayinfo *);
extern void __attribute__ ((visibility ("internal"))) ayGetChans(struct ay_driver_frame_state_t *);
extern int  __attribute__ ((visibility ("internal"))) ayGetMute(int ch);
extern void __attribute__ ((visibility ("internal"))) ayStartSong(int song);
extern void __attribute__ ((visibility ("internal"))) ayChanSetup(void);

#endif
