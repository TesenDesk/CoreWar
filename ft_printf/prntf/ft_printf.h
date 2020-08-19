/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstygg <mstygg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:38:57 by mstygg            #+#    #+#             */
/*   Updated: 2020/08/01 17:42:55 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H


# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <stddef.h>

/*
** %[parameter][flags][width][.precision][length]type
*/

/*
** ‘%d’, ‘%i’
** Print an integer as a signed decimal number.
** See Integer Conversions, for details.
** ‘%d’ and ‘%i’ are synonymous for output,
** but are different when used with scanf
** for input (see Table of Input Conversions).
**
** ‘%o’
** Print an integer as an unsigned octal number.
** See Integer Conversions, for details.
**
** ‘%u’
** Print an integer as an unsigned decimal number.
** See Integer Conversions, for details.
**
** ‘%x’, ‘%X’
** Print an integer as an unsigned hexadecimal number.
** ‘%x’ uses lower-case letters and ‘%X’ uses upper-case.
** See Integer Conversions, for details.
**
** ‘%f’
** Print a floating-point number in normal (fixed-point) notation.
** See Floating-Point Conversions, for details.
**
** ‘%e’, ‘%E’
** Print a floating-point number in exponential notation.
** ‘%e’ uses lower-case letters and ‘%E’ uses upper-case.
** See Floating-Point Conversions, for details.
**
** ‘%g’, ‘%G’
** Print a floating-point number in either normal or
** exponential notation, whichever is more appropriate
** for its magnitude.
** ‘%g’ uses lower-case letters and ‘%G’ uses upper-case.
** See Floating-Point Conversions, for details.
**
** ‘%a’, ‘%A’
** Print a floating-point number in a hexadecimal fractional
** notation with the exponent to base 2 represented in decimal digits.
** ‘%a’ uses lower-case letters and ‘%A’ uses upper-case.
** See Floating-Point Conversions, for details.
**
** ‘%c’
** Print a single character. See Other Output Conversions.
**
** ‘%C’
** This is an alias for ‘%lc’ which is supported
** for compatibility with the Unix standard.
**
** ‘%s’
** Print a string. See Other Output Conversions.
**
** ‘%S’
** This is an alias for ‘%ls’ which is supported for
** compatibility with the Unix standard.
**
** ‘%p’
** Print the value of a pointer. See Other Output Conversions.
**
** ‘%n’
** Get the number of characters printed so far.
** See Other Output Conversions. Note that this conversion
** specification never produces any output.
**
** ‘%m’
** Print the string corresponding to the value of errno.
** (This is a GNU extension.) See Other Output Conversions.
**
** ‘%%’
** Print a literal ‘%’ character. See Other Output Conversions.
*/

/*
** константы для измененных функций заполнения
*/

/*
** CHOSE_VA_ARG_CONTENT_CONSTANTS
*/

# define IS_SIGNED_DEC 0
# define IS_UNSIGNED_DEC 1
# define IS_FRAC 2
# define IS_CHAR 3
# define IS_PTR 4
# define BUF_SIZE 512

/*
**L_DOUBLE CONSTANTS
*/
# define MANT_SIZE 63
# define CUT_EXP 1023
# define LDEXP_BIAS 16383

/*
**long_arythm_constants
*/
# define LONG_BASE 1000000000

# define LONG_LENGTH 10
# define L_AR_SIZE 2600

/*
**computation constants
*/
# define ITOA_BUF 66

/*
**double_e_form_constants
*/
# define FULL_DEC 101
# define DEC_FRAC_EDGE 102
# define PART_FRAC 103
# define FULL_FRAC 104

/*
** syntax_defs
*/

# define B_AR_CUR  buf_s->arg_ar[buf_s->ar_current]
# define U_CHAR unsigned char
# define LL long long
# define UL	unsigned long
# define ULL unsigned long long
# define LD long double
# define MOD_D_HH 1
# define MOD_D_H 2
# define MOD_D_L 3
# define MOD_D_LL 4
# define MOD_D_Z 5
# define MOD_D_J 6
# define MOD_F_LL 7
# define MOD_F_L 8
# define MOD_T	9
# define MINUS_FLAG flags[0]
# define PLUS_FLAG flags[1]
# define SPACE_FLAG flags[2]
# define ZERO_FLAG flags[3]
# define HASH_FLAG flags[4]

typedef struct			s_arg_opt
{
	U_CHAR				type;
	int					len;
	char				flags[5];
	int					width;
	int					prec;
	char				mod;
	intmax_t			l_num;
	LD					l_dnum;
	int					base;
	int					exp_pow;
	int					sci_f_minus_cell;
	U_CHAR				exp_negative;
	int					dec_size;
	int					ld_zeros;
	int					ld_zeros_cut_cell;
	U_CHAR				is_unsigned;
	char				sign;
	char				param_active;
	int					param_num;
	U_CHAR				*str;
	int					*utf_str;
}						t_arg_opt;

