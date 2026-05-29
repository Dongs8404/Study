#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct{
//     int no;
//     char name[20];
//     char phoneNumber[20];
//     char eMail[30];
//     char address[50];
// }information;

// information setInfo(information info);

// int main(void)
// {
//     information info1;
//     info1 = setInfo(info1);

//     printf("%d %s %s %s %s\n", info1.no, info1.name, info1.phoneNumber, info1.eMail, info1.address);

//     return 0;
// }

// information setInfo(information info)
// {
//     info.no = 1;
//     strcpy(info.name, "DongHyeon");
//     strcpy(info.phoneNumber,"010-4845-8404");
//     strcpy(info.eMail, "sollee8404@gmail.com");
//     strcpy(info.address, "Jinju");
//     return info;
// }

// typedef struct{
//     int stdNum;
//     char name[20];
//     char address[20];
// }information;

// int main(void)
// {
//     information info;
//     information* pInfo;

//     pInfo = &info;
//     //pInfo->stdNum = 2005011198; //(*pInfo).stdNum = 2005011198;
//     //strcpy(pInfo->name, "Taewoo"); //strcpy(*info).name, "Taewoo");
//     strcpy(&(*pInfo).name[0],"Taewoo");
//     printf("%s\n", info.name);
//     printf("%s\n", pInfo -> name);

//     return 0;
// }