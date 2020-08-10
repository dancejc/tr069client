#ifndef _DATAMODEL_H_
#define _DATAMODEL_H_

#define NODENAMESIZE 128

typedef enum
{
	TRDO_OK,
	TRDO_ERROR
}TR_RET;

typedef struct NODE{
	const char *name;
	TR_RET  (*get_para)		(char **value);
	TR_RET  (*set_para)		(char *value);
	void *reserved;
	struct NODE *child_node;
}NODE;

NODE *get_node(char *name, NODE *root);
NODE *get_rootnode();

int set_parameter(char *name, char *value);
int get_parameter(char *name, char **value);

void print_tree(NODE *p);
//Callback
//int getxct2value(char **value);

#endif
