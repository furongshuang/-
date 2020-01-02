#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"
#include "sql.c"
typedef struct{
      int id;
      char *title;
      char *content_at;
}Message;
 


 int  main (){
      sqlite3  *db=NULL;
      int res =sqlite3_open("cms.db",&db);
      if(res !=0){
          printf("open db fail\n");
          return -1;
          //插入
      //     Message message = {0,"hello","world","2019-12-30"};
      //     insert(db,message);
          //修改
      //     Message message ={0,"hello","world","2019-12-30"};
      //     insert(db,message);
        //删除
      //    delete(db,3);
        //查询
          select(db);
          //关闭数据库
          sqlite_close(db);
          return 0;
      }
 }

