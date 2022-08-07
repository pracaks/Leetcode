#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;
/*
hash map is to search a node in O(1) which wil have key and pointer to  DLL node
DLL node will have left side newest node and right side oldest node.
if new entry add node in DLL at left side . Add entry in hash too.

*/
struct dllnode{
     int key;
     int value;
     struct dllnode * next;
     struct dllnode * prev;
     dllnode(int key, int value )
        : key(key), value(value)    {
            next = NULL;
            prev = NULL;
    }
};
struct dllnode * leftptr = NULL;
struct dllnode * rightptr = NULL;
void movetoFront( struct dllnode * node)
{
    if(leftptr==node)
    {
       //already front 
       return;
    }
    else if(rightptr == node)
    {   //its last node and atleast two node are there in DLL 
        //cut 
        node->prev->next = NULL;
        rightptr = node->prev;
        //prepare
        node->prev = NULL;
        node->next = leftptr;
        node->next->prev= node;
        //paste
        leftptr = node;
        
        return;
    }
    else
    {   // middle node;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = leftptr;
        node->prev = NULL;
        leftptr = node;
        return;
    }
}
struct dllnode * insertInFront( int key , int data)
{
    // create new  node and insert in front  left 
    struct dllnode * newNode =  new  dllnode(key, data);
    if(leftptr == NULL) // first node  DLL
    {
       leftptr = rightptr = newNode;
    } 
    else
    {
        newNode->next = leftptr;
        leftptr->prev =  newNode;
        leftptr = newNode;
    }
    return newNode;
}
int removefromBack(void)
{
  // delete last node , node from back / right
  struct dllnode * lastNode = rightptr;
  if(rightptr != leftptr) // there are atleast two node 
  {
     rightptr = lastNode->prev; // if size is 1 this can be null
     rightptr->next = NULL;
  }
  else
  {
      leftptr = rightptr = NULL;
  }
  
  int val = lastNode->value;
  delete lastNode;
  return val;
}
int g_capacity;
unordered_map <int, struct dllnode * > hashMap; 
class LRUCache {   
public:
    LRUCache(int capacity) {
        g_capacity = capacity;
        hashMap.clear();
    }    
    int get(int key) {
        std::unordered_map<int,struct dllnode *>::const_iterator found = hashMap.find (key);
        if ( found == hashMap.end() )
            return -1;
        else
        {
            movetoFront(found->second); // update the node to bring it to front;
            return found->second->value;
        }   
    }
    
    void put(int key, int value) {
        // search if found just update  I didnt read question properly and forgot this condition 
        // else insert in insert if its full make space 
        std::unordered_map<int,struct dllnode *>::const_iterator found = hashMap.find (key);
        if(found != hashMap.end() )
        {  // element is in cache 
            found->second->value = value;
            movetoFront(found->second); // update the node to bring it to front;
        }
        else 
        { // insert new  entry in LL and hashmap
            if(hashMap.size()==g_capacity)
            { // its full 
                int rkey = removefromBack();
                hashMap.erase(rkey);            
            }
            struct dllnode * nNode = insertInFront(key,value);
            hashMap[key] = nNode;
        }
        
     }
};
int main()
{
    int capacity = 3;
    LRUCache* cache = new LRUCache(capacity);
    cache->put(1, 0);
    cache->put(2, 2); // cache is {1=1, 2=2}
    int value = cache->get(1);    // return 1
    cache->put(3, 3); // LRU key was 2, evicts key 2, cache is v{1=1, 3=3}
    value =cache->get(2);    // returns -1 (not found)
    cache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    value =cache->get(1);    // return -1 (not found)
    value =cache->get(3);    // return 3
    value =cache->get(4);    // return 4

    return 0;
}
