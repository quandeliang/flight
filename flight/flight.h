#ifndef __FLIGHT_H__
#define __FLIGHT_H__


typedef struct flight{

      char number[18];
      char staddress[18];
      char arraddress[18];
      char date[12];
      char type[8];
      char stime[8];
      char atime[8];
      float price;
}flight_data,*pflight_data;


//extern void create_flightifno(pflight_data *f);
#endif
