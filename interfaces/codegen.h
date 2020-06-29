//
// Created by ikira on 19.05.2020.
//

#ifndef CORE_CODEGEN_H
#define CORE_CODEGEN_H

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "libft.h"
#include "constants.h"

typedef struct		s_codegen t_codegen;
typedef struct      s_vector  t_vector;
typedef struct      s_hash_map t_hash_map;


void            generate_code(t_hash_map *map, t_vector *text, char *filename);
#endif //CORE_CODEGEN_H
