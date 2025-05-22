#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void check_book();
void take_book();
void return_book();

int main(){

    int choice,isrunning=1;

    while (isrunning){

    printf("Enter the choice:\n1)check book \n2)take Book \n3)Return Book\n4)exit the portal \n->>");
    scanf("%d",&choice);

    switch (choice){
        
        case 1 :
            check_book();
            break;
        
        case 2 :
            take_book();
            break;
        
        case 3 :
            return_book();
            break;
        
        case 4 :
            printf("\nSuccessfully exit the portal!!\n");
            isrunning=0;
            break;
        
        default:
            printf("\nenter the valid choice??: \n");


    }

}
 
        return 0;

}

void check_book(){

    int ch;
    
    FILE *file;
    file=fopen("sajan.txt","r");
    
    if (file==NULL){
        printf("NO BOOK !!! \n In your wallet right now");
    }
    
    printf("File opened successfully.\n here is book detail !\n");
    
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    
    fclose(file);   
    
}

void take_book(){
    FILE *file;
    char book[100];
    int choice=1;

    file = fopen("sajan.txt", "a");

    if (!file) {
        
        printf("\n (404) status code \n");
        fclose(file);
        
        return;
    }
    
    while (choice){
        
        printf("\nenter the book name-> ");
        scanf("%s",book);

        fputs(book, file);
        fputc('\n', file);

        printf("\nenter (1) for more book or (0) for not:  ->");
        scanf("%d",&choice);
    
    }  
    
    fclose(file);
    printf("\nsuccessfully added book !!!\n");

}


void return_book(){
    
    FILE *file,*temp;
    char content[100];
    
    int isrunning=1,found=0;

    file=fopen("sajan.txt", "r");
    temp=fopen("temp.txt","w");
    
    if (!file || !temp) {
        
        printf("\n 404 status code !!\n");
        fclose(file);
        
        return ;
    }

    while (isrunning){
        char *target=malloc(100);
        
        printf("\nenter the book'name for returning: ->\n");
        scanf("%s",target);

        while (fgets(content, sizeof(content), file)) {
            content[strcspn(content, "\n")] = 0;

            if (strcmp(content, target) != 0) {
                fprintf(temp, "%s\n", content);
               
            } 
            
            else {
                found = 1;
            }
    
    }   

    fclose(file);
    fclose(temp);

    if (found) {

        remove("sajan.txt");
        
        rename("temp.txt", "sajan.txt");
        printf("Book \"%s\" removed successfully.\n", target);

    } else {
        
        remove("temp.txt");
        printf("Book \"%s\" not found in file.\n", target);
        
    }

    printf("\nMore book need to return (1(yes) or 0(no)) -> \n");
    scanf("%d",&isrunning);
    
    free(target);
}

}