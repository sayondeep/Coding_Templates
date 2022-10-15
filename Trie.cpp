//
// Created by SAYON DEEP on 23-06-2022.
//
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node* children[26];
    bool isend;

    Node()
    {
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;

        }
        isend = false;
    }
};

class Trie
{

    Node* root;

public:

    Trie()
    {
        root = new Node();
    }


    void insert(string word)
    {
        Node * node = root;

        for(int i=0;i<word.length();i++)
        {
            int index = word[i]-'a';

            if(node->children[index]==NULL)
            {
                Node *new_node = new Node();
                node->children[index]=new_node;
            }
            node = node->children[index];
        }

        node->isend =true;
    }

    bool search(string word)
    {
        Node *node = root;

        for(int i=0;i<word.length();i++)
        {
            int index = word[i]-'a';

            if(node->children[index]!=NULL)
                node = node->children[index];
            else
                return false;
        }

        return node->isend;
    }

    int word_count(Node* root,string& str)
    {
        int count=0;


        if(root->isend)
        {
            count++;
            cout<<str<<endl;
        }

        for(int i=0;i<26;i++)
        {
            if(root->children[i])
            {
                str += ('a'+i);
                count+= word_count(root->children[i],str);
                str.pop_back();
            }
        }
        return count;
    }

    int word_count_util()
    {
        string str="";
        return word_count(root,str);
    }

};

int main()
{
    Trie* trie  = new Trie();

    trie->insert("whatisup");
    trie->insert("whatisdown");
    trie->insert("whatisleft");
    trie->insert("whatisright");
//    cout<<trie->search("whatisdown")<<endl;
//    cout<<trie->search("whatisleft")<<endl;
//    cout<<trie->search("whatisup")<<endl;

    cout<<trie->word_count_util()<<endl;
}