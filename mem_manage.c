#include <stdlib.h>
#include <stdio.h>

typedef struct s_mem
{
	void			*adress;
	struct s_mem    *next;
}					t_mem;

t_mem *mem_init(void *add)
{
    t_mem *mem;

    mem = malloc(sizeof(t_mem));
    if(!mem)
        return(NULL);
    mem->next = NULL;
    mem->adress = add;
    return (mem);
}

void free_mem(t_mem *mem)
{
    t_mem *temp;

    temp = mem;
    while(temp)
    {
        temp = mem->next;
        free(mem->adress);
        free(mem);
        mem = temp;
    }
}
void add_mem(t_mem *mem, void *add)
{
    t_mem *temp;
    t_mem *temp2;

    temp2 = mem;
    temp = malloc(sizeof(t_mem));
    if(!temp)
    {
        free(add);
        free_mem(mem);
    }
    while(temp2->next)
        temp2 = temp2->next;
    temp->next = NULL;
    temp->adress = add;
    temp2->next = temp;
}
void *ft_malloc(size_t total, t_mem *mem)
{
    void *memory;

    memory = malloc(total);
    if(!memory)
        free_mem(mem);
    add_mem(mem, memory);
    return (memory);
}

//int main()
//{
//    t_mem *mem = mem_init(NULL);
//    char *a = ft_malloc(100, mem);
//    char *a2 = ft_malloc(100, mem);
//    char *a3 = ft_malloc(100, mem);
//    char *a4 = ft_malloc(100, mem);
//    char *a5 = ft_malloc(100, mem);
//    free_mem(mem);
//}