typedef struct			s_buf_struct
{
	U_CHAR				buf[BUF_SIZE];
	size_t				size;
	U_CHAR				params;
	t_arg_opt			*arg_ar;
	size_t				arg_num;
	size_t				ar_current;
	int					counter;
}						t_buf_struct;

typedef struct			s_float_part
{
	int					exp_part;
	ULL					frac_part;
	short				frac_length;
	U_CHAR				sign;
	U_CHAR				not_number;
	U_CHAR				inf;
	U_CHAR				zero;
}						t_float_part;

typedef struct			s_def_num
{
	union				u_point
	{
		LD				ld;
		U_CHAR			bytes[sizeof(LD)];
	}					point;
	U_CHAR				sign;
}						t_def_num;

typedef struct			s_long_num
{
	ULL					l_num[L_AR_SIZE];
	U_CHAR				sign;
	size_t				filled;
	int					cur;
}						t_long_num;

typedef struct			s_dec_frac
{
	t_long_num			dec;
	t_long_num			frac;
	t_long_num			l_pow;
	t_long_num			l_unit;
	size_t				res_filled;
}						t_dec_frac;

typedef void			(*t_fptr_floatoperation)(t_buf_struct *, t_dec_frac *);
typedef void			(*t_fptr_chose_content)(t_arg_opt *opt, size_t size,
		va_list *ap);

# define OP_P_TYPE opt[arg_pos].type
# define OP_P_MOD opt[arg_pos].mod
# define OP_P_UL_NUM opt[argPos].ul_num
# define OP_P_LNM opt[arg_pos].l_num
# define OP_P_LDN opt[arg_pos].l_dnum

int						ft_printf(const char *restrict format, ...);

/*
**parse_and_manage
*/
int						form_str_from_arg(t_buf_struct *buf_s, U_CHAR **format);
int						process_arg(t_buf_struct *buf_s,
		U_CHAR **format_str, va_list *ap);
void					fill_type_shift(U_CHAR **str);
void					read_str(U_CHAR **string, t_buf_struct *buf_s);
size_t					count_args(char const *format);
int						init_arg_ar(t_buf_struct *buf_s, U_CHAR *format,
		va_list *ap, U_CHAR *malloc_on);
void					fill_arg_ar(t_buf_struct *buf_s,
		U_CHAR *format, va_list *ap);
void					norm_zero_prec(t_dec_frac *l_num, int index);
void					norm_zeros_equal_prec(t_dec_frac *l_num,
		int index, int *ld_zeros);
/*
**distinguish_types
*/
int						is_integer(U_CHAR ch);
int						is_signed_int(U_CHAR ch);
int						is_string(U_CHAR ch);
int						is_floating(U_CHAR ch);
int						is_unsigned(U_CHAR ch);
/*
**fill_spec
*/
void					fill_flags(U_CHAR **str, t_arg_opt *opt,
		size_t arg_pos);
void					fill_mod(U_CHAR **str, t_arg_opt *opt, size_t pos);
size_t					fill_params(U_CHAR **str, t_arg_opt *opt,
		size_t arg_pos);
void					fill_precision(U_CHAR **str, t_arg_opt *opt,
		size_t arg_pos, va_list *ap);
void					fill_type(U_CHAR *format_str, t_arg_opt *opt,
		size_t arg_pos);
void					fill_width(U_CHAR **str, t_arg_opt *opt,
		size_t pos, va_list *ap);
void					fill_content(t_arg_opt *opt, size_t	arg_pos,
		va_list *ap_origin);
int						check_for_spec(U_CHAR tmp);
/*
**Content decision maker
*/

void					chose_content(t_arg_opt *opt, size_t pos, va_list *ap);
int						find_chose_opt_index(char type);
void					skip_args(t_arg_opt *opt, size_t arg_pos, va_list *ap);
void					chose_signed_dec(t_arg_opt *opt, size_t arg_pos,
		va_list *ap);
void					chose_unsigned_dec(t_arg_opt *opt, size_t arg_pos,
		va_list *ap);
void					chose_floating_point(t_arg_opt *opt, size_t arg_pos,
		va_list *ap);
void					chose_char(t_arg_opt *opt, size_t arg_pos, va_list *ap);
void					chose_char_no_assign(t_arg_opt *opt,
		size_t arg_pos, va_list *ap);
void					chose_ptr(t_arg_opt *opt, size_t arg_pos, va_list *ap);
int						check_args(t_buf_struct *buf_s);

/*
**lib
*/
int						count_base(ULL val, U_CHAR base);
long long				ft_atol_pf(const U_CHAR *str);
size_t					ft_strlen_pf(const U_CHAR *s);
void					ft_ltoa_base(t_buf_struct *buf_s, uintmax_t value,
		U_CHAR base);
