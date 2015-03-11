#include "tarea.h"
#include <assert.h>

int main(void)
{
	struct tarea *t1;
	char info[250];

	t1 = curso_tarea_alloc();

	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_NOMBRE_TAREA,"matar");
	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_DESC_TAREA, 
				"ejecutar al profe");
	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_USUARIO, "Jose");
	curso_tarea_attr_set_u32(t1, CURSO_TAREA_ATTR_ID, 0);
	curso_tarea_attr_set_u32(t1, CURSO_TAREA_ATTR_PRIORIDAD, 0);

	curso_tarea_snprintf(info, sizeof(info), t1);
	printf("los valores del coche son %s\n", info);

	curso_tarea_free(t1);
	return 0;
}
