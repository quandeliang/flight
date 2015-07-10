#include"doublelist.h"


void initadress(P_doubledata *I){

   *I=(P_doubledata)malloc(sizeof(Doubledata));
   if(*I==NULL){
   perror("Failed to allocate storage\n");
   exit(1);
   }

   INIT_LIST_HEAD(&(*I)->list); 
   
}
//#if 0

//#endif
void create_doublelist(P_doubledata h){

  P_doubledata c;
  char input,buf[MY_BUFSIZ];
  int i=0;
  struct list_head *p;
  //scanf("%d",&input); 
  for(p=h->list.next,i=0;p!= &h->list;p=p->next,i++);

  while('0'){

  printf("\n<   Please ipnut NO. %d flight information   >\n",++i);
   
  c=(P_doubledata)malloc(sizeof(Doubledata));
   if(c==NULL){
   perror("Failed to allocate storage\n");
   exit(1);
   }
   bzero(buf,MY_BUFSIZ);
   sprintf(buf,"%d: ",i);
   printf("Pease input flight number:");
   scanf("%s",c->data_list.number);
   strcat(buf,c->data_list.number);
   strcat(buf,"\t");
   
   printf("Pease input flight startaddaress:");
   scanf("%s",c->data_list.staddress);
   strcat(buf,c->data_list.staddress);
   strcat(buf,"\t");
   
   printf("Pease input flight arraiveaddress:");
   scanf("%s",c->data_list.arraddress);
   strcat(buf,c->data_list.arraddress);
   strcat(buf,"\t");
   
   printf("Pease input flight date:");
   scanf("%s",c->data_list.date);
   strcat(buf,c->data_list.date);
   strcat(buf,"\t");

   printf("Pease input flight type:");
   scanf("%s",c->data_list.type);
   strcat(buf,c->data_list.type);
   strcat(buf,"\t");

   printf("Pease input flight starttime(hour:minute):");
   scanf("%s",c->data_list.stime);
   strcat(buf,c->data_list.stime);
   strcat(buf,"\t");
   
   //fgets(c->data_list.stime,strlen(c->data_list.stime),stdin);

   printf("Pease input flight arrivetime(hour:minute):");
   fflush(stdin);
   //fgets(c->data_list.atime,strlen(c->data_list.atime),stdin);
   scanf("%s",c->data_list.atime);
   strcat(buf,c->data_list.atime);
   strcat(buf,"\t");

   printf("Pease input flight price:");
   scanf("%f",&c->data_list.price);
   strcat(buf,"\n");
   printf("\n");
  //insert_doublelistF(c,h);
   my_write_file(buf);
   list_add_tail(&c->list,&h->list);
   //if(i==0)  h->list.next=&c->list;
      show_doublelist(h);
      printf("Continue to input flight information?(Y/N)\n");
      while(getchar()!='\n');
      scanf("%c",&input);
	    while(getchar()!='\n');
      if(input=='Y'||input=='y'); 
      else break;

  }


}

void sort_doublelist(P_doubledata h){

      struct list_head *p=h->list.next,*q;
      struct list_head *new1,*new2;
      int start1,start2,s1,s2;

      INIT_LIST_HEAD(&h->list);  //break kernellist

      while(p!=&h->list){
       
	    q=p;
	    p=p->next;

	    for(new1=&h->list,new2=h->list.next;new2!=&h->list;new1=new2,new2=new2->next){
		  
	    sscanf((char*)get_data(P_doubledata,h,new2,data_list.stime),"%d:%d",&start1,&start2 );//10:30
	    sscanf((char*)get_data(P_doubledata,h,q,data_list.stime),"%d:%d",&s1,&s2);//11:30
			
			if((start1*100+start2)>(s1*100+s2))
			break;
	    }
		  //list_move(q,new1);
		  //list_add_tail(q,new2);
		  list_add(q,new1);

      
      }

}

void del_doublelist(struct list_head *del){
       
      del->prev->next=del->next;
      del->next->prev=del->prev;
  
}

