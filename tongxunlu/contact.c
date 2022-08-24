#include "contact.h"



void welcome()
{
	printf("  ٩(๑^o^๑)۶   ٩(๑^o^๑)۶   welcome!  ٩(๑^o^๑)۶  ٩(๑^o^๑)۶\n");
}

void menu()
{
    printf("╔═══════════════════════════════════════════════════════╗\n");
	printf("╠═════════════   ☏ 欢迎来到拉胯通讯录 ☏   ══════════════╣\n");
	printf("╠══════════════════   (ง •̀_•́)ง加油    ══════════════════╣\n");
	printf("╠═══════         1.添加          2.删除         ════════╣\n");
	printf("╠═══════         3.查找          4.修改         ════════╣\n");
	printf("╠═══════         5.显示          6.清空         ════════╣\n");
	printf("╠═══════         7.排序          8.音乐         ════════╣\n");
	printf("╠═══════         9.会员          0.退出         ════════╣\n");
	printf("╚═══════════════════════════════════════════════════════╝\n");

}


//按id查找
linklist *FindId(linklist *contact,char* id)
{
    linklist *q=contact->next;
    while(q->next != NULL)
    {
        if(strcmp(q->data.id,id)==0)
        {
            return q;
            
        }
        q=q->next;
        
    }
    if (q->next == NULL)
    {
        if(strcmp(q->data.id,id)==0)
        {
            return q;
        }
        else
        {
            printf("\n查无此人\n");
        }
    }
    
}


//按名字查找
linklist *FindName(linklist *contact,char* name)
{
    linklist *q2=contact->next;
    while(q2->next != NULL)
    {
        if(strcmp(q2->data.name,name)==0)
        {
            return q2;
        }
        q2=q2->next;
        
    }
    if (q2->next == NULL)
    {
        if(strcmp(q2->data.name,name)==0)
        {
            return q2;
        }
        //都没找到
        else
        {
            printf("\n查无此人\n");
        }
    }
    
}


//通讯录链表的建立
void *LinklistCreate()//通讯录链表的建立 
{ 

    linklist *contact =(linklist *)malloc(sizeof(linklist));
    contact->next=NULL;
    return contact;
}


//数据的插入（尾插法）
void LinklistInsertTail(linklist *contact)
{  
    putchar('\n');
    //开辟空间并赋值
    linklist *tmp = (linklist *)malloc(sizeof(linklist));
    printf("请输入ID:");
    scanf("%s",tmp->data.id);
    printf("输入姓名:");
    scanf("%s",tmp->data.name);
    printf("电话号码:");
    scanf("%s",tmp->data.telnum);
    tmp->next = NULL;

    linklist *p = contact;
   //找到最后一个结点，循环结束，p此时指向最后一个结点的地址
   while(p->next != NULL) 
   {
        p = p->next;
   }
    tmp->next = p->next;
    p->next = tmp;
    return;
}


//判空
bool LinklistIsEmpty(linklist *contact)
{
    return contact->next == NULL ? 1 : 0;
}


//删除
void LinklistDelete(linklist *contact)
{
    if(LinklistIsEmpty(contact))
    {
        printf("通讯录为空，删除失败\n");
    }
    else
    {   
        char id[MAX_ID];
        char name[MAX_NAME];
        int input = 0;

        do
        {
            printf(" 1.按照id删除   2.按照姓名删除   0.返回\n");
            printf("请选择：");
		    scanf("%d", &input);
            switch (input)
            {
                //按照ID删除
            case 1:
                printf("输入要删除的用户的id:");
		        scanf("%s", id);
                linklist *Delid=FindId(contact,id);
                while(contact->next != Delid)
                {
                    contact = contact->next;
                }
                linklist *p;
                p = contact->next;
                contact->next = p->next;
                free(p);
                p = NULL;
                return;


                //按照姓名删除
            case 2:
                printf("输入要删除的用户的name:");
		        scanf("%s", name);
                linklist *Delname=FindName(contact,name);
                while(contact->next != Delname)
                {
                    contact = contact->next;
                }
                linklist *pq;
                pq = contact->next;
                contact->next = pq->next;
                free(pq);
                pq = NULL;
                return;
                
            case 0:
                return;
            default:
                printf("你特么绝对是来捣乱的！！！");
                return;
            }
        } while (input);
    }
}


