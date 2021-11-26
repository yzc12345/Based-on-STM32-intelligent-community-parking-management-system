#ifndef _TABLE_H_
#define _TABLE_H_

#include "sys.h"
#include "lvgl.h"

#define TABLE_COL_CNT   5   
#define TABLE_ROW_CNT   5   


struct table1_data
{
	char num[3];
	char name[20];
	char time_into[20];
	char time_out[20];
};
extern struct table1_data data_1[TABLE_ROW_CNT-1];

void table_create(lv_obj_t *parent);

extern char *TABLE_CELL_VALUE[TABLE_ROW_CNT][TABLE_COL_CNT];
extern char *data[TABLE_COL_CNT][TABLE_ROW_CNT];
extern lv_obj_t *table1;

extern lv_task_t *table_task;
#endif

