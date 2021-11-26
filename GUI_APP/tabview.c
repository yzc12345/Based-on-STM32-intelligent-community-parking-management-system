#include "tabview.h"
#include "start_task.h"
#include "table.h"
#include "chart.h"

lv_obj_t *tabview=NULL;

void tabview_create(lv_obj_t *parent)
{
	lv_obj_t *win=general_win_create(parent,"停车场信息 ");

	tabview=lv_tabview_create(win,NULL);
	lv_obj_align(tabview,win,LV_ALIGN_IN_TOP_MID,0,38);

	lv_obj_t *tab1=lv_tabview_add_tab(tabview,"table");
	table_create(tab1);

	lv_obj_t *tab2=lv_tabview_add_tab(tabview,"chart");
	chart_create(tab2);
}

