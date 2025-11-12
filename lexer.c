/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 06:16:42 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/12 07:28:43 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int is_ifs(int c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

size_t	count_token(char *s)
{
	size_t	cnt;
	unsigned int flag;
	
	flag = 0;
	cnt = 0;
	while (*s)
	{
		while (*s && is_ifs(*s))
			s++;
		if (*s == '\'' && s++)
			flag |= ST_SQ;
		
		
		
		
		
	}
	
	
	
	
	
}

char **lex_split(char *s)
{
	char	**spl;
	size_t	token;

	token = count_token(s);
	spl = malloc(sizeof(char *) * token);
	if(!token)
		return (NULL);
	
	
	
	
	
	
	
	
	
	
}


/*

grep 'hello world' -n file → ["grep","hello world","-n","file"]

echo "A B" C\ D "\"Q\"" → ["echo","A B","C D","\"Q\""]

awk -F ", " '{print $1}' → ["awk","-F",", ","{print $1}"]

echo "" '' foo → ["echo","","","foo"]

echo "foo"'bar' → ["echo","foobar"]

./a.out a\ b "c d" e\\f → ["./a.out","a b","c d","e\\f"]

エラー: echo "abc（未閉）→ 分割失敗として扱う


*/


