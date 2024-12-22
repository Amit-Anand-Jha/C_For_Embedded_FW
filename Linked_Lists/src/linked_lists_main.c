#include "../inc/linked_lists.h"

typedef enum ll_action
{
	create_ll            = 0,
	add_node_at_end      = 1,
	append_node_at_pos_i = 2,
	delete_last_node     = 3,
	delete_node_at_pos_i = 4,
	quit                 = 5
}ll_action;


void linked_list_func();

int main()
{
	TRACE("Enter the number of nodes you want in the Linked List");
	int num_nodes;
	scanf("%d",&num_nodes);

	struct ll *head = create_linked_list();
	num_nodes = num_nodes-1;

	while(num_nodes > 0)
	{	
		TRACE("Enter the data of the next node");
		float datan;
		scanf("%f", &datan);
		append_linked_list_node_at_end(head,datan);
		num_nodes = num_nodes-1;
	}
	//linked_list_func();
	count_num_nodes(head);
	disp_linked_list(head);

	printf("\n\n");
	return 0;
}
	


void linked_list_func()
{
	TRACE(" Please select from the below options");

	int option = 0, n = 0;

	TRACE("a> Enter 0 to create a New Linked List");

	TRACE("b> Enter 1 to add new node at the end of the Linked List");

	TRACE("c> Enter 2 to add a new node at position 'i' in the Linked List");

	TRACE("d> Enter 3 to delete the last node of the Linked List");

	TRACE("e> Enter 4 to delete the node at position 'i' in the Linked List");

	TRACE("d> Enter 5 to exit from the options");

	scanf("%d",&n);

	struct ll *head_new = NULL;
	float data;

	while(option!=quit)
	{
		switch(n)
		{
			case create_ll:
				TRACE("You have chosen to create a new linked list. Enter the data of the first node");
				scanf("%f",& data);
				struct ll *new_list = create_linked_list(NULL, data);
				TRACE_HIGH("\n\nLinked List created has : Head = 0x%x  Link = 0x%x  and Value = %f\n\n", &new_list, new_list->link, new_list->value);
				break;

			case add_node_at_end:
				TRACE("Enter data inside the new node to be appended to the Linked List");
				scanf("%f",&data);
				printf("\n");
				append_linked_list_node_at_end(NULL,data);
				break;

			case append_node_at_pos_i:
				TRACE("Enter the name of the Linked List in which the new node is to be inserted");
				break;

			case delete_last_node:
				TRACE("Enter the name of the Linked List of which the last node has to be deleted");
				break;

			case delete_node_at_pos_i:
				TRACE("Enter the name of the Linked List from which node at a particular position has to be deleted");
				break;

			default:
				TRACE("Invalid Selection of Input");
				break;
		}
	}

	printf("\n\n");
}
