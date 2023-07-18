#include <bits/stdc++.h>
#define ALPHA_START 'A'
#define ALPHA_SIZE 26
using namespace std;

struct Vertex
{
    char alphabet;
    bool exist;
    vector<Vertex *> child;
    Vertex(char a) : alphabet(a), exist(false)
    {
        child.assign(ALPHA_SIZE, NULL);
    }
};

class Trie
{
private:
    Vertex *root;

public:
    Trie() { root = new Vertex('!'); }
    void insert(string word)
    {
        Vertex *cur = root;
        for (int i = 0; i < word.size(); i++)
        {
            int alphaNum = word[i] - ALPHA_START;
            if (cur->child[alphaNum] == NULL)
                cur->child[alphaNum] = new Vertex(word[i]);
            cur = cur->child[alphaNum];
        }
        cur->exist = true;
    }
    bool search(string word)
    {
        Vertex *cur = root;
        for (int i = 0; i < word.size(); i++)
        {
            int alphaNum = word[i] - ALPHA_START;
            if (cur->child[alphaNum] == NULL)
                return false;
            cur = cur->child[alphaNum];
        }
        return cur->exist;
    }
    bool startsWidth(string prefix)
    {
        Vertex *cur = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            int alphaNum = prefix[i] - ALPHA_START;
            if (cur->child[alphaNum] == NULL)
                return false;
            cur = cur->child[alphaNum];
        }
        return true;
    }
};