class DLLNode
{
public : 
    int key;
    int val;
    DLLNode* next;
    DLLNode* prev;
    DLLNode(int _key,int _val)
    {
        key = _key;
        val = _val;
    }
};
#include<bits/stdc++.h> 
class LRUCache
{
public:
    /*Take n which stores the capacity*/
    int n;
    /*HashTable to check whether key exists or not*/
    unordered_map<int,DLLNode*> map;
    /*Taking two dummy Nodes*/
    DLLNode* head = new DLLNode(-1,-1),*tail = new DLLNode(-1,-1);
    LRUCache(int capacity)
    {
        n = capacity;
        /*connecting both the tail and head nodes*/
        head->next = tail;
        tail->prev = head;
    }
    void deleteNode(DLLNode* currNode)
    {  
        /*Making prevNode->next point to nextNode*/
        currNode->prev->next = currNode->next;
        /*Making nextNode->prev point to prevNode*/
        currNode->next->prev = currNode->prev;
        delete currNode; /*deleting currNode from memory*/
    } 
    void addNode(int key,int value)
    {  
        DLLNode* currNode = new DLLNode(key,value);
        DLLNode* nextNode = head->next;
        head->next = currNode; /*making head->next point to currNode*/
        currNode->next = nextNode; /*currNode->next point to head->next*/
        currNode->prev = head; /*currNode->prev points to head*/
        nextNode->prev = currNode; /*nextNOde->prev points to currNode*/
    } 
    /*
    Two cases are possible for get
    Case 1 : If key already exists in the cache
       a. Then this will become the recently visited cache.
       b. So delete the node from it's current location.
       c. Insert new node with the provided key and Value at the next of headNode.
    case 2 : key doesn't exists in cache so return -1
    */
    int get(int key)
    { 
       //case 1
       if(map.find(key) != map.end())
       {  
           DLLNode* existingNode = map[key];
           int value = existingNode->val;
           deleteNode(existingNode); /*Deleting the previous occurence of node*/
           map.erase(key); /*Deleting the previous occurence of the node in map*/
           addNode(key,value); /*Adding new occurence as head->next*/
           map[key] = head->next; /*New occurence is at head->next,so taking
           new occurence into map*/
           return value;
       }
       //case 2
       else  return -1;
    } 
    /*
    There may be 3 cases possible,while inserting node into LRU cache.
    1.Case 1 : If key already exists in the cache
       a. Then this will become the recently visited cache.
       b. So delete the node from it's current location.
       c. Insert new node with the provided key and newValue at the next of headNode.
    2. Case 2 : If the cache is full
       a.Then we should delete the Least recently used node.
       b.LRU is the previous Node of tail,so delete the LRU Node.
       c.Insert new node with the provided key and value at the next of headNode.
    3.case 3 : Cache is not full
       a.Now coming node will be most recently visited node.
       b.So Insert new node with the provided key and value at the next of headNode.
    */
    void put(int key, int value)
    {
       //case 1 
       if(map.find(key) != map.end())
       {
           DLLNode* existingNode = map[key];
           deleteNode(existingNode); /*Deleting the previous occurence of node*/
           map.erase(key); /*Deleting the previous occurence of the node in map*/
       }
       //case 2 
       if(map.size() == n)
       {
           DLLNode* LRUNode = tail->prev;
           map.erase(LRUNode->key); /*deleting the LRU Node from map*/
           deleteNode(LRUNode); /*deleting the LRU node*/
       }
       //case 3
       /*In every case we are adding new Node and inserting into map the new
       occurence,so doing it only once.*/

       addNode(key,value); /*Adding new occurence as head->next*/
       map[key] = head->next; /*New occurence is at head->next,so taking
           new occurence into map*/
    }
};
