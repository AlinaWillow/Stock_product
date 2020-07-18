#include <stdio.h>
#include <stdlib.h>
//function prototype
void alignmid(char[]);
void alignlef(char[]);
void main();
void get_file();
void add();
void dele();

void menu(){

    alignmid("MAIN MENU\n\n");

    alignlef("1.Check stock\n");
    alignlef("2.Add items\n");
    alignlef("3.Delete items\n");
    alignlef("4.Quit\n");


}


void main(){
    system("cls");
    menu();
    int m;

        printf("enter the number: ");
        scanf("%d",&m);


    if(m==1){
        get_file();
    }
    else if(m==2){
        add();
    }
    else if(m==3){
        dele();
    }



}


void get_file(){
    char name_item[30];

    FILE *f ;
    f = fopen("data.txt","r");

if (f == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    system("cls");
    alignmid("CHECK STOCK");
    alignlef("Name\t\tamount\n");
    alignlef("_______________________\n");

    while (fgets(name_item,30,f)!= NULL)
    {
        alignlef(("%s\n",name_item));


    }
    fclose(f);

    char go_menu[2];
    printf("\n Go back to menu?[Y/N]: ");
    scanf("%s",go_menu);
    if(strcmp (go_menu,"Y")==0||strcmp (go_menu,"y")==0){
        main();
    }
    else exit(0);


}


void add(){
    char add_deci[2];
    system("cls");

    printf("Enter new record[Y/N]: ");
    scanf("%s",add_deci);


    while (strcmp (add_deci,"Y" )==0||strcmp (add_deci,"y" )==0){
        system("cls");
        alignmid("ADD ITEM");
        char name_item[30];
        int amount_item;
        FILE *f ;
        f = fopen("data.txt","a+");


        if(f == NULL){
        printf("File could not be opened");
        exit(0);
        }
            {

            printf("Name of new item: ");
            scanf("%s",name_item);
            printf("amount of %s: ",name_item);
            scanf("%d",&amount_item);
            fprintf(f,"%s\t\t%d\n",name_item,amount_item);
            printf("\n\n** New item is already recorded!**\n\n");
            fclose(f);
            printf("Enter new record[Y/N]?");
            scanf("%s",add_deci);

            }


        }
        main();
    }


void dele(){

    system("cls");
    char add_deci[2];

    printf("delete item? [Y/N]: ");
    scanf("%s",add_deci);

    while (strcmp (add_deci,"Y" )==0||strcmp (add_deci,"y" )==0){
        system("cls");
        alignmid("DELETE ITEM");
        FILE*f;
        FILE*file2;
        char file_data;
        int delete_line, temp=1;

        f = fopen("data.txt","r");
        file_data = getc(f);

        while (file_data != EOF)
        {
            printf("%c", file_data);
            file_data = getc(f);
        }
        rewind(f);
        printf(" \nEnter number of the line to be deleted:");
        scanf("%d", &delete_line);
        //open new file in write mode
        file2 = fopen("copy.txt", "w");
        file_data = 'A';
        while (file_data != EOF)
        {
            file_data = getc(f);
            //except the line to be deleted
            if (temp != delete_line)
            {
                //copy all lines in file data.txt
                putc(file_data, file2);
            }
            if (file_data == '\n')
            {
                temp++;
            }
        }
        fclose(f);
        fclose(file2);
        remove("data.txt");

        rename("copy.txt", "data.txt");
        printf("\nThe new record is\n\n");

        f = fopen("data.txt", "r");
        file_data = getc(f);

        while (file_data != EOF)
        {
            printf("%c", file_data);
            file_data = getc(f);
        }
        fclose(f);

        printf("\ndelete item? [Y/N]:");
        scanf("%s",add_deci);

    }
    main();
}

void alignmid(char input[]){

    int i,len;
    len=strlen(input);

    printf("\n");
    for(i=0; i<(40-(len/2)); i++)
        printf(" ");

    printf("%s",input);

    for(i=0; i<(40-(len/2)); i++)
        printf(" ");

    printf("\n");


}

void alignlef(char input[]){
    int i;
    for(i=0;i<30;i++){
        printf(" ");
    }
    printf("%s",input);
    printf("\n");
}

