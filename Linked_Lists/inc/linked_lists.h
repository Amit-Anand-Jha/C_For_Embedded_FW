#include<stdlib.h>
#include "../../Common_Defs/inc/common_defs.h"


/*------------------------------------------------------------------------------------------
 *
 *                                       DECLARATIONS
 *
 * ----------------------------------------------------------------------------------------*/

// Declaration of the Linked List structure which contains entities of a node
// Each node has 2 entity - a link (pointing to next node in the LL) and a value
typedef struct ll
{
	float value;
	struct ll *link;
}ll;


/*------------------------------------------------------------------------------------------
 * Declaration of API append_new_node_in_ll_at_pos_i()
 *
 * @BRIEF : This API adds a new node to an existing LL at a desired position in the LL
 *
 * @INPUT :
 *           (i)   head pointer of the LL where the new node has to be inserted
 *           (ii)  the data to be appended in the new node
 *           (iii) the position (index) at which the new node has to be inserted in the LL
 *
 * @RETURN :
 *           None - This API returns nothing
 * ----------------------------------------------------------------------------------------*/

void append_new_node_in_ll_at_pos_i(struct ll *head, float data_to_append, int pos);




/*------------------------------------------------------------------------------------------
 * Declaration of API append_linked_list_node_at_end()
 * 
 *
 * @BRIEF : This API adds a new node to an existing LL at the very end of the LL
 *
 * @INPUT :
 *           (i)   head pointer of the LL where the new node has to be inserted
 *           (ii)  the data to be appended in the new node
 *
 * @RETURN :
 *           None - This API returns nothing
 * ----------------------------------------------------------------------------------------*/

void append_linked_list_node_at_end(struct ll *head, float data);




/*------------------------------------------------------------------------------------------
 * Declaration of API disp_linked_list()
 * 
 *
 * @BRIEF : This API displays the Linked List completely from first to last node
 *
 * @INPUT :
 *           (i)   head pointer of the LL where the new node has to be inserted
 *
 * @RETURN :
 *           None - This API returns nothing
 * ----------------------------------------------------------------------------------------*/

void disp_linked_list(struct ll *head);



/*------------------------------------------------------------------------------------------
 * Declaration of API create_linked_list()

 * 
 *
 * @BRIEF : This API creates the head node of a new Linked List
 *
 * @INPUT :
 *           None - This API needs no Input 
 *
 * @RETURN :
 *           (i) head node (pointer) of the newly created LL
 * ----------------------------------------------------------------------------------------*/

struct ll *create_linked_list();



/*------------------------------------------------------------------------------------------
 * Declaration of API  count_num_nodes()

 * 
 *
 * @BRIEF : This API counts the total number of nodes in a Linked List
 *
 * @INPUT :
 *           (i) head of the LL whose total number of nodes are to be known 
 *
 * @RETURN :
 *           (i) the number of nodes in the LL
 * ----------------------------------------------------------------------------------------*/

int count_num_nodes(struct ll *head);







/*------------------------------------------------------------------------------------------
 *
 *                                    DEFINITIONS
 *
 * ----------------------------------------------------------------------------------------*/

struct ll *create_linked_list()
{
	// Allocate a memory location for the new node
	struct ll *head = (struct ll *) malloc(sizeof(struct ll *));

	TRACE("Please enter the value to be stored in the first node of the LL");

	float data;

	scanf("%f",&data);

	head->value = data;
	head->link = NULL;

	TRACE_HIGH("The address of head of the newly created LL is 0x%x", &head);
	TRACE_HIGH("head node has the address to first node of LL which is 0x%x", head);
	TRACE_HIGH("head is at 0x%x -> 0x%x -> NULL",&head, head);

	//count_num_nodes(head);
	//disp_linked_list(head);

	return head;
}




int count_num_nodes(struct ll *head)
{
	// Initialize the tail as the head before we start traversing the LL
	struct ll * tail = head;
	
	// Initialize the #NODES = 0
	int num_nodes = 0;

	// If head != NULL i.e. head points to a valid node then #NODES = 1
	if(head != NULL)
	{
		num_nodes = 1;
	}

	TRACE_HIGH("The head of the Linked List is 0x%x \t", head);

	// Keep incrementing the tail pointer - i.e. traverse through each node of the LL
	// till we reach a point where the tail points to NULL. Increment #NODES meanwhile
	// tail = NULL would imply the end of the linked list
	while (tail->link != NULL)
	{
		tail = tail->link;
		num_nodes = num_nodes + 1;
	}

	TRACE_HIGH("The tail of the Linked List is 0x%x and the total number of nodes is %d", tail, num_nodes);

	return num_nodes;
}



