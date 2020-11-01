/**
 * @file algo_dir_utils.c
 * @author Paul Coral
 * @brief Some utils function, give algorithm function to the main program
 * @date 2020-11-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once
#include "../algo_interface/algo_interface.h"
#include "algo_error.h"

/**
 * @brief display the list of available algorithms
 *
 */
void list_algos(void);

/**
 * @brief return the sort function, or NULL in case of issue
 *
 * @param index index of the sort function
 * @param ai pointer to the func
 * @return an error code
 */
algo_error_t select_algo(const unsigned index, algo_interface_t *ai);

/**
 * @brief free the handle to shared library
 *
 */
void free_algo_lib(void);
