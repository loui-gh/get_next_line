# get_next_line
get_next_line focuses on memory, pointers and memory allocation

The purpose of the function is to read a file up to the user-defined buffer size, and then return the next line. If there is nothing
else to read or if an error has occurred it should return NULL. It may sound easy, but the challenge is actually how to allocate the memory
efficiently, so that you can return only one line per function call with no memory leaks and any buffer size between 0 and 10,000.

The norminette requires that we use no more than 5 functions per .c file, and the project stipulated that we turn in just two .c files.
I used a lot of my functions from libft and amended ft_strlen to be able to differentiate between EOF and '\n' using a flag.

