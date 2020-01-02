#include<stdio.h>
#include<stdlib.h>
#include"sqlite3.h"
typedef struct{
      int id;
      char *title;
      char *content;
      char *created_at;
}Message;
// 插入
int insert(sqlite3 *db,Message message){
    char *err;
    char sql[100];
    sprintf(sql,"INSERT  INTO  news (title,content,created_at) VALUES  ('%s','%s','%s')",message.title,message.content,message.created_at);
    if(0 != sqlite3_exec(db,sql,NULL,NULL,&err)){
             printf("%s\n",err);
             exit(-1);
    }
    return 0;
}
// 修改
int update(sqlite3 *db, Message message){
      char *err;
      char sql[100];
    sprintf(sql,"UPDATE news SET title = '%s' WHERE id = %d",message.title,message.id);
          if (0 !=sqlite3_exec(db, sql, NULL,NULL,&err)){
              printf("%s\n",err);
              exit(-1);
      }
      return 0;
}
//删除
int delete(sqlite3 *db, int id){
     char   *err;
     char sql[100];
     sprintf(sql,"DELETE FROM news WHERE id = %d",id);
     if(0 !=sqlite3_exec(db,sql,NULL,NULL,&err)){
          printf("%s\n",err);
          exit(-1);
     }
     return 0;
}
//查询
int callback(void *para,int col_count,char  **col_value,char  **col_name){
        //  for(int i=0; i<col_count;i++){
             printf("%s:%s:%s\n",col_name[1],col_value[2],col_value[3]);
             printf("*********************\n");
        //  }
         return 0;
}
int  seet(sqlite3 *db){
    char  *err;
    char sql[]="SELECT * FROM  news";
    if (0 !=sqlite3_exec(db, sql, callback, NULL, &err)){
        printf("%s\n",err);
        exit(-1);
    }
    return 0;
}

 int  main (){
         //打开数据库
      sqlite3  *db=NULL;
      int res =sqlite3_open("cms.db",&db);
      if(res !=0){
          printf("open db fail\n");
          return -1;
      }
          //插入
        //   Message message = {0,"你好","吗","2019-12-31"};
        //   insert(db,message);
          //修改
          // Message message ={0,"hello","world","2019-12-30"};
          // update(db,message);
        //删除
        //  delete(db,3);
        //查询
          seet(db);

          //关闭数据库
          sqlite3_close(db);
          return 0;
      
}