//
// Created by ikira on 19.05.2020.
//

#ifndef CORE_CODEGEN_H
#define CORE_CODEGEN_H

#include "op.h"
#include "libft.h"
#include "expr.h"
#include "expr_defines.h"
#include "../parser/expr_private.h"

typedef struct		s_codegen t_codegen;

void            generate_code(t_hash_map *map, t_vector *text, char *filename);
#endif //CORE_CODEGEN_H
