/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
    public:
        RandomListNode *copyRandomList(RandomListNode *head) {
            if (head == NULL) return NULL;
            RandomListNode* cur = head;
            RandomListNode* result = NULL;

            // create the copy of the list and put elements next to ones in the original list
            // to make it easier to set the random element later
            while (cur) {
                RandomListNode* n = new RandomListNode(cur->label);
                n->next = cur->next;
                cur->next = n;
                cur = n->next;
                if (result == NULL) result = n;
            }

            // next step - we set up proper random pointers using the previously built list
            cur = head;
            while (cur) {
                RandomListNode* n  = cur->next;
                if (cur->random) n->random = cur->random->next;
                cur = n->next;
            }

            // now we can remove temporary links from the original list
            cur = head;
            while(cur) {
                RandomListNode* n = cur->next;
                cur->next = n->next;
                if (cur->next) n->next = cur->next->next;
                cur = cur->next;
            }

            return result;
        }
};
