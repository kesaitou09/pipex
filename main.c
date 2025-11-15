/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaitou <kesaitou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:23:38 by kesaitou          #+#    #+#             */
/*   Updated: 2025/11/16 03:50:57 by kesaitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

// void	child_pipeline(t_args args, t_proc proc, int i)
// {
// 	if (i == 0)
// 	{
// 		if (dup2(args.in_fd, STDIN_FILENO) == -1)
// 			_exit(1);
// 	}
// 	else
// 	{
// 		if (dup2(proc.prev_read, STDIN_FILENO) == -1)
// 			_exit(1);
// 	}
// 	if (i < proc.cmds - 1)
// 	{
// 		if (dup2(proc.p[1], STDOUT_FILENO) == -1)
// 			_exit(1);
// 	}
// 	else
// 	{
// 		if (dup2(args.ou_fd, STDOUT_FILENO) == -1)
// 			_exit(1);
// 	}
// }

void	init_proc(t_proc *proc, t_args args)
{
	proc->cmds = args.ac - 3;
	proc->last_pid = -1;
	proc->prev_read = -1;
	proc->pid = -1;
}

// int	wait_process(t_proc proc)
// {
// 	int		i;
// 	int		stat;
// 	int		exit_code;
// 	pid_t	wpid;

// 	i = 0;
// 	exit_code = 1;
// 	while (i < proc.cmds)
// 	{
// 		wpid = wait(&stat);
// 		if (wpid == -1)
// 		{
// 			perror("wait");
// 			break ;
// 		}
// 		if (wpid == proc.last_pid)
// 		{
// 			if (WIFEXITED(stat))
// 				exit_code = WEXITSTATUS(stat);
// 			else if (WIFSIGNALED(stat))
// 				exit_code = 128 + WTERMSIG(stat);
// 		}
// 		i++;
// 	}
// 	return (exit_code);
// }

// void	parent_process(t_proc *proc, int i)
// {
// 	if (proc->prev_read != -1)
// 		close(proc->prev_read);
// 	if (i < proc->cmds - 1)
// 	{
// 		close(proc->p[1]);
// 		proc->prev_read = proc->p[0];
// 	}
// 	if (i == proc->cmds - 1)
// 		proc->last_pid = proc->pid;
// }

// void	child_process(t_proc proc, t_args args, int i)
// {
// 	child_pipeline(args, proc, i);
// 	if (proc.prev_read != -1)
// 		close(proc.prev_read);
// 	if (i < proc.cmds - 1)
// 	{
// 		close(proc.p[0]);
// 		close(proc.p[1]);
// 	}
// 	close(args.ou_fd);
// 	manage_exec(args, i);
// }

// int	heredoc_fork_process(t_args args)
// {
// 	t_proc	proc;
// 	int		i;

// 	init_proc(&proc, args);
// 	i = 0;
// 	while (i < proc.cmds)
// 	{
// 		if (i < proc.cmds - 1)
// 			pipe(proc.p);
// 		proc.pid = fork();
// 		if (proc.pid < 0)
// 			return (1);
// 		else if (proc.pid == 0)
// 			child_process(proc, args, i);
// 		parent_process(&proc, i);
// 		i++;
// 	}
// 	close(args.ou_fd);
// 	if (proc.prev_read != -1)
// 		close(proc.prev_read);
// 	return (wait_process(proc));
// }

// int	fork_process(t_args args)
// {
// 	t_proc	proc;
// 	int		i;

// 	init_proc(&proc, args);
// 	i = 0;
// 	while (i < proc.cmds)
// 	{
// 		if (i < proc.cmds - 1)
// 			pipe(proc.p);
// 		proc.pid = fork();
// 		if (proc.pid < 0)
// 			return (1);
// 		else if (proc.pid == 0)
// 			child_process(proc, args, i);
// 		parent_process(&proc, i);
// 		i++;
// 	}
// 	close(args.in_fd);
// 	close(args.ou_fd);
// 	if (proc.prev_read != -1)
// 		close(proc.prev_read);
// 	return (wait_process(proc));
// }
/*
	here_doc
	「入力」
	入力を入力ファイルとして扱うことができればそれを同じ処理に送ることができる
	./pipex here_doc LIMITER cmd cmd1 file
		[0]     [1]      [2]   [3]  [4]  [5]
	改行までの入力を受け取ってそれがav[2]と一致してない間は入力を受取つづける
	「出力」
	最後のコマンドの実行結果をoutfileの末尾に追記する
	ファイルに追記する方法はO_APPENDを指定する




*/

int	branch_process(t_args args)
{
	if (!ft_strcmp(args.av[1], "here_doc"))
	{
		if (here_doc(&args) == ERROR)
		{
			ft_printf("dd");
			return (1);
		}
		ft_printf("dd");
		return (heredoc_fork_process(args));
	}
	else
		return (fork_process(args));
}

int	init_args(t_args *args, int ac, char **av, char **envp)
{
	args->ac = ac;
	args->av = av;
	args->envp = envp;
	if (!ft_strcmp("here_doc", av[1]))
	{
		args->in_fd = -1;
		args ->ou_fd = open(av[ac - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	}
	else
	{
		args->in_fd = open(av[1], O_RDONLY);
		if (args ->in_fd == -1)
			return (ERROR);		
		args->ou_fd = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		
	}
	if (args->ou_fd == -1)
		return (ERROR);
	return (SUCCESS);
}

int	main(int ac, char **av, char **envp)
{
	t_args	args;

	if (init_args(&args, ac, av, envp) == ERROR)
		return (1);
	return (branch_process(args));
}

/*
	pipexでのパイプはあるプロセスの標準出力を別のプロセスの標準入力に送る
	fd[0]は読み取り用
	fd[1]は書き込み用

	fd[1]への出力はfd[0]からの入力になる


	gnlでfd０で改行がくるまで受け付けて
	Heredocは指定した文字列が完全一致指定な限り入力を受けつけ続ける







./pipex file1 cmd1 cmd2 file2
 ファイル１をcmd1に入力して
 cmd1を実行するためには子プロセスを作ってexecveをする必要がある
 cmd1を実行するにはフルパスを検索し、
 dir/av[i]の形式で全探索する必要がある
 av[2] ~ av[ac - 2]まで全探索すれば良い
 av[i] を空白でsplitする


file cmd cmd cmd cmd file
[0]		[1] [2] [3] [4] [5]
		[1] | [2] | [3] | [4] | [5]
		1    2     3     4    5

i = 1;
while(i < ac - 2)

fork()するタイミングとpipe()するタイミング
forkはコマンドを別プロセスで実行するために必要
pipeは入出力を制御するために必要
pipeは最後以外のコマンドを実行するタイミングで必要

コマンドが見つからない → 127。
見つかるが実行不可（権限なし・ディレクトリ等）→ 126。

シグナルで終了 → 128 + シグナル番号（例：SIGINT=2なら130）。

リダイレクト失敗（例：> outfile を開けない）→ コマンドは実行されず、終了ステータスは非0（一般に1）。


0	正常終了
1	一般的なエラー
2	ビルトインコマンドの誤用
126	コマンドを実行できなかった（実行権限がない）a.outを作って権限０００で実行
127	コマンドが見つからなかった
128	exit コマンドに不正な引数を渡した
128+n	シグナル n で致命的なエラー（例: 130はCtrl+Cでの終了）
255	範囲外の終了ステータス

ac = 7
i = 2
i < ac - 2
*/
