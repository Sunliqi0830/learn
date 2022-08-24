#include "contact.h"

int main()
{

    welcome();
    //创建新链表
    linklist *contact=LinklistCreate();
    //printf("contact 1111111111\n");
	//通讯录信息读取
	LoadContact(contact);
    //printf("contact 222222222222222222\n");
    int input = 0;
    
    do
	{
		menu();//菜单显示界面
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1://添加
            LinklistInsertTail(contact);		
			break;
		case 2://删除
            LinklistDelete(contact);			
			break;
		case 3://查找
			SearchContact(contact);
			break;
		case 4://修改
            ModifyContact(contact);			
			break;
		case 5://显示
			LinklistPrint(contact);
			break;
		case 6://清空
			ContactClear(contact);
			break;
		case 7://排序
			SortContact(contact);			
			break;
		case 8://音乐
			Music();
			break;
		case 9://会员
			VIP();
			break;
		case 0://退出
			//通讯录信息保存后退出
			SaveContact(contact);
			break;
		default:
			printf("请重新输入！\n");
			break;
		}
	} while (input);
	return 0;
}

