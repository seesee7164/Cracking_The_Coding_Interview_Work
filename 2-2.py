#!/usr/bin/env python3

node * fromLast(int k):
    i = 0
    node * currnode = startnode
    while i < k:
        if currnode.nextnode != NULL:
            currnode = currnode.nextnode
            i+=1
        else:
            print("there were fewer than k nodes in the linked list")
            return NULL
    node* currnode2 = startnode
    while currnode.nextnode != NULL:
        currnode2 = currnode2.nextnode
        currnode = currnode.nextnode
    return currnode2