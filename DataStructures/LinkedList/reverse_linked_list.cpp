// (3 pointer (newhead/prev , curr/head ,  next) | T.C. = O(N), S.C = O(1))
ListNode *reverseList(ListNode *head)
{
  ListNode *prev = NULL, *next = NULL;
  while (head)
  {
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }
  return prev;
}