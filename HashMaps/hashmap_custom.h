#include <iostream>
using namespace std;

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
    }
    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
    MapNode<V> *buckets;
    int size;
    int numbuckets;

public:
    outmap()
    {
        size = 0;
        numbuckets = 5;
        buckets = new MapNode<V> *[numbuckets];
        for (int i = 0; i < numbuckets; i++)
        {
            buckets[i] = NULL;
        }
    }
    ~ourmap()
    {
        fr(int i = 0; i < numbuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }
    int count()
    {
        return count;
    }
    V getValue(string, key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }
    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        double loadfactor = (1.0 * count) / numbuckets;
        if (loadfactor > 0.7)
        {
            rehash();
        }
    }
    void rehash()
    {
        MapNode<V> **temp = buckets;
        buckets = new MapNode<V> *[2 * numbuckets];
        for (int i = 0; i < 2 * numbuckets; i++)
        {
            buckets[i] = NULL;
        }
        int oldbucketcount = numbuckets;
        numbuckets *= 2;
        count = 0;
        for (int i = 0; i < oldbucketcount; i++)
        {
            MapNode<V> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        for (int i = 0; i < oldbucketcount; i++)
        {
            MapNode<V> *head = temp[i];
            delete head;
        }
        delete[] head;
    }
    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }

private:
    int getBucketIndex(string key)
    {
        int hashCode = 0;
        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numbuckets;
            currentCoeff *= 37;
            currentCoeff = currentCoeff % numbuckets;
        }
        return hashCode % numbuckets;
    }
};
