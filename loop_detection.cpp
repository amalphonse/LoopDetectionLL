#include<iostream>

using namespace std;

struct node {
	int data;
	node* next;
};

node* getNewNode(int data) {
	node* newNode = new node();
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

node* Insert_at_end(node* head, int data) {
	if (head == NULL) {
		head = getNewNode(data);
	}
	else {
		node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = getNewNode(data);
	}
	return head;
}

node* loop_detection(node* head) {
	node* slow = head;
	node* fast = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			break;
		}
	}

	slow = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}
void print(node* head) {
	if (head == NULL)
		return;
	node* temp = head;
	while (temp)
	{
		cout << temp->data << endl;
		temp = temp->next;

	}

}


int main() {
	node* root = NULL;
	root = Insert_at_end(root, 1);
	root = Insert_at_end(root, 2);
	root = Insert_at_end(root, 3);
	root = Insert_at_end(root, 4);
	root = Insert_at_end(root, 5);
	print(root);
	root->next->next->next->next = root;

	cout << loop_detection(root)->data << endl;



	return 0;
}