void insert_doublelistB(struct list_head *in,struct list_head *new){
   
      new->next=in->next;
      new->prev=in;
      in->next->prev=new;
      in->next=new;

}

void insert_doublelistF(struct list_head *new,struct list_head *in){

      new->next=in;
      new->prev=in->prev;
      in->prev->next=new;
      in->prev=new;
}

void show_doublelist(P_doubledata h){
 

   struct list_head *p;
   int i=1;

  /*P_doubledata mypos;
     list_for_each_entry(mypos,&h->list,list){
     printf("%s\t",mypos->data_list.number);
     printf("%s\t",mypos->data_list.staddress);
     printf("%s\t\t",mypos->data_list.arraddress);
     printf("%s\t",mypos->data_list.date);
     printf("%s\t",mypos->data_list.type);
     printf("%d\t",mypos->data_list.stime);
     printf("%d\t",mypos->data_list.atime);
     printf("\t%.2f\n",mypos->data_list.price);
     printf("%d ", mypos ->data_list);
     }*/
  

   printf("NO.\tnumber\tstaddress\tarraddress\tdate\ttype\tstarttime\tarrivetime\tprice\n");
   for(p=h->list.next;p!= &h->list;p=p->next){
	 oneshow_doublelist(h,p,i++);
  }
     
  printf("*****************************************************************************************************\n");
}
void oneshow_doublelist(P_doubledata h,struct list_head *p,int nu){

     printf(YELLOW"%d\t"NONE,nu);
     printf(BROWN"%s\t"NONE,get_data(P_doubledata,h,p,data_list.number));
     printf(BROWN"%s\t",get_data(P_doubledata,h,p,data_list.staddress));
     printf("%s\t",get_data(P_doubledata,h,p,data_list.arraddress));
     printf("%s\t",get_data(P_doubledata,h,p,data_list.date));
     printf("%s\t",get_data(P_doubledata,h,p,data_list.type));
     printf("%s\t",get_data(P_doubledata,h,p,data_list.stime));
     printf("%s\t",get_data(P_doubledata,h,p,data_list.atime));
     printf("%.2f\n"NONE,get_data(P_doubledata,h,p,data_list.price));

}
bool search_doublelist(P_doubledata h,int select,struct list_head **del_val){

      
      bool exist_flag=false;
      char key[20];
      int nu=1;
      float key_price;
      struct list_head *p;

      switch(select) {
      
	    case 1:
		  printf("Please input number:");
		  scanf("%s",key);

      system("clear");
      printf("*****************************************< ");
      printf(LIGHT_RED"Search Information"NONE);
      printf(" >*************************************\n");
   printf("NO.\tnumber\tstaddress\tarraddress\tdate\ttype\tstarttime\tarrivetime\tprice\n");
       for(p=h->list.next;p!= &h->list;p=p->next){
	    if(!strcmp(key,get_data(P_doubledata,h,p,data_list.number))){
		  exist_flag=true;
		  oneshow_doublelist(h,p,nu++);
		  del_val[nu-2]=p;
	    }
       }
		  break;
	    
	    case 2:
		  printf("Please input startaddress:");
		  scanf("%s",key);

      system("clear");
      printf("*****************************************< ");
      printf(LIGHT_RED"Search Information"NONE);
      printf(" >*************************************\n");
   printf("NO.\tnumber\tstaddress\tarraddress\tdate\ttype\tstarttime\tarrivetime\tprice\n");
       for(p=h->list.next;p!= &h->list;p=p->next){
	    if(!strcmp(key,get_data(P_doubledata,h,p,data_list.staddress))){
		  exist_flag=true;
		  oneshow_doublelist(h,p,nu++);
		  del_val[nu-2]=p;
	    }
       }
		  break;
      
	    case 3:
		  printf("Please input arriveaddress:");
		  scanf("%s",key);

      system("clear");
      printf("*****************************************< ");
      printf(LIGHT_RED"Search Information"NONE);
      printf(" >*************************************\n");
   printf("NO.\tnumber\tstaddress\tarraddress\tdate\ttype\tstarttime\tarrivetime\tprice\n");
       for(p=h->list.next;p!= &h->list;p=p->next){
	    if(!strcmp(key,get_data(P_doubledata,h,p,data_list.arraddress))){
		  exist_flag=true;
		  oneshow_doublelist(h,p,nu++);
		  del_val[nu-2]=p;
	    }
       }
		  break;

	    case 4:
		  printf("Please input date:");
		  scanf("%s",key);

      system("clear");
      printf("*****************************************< ");
      printf(LIGHT_RED"Search Information"NONE);
      printf(" >*************************************\n");
   printf("NO.\tnumber\tstaddress\tarraddress\tdate\ttype\tstarttime\tarrivetime\tprice\n");
       for(p=h->list.next;p!= &h->list;p=p->next){
	    if(!strcmp(key,get_data(P_doubledata,h,p,data_list.date))){
		  exist_flag=true;
		  oneshow_doublelist(h,p,nu++);
		  del_val[nu-2]=p;
	    }
       }
		  break;

	    case 5:
		  printf("Please input type:");
		  scanf("%s",key);

      system("clear");
      printf("*****************************************< ");
      printf(LIGHT_RED"Search Information"NONE);
      printf(" >*************************************\n");
   printf("NO.\tnumber\tstaddress\tarraddress\tdate\ttype\tstarttime\tarrivetime\tprice\n");
       for(p=h->list.next;p!= &h->list;p=p->next){
	    if(!strcmp(key,get_data(P_doubledata,h,p,data_list.type))){
		  exist_flag=true;
		  oneshow_doublelist(h,p,nu++);
		  del_val[nu-2]=p;
	    }
       }
			break;

	    case 6:
		  printf("Please input starttime:");
		  scanf("%s",key);

      system("clear");
      printf("*****************************************< ");
      printf(LIGHT_RED"Search Information"NONE);
      printf(" >*************************************\n");
   printf("NO.\tnumber\tstaddress\tarraddress\tdate\ttype\tstarttime\tarrivetime\tprice\n");
       for(p=h->list.next;p!= &h->list;p=p->next){
	    if(!strcmp(key,get_data(P_doubledata,h,p,data_list.stime))){
		  exist_flag=true;
		  oneshow_doublelist(h,p,nu++);
		  del_val[nu-2]=p;
	    }
       }
			break;

	    case 7:
		  printf("Please input arrivetime:");
		  scanf("%s",key);

      system("clear");
      printf("*****************************************< ");
      printf(LIGHT_RED"Search Information"NONE);
      printf(" >*************************************\n");
   printf("NO.\tnumber\tstaddress\tarraddress\tdate\ttype\tstarttime\tarrivetime\tprice\n");
       for(p=h->list.next;p!= &h->list;p=p->next){
	    if(!strcmp(key,get_data(P_doubledata,h,p,data_list.atime))){
		  exist_flag=true;
		  oneshow_doublelist(h,p,nu++);
		  del_val[nu-2]=p;
	    }
       }
			break;

	    case 8:
		  printf("Please input price:");
		  scanf("%f",&key_price);

      system("clear");
      printf("*****************************************< ");
      printf(LIGHT_RED"Search Information"NONE);
      printf(" >*************************************\n");
   printf("NO.\tnumber\tstaddress\tarraddress\tdate\ttype\tstarttime\tarrivetime\tprice\n");
       for(p=h->list.next;p!= &h->list;p=p->next){
	    if(key_price==get_data(P_doubledata,h,p,data_list.price)){
		  exist_flag=true;
		  oneshow_doublelist(h,p,nu++);	
		  del_val[nu-2]=p;
	    }	
       }  
			 break;
      }
      return exist_flag;
}
bool empty_doublelist(P_doubledata h1){

     if(h1->list.prev==&h1->list)
	   return true;
     else 
	   return false;
}
