//
// Created by ikira on 19.05.2020.
//

#ifndef CORE_CODEGEN_H
#define CORE_CODEGEN_H

#include "../virtual_machine/include/op.h"
#include "libft.h"
#include "expr.h"
#include "expr_defines.h"
#include "../parser/expr_private.h"

typedef struct		s_codegen t_codegen;

t_codegen		*codegen_ctor(t_hash_map *labels_free, t_vector *labels_ptrs,
							   header_t *header);
void			codegen_dtor(t_codegen *code);
void		codegen_codegen(t_codegen *data, t_expr *q);
int			champ_exec_constructor(t_codegen *data);
#endif //CORE_CODEGEN_H
