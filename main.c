
// int	main(void)
// {
// 	int fd = open("gnlTester/files/41_no_nl", O_RDONLY);
// 	char *line;

// 	if (fd < 0)
// 		return (-1);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	}	
// 	printf("%s", line);
// 	free(line);
// 	close(fd);
// 	return (0);
// }