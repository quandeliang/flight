#include"../kernellist/doublelist.h"

#define del_val_size 10
struct list_head *del_val[del_val_size];

void add_flightifno(P_doubledata h){


		  system("clear");
      printf("***********************************************\n");
      printf("*                                             *\n");
      printf("*                                             *\n");
      printf("*          ");
      printf(LIGHT_RED"Add flight information"NONE);
      printf("             *\n");
      printf("*                                             *\n");
      printf("*                                             *\n");
      printf("*                                             *\n");
      printf("***********************************************\n");
		  create_doublelist(h);

}

bool select_part(int* part){

      system("clear");
      printf("***********************************************\n"NONE);
      printf("*                                             *\n"NONE);
      printf("*         "NONE);
      printf(LIGHT_RED"Plsease select function"NONE);
      printf("             *\n"NONE);
      printf("*                                             *\n"NONE);
      printf("*         1: Add flight information           *\n"NONE);
      printf("*         2: Show flight information          *\n"NONE);
      printf("*         3: Search flight information        *\n"NONE);
      printf("*         4: Delete flight information        *\n"NONE);
      printf("*         5: Exit                             *\n"NONE);
      printf("*                                             *\n"NONE);
      printf("*                                             *\n");
      printf("***********************************************\n"NONE);
      
      printf("Please input any valid value(1-5):");
      
      bool ret;
      ret=scanf("%d",part);
      while(getchar()!='\n');

      return ret;
}

void show_flightifno(P_doubledata h){

      
      system("clear");
      if(empty_doublelist(h)) {
      printf("\n                                    Sorry!None flight information!\n");
      goto loop1;
      }
      printf("*****************************************< ");
      printf(LIGHT_RED"Flight Information"NONE);
      printf(" >*************************************\n");
      //sort_doublelist(h);
      show_doublelist(h);
loop1:
      printf("\n                                              < Enter >         \n\n");
      while(getchar()!='\n');

}
void search_result(P_doubledata h){
      
      
      int select;

      system("clear");
      if(empty_doublelist(h)) {
      printf("\n                                    Sorry!None flight information!\n");
      goto loop1;
      }

      printf("***********************************************\n");
      printf("*                                             *\n");
      printf("*          ");
      printf(LIGHT_RED"Plsease select keyword"NONE);
      printf("             *\n");
      printf("*                                             *\n");
      printf("* 1:number   2:startadress    3:arriveaddress *\n");
      printf("* 4:date     5:type           6:starttime     *\n");
      printf("* 7:arrivetime                8:price         *\n");
      printf("*                                             *\n");
      printf("*               0:return                      *\n");
      printf("*                                             *\n");
      printf("***********************************************\n");
      printf("Please input any valid value(1-9):");
      scanf("%d",&select);
      while(getchar()!='\n');
      if(select>8||select<=0)return;
      

		  if(!search_doublelist(h,select,del_val)){
		  printf("\n                                 !This keyword is not exit!\n");}
     
      while(getchar()!='\n');
loop1:
      printf("\n                                            < Enter >   \
		  \n\n");

      while(getchar()!='\n');

}
void after_del_show(P_doubledata h,struct list_head **del_val,int nu){
      
      int i;
      system("clear");
      printf("*****************************************< ");
      printf(LIGHT_RED"Flight Information"NONE);
      printf(" >*************************************\n");
      for(i=0;i<nu;i++)
	    oneshow_doublelist(h,del_val[i],i+1);

}

