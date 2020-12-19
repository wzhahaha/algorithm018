第八周学习笔记

本周主要是三块内容：位运算、布隆过滤器、排序算法。

1、针对位运算，其计算效率较快。常用的总结如下：

仅将第n位置1：x|(1<<n)

仅将第n位置0：x&(~(1<<n))

X=X&(X-1)清零最低位的1

X&-X : 得到最低位的1

X&~X:置为0

以及判断奇数偶数，进制之间转换等等；

2、布隆过滤器：布隆过滤器（Bloom Filter）的核心实现是一个超大的位数组和几个哈希函数 。

布隆过滤器的应用，在很多场景下，我们都需要一个能迅速判断一个元素是否在一个集合中。譬如：

**网页爬虫对URL的去重，避免爬取相同的URL地址；**

**反垃圾邮件，从数十亿个垃圾邮件列表中判断某邮箱是否垃圾邮箱（同理，垃圾短信）；**

缓存击穿，将已存在的缓存放到布隆中，当黑客访问不存在的缓存时迅速返回避免缓存及DB挂掉。

3、LRU Cache: 即最近最少使用缓存机制；

4、排序算法：

https://www.cnblogs.com/onepixel/p/7674659.html

排序算法只要搞清楚原理，包括时间复杂度与空间复杂度，最坏情况等；重点需要关注：快排、归并排序和堆排序。

快排：

//C/C++

int random_partition(vector<int>& nums, int l, intr) {

  int random_pivot_index = rand() % (r - l +1) + l;  //随机选择pivot

  int pivot = nums[random_pivot_index];

  swap(nums[random_pivot_index], nums[r]);

  int i = l - 1;

  for (int j=l; j<r; j++) {

​    if (nums[j] < pivot) {

​      i++;

​      swap(nums[i], nums[j]);

​    }

  }

  int pivot_index = i + 1;

  swap(nums[pivot_index], nums[r]);

  return pivot_index;

}

void random_quicksort(vector<int>& nums, int l, int r) {

  if (l < r) {

​    int pivot_index = random_partition(nums, l, r);

​    random_quicksort(nums, l, pivot_index-1);

​    random_quicksort(nums, pivot_index+1, r);

  }

}

归并排序：

void mergeSort(vector<int> &nums, int left, int right) {

​	if (left >= right) return;

​	

​	int mid = left + (right - left) / 2;

​	mergeSort(nums, left, mid);

​	mergeSort(nums, mid+1, right);

​	

​	merge(nums, left, mid, right);

}

void merge(vector<int> &nums, int left, int mid, int right) {

​	vector<int> tmp(right-left+1);

​	int i = left, j = mid+1, k = 0;

​	

​	while (i <= mid && j <= right) {

​		tmp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];

​	}

​	while (i <= mid) tmp[k++] = nums[i++];

​	while (j <= right) tmp[k++] = nums[j++];

​	

​	for (i = left, k = 0; i <= right;) nums[i++] = tmp[k++];

}

堆排序：

void heapify(vector<int> &array, int length, int i) {

​    int left = 2 * i + 1, right = 2 * i + 2;

​    int largest = i;

​    if (left < length && array[left] > array[largest]) {

​        largest = left;

​    }

​    if (right < length && array[right] > array[largest]) {

​        largest = right;

​    }

​    if (largest != i) {

​        int temp = array[i]; array[i] = array[largest]; array[largest] = temp;

​        heapify(array, length, largest);

​    }

​    return ;

}

void heapSort(vector<int> &array) {

​    if (array.size() == 0) return ;

​    int length = array.size();

​    for (int i = length / 2 - 1; i >= 0; i--) 

​        heapify(array, length, i);

​    for (int i = length - 1; i >= 0; i--) {

​        int temp = array[0]; array[0] = array[i]; array[i] = temp;

​        heapify(array, i, 0);

​    }

​    return ;

}





