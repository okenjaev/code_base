#ifndef CARR_H
#define CARR_H

#include "../code_base.h"

#define carr(x) x*
#define carr_init(es, cp) (es*)nc_carr_init(sizeof(es), cp)
#define carr_free(x) nc_carr_free((char*)x)
#define carr_size(x) *nc_carr_size((char*)x)
#define carr_remove(x, y) nc_carr_remove((char*)x, y)

#define carr_append(x, y)				\
    {							\
        nc_carr_ensure_cap((char **) &x);		\
	u32 *size = nc_carr_size((char*) x);	\
	x[*size] = y;					\
	*size += 1;					\
    }							\

void
nc_carr_ensure_cap(char** arr);

void
nc_carr_remove(char* arr, u32 index);

char*
nc_carr_init(u32 elem_size, u32 cap);    

u32*
nc_carr_size(char* arr);

void
nc_carr_free(char *arr);

#endif /* CARR_H */
