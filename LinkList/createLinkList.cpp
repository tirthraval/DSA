#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
    public:
        Node(int data1, Node* temp){
            data = data1;
            next = temp;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};
Node* convertToLinkList(vector<int> &arr){
    Node*head = nullptr;
    //{1,2,5,6,7,8}
    for(int i = 0; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        head = temp;

    }
    return head;
}

void printLinkList(Node *head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data;
        temp = temp->next;
    }
}

Node* deleteHead(Node* head){
    Node* temp =head;
    if(head == NULL)
        return;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL)
        return;
    Node* temp = head;
    while(temp != NULL){
        if(temp->next->next == nullptr)
            delete temp->next;
        temp = temp->next;
    }
}

Node* deleteK(Node* head, int k){
    if(head == NULL)
        return;
    if(k == 1){
        Node*temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node *prev = NULL;
    int cnt = 0;

    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertfirst(Node* head, int val){
    Node *temp = new Node(val, NULL);
    temp->next = head;
    head = temp;
    return head;

}
Node* insertLast(Node* head, int val){
     if( head == NULL){
        return new Node(val);
    }
    //there are multiple node
    Node *temp = head;
    while(temp->next != NULL){ 
       temp = temp->next;
    }
     Node * newNode = new Node(val);
     temp->next = newNode;
         
    return head;


}
Node* insertK(Node* head, int val, int k){
        if(head == NULL){
            return;
        }
        Node* temp = head;
        while(k > 1){
            temp = temp->next;
            k--;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
}

int main()
{

    Node*x = new Node(5); //create the node 
    //create the list from arr

    vector<int> arr = {1,2,5,6,7,8};
    Node* head =  convertToLinkList(arr);
    
}