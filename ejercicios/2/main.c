#include "gestor_tarea.h"

int main(void)
{
	struct tarea *t1, *t2, *t3;
	struct gestor_tarea *gt;
	char info[5000];

	t1 = curso_tarea_alloc();
	
	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_NOMBRE_TAREA, "Again");
	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_DESC_TAREA, "Poresito");
	curso_tarea_attr_set_str(t1, CURSO_TAREA_ATTR_USUARIO, "Quini");
	curso_tarea_attr_set_u32(t1, CURSO_TAREA_ATTR_ID, 0);
	curso_tarea_attr_set_u32(t1, CURSO_TAREA_ATTR_PRIORIDAD, 5);

	t2 = curso_tarea_alloc();
	
	curso_tarea_attr_set_str(t2, CURSO_TAREA_ATTR_NOMBRE_TAREA, "molar");
	curso_tarea_attr_set_str(t2, CURSO_TAREA_ATTR_DESC_TAREA, "Po eso");
	curso_tarea_attr_set_str(t2, CURSO_TAREA_ATTR_USUARIO, "Shevchenko");
	curso_tarea_attr_set_u32(t2, CURSO_TAREA_ATTR_ID, 1);
	curso_tarea_attr_set_u32(t2, CURSO_TAREA_ATTR_PRIORIDAD, 2);

	
	t3 = curso_tarea_alloc();
	curso_tarea_attr_set_str(t3, CURSO_TAREA_ATTR_NOMBRE_TAREA, "Paquete");
	curso_tarea_attr_set_str(t3, CURSO_TAREA_ATTR_DESC_TAREA, "Fuera");
	curso_tarea_attr_set_str(t3, CURSO_TAREA_ATTR_USUARIO, "Jhon");
	curso_tarea_attr_set_u32(t3, CURSO_TAREA_ATTR_ID, 2);
	curso_tarea_attr_set_u32(t3, CURSO_TAREA_ATTR_PRIORIDAD, 6);

	gt = curso_gestor_tarea_alloc();

	curso_gestor_tarea_attr_set_tarea(gt, CURSO_GESTOR_TAREA_ATTR_TAREAS,
						t1);
	curso_gestor_tarea_attr_set_tarea(gt, CURSO_GESTOR_TAREA_ATTR_TAREAS,
						t2);
	curso_gestor_tarea_attr_set_tarea(gt, CURSO_GESTOR_TAREA_ATTR_TAREAS,
						t3);

	curso_gestor_tarea_snprintf(info, sizeof(info), gt);
	printf("%s", info);

	curso_gestor_tarea_free(gt);
}
