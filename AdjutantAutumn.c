#include <ctype.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Colors
#define ANC_RED				"\x1b[31m"
#define ANC_GREEN			"\x1b[32m"
#define ANC_YELLOW			"\x1b[33m"
#define ANC_BLUE			"\x1b[34m"
#define ANC_MAGENTA			"\x1b[35m"
#define ANC_CYAN			"\x1b[36m"
#define ANC_WHITE			"\x1b[37m"
#define ANC_RESET			"\x1b[0m"

#define PT_ANN				"\x1b[37m[.]\x1b[0m "
#define PT_WIN				"\x1b[32m[*]\x1b[0m "
#define PT_FAIL				"\x1b[31m[*]\x1b[0m "

// Prototypes
// For system maintenance
void system_maintenance();
void update(void);
void antivirus(void);

// For note thingy
void noteHandler(void);
void createNote(char *filename);
void readNote(char *filename);
void readNoteList(char *filename);
void updateNote(char *filename);
void deleteNote(char *filename);

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
    if (system(updateClam) == 0)
    {
        printf(PT_WIN"Update complete\n");
    }
    else
    {
        printf(PT_FAIL"Something went wrong...\n");
        // exit(EXIT_FAILURE);
    }
    
    printf("Executing command: %s\n", scan);
    printf(PT_ANN"Scanning for virus...\n");
    if (system(scan) == 0)
    {
        printf(PT_WIN"Scanning complete!\n");
        free(updateClam);
    }
    else
    {
        printf(PT_FAIL"Scanning failed!\n");
        free(updateClam);
        exit(EXIT_FAILURE);
    }
}

// NOTES
void noteHandler(void)
{
    char *choice;
    char *fchoice;
    char *file = "savefileAA.dat";
    char *note;
    int i;
    choice = malloc(4);

    printf("Add new note\n");
    printf("Read single note\n");
    printf("Read all notes\n");
    printf("Update a note\n");
    printf("Delete a note\n");
    
    scanf("%s", choice);
    
    if (strcmp(choice, "add") == 0)
        createNote(file);
    else if (strcmp(choice, "read") == 0 )
        readNote(file);
    else if (strcmp(choice, "r") == 0 )
        readNoteList(file);
    else if (strcmp(choice, "update") == 0 )
        updateNote(file);
    else if (strcmp(choice, "delete") == 0 )
        deleteNote(file);
    else
        printf("Command not reconized.. you wrote %s\n", choice);
}

void createNote(char *filename)
{
    FILE *fp;
    char *fileCmd = malloc(4);

    char *note = malloc(4096);
    char *choice = malloc(4);

    fileCmd = "y";

    printf("Write note:\n");
    scanf("%s", note);

    fp = fopen(filename, "a");
    if (filename == NULL)
    {
        printf(PT_FAIL"Error opening file\n");
        exit(EXIT_FAILURE);
    }
    
    if (note != NULL)
    {
        fprintf(fp, "%s\n", note);
        printf(PT_WIN"Note saved\n");
    }
    else
        printf(PT_FAIL"Eat shit\n");
    
    fclose(fp);
    /*free(note);
     * free(choice);
     * free(fileCmd);*/
}

void readNote(char *filename)
{

}

void readNoteList(char *filename)
{
    FILE *fp;
    int c;
    
    fp = fopen(filename, "r");
    if (filename == NULL)
    {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
        printf("hello you\n");
    }
    
    while (1)
    {
        c = fgetc(fp);
        if( feof(fp) )
        {
            break;
        }
        printf("%c", c);
    }
    fclose(fp); 
}

void updateNote(char *filename)
{

}

void deleteNote(char *filename)
{

}

// END NOTES

int main(int argc, char **argv)
{
    int aflag = 0;
    int bflag = 0;
    char *cvalue = NULL;
    int index;
    int c;
    
    while ((c = getopt (argc, argv, "abmnc:")) != -1)
    {
        switch (c)
        {
            case 'm':
                system_maintenance();
                break;
            case 'n':
                noteHandler();
                break;
            case '?':
                if (optopt == 'c')
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                else if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf (stderr, "Unknown option character `\\x%x'.\n", optopt);
                return 1;
            default:
                abort ();
        }
    }
    for (index = optind; index < argc; index++)
        printf ("Non-option argument %s\n", argv[index]);
    return 0;
}

// Testing something cool
