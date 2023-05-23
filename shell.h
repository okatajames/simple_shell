#ifndef _SHELL_H_
#define _SHELL_H_


#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


/* Read & write to bufferrfers */
#define bufferr_FLUSH -1
#define READ_bufferrFER_SIZE 1024
#define WRITE_bufferrFER_SIZE 1024


/* Chaining commands */
#define CMD_AND 2
#define CMD_CHAINER 3
#define CMD_NORMAL 0
#define CMD_OR 1


/* Num & Char Converters */
#define CONV_UNSIGN	2
#define CONV_LOWERCHAR	1

/* captline handlers, 1 for system getline and string tokenizer */
#define CONST_GETLIN 0
#define CONST_STRHTOK 0


/* Handle shell hist and hist maximum */
#define HISTRY_DB	".simple_shell_history"
#define HISTRY_MAXVAL	4096


extern char **environ;

/**
 * struct list_strh - SLL
 * @integ: the field element
 * @strh: strh element
 * @next: next node ptre
 */

typedef struct list_strh
{
	int integ;
	char *strh;
	struct list_strh *next;
}
lst_tracker;

/**
 * struct infoparser - args for a routine & match routine to ptr struct
 * @status: last exec cmd is status
 * @loca: loca for cmd strh
 * @hist: shell hist node
 * @flag_linehcter: The input line that is set to 1 for the in
 * @filereader: file dir to capture input from line
 * @filenamef: filename for prog lang
 * @error_numb: couter for errs
 * @environt: copy for environt
 * @environ:  prototype for environt from internal environt
 * @couter_lin: counter for lines
 * @counterhistory: htry integ line variable tracker
 * @comdbufferrfertype: command cmdflag "||" and "&&"
 * @comdbufferrfer: chains ptr addr to comdbufferrfer when chain is activated
 * @changedenvt: changes to on when environ is change
 * @argv:  strhs arrays from argnull
 * @argc: counter for args
 * @argnull: strh from getline args
 * @alias: aliases
 *
 */


typedef struct infoparser
{
	char *argnull;
	char **argv;
	char *loca;
	int argc;
	unsigned int couter_lin;
	int error_numb;
	int flag_linehcter;
	char *filenamef;
	lst_tracker *environt;
	lst_tracker *hist;
	lst_tracker *alias;
	char **environ;
	int changedenvt;
	int status;

	char **comdbufferrfer;
	int comdbufferrfertype;
	int filereader;
	int counterhistory;
} info_tracker;

#define INITIALIZE_INFORN \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct bult_ins - builtinstring and  related function
 * @cmdflag: bult_ins cmd flag
 * @routine: routine
 */
typedef struct bult_ins
{
	char *cmdflag;
	int (*routine)(info_tracker *);
} bult_ins_tracker;


/* Shell loops */
int hsh(info_tracker *, char **);
int cap_bltin(info_tracker *);
void comd_finde(info_tracker *);
void comd_folk(info_tracker *);


/* Parsers  */
int checkcmd(info_tracker *, char *);
char *checkdups(char *, int, int);
char *pathlookup(info_tracker *, char *, char *);


/* Keeping the shell in a loop  */
int shell_loop(char **);


/* Error handlers  */
void _puterr(char *);
int _putcharrherr(char);
int _putfiled(char c, int filedesc);
int _putssfiled(char *strh, int filedesc);


/* toem_strings.c */
int _lenstrh(char *);
int _comparestrh(char *, char *);
char *startwith(const char *, const char *);
char *_concatstrh(char *, char *);

/* toem_string1s.c */
char *_copystrh(char *, char *);
char *_duplicstrh(const char *);
void _strhputt(char *);
int charput(char);

/* Exit Shell */
char *_stringhcopy(char *, char *, int);
char *_stringhconcat(char *, char *, int);
char *_stringhchar(char *, char);

/* Tokenizer helpers */
char **strinhtoken2(char *, char *);
char **strinhtoken3(char *, char);

/* Reallocators  */
char *_setmemory(char *, char, unsigned int);
void freememory(char **);
void *_memoryrealloc(void *, unsigned int, unsigned int);

/* Memory handlers */
int freebatch(void **);

/* Array to ints */
int mode_interactive(info_tracker *);
int delmi_ter(char, char *);
int alphaor(int);
int _arrtoint(char *);

/* Errors handlers */
int _errhtointi(char *);
void printferr(info_tracker *, char *);
int printf_delim(int, int);
char *num_conv(long int, int, int);
void comet_rem(char *);

/* Builtins */
int _shoutexit(info_tracker *);
int _shoutchangedir(info_tracker *);
int _shoutmanhlp(info_tracker *);

int _shouthist(info_tracker *);
int _shoutalias(info_tracker *);

ssize_t captinput(info_tracker *);
int captline(info_tracker *, char **, size_t *);
void handlesig(int);

void clear_all(info_tracker *);
void setall(info_tracker *, char **);
void freeall(info_tracker *, int);
char *getenvrt(info_tracker *, const char *);
int shoutenvrt(info_tracker *);
int shoutsetenvrt(info_tracker *);
int shoutunsetenvrt(info_tracker *);
int shoutpopuenvrtlist(info_tracker *);

char **getenvrtt(info_tracker *);
int unsetevnrt(info_tracker *, char *);
int setenvrt(info_tracker *, char *, char *);

char *histo_open(info_tracker *info);
int histo_write(info_tracker *info);
int histo_read(info_tracker *info);
int histo_buildlist(info_tracker *info, char *bufferr, int countliner);
int histo_numbering(info_tracker *info);

lst_tracker *node_adder(lst_tracker **, const char *, int);
lst_tracker *node_endadd(lst_tracker **, const char *, int);
size_t strhprintflist(const lst_tracker *);
int node_enddelete(lst_tracker **, unsigned int);
void listlfree(lst_tracker **);


size_t lenlistl(const lst_tracker *);
char **listltostrh(lst_tracker *);
size_t printflistl(const lst_tracker *);
lst_tracker *node_starterwith(lst_tracker *, char *, char);
ssize_t node_indexcapt(lst_tracker *, lst_tracker *);


int chainor(info_tracker *, char *, size_t *);
void chainchecker(info_tracker *, char *, size_t *, size_t, size_t);
int aliasreplacer(info_tracker *);
int aliasvarsv(info_tracker *);
int strhreplacer(char **, char *);

#endif
