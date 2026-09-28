# Linked List Handbook

---

## 1. Node Definition & Traversal

```cpp
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Traversal
ListNode* temp = head;
while (temp != nullptr) {
    cout << temp->val << " ";
    temp = temp->next;
}
```

---

## 2. Classic Patterns & Solutions

### Pattern 1: Reversing a Linked List (LC 206)
**3-Pointer Idiom (`prev`, `curr`, `front`):**

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    
    while (curr != nullptr) {
        ListNode* front = curr->next; // 1. Save next node
        curr->next = prev;            // 2. Reverse link
        prev = curr;                  // 3. Advance prev
        curr = front;                 // 4. Advance curr
    }
    return prev; // New head
}
```

---

### Pattern 2: Merge Two Sorted Lists (LC 21)
```cpp
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;
    
    ListNode* head = (list1->val < list2->val) ? list1 : list2;
    if (head == list1) list1 = list1->next;
    else list2 = list2->next;
    
    ListNode* curr = head;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            curr->next = list1;
            list1 = list1->next;
        } else {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }
    curr->next = list1 ? list1 : list2; // Attach remainder
    return head;
}
```

---

### Pattern 3: Cycle Detection (Floyd’s Tortoise & Hare - LC 141)
- Fast pointer moves 2 steps, slow pointer moves 1 step.
- If cycle exists, they are guaranteed to meet inside the cycle in $\mathcal{O}(n)$ time and $\mathcal{O}(1)$ space.

```cpp
bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}
```

---

### Pattern 4: Remove N-th Node From End (LC 19)
**Maintain a fixed gap of $n$ nodes:**
1. Advance `back` pointer $n$ steps ahead.
2. If `back == nullptr`, we must delete the head (`return head->next`).
3. Advance both `front` and `back` until `back->next == nullptr`.
4. `front` is now immediately before the target node $\rightarrow$ `front->next = front->next->next`.

```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* front = head;
    ListNode* back = head;
    
    for (int i = 0; i < n; i++) back = back->next;
    if (!back) return head->next; // Head deletion case
    
    while (back->next) {
        front = front->next;
        back = back->next;
    }
    front->next = front->next->next;
    return head;
}
```
> **Mistake Prevention:** Keep gap exactly $n$, always check if head deletion occurs when `back` becomes `nullptr`.
