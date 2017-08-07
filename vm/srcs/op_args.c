/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveniat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 03:56:55 by pveniat           #+#    #+#             */
/*   Updated: 2017/08/06 03:56:57 by pveniat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		copy_reg(t_op_arg *arg, t_loop_data *ld, char *pc_addr, int nbr_arg)
{
	int		reg_nbr;

	ld->pc_delta++;
	if ((ld->op.args_type[nbr_arg] & T_REG) == 0)
		return (-1);
	reg_nbr = *pc_addr;
	if (reg_nbr > 16 || reg_nbr <= 0)
		return (-1);
	arg->addr = (int *)&ld->process->regs[reg_nbr - 1];
	return (0);
}

int		copy_ind(t_op_arg *arg, t_loop_data *ld, char *pc_addr, int nbr_arg)
{
	ld->pc_delta += 2;
	if ((ld->op.args_type[nbr_arg] & T_IND) == 0)
		return (-1);
	if (ld->op.id != 13 && ld->op.id != 14 && ld->op.id != 15)
		arg->addr = (int *)(ld->pc - 1 + ((swap_int16(*(int16_t *)pc_addr))
			% IDX_MOD));
	else
		arg->addr = (int *)(ld->pc - 1 +
		(swap_int16(*(int16_t *)pc_addr)));
	arg->addr = (int *)get_addr_in_mem((char *)arg->addr);
	return (0);
}

int		copy_arg(t_op_arg *arg, int *tmp_arg, t_loop_data *ld, int nbr_arg)
{
	char	*pc_addr;

	pc_addr = get_addr_in_mem(ld->pc + ld->pc_delta);
	arg->type = ld->arg_type;
	if (ld->arg_type == REG_CODE)
		return (copy_reg(arg, ld, pc_addr, nbr_arg));
	else if (ld->arg_type == DIR_CODE)
	{
		ld->pc_delta += ld->op.label_size;
		if ((ld->op.args_type[nbr_arg] & T_DIR) == 0)
			return (-1);
		if (ld->op.label_size == 2)
			*tmp_arg = (int)load_int16((t_op_arg){(int *)pc_addr, ld->arg_type})
				<< 16;
		else
			*tmp_arg = load_int32((t_op_arg){(int *)pc_addr, ld->arg_type});
		arg->addr = tmp_arg;
	}
	else if (ld->arg_type == IND_CODE)
		return (copy_ind(arg, ld, pc_addr, nbr_arg));
	else
		return (-1);
	return (0);
}

void	get_all_op_args(t_loop_data *ld)
{
	int				i;

	if (ld->op.octal_code)
	{
		ld->pc_delta++;
		i = 4;
		ld->ret = 0;
		while (--i > 0 && 4 - i <= ld->op.nbr_arg)
		{
			ld->arg_type = ((*ld->pc & (3 << (i * 2))) >> (i * 2));
			if (copy_arg(&ld->args[3 - i], &ld->tmp_arg[3 - i], ld, 3 - i))
				ld->ret = -1;
		}
	}
	else
	{
		ld->arg_type = ld->op.args_type[0];
		ld->ret = copy_arg(&ld->args[0], &ld->tmp_arg[0], ld, 0);
	}
}
