#include <iostream>
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
 };
 
int main() {
    vector<int> nums1 = {9,3,4,2,5,73,2,83};
	int res = BinarySearch2(nums1,2);
	cout<<res<<endl;
	
	return 0;
}
