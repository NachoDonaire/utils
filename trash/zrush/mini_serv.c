#include <sys/socket.h>
#include  <unistd.h>

struct s_client{
	int	id;
	char	*msg;
	int	socket;
}t_client;


void	plusClient(Client *cls, int *ncl, int clsocket)
{
	if (!cls)
	{
		clients = malloc(sizeof(t_client));
		if (!clients)
		{
			write_msg(2, "Fatal error\n");
			exit(1);
		}
		(*clients).id = *ncl - 1;
		(*clients).socket = clsocket;
		*ncl++;
		return ;
	}
}

void	lessClient(Client *cls, int *ncl, int clsocket)
{
	Clients *newcl = malloc(sizeof(t_client) * --(*ncl));
	if (!newcl)
	{
			write_msg(2, "Fatal error\n");
			exit(1);
	}
	while (y < *ncl)
	{
		if (cls[i].socket == clsocket)
			continue;
		cls[y].id = 



		

void	write_msg(int fd, char *s)
{
		write(fd, s, strlen(s));
}

int	find_event(int curr, int ncl, t_client *cls)
{
	for (int i = 0; i < ncl; i++)
	{
		if (cls[i].socket == curr)
			return i;
	}
	return -1;
}

char *str_join(char *buf, char *add)
{
        char    *newbuf;
        int             len;

        if (buf == 0)
                len = 0;
        else
                len = strlen(buf);
        newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
        if (newbuf == 0)
                return (0);
        newbuf[0] = 0;
        if (buf != 0)
                strcat(newbuf, buf);
        free(buf);
        strcat(newbuf, add);
        return (newbuf);
}


int	main(int argc, char **args)
{
	int	listener, len;
	int	current;
	struct sockaddr_in servaddr, cli;
	t_client *clients;
	fd_set readfds;
	fd_set writefds;
	int	nsockets;
	char	recData[300000];

	nsockets = 0;
	if (argc != 2)
	{
		write_msg(2, "Wrong number of arguments\n");
		return 1;
	}
	listener = socket(AF_INET, SOCK_STREAM, 0);
	if (listener == -1)
	{
		write_msg(2, "Fatal error\n");
		return 1;
	}
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = 2130706433; //127.0.0.1
	servaddr.sin_port = atoi(args[1]);

	if ((bind(listener, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) {
		write_msg(2, "Fatal error\n");
		return 1;
	}
	if (listen(listener, 10) != 0) {
		write_msg(2, "Fatal error\n");
		return 1;
	}
	nsockets++;
	while (1)
	{
		current = select(nsockets, &readfds, &writefds, NULL, NULL);
		if (current == listener)
		{
			len = sizeof(cli);
			connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
			if (connfd < 0)
				continue ;
			plusClient(clients, &nsockets, connfd);

		}
		else
		{
			int clientpos = find_event(current, nsockets - 1, clients);
			if (FD_ISSET(&readfds))
			{
				if (clients[clientpos].msg)
				{
					if (recv(clients[clientpos].socket, recData, 300000, 0) <= 0)
					{

					char *neoMsg = str_join(


			
		FD_SET((&readfds);
		FD_SET((&writefds);