//遍历通讯录
void LinklistPrint(linklist *contact)
{   

    if(LinklistIsEmpty(contact))
    {
        printf(" 通讯录为空 \n");
        return;
    }
    else
    {
        //定义一个指针遍历保存第一个有数据的结点的地址
        linklist *p = contact->next;
        //循环遍历单链表，直到p的指针域为空，结束循环遍历
        while(p->next != NULL)
        {
            printf("%s  ",p->data.id);
            printf("%s  ",p->data.name);
            printf("%s  ",p->data.telnum);
            putchar('\n');
            //p指向下一个结点（p保存下一个结点的地址）
            p = p->next;
        }
        //此时p为最后一个结点的地址，输出最后一个结点的保存的数据
        printf("%s  ",p->data.id);
        printf("%s  ",p->data.name);
        printf("%s  ",p->data.telnum);
        putchar('\n');
    }
    putchar('\n');
}


//查找
void SearchContact(linklist *contact)
{   
    char id[MAX_ID];
	char name[MAX_NAME];
    int input = 0;
    int ret;
    do
    {
        printf("1.按照ID查找   2.按照姓名查找 0.******返回\n");
		printf("请选择：");
		scanf("%d", &input);

		switch (input)
        {
        case 1:
			printf("请输入你要查找的ID:");
			scanf("%s", id);
            //定义一个指针遍历保存第一个有数据的结点的地址
            linklist *p2 = contact->next;
            ret = strcmp(p2->data.id, id);
            while(p2->next != NULL)
            {   
                if(ret == 0)
                {
                    printf("查找成功\n");
                    printf("%s  ",p2->data.id);
                    printf("%s  ",p2->data.name);
                    printf("%s  ",p2->data.telnum);
                    putchar('\n');
                    putchar('\n');
                    return;               
                }
                p2 = p2->next;
                ret = strcmp(p2->data.id, id);  
            }
            if(p2->next == NULL && ret == 0)
            {
                printf("查找成功\n");
                printf("%s  ",p2->data.id);
                printf("%s  ",p2->data.name);
                printf("%s  ",p2->data.telnum);
                putchar('\n');
                putchar('\n');
                return;
            }
            else
            {
                printf("你特么绝对是来捣乱的！！！"); 
                putchar('\n');
                return;  
            }                        
            
            
            


        case 2:
			printf("请输入你要查找的name:");
			scanf("%s", name);
            //定义一个指针遍历保存第一个有数据的结点的地址
            linklist *p3 = contact->next;
            ret = strcmp(p3->data.name, name);
            while(p3->next != NULL)
            {   
                if(ret == 0)
                {
                    printf("查找成功\n");
                    printf("%s  ",p3->data.id);
                    printf("%s  ",p3->data.name);
                    printf("%s  ",p3->data.telnum);
                    putchar('\n');
                    putchar('\n');
                    return;               
                }
                p3 = p3->next;
                ret = strcmp(p3->data.name, name);  
            }
            if(p3->next == NULL && ret == 0)
            {
                printf("查找成功\n");
                printf("%s  ",p3->data.id);
                printf("%s  ",p3->data.name);
                printf("%s  ",p3->data.telnum);
                putchar('\n');
                putchar('\n');
                return;
            }
            else
            {
                printf("你特么绝对是来捣乱的！！！"); 
                putchar('\n');
                return;  
            }
        }
    } while (input);
    
}


