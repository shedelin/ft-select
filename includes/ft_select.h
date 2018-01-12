/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shedelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 17:38:50 by shedelin          #+#    #+#             */
/*   Updated: 2014/01/08 17:38:53 by shedelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <termios.h>

typedef struct		s_dlst
{
	char			*name;
	int				cond;
	char			type;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}					t_dlst;

typedef struct		s_glob
{
	int				line;
	int				col;
	int				maxlen;
	t_dlst			*lst;
	struct termios	term;
}					t_glob;

void				ft_sl_initshell(void);
void				ft_sl_read(void);
void				ft_sl_key(char *key);
void				ft_sl_exit(void);
void				ft_sl_del(void);
void				ft_sl_dospace(void);
void				ft_sl_doentry(void);
void				ft_sl_signal(void);
void				ft_sl_sigint(int sig);
void				ft_sl_sigtstp(int sig);
void				ft_sl_sigcont(int sig);
t_glob				*ft_sl_singleton(void);
void				ft_sl_getsize(int sig);
void				ft_sl_put(void);
int					ft_sl_sizecheck(t_dlst *lst, t_glob *g);
void				ft_sl_putone(t_dlst *list);
void				ft_sl_moveup(void);
void				ft_sl_movedw(void);
void				ft_sl_moveright(void);
void				ft_sl_moveleft(void);
t_dlst				*ft_sl_dolst(int ac, char **av);
int					ft_sl_getmaxlen(t_dlst *lst);
void				ft_sl_error(int error);
void				ft_sl_errorsize(void);
int					ft_sl_putchar(int c);
int					ft_sl_putstr(char *str);
void				ft_sl_lstaddend(t_dlst **lst, t_dlst *new);
t_dlst				*ft_sl_creatlst(char *name, int condition, char type);
void				ft_sl_delone(t_dlst **lst, t_dlst *todel);
void				ft_sl_freelst(t_dlst *todel);
int					ft_sl_countlst(t_dlst *lst);
void				ft_sl_search(char c);
char				ft_sl_gettype(char *str);
void				ft_sl_printcolor(t_dlst *list, char *type);

#endif
