#include <iostream>

#include<ctime>
#include<queue>
#include<cassert> 

using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

 template<typename Kry,typename Value>
 class BST
 {
 	private:
 		struct Node{
 			Key key;
 			Value value;
 			node *left;
 			node *right;
 			
 			Node(Key k,Value v):key(k),value(v),left(NULL),right(NULL){
			 }
		 };
		 int count = 0;
		 Node* root;
		 Node* insert(Node* root,Key k,Value v)
		 {
		 	if(root==NULL)
			{
			 	count++;
			 	return new node(k,v);
			} 
			
			if(k==root->key)
			{
				root->value = v;
			}else if(k<root->key)
			{
				root->left = insert(root->left,k,v);
			}else
				root->right = insert(root->right,k,v);
			
			return root;
		 }
		 
		 bool contain(Node* root,Key key)
		 {
		 	if(root==NULL) return false;
		 	if(key==root->key)
		 	return true;
		 	
		 	if(key<root->key)
		 	{
		 		return contain(root->left,key);
			 }else
			 {
			 	return contain(root->right,key);
			 }
		 }
		 
		 Value* search(Node* root,Key key)
		 {
		 	if(root==NULL) return NULL;
		 	
		 	if(key==root->key) return &(root->value)
		 	else if(key<root->key) return search(root->left,key);
		 	else return search(root->right,key);
		 }
		 
		 //前序遍历 递归 
		 void preOrder(Node* node)
		 {
		 	if(node==NULL) return;
		 	cout<<node->value<<endl;
		 	preOrder(root->left);
		 	preOrder(root->right);
		 }
		 //中序遍历 递归 
		 void inOrder(Node* node)
		 {
		 	if(node==NULL) return;
		 	inOrder(node->left);
		 	cout<<node->value<<endl;
		 	inOrder(node->right);
		 }
		 
		 //后序遍历 递归 
		 void postOrder(Node* node)
		 {
		 	if(node==NULL) return;
		 	postOrder(node->left);
		 	postOrder(node->right);
			cout<<node->value<<endl; 
		 }
		 
		 void destroy(Node* node)
		 {
		 	if(node==NULL) return;
		 	destroy(node->left);
		 	destroy(node->right);
		 	
		 	delete node;
		 	count--;
		 }
		 
		 //寻找最小值 
		 Node* minimum(Node* node)
		 {
		 	if(node->left==NULL)
		 	return node;
		 	
		 	return minimum(node->left);
		 }
		 
		 //寻找最大值 
		 Node* maximun(Node* node)
		 {
		 	if(node->right==NULL)
		 	return node;
		 	
		 	return maximum(node->right);
		  } 
		  
		  //删除最小值 
		  Node* removeMin(Node* node)
		  {
		  	if(node->left==NULL)
		  	{
		  		Node* rightNode = node->left;
		  		delete node;
		  		count--;
		  		return rightNode;
			  }
			  
			  root->left = removeMin(node->left);
			  return node;
		   } 
		   
		   //删除最大值 
		   Node* removeMax(Node* node)
		   {
			   	if(node->right==NULL)
			   	{
			   		Node* leftNode = node->left;
			   		delete node;
			   		count--;
			   		return leftNode;
				}
				
				node->right = removeMax(node->right);
				return node;
				
			   
		   }
		   
		   Node* remove(Node* node,Key key)
		   {
		   		if(node==NULL)
		   			return NULL;
		   			
		   		if(key<node->key)
		   		{
	   				node->left =  remove(node->left,key);
	   				return node;
			   }else if(key>node->key)
			   {
			   		node->right = remove(node->right,key); 
			   		return node;
			   }else //key==node->key
			   {
			   		if(node->left==NULL)
			   		{
			   			Node* rightNode =  node->right;
						delete node;
						count--;
						return rightNode; 
				    }
					if(node->right==NULL)
				    {
				    	Node* leftNode = node->left;
				    	delete node;
				    	count--;
				    	return leftNode;
					}
					
					//左右都不为NULL 找到后继结点 即子树的小值
					Node* successor = new Node(minimun(node->right));
					count++;
					successor->right = removeMin(node->right);
					successor->left = node->left;
					
					delete node;
					count--;
					
					return successor;
			   	
			   }
		   }
    public:
    	BST(){
    		root = NULL;
    		count = 0;
		}
    	~BST(){
    		destroy(root); 
		}
    	bool isEmpty()
    	{
    		return count==0;
		}
		
		int size()
		{
			return count;
		}
		void insert(Key k,Value v)
		{
			root = insert(root,k,v);
		}
		// 查看二分搜索树中是否存在键key
		bool contain(Key key)
		{
			return contain(root,key);
		}
		
		// 在二分搜索树中搜索键key所对应的值。如果这个值不存在, 则返回NULL
		Value* search(Key key)
		{
			return search(root,key);
		}
		
		//前序遍历
		void preOrder()
		{
			return preOrder(root);
		 } 
		
		//中序遍历
		void inOrder()
		{
			return inOrder(root);
		 } 
		 
		//后序遍历
		void postOrder()
		{
			return postOrder(root);
		 } 
		 
		 //层序遍历 
		 void levelOrder()
		 {
		 	queue<Node*> q;
		 	q.push(root);
		 	
		 	while(!q.empty())
		 	{
		 		Node* node = q.front();
		 		q.pop();
		 		cout<<node->value<<endl;
				
				 if(node->left)
				 q.push(node->left);
				 if(node->right)
				 q.push(node->rigit); 
			 }
		} 
		//最小值 
		Key minimum()
		{
			assert(count>0);
			Node* node = minimum(root);
			return node->key;
		 } 
		 
		 //最大值 
		 Key maximum()
		 {
		 	assert(count>0);
		 	Node* node = maximum(root);
		 	
		 	return node->key;
		  } 
		  
		  //移除最小值 
		  void removeMin()
		  {
		  	if(root)
		  	{
		  		root = removeMin(root);
			  }
		  }
		  
		  //移除最大值 
		  void removeMax()
		  {
		  	if(root)
		  	{
		  		root = removeMax(root);
			  }
		   }
		   
		  //移除结点key 
		  void remove(Key key)
		  {
		  	assert(count>0); 
		  	root = remove(root, key);
		   } 
 };
 
int main() {

	return 0;
}