void					ft_normal_ltoa(U_CHAR *buf, ULL value);
U_CHAR					*ft_strndup(const U_CHAR *src, size_t len);
U_CHAR					*ft_strchr_pf(const U_CHAR *s, int c);
void					*ft_memcpy_pf(void *dst, const void *src, size_t n);
void					ft_putchar_pf(char c);
ULL						ft_pow(ULL base, int exponent);
void					ft_bzero_pf(void *s, size_t n);
/*
**num_manager
*/
void					manage_dec_num(t_buf_struct *buf_s, U_CHAR base);
void					manage_unsigned_num(t_buf_struct *buf_s, U_CHAR base);
int						process_signed_num(t_buf_struct *buf_s);
void					process_unsigned_num(t_buf_struct *buf_s);
void					adjust_num_width(t_buf_struct *buf_s);
int						count_size_dec_num(LL num, int base);
int						count_size_unsigned_num(ULL num);
void					adjust_int_width(t_buf_struct *buf_s, int *substract);
/*
**long_double_manager
*/
void					cut_ld(LD const *ld_num, t_float_part *parted_num);
int						get_ldsign(t_def_num *ld_struct);
t_fptr_floatoperation	chosefloatfunc(t_buf_struct *buf_s,
		t_fptr_floatoperation operations[2]);
/*
** int					checklNumExp(t_dec_frac *l_num);
*/
ULL						get_firstdig_sciform(t_buf_struct *buf_s,
		t_long_num *l_num);
void					cut_exp_num(t_dec_frac *l_num);
/*
** int					check_num_for_prec(U_CHAR *tmpNum, t_dec_frac *l_num);
*/
int						find_non_zero_char(U_CHAR *tmp);
/*
** U_CHAR 				is_zero_charExp(U_CHAR *tmpNum);
*/
U_CHAR					is_zero_l_num(t_dec_frac *l_num);
void					manage_ldouble_num(t_buf_struct *buf_s);
void					put_sci_exp_prec(t_buf_struct *buf_s,
		t_dec_frac *l_num);
void					str_to_inf(t_buf_struct *buf_s);
void					str_to_nan(t_buf_struct *buf_s);
int						check_for_inf_nan(t_buf_struct *buf_s,
		t_float_part *p_n);
void					count_exp_pow(t_buf_struct *buf_s, t_dec_frac *l_num);
ULL						ull_length(ULL num);
/*
**long_double_precision
*/
void					adjust_fnum_prec(t_buf_struct *buf_s,
		t_dec_frac *l_num);
void					adjust_double_norm_form(t_dec_frac *l_num, int prec,
		int count_prec, int *ld_zeros);
void					adjust_double_sci_form(t_buf_struct *buf_s,
		t_dec_frac *l_num);
void					adjust_sci_prec(t_buf_struct *buf_s, t_dec_frac *l_num,
		int count_prec, int cut_point);
void					analize_frac_cell(t_dec_frac *l_num, int dif_prec,
		int *ld_zeros, U_CHAR is_zero_cell);
void					analize_frac_cell_zeros(t_dec_frac *l_num, int index,
		int dif_prec, int *ld_zeros);
void					analize_frac_cell_z_p_0(t_dec_frac *l_num, int index,
		int *ld_zeros);
void					analize_frac_cell_dec(t_dec_frac *l_num, int dif_prec);
void					analize_frac_cell_z_p_0_dec(t_dec_frac *l_num,
		int index);
int						check_for_nines(ULL tmp_num);
int						check_for_ones(ULL tmp_num);
int						check_for_fives2(t_long_num *l_num, int index,
		int dif_prec, ULL first_dig);
void					rebuild_lnum(t_dec_frac *l_num, int index,
		int *ld_zeros);
void					rebuild_dec(t_dec_frac *l_num, int dec_index);
void					clear_lnum_df(t_long_num *l_num, int index);
int						is_zero_l_num_norm(t_long_num *l_num, int index);
ULL						find_first_dig_sciform(t_dec_frac *l_num);
ULL						find_first_l_num(t_dec_frac *l_num);
int						sci_count_prec(t_buf_struct *buf_s,
		t_dec_frac *l_num, int cut_point);
void					rebuild_frac_cell(t_dec_frac *l_num,
		int *ld_zeros, int is_zero_cell);
/*
**transform переделать(сделать с 1 буфером)
*/
/*
** int				transform_ld_to_str(t_buf_struct *buf_s, t_float_part *p_n);
*/
int						get_ldexp(t_def_num *ld_struct);
U_CHAR					get_ldlength(ULL frac_part);
U_CHAR					*make_ld_str(t_dec_frac *l_num, t_float_part *p_n);
ULL						get_ldfrac(t_def_num *ld_struct);
/*
**long_arythmetic
*/
size_t					count_dec_frac_digs(t_long_num *l_num);
void					count_ld_num(t_buf_struct *buf_s, t_float_part *p_n,
		t_dec_frac *l_num);
