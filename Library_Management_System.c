#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>

struct Books
{
    int bookid;
    char name[700];
    char author[600];
    char cat[500];
    struct Books *next;
    
}* head;

void insert(int bookid, char* name, char* author, char* cat)
{
	
    struct Books * book = (struct Books *) malloc(sizeof(struct Books));
 book->bookid = bookid;
 strcpy(book->name, name);
 strcpy(book->author, author);
 strcpy(book->cat, cat);
 book->next = NULL;
	
 if(head==NULL){
  // if head is NULL
  // set book as the new head
  head = book;
 }
 else{
  // if list is not empty
  // insert book in beginning of head
  book->next = head;
  head = book;
 }
	
}

void searchid(int bookid)
{
    struct Books * temp = head;
 while(temp!=NULL){
  if(temp->bookid==bookid){
  	SetColor(7);
   printf("\nBook ID: %d\n", temp->bookid);
   printf("Name: %s\n", temp->name);
   printf("Author: %s\n", temp->author);
   printf("Category: %s\n", temp->cat);
   SetColor(15);
   return;
  }
  temp = temp->next;
 }
 SetColor(12);
 printf("Book with ID number %d is not found !!!\n", bookid);
 SetColor(15);
}

void searchbook(char name[700])
{
    struct Books * temp = head;
 while(temp!=NULL){
  if(strcmp(temp->name,name)==0) 
  {
  	SetColor(7);
   printf("\nBook ID: %d\n", temp->bookid);
   printf("Name: %s\n", temp->name);
   printf("Author: %s\n", temp->author);
   printf("Category: %s\n", temp->cat);
   SetColor(15);
   return;
  }
  
  temp = temp->next;
 }
 SetColor(12);
 printf("Book with name %s is not found !!!\n", name);
 SetColor(15);
}

void searchauthor(char author[600])
{
    struct Books * temp = head;
 while(temp!=NULL){
  if(strcmp(temp->author,author)==0) 
  {
  	SetColor(7);
   printf("\nBook ID: %d\n", temp->bookid);
   printf("Name: %s\n", temp->name);
   printf("Author: %s\n", temp->author);
   printf("Category: %s\n", temp->cat);
   SetColor(15);
   return;
  }
  temp = temp->next;
 }
 SetColor(12);
 printf("Book with author name %s is not found !!!\n", author);
 SetColor(15);
}

void searchcat(char cat[500])
{
    struct Books * temp = head;
 while(temp!=NULL){
  if(strcmp(temp->cat,cat)==0) 
  {
  	SetColor(7);
   printf("\nBook ID: %d\n", temp->bookid);
   printf("Name: %s\n", temp->name);
   printf("Author: %s\n", temp->author);
   printf("Category: %s\n", temp->cat);
   SetColor(15);
   return;
  }
  temp = temp->next;
 }
 SetColor(12);
 printf("Book with category name %s is not found !!!\n", cat);
 SetColor(15);
}

void update(int bookid)
{
	
    struct Books * temp = head;
 while(temp!=NULL){
  
  if(temp->bookid==bookid){
  	SetColor(10);
   printf("Record with Book ID number %d Found !!!\n", bookid);
   SetColor(15);
   printf("Enter the Book Name: ");
   scanf("%s", temp->name);
   printf("Enter the Author Name: ");
   scanf("%s", temp->author);
   printf("Enter the Category Name: ");
   scanf("%s", temp->cat);
   SetColor(10);
   printf("Updation Successful!!!\x2\x2\x2\n");
   SetColor(15);
   return;
  }
  temp = temp->next;
  
 }
 SetColor(12);
 printf("Book with ID number %d is not found !!!\n", bookid);
 SetColor(15);
	
}

void Delete(int bookid)
{

    struct Books * temp1 = head;
 struct Books * temp2 = head; 
 while(temp1!=NULL){
  
  if(temp1->bookid==bookid){
   SetColor(10);
   printf("Record with Book ID number %d Found !!!\n", bookid);
   SetColor(15);
   
   if(temp1==temp2){
    // this condition will run if
    // the record that we need to delete is the first node
    // of the linked list
    head = head->next;
    free(temp1);
   }
   else{
    // temp1 is the node we need to delete
    // temp2 is the node previous to temp1
    temp2->next = temp1->next;
    free(temp1); 
   }
   SetColor(10);
   printf("Record Successfully Deleted !!!\n");
   SetColor(15);
   return;
   
  }
  temp2 = temp1;
  temp1 = temp1->next;
  
 }
 SetColor(12);
 printf("Book with ID number %d is not found !!! Recheck the ID\n", bookid);
 SetColor(15);
	
}

void display()
{
    struct Books * temp = head;
 while(temp!=NULL){
  
  printf("Book ID : %d\n", temp->bookid);
  printf("Book Name: %s\n", temp->name);
  printf("Author Name: %s\n", temp->author);
  printf("Category Name: %s\n", temp->cat);
  temp = temp->next;
  
 }
}


