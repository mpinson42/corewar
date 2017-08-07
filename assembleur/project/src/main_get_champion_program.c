/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_champion_program.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:03:12 by apieropa          #+#    #+#             */
/*   Updated: 2017/07/27 20:03:14 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	get_champion_program(char **lines, t_instr *instrs, t_header *header)
{
	get_instructions(lines, instrs, header);
	opcode_meta_pass(instrs);
	arguments_meta_pass(instrs);
	addresses_pass(instrs, header);
	arguments_values_pass(instrs);
	header->magic = invert_endianness_o4(header->magic);
	header->prog_size = invert_endianness_o4(header->prog_size);
}
