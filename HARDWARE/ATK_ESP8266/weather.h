#ifndef __WEATHER_H
#define __WEATHER_H

#include "sys.h"

//子对象1结构体--Location
typedef struct
{
	char id[32];
	char name[32];
	char country[32];
	char path[64];
	char timezone[32];
	char timezone_offset[32];
}Location;
 
//子对象2结构体--Now
typedef struct
{
	char text[32];
	char code[32];
	char temperature[32];
}Now;

typedef struct
{
	Location location;		//子对象1
	Now now;				//子对象2
	char last_update[64];	//子对象3
}Results;

u8 get_current_weather(void);
u8 get_3days_weather(void);
void show_weather(void);

u8 get_beijing_time(void);
#endif

