#ifndef _BAR_H_
#define _BAR_H_

#include "sys.h"
#include "lvgl.h"

extern lv_task_t *task_bar;
extern uint16_t bar_value;
void bar_create(lv_obj_t *parent);

#endif
