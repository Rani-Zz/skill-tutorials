#include <iostream>
#include<cassert> 
#include<queue>

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
		 
		 //ǰ����� �ݹ� 
		 void preOrder(Node* node)
		 {
		 	if(node==NULL) return;
		 	cout<<node->value<<endl;
		 	preOrder(root->left);
		 	preOrder(root->right);
		 }
		 //������� �ݹ� 
		 void inOrder(Node* node)
		 {
		 	if(node==NULL) return;
		 	inOrder(node->left);
		 	cout<<node->value<<endl;
		 	inOrder(node->right);
		 }
		 
		 //������� �ݹ� 
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
		 
		 //Ѱ����Сֵ 
		 Node* minimum(Node* node)
		 {
		 	if(node->left==NULL)
		 	return node;
		 	
		 	return minimum(node->left);
		 }
		 
		 //Ѱ�����ֵ 
		 Node* maximun(Node* node)
		 {
		 	if(node->right==NULL)
		 	return node;
		 	
		 	return maximum(node->right);
		  } 
		  
		  //ɾ����Сֵ 
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
		   
		   //ɾ�����ֵ 
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
		// �鿴�������������Ƿ���ڼ�key
		bool contain(Key key)
		{
			return contain(root,key);
		}
		
		// �ڶ�����������������key����Ӧ��ֵ��������ֵ������, �򷵻�NULL
		Value* search(Key key)
		{
			return search(root,key);
		}
		
		//ǰ�����
		void preOrder()
		{
			return preOrder(root);
		 } 
		
		//�������
		void inOrder()
		{
			return inOrder(root);
		 } 
		 
		//�������
		void postOrder()
		{
			return postOrder(root);
		 } 
		 
		 //������� 
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
		//��Сֵ 
		Key minimum()
		{
			assert(count>0);
			Node* node = minimum(root);
			return node->key;
		 } 
		 
		 //���ֵ 
		 Key maximum()
		 {
		 	assert(count>0);
		 	Node* node = maximum(root);
		 	
		 	return node->key;
		  } 
		  
		  //�Ƴ���Сֵ 
		  void removeMin()
		  {
		  	if(root)
		  	{
		  		root = removeMin(root);
			  }
		  }
		  
		  //�Ƴ����ֵ 
		  void removeMax()
		  {
		  	if(root)
		  	{
		  		root = removeMax(root);
			  }
		   } 
 };
 
int main() {

	return 0;
}
