#include <stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

typedef long (*syscall_fn_t)(long, long, long, long, long, long, long);

static syscall_fn_t next_sys_call = NULL;
FILE *fp;
char buffer[1024];
int count=0;
char str[30];
static long hook_function(long a1, long a2, long a3,
			  long a4, long a5, long a6,
			  long a7)
{
	//printf("output from hook_function: syscall number '%ld' \br '%ld'\n", a1,a2);
	// printf("output from hook_function: syscall number '%ld'\n", a1);

	if (a1==59)
	{
		//sprintf(str, "%ld",a2);
		//char *argv[]={str,"toilet","-f","smmono9","--gay",NULL};
		
		// for (int i = 0; argv[i] != NULL; i++) 
		// {
		// 	printf("argv[%d] = %s\n", i, argv[i]); 
		// }

		//printf("%ld\n",a3);
		//printf("%s\n",(const char*)a3);
		const char **args = (const char **)a3;
		args[6] = "--gay";
		args[7] = NULL;
		// for (int i = 0; args[i] != NULL; ++i) {
    	// 	printf("argv[%d] = %s\n", i, args[i]);
			
		// }

		// char *argv[] = {"/usr/bin/toilet", "-f", "smmono9", "--gay", str, NULL};
		//a3 = (long)argv;
		//a3 = execvp("toilet",args);
		//printf("a3 %ld\n",a3);
	
	}
	
	return next_sys_call(a1, a2, a3, a4, a5, a6, a7);
}

int __hook_init(long placeholder __attribute__((unused)),
		void *sys_call_hook_ptr)
{
	printf("output from __hook_init: we can do some init work here\n");

	next_sys_call = *((syscall_fn_t *) sys_call_hook_ptr);
	*((syscall_fn_t *) sys_call_hook_ptr) = hook_function;

	return 0;
}
