typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}
void append(Node** head, int data){
    Node* newNode = createNode(data);

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void removeNode(Node** head, int data)
{
    if (*head == NULL)
        return;

    Node* temp = *head;

    // 헤드 삭제
    if (temp->data == data)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    // 다음 노드 검사
    while (temp->next != NULL)
    {
        if (temp->next->data == data)
        {
            Node* del = temp->next;
            temp->next = temp->next->next;
            free(del);
            return;
        }

        temp = temp->next;
    }
}

void printList(Node* head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(void)
{
    Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);

    removeNode(&head, 20);
    printList(head);
    return 0;
}