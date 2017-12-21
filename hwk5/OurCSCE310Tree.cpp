#include "OurCSCE310Tree.h"
#include <iostream>
#include <cmath>
using namespace std;

/*
class OurCSCE310Tree{
 public:
  OurCSCE310Tree(void);
  OurCSCE310Tree(OurCSCE310Tree&);
  ~OurCSCE310Tree(void);
  void operator=(OurCSCE310Tree&);
  OurCSCE310Tree* getParent(void);
  OurCSCE310Tree* getLeft(void);
  OurCSCE310Tree* getRight(void);
  int getValue(void);
  void setParent(OurCSCE310Tree*);
  void setLeft(OurCSCE310Tree*);
  void setRight(OurCSCE310Tree*);
  void setValue(int);
  void insert(int);
  void printPreorder(void);
  void printInorder(void);
  void printPostorder(void);
  void rotateLeft(void);
  void rotateRight(void);
  void rotateLeftRight(void);
  void rotateRightLeft(void);
  void deleteNode(int);
  int getHeight();
  
 private:
  int value;
  OurCSCE310Tree* parent;
  OurCSCE310Tree* left;
  OurCSCE310Tree* right;
};
 */

OurCSCE310Tree::OurCSCE310Tree(){
  value = 0;
  parent = NULL;
  left = NULL;
  right = NULL;
}

OurCSCE310Tree::OurCSCE310Tree( OurCSCE310Tree& other){
  delete parent;
  delete left;
  delete right;
  value = other.getValue();
  parent = other.getParent();
  left = other.getLeft();
  right = other.getRight();
}

void OurCSCE310Tree::operator=( OurCSCE310Tree& other){
  delete parent;
  delete left;
  delete right;
  value = other.getValue();
  parent = other.getParent();
  left = other.getLeft();
  right = other.getRight();
}

OurCSCE310Tree::~OurCSCE310Tree(){
  delete left;
  left = NULL;
  delete right;
  right = NULL;
  value = 0;
}

OurCSCE310Tree* OurCSCE310Tree::getParent(){
  return parent;
}

OurCSCE310Tree* OurCSCE310Tree::getLeft(){
  return left;
}

OurCSCE310Tree* OurCSCE310Tree::getRight(){
  return right;
}

int OurCSCE310Tree::getValue(){
  return value;
}

void OurCSCE310Tree::setParent( OurCSCE310Tree* par ){
  parent = par;
}

void OurCSCE310Tree::setLeft( OurCSCE310Tree* lft ){
  left = lft;
}

void OurCSCE310Tree::setRight( OurCSCE310Tree* rght ){
  right = rght;
}

void OurCSCE310Tree::setValue( int val ){
  value = val;
}

void OurCSCE310Tree::insert( int val ){
  if( !getValue() ){
    setValue( val );
  }
  else if( ( val < getValue() && !getLeft() ) || ( val < getValue() && !getLeft()->getValue() ) ){
    left = new OurCSCE310Tree();
    left->setParent( this );
    left->setValue( val );
  }
  else if( ( val > getValue() && !getRight() ) || ( val > getValue() && !getRight()->getValue() ) ){
    right = new OurCSCE310Tree();
    right->setParent( this );
    right->setValue( val );
  }
  else if( val < getValue() ){
    getLeft()->insert( val );
  }
  else{
    getRight()->insert( val );
  }

  if( getLeft() && getLeft()->getRight() && !getRight() || getLeft() && getLeft()->getRight() && getRight() && getLeft()->getHeight() > getRight()->getHeight() + 1 && getLeft()->getRight()->getHeight() > getLeft()->getLeft()->getHeight() + 1 ){
    rotateLeftRight();
  }
  else if( getRight() && getRight()->getLeft() && !getLeft() || getRight() && getRight()->getLeft() && getLeft() && getRight()->getHeight() > getLeft()->getHeight() + 1 && getRight()->getLeft()->getHeight() > getRight()->getRight()->getHeight() + 1 ){
    rotateRightLeft();
  }
  else if( getLeft() && !getRight() && getLeft()->getHeight() > 1 || getLeft() && getRight() && getLeft()->getHeight() > getRight()->getHeight() + 1 ){
    rotateRight();
  }
  else if( getRight() && !getLeft() && getRight()->getHeight() > 1 || getRight() && getLeft() && getRight()->getHeight() > getLeft()->getHeight() + 1 ){
    rotateLeft();
  }
}

void OurCSCE310Tree::printPreorder(){
  if( getValue() ){
    cout << getValue();
  }
  if( getLeft() && getLeft()->getValue() ){
    cout << ",";
    getLeft()->printPreorder();
  }
  if( getRight() && getRight()->getValue() ){
    cout << ",";
    getRight()->printPreorder();
  }
}

