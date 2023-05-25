#include "shell.h"

/**
 * input_bufferr - routine for bufferrfers chain comds
 * @info: Struct for routine information
 * @bufferr: bufferrfer memory addresses
 * @lenh: lenh var
 *
 * Return: Returns integ of bytes
 */

ssize_t input_bufferr(info_tracker *info, char **bufferr, size_t *lenh)
{
	ssize_t st = 0;
	size_t len_p = 0;

	if (!*lenh)
	{
		free(*bufferr);
		*bufferr = NULL;
		signal(SIGINT, handlesig);

		#if CONST_GETLIN
		st = getline(bufferr, &len_p, stdin);

		#else
		st = captline(info, bufferr, &len_p);

		#endif
		if (st > 0)
		{
			if ((*bufferr)[st - 1] == '\n')
			{
				(*bufferr)[st - 1] = '\0';
				st--;
			}

			info->flag_linehcter = 1;
			comet_rem(*bufferr);
			histo_buildlist(info, *bufferr, info->counterhistory++);
			{
				*lenh = st;
				info->comdbufferrfer = bufferr;
			}
		}
	}
	return (st);
}


/**
 * captinput - routine that gets a line
 * @info: Struct for routine information
 *
 * Return: Returns integ of bytes
 */

ssize_t captinput(info_tracker *info)
{
	static char *bufferr;
	static size_t y, z, lenh;
	ssize_t st = 0;
	char **bufferr_p = &(info->argnull), *p;

	charput(bufferr_FLUSH);

	st = input_bufferr(info, &bufferr, &lenh);

	if (st == -1)
	{
		return (-1);
	}
	if (lenh)
	{
		z = y;
		p = bufferr + y;
		chainchecker(info, bufferr, &z, y, lenh);

		for (z = 0; z < lenh; z++)
		{
			if (chainor(info, bufferr, &z))
			{
				break;
			}
		}

		y = z + 1;
		if (y >= lenh)
		{
			y = lenh = 0;
			info->comdbufferrfertype = CMD_NORMAL;
		}
		*bufferr_p = p;
		return (_lenstrh(p));
	}

	*bufferr_p = bufferr;
	return (st);
}


/**
 * read_bufferr - reads a bufferrfer
 * @info: Struct for routine information
 * @bufferr: bufferrfer
 * @y: szerr
 *
 * Return: returns st
 */

ssize_t read_bufferr(info_tracker *info, char *bufferr, size_t *y)
{
	ssize_t st = 0;

	if (*y)
	{
		return (0);
	}
	st = read(info->filereader, bufferr, READ_bufferrFER_SIZE);
	if (st >= 0)
	{
		*y = st;
	}
	return (st);
}


/**
 * captline - receives nex lin from stdin
 * @info: Struct for routine information
 * @ptr: ptr address for bufferrfer prealloc or NULL
 * @length: size of prealloc ptr when bufferrfer not NULL
 *
 * Return: returns s
 */

int captline(info_tracker *info, char **ptr, size_t *length)
{
	static char bufferr[READ_bufferrFER_SIZE];
	static size_t y, lenh;

	size_t sik;
	ssize_t st = 0, s = 0;

	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;

	if (p && length)
	s = *length;

	if (y == lenh)
	y = lenh = 0;
	st = read_bufferr(info, bufferr, &lenh);

	if (st == -1 || (st == 0 && lenh == 0))
	return (-1);

	c = _stringhchar(bufferr + y, '\n');
	sik = c ? 1 + (unsigned int)(c - bufferr) : lenh;
	new_p = _memoryrealloc(p, s, s ? s + sik : sik + 1);

	if (!new_p)
	return (p ? free(p), -1 : -1);
	if (s)
	_stringhconcat(new_p, bufferr + y, sik - y);

	else
	_stringhcopy(new_p, bufferr + y, sik - y + 1);
	s += sik - y;
	y = sik;
	p = new_p;
	if (length)
	*length = s;
	*ptr = p;
	return (s);
}


/**
 * handlesig - stops use of ctrl-C
 * @sig_num: number of signal
 *
 * Return: returns void
 */

void handlesig(__attribute__((unused))int sig_num)
{
	_strhputt("\n");
	_strhputt("$ ");
	charput(bufferr_FLUSH);
}
