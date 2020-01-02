#include<stdio.h>
#include<stdlib.h>
#include"sqlite3.h"
//循环li 数据库有几条数据就循环几次 中间页
int callback(void *para,int col_count,char **col_value,char **col_name){
          printf("<li><a href='news2.cgi?%s'>%s</a></li>\n",col_value[0],col_value[1]);
        return 0;
}

int seet(sqlite3 *db){
    printf("<ul>");
    char *sql ="SELECT * FROM news";
    char *err;
    if(0!= sqlite3_exec(db,sql,callback,NULL,&err)){
        printf("%s\n",err);
        exit(-1);
    }
    printf("</ul>");
    return 0;

    int main(){

        printf("Content-Type:text/html\n\n");
    }
}