void del_flightifno(P_doubledata h){

      
      int select;

      system("clear");
      if(empty_doublelist(h)) {
      printf("\n                                    Sorry!None flight information!\n");
      goto loop1;
      }
      printf("*****************************************< ");
      printf(LIGHT_RED"Flight Information"NONE);
      printf(" >*************************************\n");
      show_doublelist(h);	    
      printf("***********************************************\n");
      printf("*                                             *\n");
      printf("*          ");
      printf(LIGHT_RED"Plsease select keyword"NONE);
      printf("             *\n");
      printf("*                                             *\n");
      printf("* 1:number   2:startadress    3:arriveaddress *\n");
      printf("* 4:date     5:type           6:starttime     *\n");
      printf("* 7:arrivetime                8:price         *\n");
      printf("*                                             *\n");
      printf("*               0:return                      *\n");
      printf("*                                             *\n");
      printf("***********************************************\n");


      printf("Please input any valid value(1-9):");
      scanf("%d",&select);
      while(getchar()!='\n');
      if(select>=9||select<1)return;
      
      //system("clear");

		  if(!search_doublelist(h,select,del_val)){
		  printf("\n                                      !This keyword is not exit!\n");
		  //fflush(stdin);
		  while(getchar()!='\n');
		  goto loop1;
		}
      int del_nu,i=0;
      char ch,cmp;

      for(del_nu=0;del_nu<del_val_size;del_nu++)
      if(del_val[del_nu]!=NULL) i++;
      del_nu=i;

 while(1) {


      while(1){

      printf("Please input delete flightifno NO.:");
      //fflush(stdin);
      while(getchar()!='\n');
      
      if(scanf("%d",&select)==0||(select>(del_nu+1))||(select<0)){
	    printf("Error!Pleast try again!\n");
      }
      else 
	    break;
      
      }

      printf("Are you sure to delete?(y\\n)\n");
      while(getchar()!='\n'); 
      scanf("%c",&ch);

      if(ch=='Y'||ch=='y'){
      list_del(del_val[select-1]);
      //free(del_val[select-1]);
      printf("No. %d flight information is deleted!\n",select);
      i--;
      
      for(cmp=select-1;cmp<del_nu-1;cmp++)
	    del_val[cmp]=del_val[cmp+1];
	    del_val[cmp]=NULL;
	    del_nu--;
      }
     
      if(i<=0) break;
      else {
	    printf("Do you want to continue delete?(y/n)\n");
	   while(getchar()!='\n'); 
	    scanf("%c",&ch);

	    if(ch=='Y'||ch=='y') after_del_show(h,del_val,del_nu);
	    else break;
     }
   } 
     
      while(getchar()!='\n');
loop1:
      printf("\n                                              < Enter >   \
		  \n\n");

      while(getchar()!='\n');


}
void welcome(void){

      system("clear");
      printf(back4"***********************************************\n"NONE);
      printf(back4"*                                             *\n"NONE);
      printf(back4"*                                             *\n"NONE);
      printf(back4"*                                             *\n"NONE);
      printf(back4"*         "NONE);
      printf(back4"WELCOME TO DiaoZhaTian"NONE);
      printf(back4"              *\n"NONE);
      printf(back4"*                                             *\n"NONE);
      printf(back4"*                                             *\n"NONE);
      printf(back4"*                                             *\n"NONE);
      printf(back4"***********************************************\n"NONE);
      
      printf("\n                 < Enter >   \
		  \n\n");

      while(getchar()!='\n');
      
}
void byebye(){

      system("clear");
      //printf("Thinks for your use!\n");
      printf(back6"************* Thinks for your use! ************\n"NONE);
      printf(back6"*                                             *\n"NONE);
      printf(back6"*                                             *\n"NONE);
      printf(back6"*                                             *\n"NONE);
      printf(back6"*                   BYEBYE                    *\n"NONE);
      printf(back6"*                                             *\n"NONE);
      printf(back6"*                   ~    ~                    *\n"NONE);
      printf(back6"*                      ~                      *\n"NONE);
      printf(back6"*                                             *\n"NONE);
      printf(back6"*                                             *\n"NONE);
      printf(back6"***************** Good lucky! *****************\n"NONE);
}
int main(void){

      welcome();
      int part;

      P_doubledata h;
      initadress(&h);

      for(part=0;part<del_val_size;part++)
	    del_val[part]=NULL;
      
      for(;;){
      
      
      
      fflush(stdin); 
      //while(getchar()!='\n');
      if( (select_part(&part)) && (part>=1&&part<=4) ){
      switch(part){
      
	    case 1:
		  add_flightifno(h);
		  sort_doublelist(h);
		  break;
	    case 2:
		  show_flightifno(h);
		  break;
	    case 3:
		  search_result(h);
		  break;
	    case 4:
		  del_flightifno(h);
		  break;
	    default:
		  break;
      }
      }
      else {
		  char ch;
		  if(part==5){
		  printf("Are you sure to exit program?(y/n)\n");
		  fflush(stdin); 
		  scanf("%c",&ch);

		  if(ch=='N'||ch=='n') ;
		  else{
		  printf("Thinks for your use!\n");
		  break;
		  }
		  }else{
		  printf("Are you want to exit program?(y/n)\n");
		  fflush(stdin); 
		  scanf("%c",&ch);

		  if(ch=='N'||ch=='n') ;
		  else{
		  byebye();
		  break;
		  
		  }
		  }
      }
      }
    return 0;


}



