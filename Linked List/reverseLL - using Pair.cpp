#include <bits/stdc++.h>

// T = O(n) , S = O(n)

pair<Node*, Node*> helper(Node *head){

    if(head == NULL || head->next == NULL) {
        pair<Node *, Node *> ans(head, head);
        return ans;
    }

    pair<Node * ,Node *> newAns = helper(head->next);

    if(newAns.second != NULL){
        newAns.second->next = head;
        head->next = NULL;

        newAns.second = head;
        return newAns;
    }

} 

Node *reverseLinkedListRec(Node *head)
{
    //Write your code here

    return helper(head).first;

}