#include "avl_tree.h"

int main()
{
	Tree_t avl_tree;
	int insert_val, search_val, delete_val, option;
	
	init(&avl_tree);
	while(1)
	{
		printf("\n1.Insert\n2.Display\n3.Search\n4.Delete node\n5.Free tree\n6.Exit\n");
		printf("> ");
		scanf("%d", &option);
		printf("\n");
		switch(option)
		{
			case 1: printf("\nEnter the key to be inserted\n> ");
				scanf("%d", &insert_val);
				make(&avl_tree, insert_val);
				break;

			case 2: display(&avl_tree);
				break;

			case 3: printf("\nEnter the element to be searched\n> ");
				scanf("%d", &search_val);
				if(search(&avl_tree, search_val))
					printf("\n%d found.\n", search_val);
				else
					printf("\n%d not found.\n", search_val);
				break;

			case 4: printf("\nEnter the element to be deleted\n> ");
				scanf("%d", &delete_val);
				if(del(&avl_tree, delete_val))
					printf("\n%d deleted.\n", delete_val);
				else
					printf("\n%d not found. Cannot delete.\n", delete_val);
				printf("\n");
				break;

			case 5: clear_tree(&avl_tree);
				init(&avl_tree);
				break;

			case 6:	clear_tree(&avl_tree);
				exit(0);
				break;

			default: printf("\nInvalid input\n");
		}
	}
	return 0;
}