//修改
void ModifyContact(linklist *contact)
{
    char id[MAX_ID];
    int ret;
    int input = 0;
    printf("请输入你要修改联系人的ID:");
    scanf("%s", id);
    linklist *Re=FindId(contact,id);  
    printf("═════════联系人修改════════\n");
	printf(" ═══ 1.ID      2.姓名 ═══\n");
	printf(" ═══ 3.电话    4.返回 ═══\n");
	printf("═══════════════════════════\n");
	printf("请输入你要修改的选项");


    scanf("%d", &input);
    switch (input)
	{
	case 1:
		printf("id:");
		scanf("%s", Re->data.id);
		break;
	case 2:
		printf("姓名：");
		scanf("%s", Re->data.name);
		break;
	case 3:
		printf("电话：");
		scanf("%s", Re->data.telnum);
		break;
	case 0:
		break;
		default:
		printf("你特么绝对是来捣乱的！！!\n");
		break;
	}
}


//清空
void ContactClear(linklist *contact)
{
    if(LinklistIsEmpty(contact))
    {
        printf("链表为空!\n");
        return;
    }
    linklist *p,*q;
    p = contact->next;
    while(p != NULL)
    {
        q = p;
        p = p->next;
        free(q);
    }
    contact->next = NULL;
    return;
}


//联系人排序
void SortContact(linklist *contact)
{
    int input;
    int length = 0;
    linklist *p = contact->next;
    while(p->next == NULL)
    {
        p = p->next;
        length++;
    }
    length++;
    do
    {
        printf(" 1.按照id排序  2.按照name排序  0.返回\n");
        printf("请选择：");
        scanf("%d",&input);
        if(input == 1)
        {
            for(int j = length - 1; j >= 0; j--)
            {
                for(int i = 0; i < j; i++)
                {
                    if(strcmp(contact->data.id, contact->next->data.id)>0)
                    {
                        DataType tmp;
                        tmp = contact->data;
                        contact->data = contact->next->data;
                        contact->next->data = tmp;    
                    }
                }

            }
            printf("排序完成");
            //遍历
            LinklistPrint(contact);
            return;
        }
        else if(input == 2)
        {
            for(int j = length - 1; j >= 0; j--)
            {
                for(int i = 0; i < j; i++)
                {
                    if(strcmp(contact->data.name, contact->next->data.name)>0)
                    {
                        DataType tmp;
                        tmp = contact->data;
                        contact->data = contact->next->data;
                        contact->next->data = tmp;
                    }
                }
            }
            printf("排序完成");
            //遍历
            LinklistPrint(contact);
            return;
        }
    }while (input);
}


//通讯录信息保存
void SaveContact(linklist *contact) 
{
    assert(contact);
    FILE *pfWrint = fopen("contact.txt","w+");
    if(pfWrint ==NULL)
    {
        perror("SaveContact");
        return;
    }
    linklist *p = contact->next;
    
    for(; p->next != NULL; p = p->next)
    {
        if(1 != fwrite(&p->data, sizeof(contact->data), 1, pfWrint))
        {
            perror("fwrite");
            return;
        }
    }
    fwrite(&p->data, sizeof(contact->data), 1, pfWrint);
    fclose(pfWrint);
    pfWrint = NULL;
}


//通讯录信息读取
void LoadContact(linklist *contact)
{
    assert(contact);
    FILE *pfRead = fopen("contact.txt","rb");
    if(pfRead == NULL)
    {
        perror("LoadContact");
        return;
    }
    //printf("11111111111111111111111111111111\n");


    while(1)
    {
        linklist *tmp = (linklist *)malloc(sizeof(linklist)); 
       if(0==fread(&tmp->data, sizeof(contact->data), 1, pfRead))
       {
        return;
       }
        tmp->next = NULL;
        linklist *p = contact;
        //找到最后一个结点，循环结束，p此时指向最后一个结点的地址
        while(p->next != NULL) 
        {
            p = p->next;
        }
        tmp->next = p->next;
        p->next = tmp;
  
    }
    fclose(pfRead);
    pfRead = NULL;
     //printf("4444444444444444444444444444444444444444\n");

}
    




//音乐
void Music()
{
	printf("该服务为会员项目，请先充值会员。\n");
}
//vip
void VIP()
{
	printf("充值会员请联系客服,客服微信:13637006701\n");
}