void SetColor(int ForgC)
 {
     WORD wColor;

      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                 //Mask out all but the background attribute, and add in the forgournd     color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 }

void greetings()
{
	SetColor(14);
    printf("\n\n");
    printf("\t\t\t       *************************************************\n");
    printf("\t\t\t       *\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB*\n");
    printf("\t\t\t       *\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2*\n");
    printf("\t\t\t       *     -------------------------------------     *\n");
    printf("\t\t\t       *      WELCOME TO LIBRARY MANAGEMENT SYSTEM     *\n");
    printf("\t\t\t       *     -------------------------------------     *\n");
    printf("\t\t\t       *\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2*\n");
    printf("\t\t\t       *\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB*\n");
    printf("\t\t\t       *************************************************\n");
    printf("\n\n");
    SetColor(9);
	printf("\t\t\t     *****************************************************\n");
    printf("\t\t\t     *\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB*\n");
    printf("\t\t\t     *\xDB\xB2\xDB\xB2         ------------------------          \xB2\xDB\xB2\xDB*\n");
    printf("\t\t\t     *\xDB\xB2\xDB\xB2            BY ABIRAMI MANISA              \xB2\xDB\xB2\xDB*\n");
    printf("\t\t\t     *\xDB\xB2\xDB\xB2         ------------------------          \xB2\xDB\xB2\xDB*\n");
    printf("\t\t\t     *\xDB\xB2\xDB\xB2                                           \xB2\xDB\xB2\xDB*\n");
    printf("\t\t\t     *\xDB\xB2\xDB\xB2                                           \xB2\xDB\xB2\xDB*\n");
    printf("\t\t\t     *\xDB\xB2\xDB\xB2         Coimbatore,Tamil Nadu,India       \xB2\xDB\xB2\xDB*\n");
    printf("\t\t\t     *\xDB\xB2\xDB\xB2                                           \xB2\xDB\xB2\xDB*\n");
    printf("\t\t\t     *\xDB\xB2\xDB\xB2                                           \xB2\xDB\xB2\xDB*\n");
    printf("\t\t\t     *\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB\xB2\xDB*\n");
    printf("\t\t\t     *****************************************************\n");
    SetColor(15);
    printf("\n\n\t\t\t               Press any key to continue: ");
    getch();
}


int main()
{
    head = NULL;
    int choice,n;
    char name[700];
    char author[600];
    int bookid;
    char cat[500];
    greetings();


do
{
   SetColor(11);
	printf("\n\t\xDB2\xDB2\xDB2\xDB2 MENU \xDB2\xDB2\xDB2\xDB2\t\n");
SetColor(13);	
printf("\n Enter 1 \xB10\xB10 Add book details\n Enter 2 \xB10\xB10 Search book details\n Enter 3 \xB10\xB10 Delete book details \n Enter 4 \xB10\xB10 Update book details\n Enter 5 \xB10\xB10 Display all book details\n Enter 6 \xB10\xB10 Exit\n");   
 SetColor(15);
        printf("\n\n Enter your preference: ");
        scanf("%d", &choice);
		SetColor(10);
        switch (choice)
        {
        	
            case 1:
                printf("Enter the Book ID: ");
                scanf("%d", &bookid);
                printf("Enter the Book Name: ");
                scanf("%s", name);
                printf("Enter the Book Author: ");
                scanf("%s", author);
                printf("Enter the Category Name: ");
                scanf("%s", cat);
                insert(bookid, name, author, cat);
                break;
            case 2:
            	SetColor(11);
                printf("Select the option to search: \n");
                printf("  1.Search by Book ID\n  2.Search by Book Name\n  3.Search by Author Name\n  4.Search by Category Name\n");
                
                	printf("Enter your preference of search: ");
                	scanf("%d",&n);
                	switch(n)
                	{
                		case 1:
                			printf("Enter the Book ID to search: ");
						    scanf("%d", &bookid);
						    searchid(bookid);
						    break;
				        case 2:
				        	printf("Enter the Book Name to search: ");
				    	    scanf("%s",&name);
						    searchbook(name);
						    break;
						case 3:
				        	printf("Enter the Author Name to search: ");
				    	    scanf("%s",&author);
						    searchauthor(author);
						    break;
						case 4:
				        	printf("Enter the Category Name to search: ");
				    	    scanf("%s",&cat);
						    searchcat(cat);
						    break;	    
					    default:
					    	printf("Enter the correct search preference..");
						    break;	
			        }
			        break;
				
                
			    
			
            case 3:
            	SetColor(2);
                printf("Enter the Book ID to delete: ");
                scanf("%d", &bookid);
                Delete(bookid);
                break;
            case 4:
            	SetColor(7);
                printf("Enter the Book ID  to update: ");
                scanf("%d", &bookid);
                update(bookid);
                break;
            case 5:
                display();
                break;
            case 6:
            	exit(0);
            	break;
                	
            default:
            	printf("Enter the correct preference...");
            	getch();
                	
        }
        
    } while (choice != 0);

}
