/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    string rev_and_add(string s, string t){
        int slen = s.length(), tlen = t.length();
        while(slen < tlen)s += '0', slen++;
        while(tlen < slen) t += '0', tlen++;
        
        reverse(begin(s), end(s));
        reverse(begin(t), end(t));
        
        string res;
        int carry = 0;
        
        for(int i = slen - 1; i >= 0; i--){
            int d1 = s[i] - '0';
            int d2 = t[i] - '0';
            int sum = carry + d1 + d2;
            int add = sum % 10;
            res += (add + '0');
            carry = sum / 10;
        }
        
        while(carry)res += ((carry % 10) + '0'), carry /= 10;
        reverse(begin(res), end(res));
        return res;
        
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s, t, r;
        while(l1 != NULL)s += (l1->val + '0'), l1 = l1->next;
        while(l2 != NULL)t += (l2->val + '0'), l2 = l2->next;
        
        r = rev_and_add(s, t);
        ListNode *node = new ListNode(r.back() - '0');
        r.pop_back();
        ListNode *head = node;
        
        while(!r.empty()){
            node->next = new ListNode(r.back() - '0');
            r.pop_back();
            node = node->next;
        }
        return head;
    }
};