void OurCSCE310Tree::printInorder(){
  if( getLeft() && getLeft()->getValue() ){
    getLeft()->printInorder();
    cout << ",";
  }
  if( getValue() ){
    cout << getValue();
  }
  if( getRight() && getRight()->getValue() ){
    cout << ",";
    getRight()->printInorder();
  }
}

void OurCSCE310Tree::printPostorder(){
  if( getLeft() && getLeft()->getValue() ){
    getLeft()->printPostorder();
    cout << ",";
  }
  if( getRight() && getRight()->getValue() ){
    getRight()->printPostorder();
    cout << ",";
  }
  if( getValue() ){
    cout << getValue();
  }
}

int OurCSCE310Tree::getHeight(){
  if( getLeft() && getLeft()->getValue() && ( !getRight() || !getRight()->getValue() ) ){
    return getLeft()->getHeight() + 1;
  }
  else if( getRight() && getRight()->getValue() && ( !getLeft() || !getLeft()->getValue() ) ){
    return getRight()->getHeight() + 1;
  }
  else if( getRight() && getLeft() && getRight()->getValue() && getLeft()->getValue() ){
    return fmax( getRight()->getHeight() , getLeft()->getHeight() ) + 1;
  }
  else if( getValue() && ( !getLeft() || !getLeft()->getValue() ) && ( !getRight() || !getRight()->getValue() ) ){
    return 1;
  }
  return 0;
}

void OurCSCE310Tree::rotateLeftRight(){
  getLeft()->rotateLeft();
  rotateRight();
}

void OurCSCE310Tree::rotateRightLeft(){
  getRight()->rotateRight();
  rotateLeft();
}

void OurCSCE310Tree::rotateLeft(){
  /*
  1. Create a new parent node
  2. Set that to the old parents right child
  3. New roots left is old root and left child
  4. Old roots right children is new roots left children
  */
  // OurCSCE310Tree* newNode = new OurCSCE310Tree;
  // newNode->setValue(this->getValue());

  OurCSCE310Tree* newRoot = getRight();  //Empty node reference
  OurCSCE310Tree* floatingChild = NULL;
  OurCSCE310Tree* maintainRight = NULL;
  OurCSCE310Tree* newLeftTemp = new OurCSCE310Tree;
  
  int newLeftTempValue = this->getValue();
  newLeftTemp->setValue(newLeftTempValue);
  newLeftTemp->setLeft(this->getLeft());
  //newLeftTemp->setParent(newRoot);

  if( newRoot != NULL )
  {
    floatingChild = newRoot->getLeft();
    maintainRight = newRoot->getRight();

    int newRootVal = newRoot->getValue(); 
    this->setValue(newRootVal);
  }

  this->setRight(maintainRight);
  this->setLeft(newLeftTemp);

  if (floatingChild != NULL) //References the new right child of old root
  {
    floatingChild->setParent(newLeftTemp);
  }
  
  if (maintainRight != NULL) //References the new roots right child
  {
    maintainRight->setParent(newRoot);
  }

  newLeftTemp->setRight(floatingChild);
  // cout << "new root: " << newRoot->getValue() << endl;
  // cout << "new left child: " << newRoot->getLeft()->getValue() << endl;
  // cout << "new right child: " << newRoot->getRight()->getValue() << endl;
  // cout << "parent: " << newLeftTemp->getParent()->getValue() << endl;
}

void OurCSCE310Tree::rotateRight(){
  OurCSCE310Tree* newRoot = getLeft();  //Empty node reference
  OurCSCE310Tree* floatingChild = NULL;
  OurCSCE310Tree* maintainRight = NULL;
  OurCSCE310Tree* newLeftTemp = new OurCSCE310Tree;
  
  int newLeftTempValue = this->getValue();
  newLeftTemp->setValue(newLeftTempValue);
  
  newLeftTemp->setRight(this->getRight());
  //newLeftTemp->setParent(newRoot);

  if( newRoot != NULL )
  {
    floatingChild = newRoot->getRight();
    maintainRight = newRoot->getLeft();

    int newRootVal = newRoot->getValue();
    this->setValue(newRootVal);
  }

  this->setLeft(maintainRight);
  this->setRight(newLeftTemp);

  if (floatingChild != NULL) //References the new left child of old root
  {
    floatingChild->setParent(newLeftTemp);
  }
  
  if (maintainRight != NULL) //References the new roots left child
  {
    maintainRight->setParent(newRoot);
  }

  newLeftTemp->setLeft(floatingChild);
}

void OurCSCE310Tree::deleteNode( int key ){
  // OurCSCE310Tree* tempTree = new OurCSCE310Tree;
  // cout << tempTree->getValue() << endl;
  // if(this->getValue == NULL)
  // {
  //   delete this;
  // }else if(key < this->getValue()){
  //   OurCSCE310Tree* lefty = NULL;
  //   lefty = this->getLeft();
  // } else if(key > this->getValue()){
  //   OurCSCE310Tree* righty= NULL;
  // }

}
