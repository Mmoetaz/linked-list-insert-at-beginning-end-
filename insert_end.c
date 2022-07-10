#include<stdio.h>
#include<stdlib.h>
typedef struct n{
	struct n* next;
	int x;
}Mylist;
typedef Mylist *list;
void create (list *l){
	*l=NULL;
}
void insert (list *l,int x){
	list e,p;
	p=(list)malloc(sizeof(list));
	p->x=x;
	p->next=NULL;
	if(*l==NULL){
		*l=p;
	}else{
		e=*l;
		while(e->next!=NULL){
			e=e->next;
		}
		e->next=p;
	}
}
void show(list l){
	list p;
	p=l;
	while(p!=NULL){
		printf("%d |",p->x);
		p=p->next;
	}
}
main(){
	list l;
	int x,n;
	create(&l);
	printf("****You can insert only at the end of the list (FiFo)****");
	printf("\n\nPress 1 to insert a new number.");
	printf("\nPress 2 to display list.");
	printf("\nPress 0 to leave.");
	do{
		printf("\nChoice:");
		scanf("%d",&n);
		if(n==1){
			printf("Number:");
			scanf("%d",&x);
			insert(&l,x);
		}
		else if(n==2){
			show(l);
		}
		else if(n!=1&&n!=2&&n!=0)
			printf("\ninvalid choice !");
	}while(n!=0);
	free(l);
}
