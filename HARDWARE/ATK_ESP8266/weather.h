#ifndef __WEATHER_H
#define __WEATHER_H

#include "sys.h"

//�Ӷ���1�ṹ��--Location
typedef struct
{
	char id[32];
	char name[32];
	char country[32];
	char path[64];
	char timezone[32];
	char timezone_offset[32];
}Location;
 
//�Ӷ���2�ṹ��--Now
typedef struct
{
	char text[32];
	char code[32];
	char temperature[32];
}Now;

typedef struct
{
	Location location;		//�Ӷ���1
	Now now;				//�Ӷ���2
	char last_update[64];	//�Ӷ���3
}Results;

u8 get_current_weather(void);
u8 get_3days_weather(void);
void show_weather(void);

u8 get_beijing_time(void);
#endif

