algorithm_cookbook
==================

data structure &amp; algorithm for interview

Problem Listing
	
	|-- 1. Arrays And Strings

		|-- 1.1 determine if a string contains all unique characters? no addtional data structures?

		|-- 1.2 reverse a string

		|-- 1.3 remove duplicate characters without additional buffer

		|-- 1.4 determine is two strings are anagrams

		|-- 1.5 replace all spaces with '%20'

		|-- 1.6 rotate a N*N matrix by 90 degree

		|-- 1.7 set the entire row and column with 0, if an element in an N*M matrix is 0

		|-- 1.8 check s2 is a rotation of s1 by using subString method

	|-- 2. Linked Lists

		|-- 2.1 remove duplicates from an unsorted linked list? no tempoary buffer?

		|-- 2.2 find the nth last element of a single linked list

		|-- 2.3 delete a node in the middle of the list

		|-- 2.4 the sum of two big num stored in two single linked list, and also in reverse order, the least digit is the head

		|-- 2.5 find the beginning of the loop from a circular linked list	

	|-- 3. Stacks and Queues

		|-- 3.1 use a single array to implement 3 stacks

		|-- 3.2 implement a new stack contains a min method to return the minimal num in the stack and in O(1) time

		|-- 3.3 implement the SetOfStacks, which is if a stack is too big, we will generate a new stack to store new data. Implement a function popAt(int index) which performs a pop operation on a specific sub-stack

		|-- 3.4 Solve the Hanoi problem using stacks

		|-- 3.5 Implement myQueue class which using two stacks

		|-- 3.6 sort a stack in ascending order, you are only allowed to use push, pop and top method 

	|-- 4 Tree And Graphs

		|-- 4.1 Implement a function to check if a tree is balanced

		|-- 4.2 find out whether there is route between two nodes in a directed graph

		|-- 4.3 convert a sorted array into a binary tree with minimal height

		|-- 4.4 create a linked list of all nodes at each depth of a binary tree

		|-- 4.5 find the next node of a given node, where every node has a link to its parent in this tree

		|-- 4.6 find the first common ancestor of two nodes in a binary tree.

			* Avoid storing additional nodes in a data structure
			* This is not necessarily a binary search tree

		|-- 4.7 decide whether T2 is subtree of T1, where T1 is very large millions of nodes, T2 maybe hundreds of nodes.

		|-- 4.8 print all paths which sum up to a given value in a binary tree, it doesn't have to start from the root.

		
	|-- 5 binary manipulation

		|-- 5.1 given two 32-bit numbers, N and M, and two bit positions i and j. implement set all bits from i to j in N equal to M.

#		|-- 5.2 given a number paased as a string, print the binary representation

		|-- 5.3 given an integer, print an the next smallest and largest num that has the same 1 bits in their binary representation

		|-- 5.4 explain (n & (n - 1)) == 0

		|-- 5.5 determine the number of bits required to convert integer A to integer B

		|-- 5.6 swap odd and even bit in an given integer

		|-- 5.7 An array A[1...n] contains all integers from 0 - n which only one integer is missing, we can only access the array by "fetch the jth bit of A[i]", find the missing one

	|-- 8 Recursion

#		|-- 8.1 generate the nth Fibonacci number   矩阵算法

		|-- 8.2 a robot sitting on the upper left of a matrix, it only could move right and down, how many poosible paths? Imagine certain squares are 'off limits', get all possible paths for the robot

#		|-- 8.3 return all subsets of a set

#		|-- 8.4 compute all permutations of a string

		|-- 8.5 print all valid combinations of n-pairs of parentheses 

		|-- 8.6 fill the area with new color until hit the border of that color

		|-- 8.7 given an infinite number of quarters (25 cents), dimes(10 cents), nickels(5 cents) and pennies(1 cent) to caculate the number ways of representing n cents

		|-- 8.8 write an algorithm to print all ways of arranging eight queens on a chess board

	|-- 9 Sorting and Searching

		|-- 9.1 given two sorted arrays, merge them in sorted order

#		|-- 9.2 sort an array of strings so that all the anagrams are next to each other

		|-- 9.3 Given a sorted array of n integers that has been rotated an unknown number of times, find an element in the array in O(logn)

		|-- 9.4 2 GB file with one string per line, which sort algorithm to sort the file

		|-- 9.5 Given a sorted array of string which is interspersed with empty strings, write a method to find the location of a given string

		|-- 9.6 given a matrix in which each row and column is sorted, find an element in it.

		|-- 9.7 叠罗汉 each person mush be both shorter and lighter than the person below him or her, compute the largest possible number of people in such a tower.   

POJ 1129 深搜

