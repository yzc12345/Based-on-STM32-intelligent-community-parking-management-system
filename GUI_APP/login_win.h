#ifndef _LOGIN_WIN_H_
#define _LOGIN_WIN_H_

#include "sys.h"
#include "lvgl.h"


void login_win_create(lv_obj_t *parent);

extern lv_task_t *time_task;
extern lv_obj_t *login_win;
#endif
