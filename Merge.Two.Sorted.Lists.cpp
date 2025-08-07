#include<iostream> 
#include<vector> 

using namespace std; 

struct ListNode{
public: 
     int val; 
     ListNode* next; 
     ListNode(): val(0), next(nullptr){}
     ListNode(int _val): val(_val), next(nullptr){}
     ListNode(int _val, ListNode* _next): val(_val), next(_next){}
};
class Solution{
public: 
     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode prehead(-1); 
       ListNode* curr = &prehead; 
       while(list1!=nullptr && list2!=nullptr){
         if(list1->val < list2->val){
           curr->next = list1; 
           list1 = list1->next; 
         }else{
           curr->next= list2; 
           list2 = list2->next; 
         }
         curr = curr->next; 
       }
       curr->next = list1==nullptr? list2:list1; 
       return prehead.next; 
     }
};
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Create first sorted list: 1 -> 3 -> 5
    int arr1[] = {1, 3, 5};
    ListNode* list1 = createList(arr1, 3);

    // Create second sorted list: 2 -> 4 -> 6
    int arr2[] = {2, 4, 6};
    ListNode* list2 = createList(arr2, 3);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    // Merge the two lists
    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}
