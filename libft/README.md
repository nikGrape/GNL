ft_memset
	SYNOPSIS
	#include <string.h>
void    *memset(void *b, int c, size_t len)


	DESCRIPTION
	The memset() function writes len bytes of value c (converted to an unsigned char) to the string b.
	RETURN VALUES
	The memset() function returns its first argument.
	ft_bzero
	SYNOPSIS
	void    bzero(void *s, size_t n)


	DESCRIPTION
	The bzero() function writes n zeroed bytes to the string s.  If n is zero, bzero() does nothing.


	

	SYNOPSIS
	void *  memcpy(void *restrict dst, const void *restrict src, size_t n)


	DESCRIPTION
	The memcpy() function copies n bytes from memory area src to memory area dst.  If dst and src overlap, behavior is undefined.
	RETURN VALUES
	The memcpy() function returns the original value of dst.
	

	SYNOPSIS
	

	DESCRIPTION
	

	RETURN VALUES
	

	

	SYNOPSIS
	

	DESCRIPTION
	

	RETURN VALUES