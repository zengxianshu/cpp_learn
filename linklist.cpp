#include <stdio.h>
#include <stdlib.h>

// 数据模型
typedef struct list
{
	int data;
	struct list *next;
}linklist;

// 创建
void CreatList(linklist *list)
{  
	scanf("%d",&list->data); 
	if(list->data!=0)
	{
		list->next=(linklist *)malloc(sizeof(linklist));
		CreatList(list->next);
	}
}

// 展示链表
void display(linklist *list)
{
   	if(list)
   	{
		printf("%d ",list->data);
		display(list->next);
   	}else{
   		printf("\n");
   	}
}

// 逆序
linklist* reverse(linklist *list)
{  
 	if(NULL==list|| NULL==list->next) 
 		return list;    //少于两个节点 否则没有反转的必要。

 	linklist *p, *q, *r;
    p = list;    
    q = list->next;  
    while(q){  
        r = q->next; //先保留下一个step要处理的指针  
        q->next = p; //然后p q交替工作进行反向  
        p = q;   
        q = r;   
    }  
    return p;      // 最后q必然指向NULL，所以返回了p作为新的头指针
}  

int main()
{
	linklist *originlist=(linklist *)malloc(sizeof(linklist));
	printf("Please create a linklist:\n");
	CreatList(originlist);
	printf("the list after create is: ");
	display(originlist);

	printf("the list after create is: ");
	display(reverse(originlist));



	return 0;
}