#ifndef _START_TASK_H_
#define _START_TASK_H_

#include "sys.h"
#include "lvgl.h"


#define USER_EVENT_BACK		(LV_EVENT_DELETE+10)  

void test_start(void);
lv_obj_t * general_win_create(lv_obj_t * parent,const char * title);
#endif
