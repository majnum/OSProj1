#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char *lineBuffer;
	struct node *prev;
	struct node *next;
};

int main(int argc, char *argv[])
{		
		/*
		FILE *in = fopen(argv[1], "r");	
		char *lineBuffer;
		size_t len = 0;
		getline(&lineBuffer,&len,in);


		fclose(in);
		*/
	
	FILE *stream;
        FILE *stream2;
        char *currentLine = NULL;
        size_t buffSize = 0;
        size_t readin;
        //argv[0] is the code, argv[1] is the input file, argv[2] is the output file

        stream = fopen(argv[1], "r");

        if((argc < 2) || (argc > 3)){
                fprintf(stderr, "usage: reverse <input> <output>\n");
                exit(1);
        }

        if(strncmp(argv[1], argv[2], strlen(argv[1])) == 0){
                fprintf(stderr, "error: input and output file must differ\n");
                exit(1);

        }

        if (argc == 2) {
                while ((readin = getline(&currentLine,&buffSize,stream)) != -1) {
                        //fwrite(currentLine,readin,1,stdout);
                        printf("%s", currentLine);
                }
        }

        if (argc == 3) {
                stream2 = fopen(argv[2], "w");
                while ((readin = getline(&currentLine,&buffSize,stream)) != -1) {
                        //fwrite(currentLine,readin,1,stream2);
                        fprintf(stream2, "%s", currentLine);
                }
                free(currentLine);
                fclose(stream2);
        }

        free(currentLine);
        fclose(stream);
        return 0;
}
