#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// If ya can't see 'tis is colors, then it's prob'rly the best ya phucked off!
#define ANC_RED				"\x1b[31m"
#define ANC_GREEN			"\x1b[32m"
#define ANC_YELLOW		"\x1b[33m"
#define ANC_BLUE			"\x1b[34m"
#define ANC_MAGENTA		"\x1b[35m"
#define ANC_CYAN			"\x1b[36m"
#define ANC_WHITE			"\x1b[37m"
#define ANC_RESET			"\x1b[0m"

#define PT_ANN				"\x1b[37m[*]\x1b[0m "
#define PT_WIN				"\x1b[32m[*]\x1b[0m "
#define PT_FAIL				"\x1b[31m[*]\x1b[0m "

// Prototypes
void welcome(void);

// For system maintenance
void system_maintenance();
void update(void);
void antivirus(void);
// end system maintenance

// For reminder sections
void reminder(void);
void createNote(void);
void readNote(void);
void updateNote(void);
void deleteNote(void);
// end reminder
// end Prototypes

// SYSTEM MAINTENANCE
void system_maintenance()
{
	printf(PT_ANN"SYSTEM MAINTENANCE\n");
		update();
		antivirus();
	printf(PT_WIN"SYSTEMS MAINTENANCE COMPLETE\n");
}

// Notice the arch syntax!!
void update(void)
{
	char *updateCommand = malloc(64);
	strcpy(updateCommand, "sudo pacman -Syu");

	printf(PT_ANN"Updating...\n");
	if (system(updateCommand) == 0)
	{
		printf(PT_WIN"Update complete!\n");
	}
	else
	{
		printf(PT_FAIL"Update failed...\n");
		exit(EXIT_FAILURE);
	}
}

void antivirus()
{
	char *scanPath;
	char *basicCmd;
	char *updateCmd;
	char *updateClam;
	char *scan;
	size_t totalCmdSize;

	updateCmd = "sudo freshclam";
	basicCmd = "sudo clamscan -r -i ";
	scanPath = "/";

	totalCmdSize = (sizeof(basicCmd) + sizeof(scanPath));

	updateClam = malloc(sizeof(updateCmd));
	scan = malloc(sizeof(totalCmdSize));

	strcat(scan, basicCmd);
	strcat(scan, scanPath);

	strcpy(updateClam, updateCmd);

	printf(PT_ANN"Updating virus...\n");
	// system(updateClam);
	printf(PT_WIN"Update complete\n");
	printf("Executing command: %s\n", scan);
	printf(PT_ANN"Scanning for virus...\n");
	if (system(scan) == 0)
	{
		printf(PT_WIN"Scanning complete!\n");
	}
	else
	{
		printf(PT_FAIL"Scanning failed!\n");
		exit(EXIT_FAILURE);
	}
}
// END SYSTEM MAINTENANCE

// A note-to-self type of thingy
void reminder()
{
	char choice;

	printf("(C)reate note\n");
	printf("(R)ead notes\n");
	printf("(U)pdate note\n");
	printf("(D)elete note");
	scanf("%c\n", &choice);
	choice = malloc(sizeof(choice));

	if (strcmp(&choice, "c") == 0)
	{
		createNote();
	}
	else if (strcmp(&choice, "r") == 0)
	{
		readNote();
	}
	else if (strcmp(&choice, "u") == 0)
	{
		updateNote();
	}
	else if (strcmp(&choice, "d") == 0)
	{
		deleteNote();
	}
}

void createNote(void)
{
	char *note;
	char saveNote;

	printf("Enter a note\n");
	scanf("%s\n", &note);
	printf("%s\n", note);
	printf("\nDo you wish to save this note?\n");
	scanf("%s\n", &saveNote);
	saveNote = malloc(sizeof(saveNote));
	if (strcmp(saveNote, "y") == 0)
	{
		printf("HIIII\n");
	}
	else if (strcmp(saveNote, "n") == 0)
	{
		printf("NIIIIIIIH§§\n");
	}
	else
	{
		printf("something\n");
	}
}
void readNote(void)
{
	printf("\n");
}
void updateNote(void)
{

}
void deleteNote(void)
{

}

// Just some welcome screen
void welcome(void)
{
	char clear[16];
	strcpy(clear, "clear");
	system(clear);

	// TODO: Add banner!
	printf("Hello, there!\n");
}

int main(int argc, char **argv)
{
	int aflag = 0;
  int bflag = 0;
  char *cvalue = NULL;
  int index;
	int c;
	welcome();

	while ((c = getopt (argc, argv, "abmrc:")) != -1)
	{
    switch (c)
      {
      case 'a':
        aflag = 1;
        break;
      case 'b':
        bflag = 1;
        break;
      case 'c':
        cvalue = optarg;
        break;
			case 'm':
				system_maintenance();
				break;
			case 'r':
				reminder();
				break;
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
      }
	}
	printf ("aflag = %d, bflag = %d, cvalue = %s\n",
          aflag, bflag, cvalue);

  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);
  return 0;

}
