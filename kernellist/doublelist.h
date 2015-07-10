#ifndef __DOUBLELIST_H__
#define __DOUBLELIST_H__

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"list.h"
#include"print.h"
#include"../flight/flight.h"
#include"../file/file.h"


#define OffsetSize(h) \
(char)((char*)&h->list-(char*)h)

#define get_data(type,head,now,data)\
      (((type )((char *)now-OffsetSize(head)) )->data)


typedef flight_data doublelist_datatype;

typedef struct DATA{

       doublelist_datatype data_list;
       struct list_head list;
}Doubledata,*P_doubledata;


extern void initadress(P_doubledata *I);
extern void create_doublelist(P_doubledata h);
extern void sort_doublelist(P_doubledata h);
extern void show_doublelist(P_doubledata h);

extern void insert_doublelistB(struct list_head *in,struct list_head *new);
extern void insert_doublelistF(struct list_head *new,struct list_head *in);
extern bool search_doublelist(P_doubledata h,int select,struct list_head **del_val);
extern void oneshow_doublelist(P_doubledata h,struct list_head *p,int nu);
extern bool empty_doublelist(P_doubledata h1);

#endif
