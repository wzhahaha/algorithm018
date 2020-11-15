第四周学习笔记：

本周主要是BFS/DFS、贪心算法、二分查找，本周工作原因仅刷了贪心相关的题目，需要加强其他算法的练习。如下总结相关算法模板：

BFS广度优先搜索:

// C/C++

void bfs(Node* root) {

  map<int, int> visited;

  if(!root) return ;

  queue<Node*> queueNode;

  queueNode.push(root);

  while (!queueNode.empty()) {

​    Node* node = queueNode.top();

​    queueNode.pop();

​    if (visited.count(node->val)) continue;

​    visited[node->val] = 1;

​    for (int i = 0; i < node->children.size(); ++i) {

​        queueNode.push(node->children[i]);

​    }

  }

  return ;

}

DFS深度优先搜索：

//递归写法：

map<int, int> visited;

void dfs(Node* root) {

  // terminator

  if (!root) return ;

  if (visited.count(root->val)) {

​    // already visited

​    return ;

  }

  visited[root->val] = 1;

  // process current node here. 

  // ...

  for (int i = 0; i < root->children.size(); ++i) {

​    dfs(root->children[i]);

  }

  return ;

}

//非递归写法：

void dfs(Node* root) {

  map<int, int> visited;

  if(!root) return ;

  stack<Node*> stackNode;

  stackNode.push(root);

  while (!stackNode.empty()) {

​    Node* node = stackNode.top();

​    stackNode.pop();

​    if (visited.count(node->val)) continue;

​    visited[node->val] = 1;

​    for (int i = node->children.size() - 1; i >= 0; --i) {

​        stackNode.push(node->children[i]);

​    }

  }

  return ;

}

二分查找：

C/C++

int binarySearch(const vector<int>& nums, int target) {

​	int left = 0, right = (int)nums.size()-1;

​	

​	while (left <= right) {

​		int mid = left + (right - left)/ 2;

​		if (nums[mid] == target) return mid;

​		else if (nums[mid] < target) left = mid + 1;

​		else right = mid - 1;

​	}

​	

​	return -1;

}