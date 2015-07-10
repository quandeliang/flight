#include "doublelist.h"


int main(){

     P_doubledata h;


   initadress(&h);
   create_doublelist(h);
   printf("Before:");
   show_doublelist(h);

   sort_doublelist(h);
   printf("After: ");
   show_doublelist(h);
   
  
   return 0;
}
