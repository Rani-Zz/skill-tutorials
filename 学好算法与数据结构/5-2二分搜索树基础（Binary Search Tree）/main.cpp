#include <iostream>
using namespace std; 
 template<typename Kry,typename Value>
 class BST
 {
 	private:
 		struct node{
 			Key key;
 			Value value;
 			node *left;
 			node *right;
 			
 			node(Key k,Value v):key(k),value(v),left(NULL),right(NULL){
			 }
		 };
		 int count = 0;
		 node* root;
    public:
    	BST(){
    		root = NULL;
    		count = 0;
		}
    	~BST(){}
    	bool isEmpty()
    	{
    		return count==0;
		}
		
		int size()
		{
			return count;
		}
 };
 
int main() {
	
	return 0;
}
