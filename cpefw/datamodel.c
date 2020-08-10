#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cpedef.h"
#include "datamodel.h"

extern NODE _root[];
static int irecursive = 0;

NODE *get_rootnode()
{
	return _root;
}

//TODO: may check set/get exit. call set/get if true.
NODE *get_node(char *name, NODE *root)
{
	if(strlen(name) > NODENAMESIZE)
		return NULL;
		
	NODE *p = root;
	char tmp[NODENAMESIZE];
	strcpy(tmp, name);
	char *s = strtok(tmp, ".");
	int i = strlen(s);
	for(; p->name; p++)
	{
		if(!strcmp(s, p->name))
		{
			s = strtok(NULL, ".");
			if(s)
			{
				if(p->child_node)
					return get_node(name + i + 1, p->child_node);//+1 for ignore the dot
				else
					return NULL;
			}
			else
				return p;
		}
	}
		
	return NULL;
}

void print_tree(NODE *p)
{
	if(!p)
		return;
	int i = 0;

	for(; p->name; p++)
	{
		for(i=irecursive;i;i--)
			fprintf(stderr, "--");
		fprintf(stderr, "%s", p->name);
		if(p->child_node)
			fprintf(stderr, "(*)");
		if(p->get_para)
			fprintf(stderr, " (g)");
		/*else
			fprintf(stderr, "() ", p->name);*/
		if(p->set_para)
			fprintf(stderr, " (s)");
		/*else
			fprintf(stderr, "()", p->name);*/
		fprintf(stderr, "\n");
		if(p->child_node)
		{
			irecursive += 1;
			print_tree(p->child_node);
			irecursive -= 1;
		}
	}
}

//TODO: if method not support. The return value must follow tr069 standard.
int set_parameter(char *name, char *value)
{
	//char *s = NULL;
	NODE *p = NULL;
	NODE *root = get_rootnode();
	p = get_node(name, root);
	if(p)
	{
		if(!(p->set_para))
		{
			TR69CLOG(TR69C_INFO, "The parameter:%s set method is not suppot.", name);
			return 0;
		}
		p->set_para(value);
	}
	else 
	{
		TR69CLOG(TR69C_INFO, "The parameter:%s was not found .", name);
		return 0;
	}
	
	return 1;
}

//TODO: if method not support. The return value must follow tr069 standard.
int get_parameter(char *name, char **value)
{
	//char *s = NULL;
	NODE *p = NULL;
	NODE *root = get_rootnode();
	p = get_node(name, root);
	if(p)
	{
		if(!(p->get_para))
		{
			TR69CLOG(TR69C_INFO, "The parameter:%s get method is not suppot.", name);
			return 0;
		}
		p->get_para(value);
	}
	else
	{
		TR69CLOG(TR69C_INFO, "The parameter:%s was not found.", name);
		return 0;
	}
	
	return 1;
}

/*int getxct2value(char **value)
{
	printf("getxct2value running.\n");
	*value = strdup("AAA");
	printf("value = %s.\n", *value);
	return 1;
}*/

/*int main()
{
	char *testname = "device";
	NODE *p = NULL;
	NODE *root = _root;
	p = get_node(testname, root);
	if(p)printf("%d\n", p->value);
	else printf("Not found.\n");
	return 0;
}*/
