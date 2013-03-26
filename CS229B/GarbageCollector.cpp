init()
{
	to_space = heap_bottom;
	space_size = heap_size / 2;
	top_of_space = to_space + space_size - 1;
	from_space = top_of_space + 1;
	free = to_space;
}

// n is number of bytes to allocate
New(int n)
{
	if(free + n > top_of_space)
	{
		flip();
	}
	if(free + n > top_of_space)
	{
		return null;
	}
	temp = free;
	free += n;
	return temp;
}

void flip()
{
	temp = from_space;
	from_space = to_space;
	to_space = temp;
	free = to_space;
	top_of_space = to_space + space_size - 1;
	for(R in root pointers)
	{
		R = copy(R);
	}
}

copy(p)
{
	if(atomic(p) || (p == null))
	{
		return p;
	}
	if(!forwarded(p))
	{
		n = sizeof(p);
		p` = free;
		free = free + n;
		temp = p[0];
		p[0] = p`;
		p`[0] = copy(temp);
		for(i = 1; i < n; i++)
		{
			p`[i] = copy(p[i]);
		}
	}
	return p[0];
}