*This project has been created as part of the 42 curriculum by dbotelho.*

This project called "get_next_line" consists on a function wich returns a line when it founds a \n separator character.

The goal of this project in therms of learning are working with functions wich interact with files, static variables

The general instructions consists on using only 3 common C functions wich are:

Malloc: allocates Heap memmory;
Free: frees/deallocates the memmory allocated to not cause memmory leaks;
Read: read a file content using a file descriptor;

My algorythim choice explanation:

So it starts by checking possible erros on incorrect buffer size and invalid file descriptors

```c 
if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (*buffer = '\0', NULL);
```

Then i start an while loop with a condition that will always be true
```c 
	while (1)
```
And inside our "infinite loop" we have our "get next line".
Here we check for empty buffer to fill it:
```c 
		if (!*buffer)
			ft_fillbuff(fd, buffer);
```
If something went wrong filling it we break the loop:
```c 
		if (!*buffer)
			break ;
```
If otherwise we filled our buffer succefully we join the variable "line" (that will return the line read at the end of the function) ,with the buffer, if joining the strings went wrong we terminate the loop and return null, and give the buffer a null terminator "\0".
```c 
		line = ft_strjoin(line, buffer);
		if (!line)
			return (*buffer = '\0', NULL);
```
After joining we check for newlines to return the line read, if we do found a new line, we return the variable line:
```c 
		if (ft_checknl(buffer))
			return (ft_mvbuff(buffer), line);
		*buffer = '\0';
```
Finally if something went wrong with our loop we return NULL, and freeing the string that got memmory allocated when we used ft_strjoin
```c 
	if (!line || !*line)
		return (free(line), NULL);
	return (line);
```
So concluding, my loop basicly was a infinite loop checking for conditions, not a loop that just goes so far like (While (str[i] != '\0')), i use the infinite loop to check for errors of joining the contents read, to check for empty buffer and for new line to finally return the line read.

The resources i used were:

https://jameshfisher.com/2017/02/22/ssize_t/ -- tu understand why read function doesent return int, or size_t, but instead a ssize_t;

https://www.educative.io/answers/read-data-from-a-file-using-read-in-c --understand how the read function behaves;

francinette  -- deeper testing;

42 peers  -- tips and extra knowledge;

chatgpt.com -- sometimes i needed it for better debugging where i couldnt find the solution with my own prespetcitve, so chatgpt saved some time and gave me other points of view.

github.com -- version control and backup of my work
