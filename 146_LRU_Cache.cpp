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

struct dllnode * insertInFront( int key , int data)
{
    // create new  node and insert in front  left 
    struct dllnode * newNode =  new  dllnode(key, data);
    if(leftptr == NULL) // entering first node in DLL
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
int removeLRU(void)
{ 
    int rkey =rightptr->key;
    // delete last node in DLL
   if(leftptr == rightptr) // single node in DLL
   {
     delete rightptr;
     leftptr = rightptr= NULL;
   }
   else
   {
     struct dllnode *todelete = rightptr;
     rightptr = rightptr->prev;
     rightptr->next = NULL;
     delete todelete;
   }
  return rkey;
}
void remove(struct dllnode * nNode)
{
  if(nNode->prev)
  {
        nNode->prev->next = nNode->next;
  }
  if(nNode->next)
  {
    nNode->next->prev = nNode->prev;
  }
  if(nNode==leftptr)
    leftptr = leftptr->next;
  if(nNode==rightptr)
    rightptr = rightptr->prev;
    return;
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
            return -1; // not found
        else
        {
            // element is in cache 
            // delete that found node in DLL 
            int value = found->second->value;
            remove(found->second);
            //insert similar node in DLL and update pointer enty in Hash
            struct dllnode * nNode = insertInFront(key,value);
            hashMap[key] = nNode;
            return found->second->value;
        }   
    }
    
    void put(int key, int value) {
        // search if found just update  I didnt read question properly and forgot this condition 
        // else insert in insert if its full make space 
        std::unordered_map<int,struct dllnode *>::const_iterator found = hashMap.find (key);
        if(found != hashMap.end() )
        {  // element is in cache 
            // delete that found node in DLL 
            remove(found->second);
            //insert similar node in DLL and update pointer enty in Hash
            struct dllnode * nNode = insertInFront(key,value);
            hashMap[key] = nNode;
        }
        else 
        { // insert new  entry in LL and hashmap
            if(hashMap.size()==g_capacity)
            { // Hash is  full , remove LRU node and remove its entry from Hash
                int rkey = removeLRU();
                hashMap.erase(rkey);            
            }
            struct dllnode * nNode = insertInFront(key,value);
            hashMap[key] = nNode;
        }
        
     }
};
void printDLL(void)
{
    struct dllnode * st = leftptr;
    while(st)
    {
        cout<<"("<<st->key<<","<< st->value<<")";
        if(st->next)
            cout<<" --> ";
     st = st->next;
    }
    cout<<endl;
}
int main()
{
    int capacity = 2;
    LRUCache* cache = new LRUCache(capacity);
    cache->put(1, 0);
    printDLL();
    cache->put(2, 2); // cache is {1=1, 2=2}
    printDLL();
    int value = cache->get(1);    // return 1
    cout<<"Get of 1 returned : "<<value<<endl;
    cache->put(3, 3); // LRU key was 2, evicts key 2, cache is v{1=1, 3=3}
    printDLL();
    value =cache->get(2);    // returns -1 (not found)
    printDLL();
    cache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    printDLL();
    value =cache->get(1);    // return -1 (not found)
    cout<<"Get of 1 returned : "<<value<<endl;
    value =cache->get(3);    // return 3
    cout<<"Get of 3 returned : "<<value<<endl;
    printDLL();
    value =cache->get(4);    // return 4
    cout<<"Get of 4 returned : "<<value<<endl;
    printDLL();

    return 0;
}
