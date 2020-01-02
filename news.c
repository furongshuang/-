#include <stdio.h>
#include <stdlib.h>
#include "wy.c"
#include "sqlite3.h"
//首页
int main(){
       printf("Content-Type: text/html\n\n");
       char *header = "<!doctype html>"\
                                        "<html>"\
                                        "<head>"\
                                        "<meta name='viewport' centent='width=device-width'>"\
                                        "<meta charset='UTF-8'>"\
                                        "<title>新闻中心</title>"\
                                        "</head>"\
                                        "<body>";
                            printf("%s\n",header);

                            printf("<style>"\
                                             "a{color: blue;}"\
                                             "li{list-style:none;text-align:center;}"\
                                             "body{background-color:#F0FFF0}"\
                                             "</style>" );
            printf("<div style='line-height:4;color:#0000CD;background-color:#00EE00;text-align:center;'>国内新闻</div>");
       //      printf("<div style='height:500,width:500;border:1px  soid  #FF6A6A; '><p>欢迎大家</p></div>");
             sqlite3  *db=NULL;
            int res = sqlite3_open("cms.db",&db);
            if(res!=0){
                   printf("open db fail\n");
                   return -1;
            }

       seet(db);
       sqlite3_close(db);
       printf("</body></html>");
       return 0;

}