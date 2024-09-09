/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
	public:
		vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
			vector<vector<int>> mat(m,vector<int>(n,-1));
			ListNode* curr=head;
			int minr=0;
			int minc=0;
			int maxr=m-1;
			int maxc=n-1;
			while(curr!=NULL){
				for(int j=minc;j<=maxc && curr!=NULL;j++){
					int i=minr;
					mat[i][j]=curr->val;
					curr=curr->next;
				}
				minr++;
				for(int i=minr;i<=maxr && curr!=NULL;i++){
					int j=maxc;
					mat[i][j]=curr->val;
					curr=curr->next;
				}
				maxc--;
				for(int j=maxc;j>=minc && curr!=NULL;j--){
					int i=maxr;
					mat[i][j]=curr->val;
					curr=curr->next;
				}
				maxr--;
				for(int i=maxr;i>=minr && curr!=NULL;i--){
					int j=minc;
					mat[i][j]=curr->val;
					curr=curr->next;
				}
				minc++;
			}
			return mat;
		}
	};