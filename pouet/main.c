int main(int ac, char **av)
{
	char		**raw_stack;
	char		**ops;
	int			size;
	t_stacks	*stacks;

	raw_stack = ft_split(av[1]);
	size = 0;
	while (raw_stack[size])
		size++;
	stacks = get_stacks(0, 0);
	stacks->stack_a = parse_stack_a(size + 1, raw_stack);
	stacks->stack_b = get_stack();
	ops = ft_split(av[2]);
}
