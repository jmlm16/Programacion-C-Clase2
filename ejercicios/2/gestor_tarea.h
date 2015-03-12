#include "tarea.h"

enum {
	CURSO_GESTOR_TAREA_ATTR_TAREAS = 0,
	CURSO_GESTOR_TAREA_ATTR_NUM_TAREAS,
	__CURSO_GESTOR_TAREA_ATTR_MAX
};

#define CURSO_GESTOR_TAREA_ATTR_MAX (__CURSO_GESTOR_TAREA_ATTR_MAX - 1)

struct gestor_tarea;

struct gestor_tarea *curso_gestor_tarea_alloc(void);
void curso_gestor_tarea_free(struct gestor_tarea *);

void curso_gestor_tarea_attr_unset_tarea(struct gestor_tarea *gt,
	       				uint32_t pos);

void curso_gestor_tarea_attr_set_tarea(struct gestor_tarea *gt, uint16_t attr,
					struct tarea *t);

uint32_t curso_gestor_tarea_attr_get_u32(struct gestor_tarea *gt,
	       				uint16_t attr);

struct tarea *curso_gestor_tarea_attr_get_tarea(struct gestor_tarea *gt,
						uint16_t attr, uint32_t pos);

const void *curso_gestor_tarea_attr_get_data(struct gestor_tarea *gt,
						uint16_t attr, uint32_t pos);

int curso_gestor_tarea_snprintf(char *buf, size_t size,
	       			struct gestor_tarea *gt);
