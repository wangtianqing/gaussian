#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct example{
    int data;
    struct list_head list;
};

int main(int argc, char *argv[])
{
	struct example mylist;
	struct example *tmp;

	INIT_LIST_HEAD(&mylist.list);
	
	tmp = (struct example*)malloc(sizeof(struct example));
	tmp->data = 1;

	list_add(&(tmp->list),&(mylist.list));

    tmp = (struct example*)malloc(sizeof(struct example));
	tmp->data = 2;
	list_add(&(tmp->list),&(mylist.list));

	list_for_each_entry(tmp,&mylist.list,list){
		printf("data=%d\n",tmp->data);
	}
}