void append_linked_list_node_at_end(struct ll *head, float data)
{
	// If the head passed is NULL - the LL doesnt exist
	if(head == NULL)
	{
		TRACE("The head pointer is NULL hence the Linked List does not exist");
	}

	// If head is not NULL then new node needs to be created. Initialize a new node and append
	// at the end of the existing linked list
	else
	{
		printf("\n");
		TRACE_HIGH("Adding the new node at the end of existing LL with the head node address 0x%x\n", head);

		// Allocate the memory location for the new node
		struct ll *new_node = (struct ll*)malloc(sizeof(struct ll*));

		// Since the new node is the last node, its link will point to NULL
		new_node->link = NULL;
		// Saving the data of the new node as the value inside the new node
		new_node->value = data;

		struct ll *actual_head = head;
		// Below logic attaches the new node at the end of the existing LL
		while(head->link != NULL)
		{
			head = head->link;
		}

		head->link = new_node;

		// Printing the entire LL till the new node
		//count_num_nodes(actual_head);
		//disp_linked_list(actual_head);
	}
}



/*------------------------------------------------------------------------------------------
 * Declaration of API append_new_node_in_ll_at_pos_i()
 *
 * @BRIEF : This API adds a new node to an existing LL at a desired position in the LL
 *
 * @INPUT :
 *           (i)   head pointer of the LL where the new node has to be inserted
 *           (ii)  the data to be appended in the new node
 *           (iii) the position (index) at which the new node has to be inserted in the LL
 *
 * @RETURN :
 *           None - This API returns nothing as it modifies the original Linked List itself
 * ----------------------------------------------------------------------------------------*/
void append_new_node_in_ll_at_pos_i(struct ll *head, float data_to_append, int pos)
{
	// If the head passed is NULL - the LL doesnt exist
	if(head == NULL)
	{
		TRACE("The head pointer is 'NULL' hence the linked list doesnt exist");
	}

	else
	{
		printf("\n");
		TRACE_HIGH("The LL where value of %f is to be inserted at index %d has head = 0x%x", data_to_append, pos, head);
		disp_linked_list(head);
		TRACE_HIGH("Adding the new node in the existing LL with the head node address 0x%x\n", head);

		// Count the number of nodes already existing in the LL
		// If the number of nodes < pos where the new node is to appended then
		// append the new node at the end of the LL. Else append the new node
		// at the given position.
		int num_nodes = count_num_nodes(head);
		
		if(pos > num_nodes)
		{
			TRACE_HIGH("Adding the new node at the end of existing LL with total nodes %d and the head node address 0x%x\n", num_nodes, head);
			append_linked_list_node_at_end(head, data_to_append);
		}

		else
		{
			TRACE_HIGH("Adding the new node at index %d of existing LL with total nodes %d and the head node address 0x%x\n", pos, num_nodes, head);

			// Allocate the memory location for the new node
			// The new_node is address of the new node that is created since its a pointer
			struct ll *new_node = (struct ll*)malloc(sizeof(struct ll*));

			// Assign the data to the new node
			new_node->value = data_to_append;

			while(pos > 1)
			{
				head = head->link;
				pos = pos - 1;
				//TRACE_HIGH("head = 0x%x and pos = %d", head, pos);
			}
			new_node->link = head->link;
			//TRACE_HIGH("new_node->link = head->link = 0x%x", new_node->link);
			
			// We assign the head_link the value of new_node and not &new_node
			// This is because &new_node is the address of the pointer variable new_node
			// While new_node is the value inside the pointer variable - which is the address of the new node
			head->link = new_node;
			
			//TRACE_HIGH("head->link = new_node = 0x%x  and  &new_node = 0x%x", new_node, &new_node);
		}
	}
}


/*------------------------------------------------------------------------------------------
 * Declaration of API disp_linked_list()
 * 
 *
 * @BRIEF : This API displays the Linked List completely from first to last node
 *
 * @INPUT :
 *           (i)   head pointer of the LL which is to be displayed 
 *
 * @RETURN :
 *           None - This API returns nothing
 * ----------------------------------------------------------------------------------------*/

void disp_linked_list(struct ll *head)
{
	FILE *file_ptr = fopen(FILENAME, "a+");
	TRACE("The values in the LL are as below\n");
	
	// Initialize the pointer which will be used to traverse the LL 
	struct ll *temp_ptr = head;

	fprintf(file_ptr, "\n");
	while(temp_ptr != NULL)
	{
		printf("%f -> ",temp_ptr->value);
		fprintf(file_ptr, "%f -> ",temp_ptr->value);
		temp_ptr = temp_ptr->link;
	}

	printf("EMPTY");
	fprintf(file_ptr, "EMPTY");

	printf("\n");
	fprintf(file_ptr, "\n");

	TRACE_HIGH("head node of the LL itself is at address 0x%x", &head);

	temp_ptr = head;
	TRACE_HIGH("head node points to address of 1st node whose address is = 0x%x", head);
	TRACE("The links of the LL are as below\n");
	while(temp_ptr != NULL)
	{
		printf("0x%x -> ",temp_ptr);
		fprintf(file_ptr, "0x%x -> ",temp_ptr);
		temp_ptr = temp_ptr->link;
	}

	printf("NULL");
	fprintf(file_ptr, "NULL");

	printf("\n");
	fprintf(file_ptr, "\n");
}


