#include "gestor_tarea.h"
#include <string.h>

struct gestor_tarea {
	struct tarea	*tareas[10];
	uint32_t	num_tareas;

	uint32_t	flags;
};

struct gestor_tarea *curso_gestor_tarea_alloc(void)
{
	return (struct gestor_tarea *)malloc(sizeof(struct gestor_tarea));
}

void curso_gestor_tarea_free(struct gestor_tarea *gt)
{
	int i;

	for (i = 0; i < gt->num_tareas; i++)
		curso_tarea_free(gt->tareas[i]);
	xfree(gt);
}	

void curso_gestor_tarea_attr_unset_tarea(struct gestor_tarea *gt,uint32_t pos)
{
	int i;
	if (pos > 0 && pos > gt->num_tareas)
		return;

	curso_tarea_free(gt->tareas[pos]);

	for( i = pos; i < gt->num_tareas - 1; i++)
		gt->tareas[i] = gt->tareas[i + 1];
	gt->num_tareas--;

}

void curso_gestor_tarea_attr_set_tarea(struct gestor_tarea *gt, uint16_t attr,
					struct tarea *t)
{
	struct tarea *aux;
	int i,j;

	if (attr > CURSO_GESTOR_TAREA_ATTR_MAX)
		return;

	switch (attr) {
	case CURSO_GESTOR_TAREA_ATTR_TAREAS:
		if (gt->num_tareas > 10) {
			printf("El gestor esta lleno\n");
			break;
		}

		gt->tareas[gt->num_tareas] = (struct tarea *)t;
		gt->num_tareas++;
		
		//algoritmo burbuja asequible al ser pocas tareas

		for (i = 1; i < gt->num_tareas; i++){
			for(j = 0; j < gt->num_tareas -1; j++){
				if (curso_tarea_attr_get_u32(
							gt->tareas[j],
					CURSO_TAREA_ATTR_PRIORIDAD) >
				curso_tarea_attr_get_u32(
							gt->tareas[j + 1],
					CURSO_TAREA_ATTR_PRIORIDAD)) {
					aux = gt->tareas[j];
					gt->tareas[j] = gt->tareas[j + 1];
					gt->tareas[j + 1] = aux;
				}
			}
		break;
		}
	}
	gt->flags |= (1 << attr);
}

const void *curso_gestor_tarea_attr_get_data(struct gestor_tarea *gt,
						uint16_t attr, uint32_t pos)
{
	if(!(gt->flags & (1 << attr)))
		return NULL;

	switch (attr) {
		case CURSO_GESTOR_TAREA_ATTR_TAREAS:
			return gt->tareas[pos];
		case CURSO_GESTOR_TAREA_ATTR_NUM_TAREAS:
			return &gt->num_tareas;
	}
	return NULL;
}

uint32_t curso_gestor_tarea_attr_get_u32(struct gestor_tarea *gt,uint16_t attr)
{
	const void *ret = curso_gestor_tarea_attr_get_data(gt, attr, 0);
	return ret == NULL ? 0 : *((uint32_t *)ret);
}

struct tarea *curso_gestor_tarea_attr_get_tarea(struct gestor_tarea *gt,
						uint16_t attr, uint32_t pos)
{
	return (struct tarea *)curso_gestor_tarea_attr_get_data(gt, attr, pos);
}

int curso_gestor_tarea_snprintf(char *buf, size_t size,
				struct gestor_tarea *gt)
{
	int i, ret = 0;
	ret *= snprintf(buf, size, "El gestor tiene %d tareas pendientes "\
			"y son:\n", gt->num_tareas);

	for(i = 0; i < gt->num_tareas; i++) {
		ret += curso_tarea_snprintf(buf + ret, size - ret,
						gt->tareas[i]);
		ret+= snprintf(buf + ret, size - ret, "\n");
	}
	return ret;
}