编程之美 目录

	|-- 2 数字之魅

		|-- 2.1 求二进制数中1的个数    变量 一个字节  求1的个数   a & (a-1) 直到不为零

			|-- 拓展  两个数 A 和 B, 从A变到B需要几步

		|-- 2.2 阶乘     N! 末尾有几个零  求5的因子个数   N!的二进制表示最低位1的位置  求2的因子个数

		|-- 2.3 发帖水王     一个数组中有一个数的个数超过了一半, 找出这个数    如果是超过四分之一?

		|-- 2.4 1的数目     从1到N，出现的1的个数   需要分类讨论     

			|--  在32位整数范围内, 求最大的满足f[N] = N的数

		|-- 2.5 寻找最大的K个数    用容量为K的最小堆来存储最大的K个数

			|-- 寻找第K大的数     线性算法

			|-- 找第K到M大的数    

			|-- 找最大的K个浮点数

		|-- 2.6 精确表达浮点数   将有限小数和无限循环小数转换成分数

		|-- 2.7 最大公约数问题   

		|-- 2.8 找符合条件的整数

		|-- 2.9 Fibonacci数列

		|-- 2.10 寻找数组中的最大数和最小数

		|-- 2.11 寻找最近点对

		|-- 2.12 快速寻找满足条件的两个数

		|-- 2.13 子数组的最大乘积      2013年腾讯实习的笔试题    

			|-- 如果限制空间  为 O(1)

			|-- 如果数组中数据可以为负数

		|-- 2.14 求数组的子数组之和的最大值

		|-- 2.15 子数组之和的最大值(二维)

		|-- 2.16 求数组的最长递增子序列

		|-- 2.17 数组循环移位

		|-- 2.18 数组分割

		|-- 2.19 区间重合判断

		|-- 2.21 只考虑加法

	|-- 3 结构之法

		|-- 3.1 字符串移位包含的问题

		|-- 3.2 电话号码对应英文单词

#		|-- 3.3 计算字符串的相似度      给定任意两个字符串, 如何计算相似度     通过递归解决   并且解答树重复

		|-- 3.4 从无头单链表中删除节点    

		|-- 3.5 最短摘要的生成

		|-- 3.6 编程判断两个链表是否相交     快慢指针

			|-- 如何判断环入口节点

		|-- 3.7 队列中取最大值操作问题 

		|-- 3.8 求二叉树节点的最大距离      

		|-- 3.9 重建二叉树

		|-- 3.10 分层遍历二叉树

	|-- 4 数学之趣

		|-- 4.1 金刚坐飞机的问题      

		|-- 4.2 瓷砖覆盖地板    Fibonacci数列   F[M] = F[M-1] = F[m-2]

		|-- 4.3 买票找零

		|-- 4.4 点是否在三角形内

		|-- 4.5 磁带文件存放优化

		|-- 4.6 桶中取黑白球

		|-- 4.7 蚂蚁爬杆

		|-- 4.8 三角形测试用例

		|-- 4.9 数独知多少

		|-- 4.10 数字哑谜和回文

		|-- 4.11 挖雷游戏的概率

Leetcode 题集

		|-- Balanced Binary Tree    Given a binary tree, determine whether it is height-balanced

		|-- Binary Tree Inorder Traversal     Given a binary tree, return the inorder traversal of its nodes' values

		|-- Binary Tree Level Order Traversal    广度优先遍历

		|-- Binary Tree Maximum Path Sum   
				Given a binary tree, find the maximum path sum   The path may start and end at any node in the tree

		|-- Binary Tree Zigzag Level Order Traversal    return the Zigzag(锯齿) level order traversal of its nodes' values

		|-- Construct Binary Tree from Inorder and Postorder Traversal 

		|-- Construct Binary Tree from Preorder and Inorder Traversal

		|-- Convert Sorted Array to Binary Search Tree      Array is Ascending Order, Convert it into height balanced Tree

		|-- Convert Sorted List to Binary Search Tree      

		|-- Decode Ways  A message from A-Z is being encoded to numbers using the following mappings : A -> 1 B -> 2 ... Z -> 26   ,    '12'  may be 'AB' or 'L'   Compute the total num of ways to decode it     Hint : dp  dp[i] = dp[i-1] + dp[i-2]

		|-- Distinct Subsequences    
			Given a String S and A String T, count the number of distinct subsequence of T in S
			A subsequence of A String is a new string which is formed from the original string by deleting some(can be none) of the characters without disturbing the relative positions of the remaining characters.
			Hint : dp   dp[i][j]   T中i个字符出现在S中前j个字符中的个数

		|-- Flatten Binary Tree to Linked List     Just Like Preorder

		|-- Gray Code   Gray code is a binary numeral system where two successive values differ in only one bits
						Print the sequence of gray code

		|-- Interleaving String   Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2
									Hint : DP   determine whether s1[i] and s2[j] can form s3 or not  s1的前i个字符和s2的前j个字符是否能组成s3

