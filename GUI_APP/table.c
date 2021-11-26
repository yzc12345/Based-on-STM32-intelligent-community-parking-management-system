#include "table.h"
#include <stdio.h>

struct table1_data data_1[TABLE_ROW_CNT-1];

lv_obj_t *table1;

LV_FONT_DECLARE(my_font_16);

const uint16_t TABLE_COL_WIDTH[TABLE_COL_CNT] = {100,100,100,100,100};

lv_task_t *table_task=NULL;

lv_style_t cell2_style;
char *TABLE_CELL_VALUE[TABLE_ROW_CNT][TABLE_COL_CNT] = {
  {"序号","车牌号码","进库时间","出库时间","消费时间"},
//  {"01","1111","15:36","16:00","100"},
//	{"02","1111","15:36","16:00","100"}

};
//char *data[TABLE_COL_CNT][TABLE_ROW_CNT];//={
//{"01","1111","15:36","16:00","100"},
//{"02","1111","15:36","16:00","100"}
//};




void table_task_cb(lv_task_t * task)
{
	uint8_t i;
	for(i=0;i<TABLE_COL_CNT;i++)
	{
		lv_table_set_cell_value(table1,i+1,0,(const char*)data_1[i].num);
		lv_table_set_cell_value(table1,i+1,1,(const char*)data_1[i].name);
		lv_table_set_cell_value(table1,i+1,2,(const char*)data_1[i].time_into);
		lv_table_set_cell_value(table1,i+1,3,(const char*)data_1[i].time_out);
	}
//	for(i=0;i<TABLE_COL_CNT;i++)
//	{
//		for(j=0;j<TABLE_ROW_CNT;j++)
//		{
//			lv_table_set_cell_value(table1,i+1,j,(const char*)data[i][j]);
//		}
//	}
}

void table_create(lv_obj_t *parent)
{
	uint16_t row,col;	

	lv_style_copy(&cell2_style,&lv_style_plain_color);
	cell2_style.body.border.width = 1;
	cell2_style.body.border.color = LV_COLOR_BLACK;
	cell2_style.body.main_color = LV_COLOR_SILVER;
	cell2_style.body.grad_color = LV_COLOR_SILVER;
	cell2_style.text.color = LV_COLOR_BLACK;
	cell2_style.text.font=&my_font_16;
	
	table1=lv_table_create(parent,NULL);
	lv_table_set_col_cnt(table1,TABLE_COL_CNT);
	lv_table_set_row_cnt(table1,TABLE_ROW_CNT);
	
	for(row=0;row<TABLE_ROW_CNT;row++)
	{
		for(col=0;col<TABLE_COL_CNT;col++)
		{
			lv_table_set_col_width(table1,col,TABLE_COL_WIDTH[col]);
			lv_table_set_cell_value(table1,0,col,(const char*)TABLE_CELL_VALUE[0][col]);
			lv_table_set_cell_align(table1,row,col,LV_LABEL_ALIGN_CENTER);
			lv_table_set_cell_type(table1,0,col,2);
		}
	}

		
	lv_table_set_style(table1,LV_TABLE_STYLE_CELL2,&cell2_style);
	lv_obj_align(table1,parent,LV_ALIGN_IN_TOP_MID,0,0);
	table_task=lv_task_create(table_task_cb,1000,LV_TASK_PRIO_MID,NULL);
}

//#define TABLE_COL_CNT   5   //表格的列数
//#define TABLE_ROW_CNT   11   //表格的行数

//lv_style_t cell1_style;
//lv_style_t cell2_style;
//lv_style_t cell3_style;

////定义每一行单元格的文本内容
//const char * const TABLE_CELL_VALUE[TABLE_ROW_CNT][TABLE_COL_CNT] = {
//  {"序号","车牌号码","进库时间","出库时间","消费金额"},//第一行,作为标题行
//  {"01","1111","15:36","16:00","100"},
//	{"02","1111","15:36","16:00","100"},
////	{"03","1111","15:36","16:00","100"},
////	{"04","1111","15:36","16:00","100"},
////	{"05","1111","15:36","16:00","100"},
////	{"06","1111","15:36","16:00","100"},
////	{"07","1111","15:36","16:00","100"},
////	{"08","1111","15:36","16:00","100"},
////	{"09","1111","15:36","16:00","100"},
////	{"10","1111","15:36","16:00","100"}
//};
////每一列的宽度
//const uint16_t TABLE_COL_WIDTH[TABLE_COL_CNT] = {160,160,160,160,160};

//void table_create(lv_obj_t *parent)
//{
//	
//	uint16_t row,col;	
//	//1.创建样式
//	//1.1 创建第一种单元格样式,用来修饰普通数据单元格
//	lv_style_copy(&cell1_style,&lv_style_plain);
//	cell1_style.body.border.width = 1;
//	cell1_style.body.border.color = LV_COLOR_BLACK;
//	//1.2 创建第二种单元格样式,用来修饰标题行中的单元格
//	lv_style_copy(&cell2_style,&lv_style_plain_color);
//	cell2_style.body.border.width = 1;
//	cell2_style.body.border.color = LV_COLOR_BLACK;
//	cell2_style.body.main_color = LV_COLOR_SILVER;//银色的背景
//	cell2_style.body.grad_color = LV_COLOR_SILVER;
//	cell2_style.text.color = LV_COLOR_BLACK;
//	cell2_style.text.font=&my_font_30;
//	
//	lv_obj_t *table1=lv_table_create(parent,NULL);
//	lv_table_set_col_cnt(table1,TABLE_COL_CNT);//设置表格的总列数
//	lv_table_set_row_cnt(table1,TABLE_ROW_CNT);//设置表格的总行数
//	//设置每一列的宽度以及标题行的文本对齐方式和单元格类型
//	for(col=0;col<TABLE_COL_CNT;col++)
//	{
//		lv_table_set_col_width(table1,col,TABLE_COL_WIDTH[col]);//设置每一列的宽度
//		lv_table_set_cell_type(table1,0,col,2);//设置为第二种单元格类型
//	}
//		//设置所有单元格的文本内容
//	for(row=0;row<TABLE_ROW_CNT;row++)
//	{
//		for(col=0;col<TABLE_COL_CNT;col++)
//		{
//			lv_table_set_cell_value(table1,row,col,(const char*)TABLE_CELL_VALUE[row][col]);//设置文本内容
//			lv_table_set_cell_align(table1,row,col,LV_LABEL_ALIGN_CENTER);//文本内容居中对齐
//		}
//	}
//	lv_table_set_style(table1,LV_TABLE_STYLE_BG,&lv_style_transp_tight);//设置表格的背景样式,为透明
//	lv_table_set_style(table1,LV_TABLE_STYLE_CELL1,&cell1_style);//设置第一种单元格的样式
//	lv_table_set_style(table1,LV_TABLE_STYLE_CELL2,&cell2_style);//设置第二种单元格的样式
//	lv_obj_align(table1,parent,LV_ALIGN_IN_TOP_LEFT,0,0);//设置表格与屏幕居中对齐
//}
