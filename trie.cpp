#include <iostream>
#include <string>
using namespace std;

#define ALPHABET_SIZE 26

typedef struct trie_node
{
	int count;   // 记录该节点代表的单词的个数
	trie_node *children[ALPHABET_SIZE]; // 各个子节点 
}*trie;

trie_node* create_trie_node()
{
	trie_node* pNode = new trie_node();
	pNode->count = 0;
	for(int i=0; i<ALPHABET_SIZE; ++i)
		pNode->children[i] = NULL;
	return pNode;
}

void trie_insert(trie root, char* key)
{
	trie_node* node = root;
	char* p = key;
	while(*p)
	{
		if(node->children[*p-'a'] == NULL)
		{
			node->children[*p-'a'] = create_trie_node();
		}
		node = node->children[*p-'a'];
		node->count += 1;
		++p;
	}
	
}

/**
 * 查询：不存在返回0，存在返回出现的次数
 */ 
int trie_search(trie root, char* key)
{
	trie_node* node = root;
	char* p = key;
	while(*p && node!=NULL)
	{
		node = node->children[*p-'a'];
		++p;
	}
	
	if(node == NULL)
		return 0;
	else
		return node->count;
}

int main()
{
	// 关键字集合
	char keys[15] ;
	trie root = create_trie_node();
    int n,m;
    cin>>n;
	// 创建trie树
	for(int i = 0; i < n; i++){
	    cin>>keys;
	    trie_insert(root, keys);
	}
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>keys;
        cout<<trie_search(root,keys)<<endl;
    }
	
	return 0;
}