int						make_ln_str(t_float_part *p_n, t_buf_struct *buf_s);
int						make_dec_buf(t_buf_struct *buf_s, t_dec_frac *l_num);
void					make_frac_buf(t_buf_struct *buf_s, t_dec_frac *l_num);
t_dec_frac				*check_frac_init(t_dec_frac *l_n);
t_dec_frac				*dec_frac_init(t_dec_frac *l_num);
t_long_num				*add_1_to_ldnum(t_long_num *l_num);
t_long_num				*l_num_init(void);
t_long_num				*long_add(t_long_num *l_num, t_long_num *l_num2);
t_long_num				*long_pow(t_long_num *l_unit, int exponent);
t_long_num				*long_short_mul(t_long_num *lnum, ULL mul_num);
t_long_num				*long_ld_init_num(ULL num);
U_CHAR					count_size_fnum(ULL num);
ULL						*long_mul(t_long_num *l1, t_long_num *l2);
void					long_ld_shift_left(ULL *ar);
void					initdec_frac(t_dec_frac *l_num);
void					long_copy(t_long_num *l1, ULL *res,
		size_t size_to_copy);
void					long_num_zero(ULL *num, size_t filled);
void					long_zero(t_long_num *num);
void					make_ld_dec(t_float_part *p_n, t_dec_frac *l_num);
size_t					make_ld_frac(t_float_part *p_n, t_dec_frac *l_num);
void					put_d_zeros(t_buf_struct *buf_s, int zero_i);
size_t					count_gap(ULL frac_part);
void					prec_cut_and_put_lnum(t_buf_struct *buf_s,
		ULL l_num, int *count_prec, int zero_i);
int						count_zero_i(t_buf_struct *buf_s, t_dec_frac *l_num,
					int count_prec, int index);
void					count_frac_part_lnum(t_dec_frac *l_num,
		t_float_part *p_n, int ten_power);
/*
**char_manager
*/
int						process_char(t_buf_struct *buf_s);
void					manage_char_or_percent(t_buf_struct *buf_s);
void					manage_str(t_buf_struct *buf_s);
void					str_to_buf(t_buf_struct *buf_s, size_t len);
void					char_to_buf(t_buf_struct *buf_s, U_CHAR ch);
size_t					count_str_len(t_arg_opt *opt);
void					adjust_utf_width(t_buf_struct *buf_s);
/*
**print_func
*/
int						ft_checkbit_pf(LL n, int pos);
void					ft_printbits_pf(ULL n, int count);
void					print_and_clear(t_buf_struct *buf_s);
void					print_sign(void);
void					print_bytes(t_def_num *ld);
/*
**put_into_buf_func
*/
void					put_ox(t_buf_struct *buf_s);
void					put_prec(t_buf_struct *buf_s, U_CHAR ch);
void					put_dec_sign(t_buf_struct *buf_s);
void					put_dec_num(t_buf_struct *buf_s, U_CHAR base);
void					put_float_sign(t_buf_struct *buf_s);
void					put_zero_spaces(t_buf_struct *buf_s, U_CHAR ch);
void					put_sign_or_space(t_buf_struct *buf_s);
void					ft_putchar_pf_utf(t_buf_struct *buf_s, int ch);
int						find_utf_len(int ch);
void					adjust_utf_num(int *ch, int len);

/*
**put_into_buf_ldouble
*/
void					put_zero_ld(t_buf_struct *buf_s);
void					put_ldouble(t_buf_struct *buf_s, t_dec_frac *l_num,
		t_fptr_floatoperation operation);
void					put_ldouble_num(t_buf_struct *buf_s, t_dec_frac *l_num);
void					put_ldouble_exp(t_buf_struct *buf_s, t_dec_frac *l_num);
void					put_inf_nan(t_buf_struct *buf_s);
void					put_zero_exp(t_buf_struct *buf_s);
void					put_sci_exp_prec(t_buf_struct *buf_s,
		t_dec_frac *l_num);
int						count_sci_exp_zero_i(t_buf_struct *buf_s,
		t_dec_frac *l_num, int index, int count_prec);
int						adjust_sci_exp_lnum_cell(t_buf_struct *buf_s,
		t_dec_frac *l_num, int index, int *count_prec);
int						put_sci_whole_dec(t_buf_struct *buf_s,
		t_dec_frac *l_num, int *count_prec);
/*
**struct_init_func
*/
void					initfptr_operations(t_fptr_floatoperation *operations);

#endif
