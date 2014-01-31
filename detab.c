#include <stdio.h>

#define TABL       4     /* length of a tab */
#define MAXLINE     255       /* max length of a line */

int get_line(char *line, int lim);
void tab_to_space(char *line, int len, char *toline, int tlen);

int main(int args, char *argv)
{
    char line[MAXLINE];          /* current line */
    char toline[MAXLINE * TABL];   /* in case of every char of the line is \t */
    int len;               /* current line length */

    while ((len = get_line(line, MAXLINE)) > 1) /* len = 1 means EOF */
    {
       tab_to_space(line, len, toline, MAXLINE * TABL);

       printf("%s", toline);
    }

    return 0;
}

int get_line(char *line, int lim)
{
    char c;
    int i;

    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
       line[i] = c;
    } /* i = 0 means EOF */
    if (c == '\n')
    {
       line[i] = c;
       ++i;
    }
    line[i] = '\0';

    return i + 1;
}

void tab_to_space(char *line, int len, char *toline, int tlen)
{
    int i;
    int j;
    int t;
    int nspace;

    for (i = 0, t = 0; i < len; i++, t++)
    {
       if (line[i] != '\t')
       {
         toline[t] = line[i];
       }
       else
       {
         nspace = TABL - (i % TABL); /* number of space to output */
         for (j = 0; j < nspace; j++, t++)
         {
          toline[t] = ' ';
         }
         t--;
       }
    }

    return;
}


#include <stdio.h>

#define TABL		4		/* length of a tab */
#define MAXLINE		255		/* max length of a line */

int get_line(char *line, int lim);
void tab_to_space(char *line, int len, char *toline, int tlen);

int main(int args, char *argv)
{
  char line[MAXLINE];				/* current line */
	char toline[MAXLINE * TABL];	/* in case of every char of the line is \t */
	int len;						/* current line length */

	while ((len = get_line(line, MAXLINE)) > 1) /* len = 1 means EOF */
	{
		tab_to_space(line, len, toline, MAXLINE * TABL);

		printf("%s", toline);
	}

	return 0;
}

int get_line(char *line, int lim)
{
	char c;
	int i;

	for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
		line[i] = c;
	} /* i = 0 means EOF */
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';

	return i + 1;
}

void tab_to_space(char *line, int len, char *toline, int tlen)
{
	int i;
	int j;
	int t;
	int nspace;

	for (i = 0, t = 0; i < len; i++, t++)
	{
		if (line[i] != '\t')
		{
			toline[t] = line[i];
		}
		else
		{
			nspace = TABL - (i % TABL); /* number of space to output */
			for (j = 0; j < nspace; j++, t++)
			{
				toline[t] = ' ';
			}
			t--;
		}
	}

	return;
}
