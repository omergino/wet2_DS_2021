#ifndef DS_WET2_RANKAVLTREE_H
#define DS_WET2_RANKAVLTREE_H

#include <iostream>
#include <ostream>
#include <algorithm>

using std::max;
using std::endl;
using std::cout;

enum RTreeStatus {R_T_SUCCESS,R_T_ALLOC_ERROR,R_T_FAIL,R_DONTKNOW};
/*------------------------------------------------------------------------------
------------------------------------RankAVLNode-------------------------------------
------------------------------------------------------------------------------*/

template <class Key, class Data>
class RankAVLNode
{
public:
    Key key;
    Data data;
    int height; //height of the tree that this node is the root
    int bf; //balance factor
    int numOfNodes; //number of node in a sub tree that this node is the root //TODO

    RankAVLNode *parent;
    RankAVLNode *left;
    RankAVLNode *right;

    RankAVLNode(Key k, Data d); //constructor
    ~RankAVLNode(); //destructor

};

/*------------------------------------------------------------------------------
------------------------------------RankAVLTree-------------------------------------
------------------------------------------------------------------------------*/

template <class Key, class Data>
class RankAVLTree
{
public:
    RankAVLNode<Key,Data> *root = nullptr;
    //RankAVLNode<Key,Data> *lastInOrder = nullptr;
    RankAVLTree(); //constructor
    ~RankAVLTree(); //destructor

    //insert Node into the right place in the tree while maintain the balance
    RTreeStatus insertNode(Key k, Data d);
    //remove Node from the tree while maintain the balance
    RTreeStatus removeNode(Key k);
    //find Node from the tree by key
    RankAVLNode<Key,Data> *findNode(Key k);
    //updates root tree
    void updateRoot(RankAVLNode<Key,Data> *n);

    //rotations
    void LLrotate(RankAVLNode<Key,Data> *n);
    void LRrotate(RankAVLNode<Key,Data> *n);
    void RRrotate(RankAVLNode<Key,Data> *n);
    void RLrotate(RankAVLNode<Key,Data> *n);

    //delete all nodes of the tree
    void clearTree();
    //print all nodes of the tree in ascending order
    void printTree();

    //find a node with index - rank
    RankAVLNode<Key,Data> *Select(int rank); //TODO
};


#endif //DS_WET2_RANKAVLTREE_H
