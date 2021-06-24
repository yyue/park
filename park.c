#include"park.h"

int show() {
    printf("***************************\n");
    printf("**Welcome to the ParkSys!**\n");
    printf("***************************\n");
    return 0;
}

int Menu() {
	printf("***************************\n\n");
	printf("       1.进车登记          \n");
	printf("       2.出车登记          \n");
    printf("       3.查询场内车辆信息    \n");
    printf("       4. 退出             \n");
	printf("       收费标准:每秒2元!     \n\n");
	printf("***************************\n\n");
    return 0;
}

/*获取时间*/
int settime(LNode *table, time_t tm) {
    struct tm *pt;
    time(&tm);
    pt = localtime(&tm);
    table->month = pt->tm_mon + 1;
    table->day = pt->tm_mday;
    table->hour = pt->tm_hour;
    table->min = pt->tm_min;
    table->sec = pt->tm_sec;
    return 0;
}

int EnCar(LNode *table) {
    time_t tm;
    struct tm *ptime;   

    char id[10];
    printf("请输入你的车牌号：\n");
	scanf("%s",id);

    while (table->next != NULL) {
        table = table->next;
    }
    LNode *pNode = (LNode*)malloc(sizeof(LNode));

	time(&tm);
	pNode->start = tm;
	ptime = localtime(&tm);
    settime(pNode, tm);
	printf("停车时间是:%d月%d日%d:%d:%d\n", pNode->month, pNode->day, pNode->hour, pNode->min, pNode->sec);

    if (table == NULL) {
        return P_FAIL;
    }
    strcpy(pNode->car_id, id);
    table->next = pNode;
    pNode->next = NULL;
    printf("停车成功！\n\n");
    
    return P_OK;
}

int display(LNode *table) {
    if (table == NULL) {
        return P_FAIL;
    }
    printf("--------park message--------\n");
    LNode *pNode = table->next;
    while (pNode != NULL) {
        printf("车牌号:%s  停车时间:%d月%d日%d:%d:%d\n",pNode->car_id, pNode->month, pNode->day, pNode->hour, pNode->min, pNode->sec);
        pNode = pNode->next;
    }
    return P_OK;;
}

int OutCar(LNode *table) {
    long int p_time;
    time_t tm;
    struct tm *ptime;
    LNode *pPrev = table;
    LNode *pNode = table->next;
    
    char id[10];
    printf("请输入你要开走的车牌号：\n");
	scanf("%s", id);

	time(&tm);
	pNode->end = tm;
	ptime = localtime(&tm);
    settime(pNode, tm);
    
    if (table == NULL) {
        return P_FAIL;
    }
    while (pNode != NULL) {
        if (strcmp(pNode->car_id, id)  == 0) {       
            LNode *pCur = pNode;

            printf("离开时间:%d月%d日%d:%d:%d\n",pNode->month, pNode->day, pNode->hour, pNode->min, pNode->sec);   
            p_time = pNode->end - pNode->start;
            printf("停车时长：%ld s\n", p_time); 
            printf("停车费用：%ld 元\n\n", p_time*2);

            pPrev->next = pNode->next;
            if(pCur != NULL) {
                free(pCur);
                pCur = NULL;
            }    
            return P_OK; 
        }
        pPrev = pNode;
        pNode = pNode->next;
        printf("成功开走了这辆车!\n");    
    }
    return P_FAIL;
}