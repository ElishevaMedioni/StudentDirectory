#pragma once
#include "Tree.h"


template <class T>
class SearchTree : public Tree<T>
{
public:
	// protocol for search trees
	void add(T value);
	bool  search(T value)
	{
		return search(Tree<T>::root, value);
	}
	void remove(T value);
    typename Tree<T>::Node * parent(typename Tree<T>::Node* current){return parentHelper(Tree<T>::root, current);};
    typename Tree<T>::Node * minimum(typename Tree<T>::Node* current);
    typename Tree<T>::Node * successor(typename Tree<T>::Node* current);
    bool isLeaf(typename Tree<T>::Node* current);
    typename Tree<T>::Node* searchP(T value){
        return searchP(Tree<T>::root, value);
    }
    

private:
	void add(typename Tree<T>::Node * current, T val);
	bool  search(typename Tree<T>::Node* current, T val);
    typename Tree<T>::Node * parentHelper(typename Tree<T>::Node * currentRoot, typename Tree<T>::Node * current);
    typename Tree<T>::Node* searchP(typename Tree<T>::Node* current, T val);
    
};


template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);
}

template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node * current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	if (current->value <= val)
		// add to right subtree
		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->right, val);
	else
		// add to left subtree
		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->left, val);
}

template <class T>
typename Tree<T>::Node* SearchTree<T>::minimum(typename Tree<T>::Node* current){
    while (current->left!= NULL) {
        current=current->left;
    }
    return current;
}


template <class T>
typename Tree<T>::Node* SearchTree<T>::successor(typename Tree<T>::Node* current){
     typename Tree<T>::Node* successor = current->right;
       while(successor->left!= NULL)
           successor = successor->left;
       return successor;
}


template <class T>
typename Tree<T>::Node* SearchTree<T>::parentHelper(typename Tree<T>::Node * currentRoot, typename Tree<T>::Node * current){
    if (Tree<T>::root==NULL or currentRoot==NULL)
        return NULL;
    else
        if (currentRoot->left==current or currentRoot->right==current)
            return currentRoot;
         else
            if (currentRoot->value<current->value)
                return parentHelper(currentRoot->right, current);
             else
                 return parentHelper(currentRoot->left, current);
}

template <class T>
bool SearchTree<T>::isLeaf(typename Tree<T>::Node *current){
    return current->left==NULL and current->right==NULL;
}


template <class T>
typename Tree<T>::Node* SearchTree<T>::searchP(typename Tree<T>::Node * current, T val)
{
    // see if argument value occurs in tree
    if (!current)
        return NULL;    // not found
    if (current->value == val)
        return current;
    if (current->value < val)
        return searchP(current->right, val);
    else
        return searchP(current->left, val);
}

template <class T>
void SearchTree<T>::remove(T val){
    if(!search(val)) //val not found
           return;
       typename SearchTree<T>::Node* p = searchP(val);

       if (isLeaf(p)) { //If the node is a leaf
           if(p == this->root){
               p=NULL;
               return;
           }
           typename Tree<T>::Node* p1=parent(p);
           if(p1->left == p)
               p1->left=NULL;
           else if(p1->right == p)
               p1->right=NULL;
           return;
       }
       if(p->right and !p->left){ //If the node has only one son in the right
           typename Tree<T>::Node* p1;
           p1=parent(p);
           if(p1->left == p)
               p1->left=p->right;
           else if(p1->right == p)
               p1->right=p->right;
           return;
       }
       if (!p->right and p->left) { //If the node has only one son in the left
           typename Tree<T>::Node* p1;
           p1=parent(p);
           if(p1->left == p)
               p1->left=p->left;
           else if(p1->right == p)
               p1->right=p->left;
           return;
       }
       //If the node has two son
       typename SearchTree<T>::Node* q=successor(p);
       T value = q->value;
       remove(value);
       p->value = value;
       return;
}
