#ifndef _RTC_TIME_H_
#define _RTC_TIME_H_

#include "sys.h"
#include "lvgl.h"

void RTC_Time_create(lv_obj_t *parent);
static void rtc_time_task(lv_task_t * t);

extern lv_task_t *task1;

extern uint8_t Secondsute;
extern uint8_t Minutes;
extern uint8_t Hours;

#endif
