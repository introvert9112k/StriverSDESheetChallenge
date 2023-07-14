class DLLNode
{
public:
    /*Node contains three values
      key -- key of the node
      value -- value of the key
      freq -- frequencey of the key in LFU cache
    */
    int key, val, freq;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int _key, int _val, int _freq)
    {
        key = _key;
        val = _val;
        freq = _freq;
    }
};

class LFUCache
{
public:
    int minFreq = 0;                                        /*Keeps track of the minimum Freq in cache*/
    int currSize = 0;                                       /*keeps track of the size of cache*/
    int maxCacheSize;                                       /*for storing the capacity of the cache*/
    unordered_map<int, DLLNode *> keyMap;                   /*For finding the existence of key in cache*/
    unordered_map<int, pair<DLLNode *, DLLNode *>> freqMap; /*for keep track of freq and its DLL head*/
    LFUCache(int capacity)
    {
        maxCacheSize = capacity; /*Taking capacity into maxCacheSize*/
    }

    void deleteNode(DLLNode *currNode)
    {
        /*Making prevNode->next point to nextNode*/
        currNode->prev->next = currNode->next;
        /*Making nextNode->prev point to prevNode*/
        currNode->next->prev = currNode->prev;
    }

    pair<DLLNode *, DLLNode *> createFreqList()
    {
        DLLNode *head = new DLLNode(-1, -1, -1);
        DLLNode *tail = new DLLNode(-1, -1, -1);
        head->next = tail;
        tail->prev = head;
        return {head, tail};
    }

    void addFront(int freq, DLLNode *currNode)
    {
        DLLNode *head = freqMap[freq].first;
        DLLNode *nextNode = head->next;
        head->next = currNode;     /*making head->next point to currNode*/
        currNode->next = nextNode; /*currNode->next point to head->next*/
        currNode->prev = head;     /*currNode->prev points to head*/
        nextNode->prev = currNode; /*nextNOde->prev points to currNode*/
    }
    void updateFreqList(int freq, DLLNode *currNode)
    {
        /*Deleting the node from current frequence list*/
        deleteNode(currNode);
        /*There may be case like,current freq is the minFreq and current
        deleted node is the lastNode in the freqList,then minFreq should be
        updated to the next i.e minFreq = minFreq+1*/
        if (minFreq == freq)
        {
            DLLNode *head = freqMap[freq].first;
            DLLNode *tail = freqMap[freq].second;
            if (head->next == tail)
            {
                ++minFreq;
                /*As the previous freqList is empty,erasing it from the freqMap*/
                freqMap.erase(freq);
            }
        }
        ++freq;           /*incrementing the freq*/
        currNode->freq++; /*Incrementing the frequency of the node*/
        /*checking whether the next frequency list exists or not.
        If not creating a frequencyList*/
        if (freqMap.find(freq) == freqMap.end())
            freqMap[freq] = createFreqList();
        /*inserting the currNode in new Frequency list*/
        addFront(freq, currNode);
    }
    int get(int key)
    {
        /*If key exists in the cache*/
        if (keyMap.find(key) != keyMap.end())
        {
            /*accessing the node*/
            DLLNode *existingNode = keyMap[key];
            int freq = existingNode->freq; /*finding freq of the key*/
            int value = existingNode->val; /*finding the value of the key*/
            /*This function will update the freqList*/
            updateFreqList(freq, existingNode);
            /*returning the value*/
            return value;
        }
        /*If key is not present returning -1*/
        return -1;
    }

    void put(int key, int value)
    {
        /*If the key exists in cache,then we need to update the cache*/
        if (keyMap.find(key) != keyMap.end())
        {
            /*accessing the node*/
            DLLNode *existingNode = keyMap[key];
            int freq = existingNode->freq; /*finding freq of the key*/
            existingNode->val = value;     /*updating the value*/
            /*This function will update the freqList*/
            updateFreqList(freq, existingNode);
        }
        else
        {
            if (currSize == maxCacheSize)
            {
                /*finding the tail node of the minFreq list*/
                DLLNode *tailNode = freqMap[minFreq].second;
                /*finding the last recently used node in the minFreq list*/
                DLLNode *LRUNode = tailNode->prev;
                int key = LRUNode->key;
                /*deleting the key from the key Map*/
                keyMap.erase(key);
                /*deleting the node*/
                deleteNode(LRUNode);
                DLLNode *head = freqMap[minFreq].first;
                DLLNode *tail = freqMap[minFreq].second;
                if (head->next == tail)
                {
                    /*As the previous freqList is empty,erasing it from the freqMap*/
                    freqMap.erase(minFreq);
                    ++minFreq;
                }
                --currSize; /*decrementing currSize*/
            }
            /*This is the first time we are inserting the node*/
            minFreq = 1;
            /*If there is no list with freq 1*/
            if (freqMap.find(1) == freqMap.end())
                freqMap[1] = createFreqList();
            /*creating the new node*/
            DLLNode *currNode = new DLLNode(key, value, 1);
            /*Taking into keyMap*/
            keyMap[key] = currNode;
            /*inserting the node in freqList*/
            addFront(1, currNode);
            ++currSize; /*incrementing the current size*/
        }
    }
}; 