/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void inorder(TreeNode* root, vector<int>& nums){
        if(!root) return;

        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1;
        vector<int> nums2;
        inorder(root1, nums1);
        inorder(root2, nums2);

        vector<int> resu;
        int i = 0;
        int j = 0;
        while(i<nums1.size() && j<nums2.size()){
            int val1 = nums1[i];
            int val2 = nums2[j];
            if(val1 < val2){
                resu.push_back(val1);
                i++;
                continue;
            }

            if(val2 < val1){
                resu.push_back(val2);
                j++;
                continue;
            }

            if(val1 == val2){
                resu.push_back(val1);
                resu.push_back(val2);
                i++;
                j++;
                continue;
            }
        }

        while(i<nums1.size()) resu.push_back(nums1[i++]);
        while(j<nums2.size()) resu.push_back(nums2[j++]);
        
        return resu;
    }
};