#ifndef __ESP8266_H
#define __ESP8266_H
#include "sys.h"
#include "stdio.h"	

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

typedef struct   //�ṹ�塣
{
    vu16  year;
    vu8   month;
    vu8   date;
    vu8   hour;
    vu8   min;
    vu8   sec;	 
}nt_calendar_obj;	 

//�û�����ATָ��
extern char restart[];
extern char cwmode[];
extern char cwlap[];
extern char cwjap[];
extern char cifsr[];
extern char cipmux[];
extern char cipstart[];
extern char cipsend[];
extern char cipserver[];
extern char cwlif[];
extern char cipstatus[];
extern char cipsto[];
extern char cipmode[];
extern char test[];


//����

u8 esp8266_send_cmd(u8 *cmd,u8 *ack,u16 waittime);
u8* esp8266_send_data(u8 *cmd,u16 waittime);
u8* esp8266_check_cmd(u8 *str);
void esp8266_start_trans(void);
u8 esp8266_quit_trans(void);
u8 get_current_weather(void);
u8 cloes_weather(void);
u8 get_weather(void);
u8 esp8266_quit_trans(void);
int cJSON_WeatherParse(char *JSON, Results *results);

u8 get_3days_weather(void);


void atk_8266_get_wanip(u8* ipbuf);
u8 get_beijing_time(void);
u8 RTC_Set(u16 syear,u8 smon,u8 sday,u8 hour,u8 min,u8 sec);
u8* atk_8266_check_cmd(u8 *str);
u8 Is_Leap_Year(u16 year);
#endif
