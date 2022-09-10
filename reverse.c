#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char *lineBuffer;
	struct node *prev;
};

int main(int argc, char *argv[])
{		
	FILE *stream = NULL;
        FILE *stream2 = NULL;
        // char *currentLine = NULL;
        size_t buffSize = 0;
        int readin = 0;
        //argv[0] is the code, argv[1] is the input file, argv[2] is the output file

        stream = fopen(argv[1], "r");
        if(argc == 3){
                stream2 = fopen(argv[2], "r+");
                //Do open file checks
                if((stream2 == NULL)&&(stream == NULL)){
                        fprintf(stderr, "error: cannot open files '%s' and '%s' \n", argv[1], argv[2]);
                        exit(1);
                }
                else if(stream2 == NULL){
                        fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);
                        exit(1);
                }
        }
        if(stream == NULL){
                fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
                exit(1);
        }
       

        //Check for the number of args
        if((argc < 2) || (argc > 3)){
                fprintf(stderr, "usage: reverse <input> <output>\n");
                exit(1);
        }
        
        struct node *tail = NULL;
  
        while(1){
                char *point = NULL;
                //head->lineBuffer = (char*) malloc(sizeof(currentLine));
                readin = getline(&point, &buffSize,stream);
                if(readin == -1){
                        free(point);
                        break;
                }
                else{
                       struct node* head = (struct node*) malloc(sizeof(struct node)); 
                        head->lineBuffer = point;
                        head->prev = tail;
                        tail = head;
                }
        }

        // while(tail != NULL){
        //                 struct node* head;
        //                 printf("%s",tail->lineBuffer);
        //                 head = tail->prev;
        //                 free(tail->lineBuffer);
        //                 free(tail);
        //                 tail = head;
        //  }

        
        if (argc == 2) {
                while(tail != NULL){
                        struct node* head;
                        printf("%s",tail->lineBuffer);
                        free(tail->lineBuffer);
                        head = tail->prev;
                        free(tail);
                        tail = head;
                }
        }

        else {
                //Check to see if the files names are the same
                if(strlen(argv[1]) == strlen(argv[2])){
                        if(strncmp(argv[1], argv[2], (strlen(argv[1]))) == 0){
                                fprintf(stderr, "error: input and output file must differ\n");
                                exit(1);
                        }
                }
                
                while(tail != NULL){
                        struct node* head;
                        fprintf(stream2,"%s",tail->lineBuffer);
                        free(tail->lineBuffer);
                        head = tail->prev;
                        free(tail);
                        tail = head;
                }
                fclose(stream2);
        }
        
        free(tail);
        //free(currentLine);
        fclose(stream);
        return 0;
}
