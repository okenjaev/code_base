#include "carr.h"

struct carr_info
{
    u32 size;
    u32 capacity;
    u32 element_size;
};

char*
nc_carr_init(u32 elem_size, u32 cap) {		
    char* arr = malloc(sizeof(struct carr_info) +	
		 elem_size * cap);		

    arr += sizeof(struct carr_info);
    *(nc_carr_size(arr)) = 0;
    *(nc_carr_cap(arr)) = cap;
    *(nc_carr_es(arr)) = elem_size;
    return arr;
}

void
nc_carr_remove(char* arr, u32 index)
{
    u32 *size = nc_carr_size(arr);
    u32 *es = nc_carr_es(arr);

    memmove(arr + index * *es, arr + (index + 1) * *es, *size - (index + 1) * *es);
    *size-=1;
}

void
nc_carr_ensure_cap(char** arr)
{
    u32* size = nc_carr_size(*arr);
    u32* cap = nc_carr_cap(*arr);

    if (*cap == *size)
    {
	u32 desired_size = *cap * 2;
	u32* es = nc_carr_es(*arr);
	
	char* temp = realloc(*arr - sizeof(struct carr_info),
			      sizeof(struct carr_info) + *es * desired_size);
	if (temp)
	{

	    temp += sizeof(struct carr_info);
	    *arr = temp;
	    *(nc_carr_cap(*arr)) = desired_size;

	    /* sm_set_message("%u", *cap); */
	}
    }
}

u32*
nc_carr_size(char* arr)
{
    return (u32*)(arr - 3 * sizeof(u32));
}

u32*
nc_carr_cap(char* arr)
{
    return (u32*)(arr - 2 * sizeof(u32));
}

u32*
nc_carr_es(char* arr)
{
    return (u32*)(arr - sizeof(u32));
}

void
nc_carr_free(char *arr)				
{							
    free(arr - sizeof(struct carr_info));	
}							


