#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node_t;

void add_at_begin(node_t **head, int info);
void add_at_end(node_t **head, int info);
void insert_at_pos(node_t **head, int info, int pos);
int countnodes(node_t *head);
void display_list(node_t *head);

node_t*
getnode(void) {

	node_t *tmp = NULL;
	tmp = (node_t *)malloc(sizeof(node_t));
	return tmp;
}

/*
 * 1. Get the node
 * 2. Fill the data
 * 3. Update the next pointer
 * 4. update the head pointer 
 */

void
add_at_begin(node_t **head, int info) {

	node_t *tmp = getnode();
	if (tmp == NULL) {
		printf("Not able to get the node\n");
		return;
	}
	/* Fill the node */
	tmp->data = info;
	tmp->next = NULL;
	
	/* Update the next and head pointer */
	if (*head == NULL) {
		*head = tmp;
	} else {
		tmp->next = *head;
		*head = tmp;
	}
	
}

void
add_at_end(node_t **head, int info) {
	
	node_t *tmp = getnode();
	if (tmp == NULL) {
		printf("Not able to get the node\n");
		return;
	}
	/* Fill the node */
	tmp->data = info;
	tmp->next = NULL;
	printf("Recieved data:%d\n", tmp->data);

	if(*head == NULL) {
		*head = tmp;
		return;
	}

	/* find the last node */
	node_t *last = *head;
	while(last->next != NULL) {
		last = last->next;
	}
	last->next = tmp;
}

/* To Return number nodes in LL */
int
countnodes(node_t *head) {
	int count = 0;
	node_t *tmp = head;

	if (tmp == NULL) {
		printf("List is emptry\n");
		return count;
	}
	while(tmp != NULL) {
		count ++;
		tmp = tmp->next;
	}
	return count;
}

/*1. Insert at begin 2. insert at end 3. insert at pos 4. invalid post */

void
insert_at_pos(node_t **head, int info, int pos) {

	int i;
	int size = countnodes(*head);
	printf("number of nodes: %d\n", size);
	if (pos > size +2) {
		printf("Invalid position\n");
		return;
	}

	node_t *newnode = getnode();
	newnode->data = info;
	newnode->next = NULL;

	if(pos == 1) {
		newnode->next = *head;
		*head = newnode;
		return;
	}

	node_t *prev = *head;
	for(i = 1; i < pos-1; i++) {
		prev = prev->next;
	}
	newnode->next = prev->next;
	prev->next = newnode;

}

void
display_list(node_t *head) {
	node_t *tmp = head;
	if (tmp == NULL) {
		printf("List is empty\n");
		return;
	}

	while(tmp !=NULL) {
		printf("%d-->", tmp->data);
		tmp = tmp->next;
	}
	printf("End of linked list\n");

}

void
RDisplay(node_t *p) {
	if (p != NULL) {
		RDisplay(p->next);
		printf("%d-->", p->data);
	}
}


int main() {

	int i, choice, n, info, pos;
	node_t* head = NULL;
	do {
		printf("1. Insert node at the begin of the List\n");
		printf("2. Insert node at the end of the list\n");
		printf("3. Insert node at the specified position\n");
		printf("4. Dispaly the linked list\n");
		printf("5. Count the number of nodes in linked list\n");
		printf("6. Exit\n");
		printf("Pleae enter your choice\n");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				system("clear");
				printf("Enter no. of nodes to be added\n");
				scanf("%d", &n);
				for(i=1; i<=n; i++) {
					printf("Enter a element to add\n");
					scanf("%d", &info);
					add_at_begin(&head, info);
				}
				break;
			case 2:
				printf("Enter a element to add\n");
				scanf("%d", &info);
				add_at_end(&head, info);
				break;
			case 3:
				printf("Enter the position where node to be inserted\n");
				scanf("%d", &pos);
				printf("Enter a element to add\n");
				scanf("%d", &info);
				insert_at_pos(&head, info, pos);
				break;
			case 4:
				display_list(head);
				//RDisplay(head);
				break;
			case 5:
				printf("Number of nodes in linked list: %d\n",
						countnodes(head));
				break;
			case 6:
				break;
				
			default:
				printf("Invalid choice\n");
		}

	}while(choice !=6);

	return 0;
}

