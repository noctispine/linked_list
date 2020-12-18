#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

struct IDs 
{
  int ID;
  int age;
  int licence_ID;
  char blood_type[5];
  char name[50];
  struct IDs* next;
};

typedef struct IDs Node;


Node*create_node(int ID, int age, int licence_ID, char bloodtype[], char name[]);
void print_IDs(Node* Node);

int main(void) {
  char str[30];
      
  int id;
  int age;
  int licence_ID;
  char blood_type[5];
  char name[50];

  FILE * pFile;
  pFile = fopen("IDs.txt","r");
  
  if (pFile == NULL)
    printf ("Error opening file unexist %s\n", strerror(errno));
  else
  {

    Node* head = create_node(0, 0, 0, "", "");
    Node* curr = head;

    
    

    for (int i = 0;fgets(str, 30, pFile); i++){
        str[strlen(str) - 1] = '\0';
        if (i % 5 == 0 ){
            id = atoi(str);
        }
        else if ((i-1) % 5 == 0 ){
            age = atoi(str);
        }
        else if((i-2) % 5 == 0){
            licence_ID = atoi(str);
        }
        else if((i-3) % 5 == 0){
            strcpy(blood_type, str);
        }
        else if ((i-4) % 5 == 0){
            strcpy(name, str);
        }
        if ((i-4) % 5 == 0){

            if(i == 4){
                
            }
         
            Node* ptr = create_node(id, age, licence_ID, blood_type, name);
            curr->next = ptr;
            curr = ptr;
          
        } 
    }

    printf("printing the linked list\n\n");
    
    int cnt = 0;
    curr = head;
    while(curr != NULL) {
        if (cnt > 0)
          print_IDs(curr);
        curr = curr->next;
        cnt++;
    }

    curr = head;
    head = NULL;
    Node* old_node;
    while( curr != NULL) {
        old_node = curr;
        curr = curr->next;
        free(old_node);
    }

    curr = old_node = NULL;
  }
  

  return 0;
}



Node* create_node(int ID, int age, int licence_ID, char bloodtype[], char name[]) {

  Node* ptr = (Node*)malloc(sizeof(Node));
  ptr->ID = ID;
  ptr->age = age;
  ptr->licence_ID = licence_ID;
  strcpy(ptr->blood_type, bloodtype);
  strcpy(ptr->name, name);

  return ptr;
}

void print_IDs(Node* node) {
    printf("%d\n%d\n%d\n%s\n%s\n\n", node->ID, node->age, node->licence_ID, node->blood_type, node->name);
}