#		|-- Largest Rectangle in Histogram    Given n itegers representing the histogram(直方图) bar height where the width of each bar, find the area of largest rectangle in the histogram

		|-- Longest Common Prefix   Using Trie data structure

		|-- Longest Consecutive Sequence  Given an unsorted array of integers, find the length of the longest consecutive(连续的) elements sequence    the Time Complexity should be O(n)

#		|--  Maximal Rectangle   Given an 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all 1's in this area 

		|-- Merge Two Sorted Arrays     A has enough spaces for merging B

		|-- Minimum Depth of Binary Tree   Given a binary tree, find its minimum depth
						The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node

		|-- Partition List      Part of the Quick Sort

		|-- Pascals Triangle   Given numRows, generate the first numRows of Pascal's triangle   杨辉三角

		|-- Path Sum1   Given a binary tree, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given one    Hint : dfs

		|-- Computing Next Right Pointers in Each Node     按层遍历

		|-- Recover the Binary Search Tree   Two elements of a binary search tree are swapped by mistake    
					O(n) is ok   But there is a solution that only cost contant spaces

		|-- Restore IP addresses   Given a string containing only digits, restore it by returning all possible valid IP addresses combinations.

		|-- Reverse Linked List    注意头部为空的判断

		|-- Same Tree    Determine whether two binary trees are the same or not?

		|-- Subsets      Given a collection of integers that might contain duplicates, return all possible subsets
							Given a set of distinct integers, return all possible subsets

		|-- Surrounded Regions  Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'. A region is captured by flipping all 'O's into 'X's in that surrounded region.

		|-- Symmetric Tree  Given a binary tree, check whether it is a mirror of itself

		|-- Triangle   Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

		|-- Unique binary search tree   Given n, how many structurally unique BST's that store values 1 ... n   Hint:dp

		|-- Unique binary search tree    Given n, print all the unique binary search trees

		|-- Valid Palindrome    Given a string, determine whether it is a palindrome, considering only alphanumeric characters and ingoring cases    Hint : Palindrome a pointer from left, another pointer from right

		|-- validate binary search tree     Hint : recursion, two args min and max to distinguish that whether the value of root is less than the max and more than the min

		|-- Best Time Buy and Sell   Given an array for which the ith element is the price of a given stock on day i. If you were permitted to complete at most one trasaction(buy one and sell one), design an algorithm to find the maximum profit

		|-- palindrome Partition   Given a string s, partition s such that every substring of the partition is a palindrome. return all possible palindrome partitioning of s

		|-- Palindrom Partition   Given a string s, partition s such that every substring of the partition is a palindrom. Return the minimum cuts needed for a palindrome partition.

		|-- Scramble String       Given a string s1, we may represent is has a binary tree by partitioning it to two non-empty Substring recursively.  Given two strings s1 and s2, determine if s2 is a scramble string of s1.  
		Hint : 用递归的方式分别计算左右子树

		|-- sumRootLeaf     Given a binary tree containing digits from 0-9 only, each root-to-leaf cloud represent a number.    Hint: 深度遍历

		|-- wordLadderII    Given two words(start and end), and a dictionary, find all shortest transformation sequence from start to end.       Hint: 海明距离

		|-- Anagrams    Given an array of Strings, return all groups of strings that are anagrams

		|-- Climbing Stairs  爬楼梯  Hint : fibonnaci

#		|-- Combination Sum 2     Given a set of candidate numbers C and a target number T , find all unique combinations in C where the candidate numbers sums to T.  The same repeated number may be chosen from C unlimited number of times    Hint: DFS
			Another would be the same number can not be chosen unlimited times

		|--  count and say     The count-and-say sequence  1 => 11 (one 1)   11 => 21 (two 1)  21 => 1211(one 2 two 1)    Given an integer n and generate the nth sequence

#		|-- first missing positive    Given an unsorted array, find the first missing positive integer  O(n) and constant space

		|-- Longest Valid Parenttheses   Given a string containing just the characters '(' and ')', find the length of the longest valid (well formed) parentheses substring.      摩根士丹利的面试题

#		|-- Next Permutation   

		|-- search Insert Position   given a sorted array and a target number, return the index if the target is found , If not, return the index where is would be inserted in order

		|-- Search for a Range   Given a sorted array of integers, find the starting and the ending position of a given target value   Hint: 二分, 拓展 找到后继续向左右分别找

		|-- search in rotated sorted array   Suppose a sorted array is rotated at some pivot unknown to you beforehand. You are given a target to search    Hint: 剑指offer

		|-- Substring with Concatenation of All Words    Given a string S and a list of words L, that are all the same length. Find all starting indices of substring(s) in S that is a concatenation(连接) of each word in L exactly once and without any intervening characters  



递归的体会：

	1. 先弄清递归的顺序. 在递归的实现中, 往往需要假设后续的调用已经完成, 在此基础上, 才实现递归逻辑。

	2. 分析递归逻辑体的逻辑, 然后写出来

	3. 考虑递归退出的边界条件