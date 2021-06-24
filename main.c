#include"park.h"

int main() {
    show();
    Menu();
    LNode table;
    table.next = NULL;

    int choice;
    while(1) {
        printf("请输入你的选择 :\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
            printf("---进车登记---\n");
            EnCar(&table);
            break;
            }
            case 2: {
                printf("---出车登记---\n");
                OutCar(&table);
                break;
            }
            case 3: {
                display(&table);
                break;
            }
            case 4: {
                exit(0);
                break;
            }
            default: {
            printf("无效选择，请重新选择！\n");
            break;
            }      
        }
    }
    return 0;
}