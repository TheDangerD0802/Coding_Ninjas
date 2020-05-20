#include<bits/stdc++.h>
using namespace std;

//Build-Tree Function
void buildTree(int *a, int *tree, int index,int s, int e)
{
	//Corner-Case
	if(s>e){
		return;
	}
	if(s==e)
	{
		tree[index] = a[s];
		return;
	}
	//Recursive-Case
	int mid = (s+e)/2;
	buildTree(a,tree,2*index,s,mid);
	buildTree(a,tree,2*index+1,mid+1,e);
	
	tree[index] = min(tree[2*index],tree[2*index+1]);
	return;
}
void update_tree(int* tree,int* lazy,int low,int high,int startR,int endR,int currPos,int inc){

	if(lazy[currPos] !=0)
{
	tree[currPos] += (high - low +1)*lazy[currPos];
	if(low!=high)
	{
		lazy[currPos*2]+= lazy[currPos];	
		lazy[currPos*2+1] += lazy[currPos];
	}
	lazy[currPos] = 0;
}

if(low > high || low > endR || high < startR )
return;
if(low >= startR && high <= endR)
{
	tree[currPos] += (high - low + 1)*inc;
	if(low != high)
	{
		lazy[currPos*2] += lazy[currPos];
		lazy[currPos*2+1] += lazy[currPos*2];
	}
	return;
}
int mid = (low+high)>>1;
update_tree(tree,lazy,currPos*2,low,mid,startR,endR,inc);
update_tree(tree,lazy,currPos*2+1,mid+1,high,startR,endR,inc);
tree[currPos] = tree[currPos*2] + tree[currPos*2 + 1];


}


int query( int *tree, int index,int s,int e, int qs, int qe){
	//1.Complete Overlap
	
	if(s>=qs && e<=qe){
		return tree[index];
	}
	
	//No Overlap
	
	if(qe<s || qs>e){
		return INT_MAX;
	}
	 //Partial Overlap
	 
	 int mid = (s+e)/2;
	 int left = query(tree,2*index,s,mid,qs,qe);
	 int right = query(tree,2*index+1,mid+1,e,qs,qe);
	  return min(left,right);
}

//Update Node
void updateNode(int *tree,int index,int s,int e,int i,int inc){
		//Out of Bounds
		if(i<s ||i>e){
			return;
		}
		//Leaf Node
		if(s==e){
			tree[index] += inc;
			return;
		}
		//Rec Case
		int mid = (s+e)/2;
		updateNode(tree,2*index,s,mid,i,inc);
		updateNode(tree,2*index+1,mid+1,e,i,inc);
		tree[index] = min(tree[2*index],tree[2*index+1]);
		return;
}

//Update Range
void updateRange(int *tree,int index,int s,int e,int rs,int re,int inc){
		//Out of Bounds
		if(re<s || rs>e){
			return;
		}
		//Leaf nodes
		if(s==e){
			tree[index] += inc;
			return;
		}

		//Rec Case
		int mid = (s+e)/2;
		updateRange(tree,2*index,s,mid,rs,re,inc);
		updateRange(tree,2*index+1,mid+1,e,rs,re,inc);
		tree[index] = min(tree[2*index],tree[2*index+1]);
		return;

}

int main()
{
	int a[] = {2,-3,1,0,5};
	int n = sizeof(a)/sizeof(int);
	
	/*For a segment Tree we do implementation 
	by creating array of 4*n + 1 size , since this array size is calculated
	by a function 2*2^k + 5 where k = [log N base 2].
	*/
	int *tree = new int[16];
	int index= 1;
	int s = 0;
	int e = n-1;
	int *lazy = new int[16];
	buildTree(a,tree,index,s,e);
	
	for(int i=1;i<=9;i++)
	cout<<tree[i]<<" ";
	cout<<endl;
	
	//int qs , qe;
	//cin>>qs>>qe;
	
	/*updateNode(tree,1,0,n-1,1,10);
	for(int i=1;i<=9;i++)
	cout<<tree[i]<<" ";
	cout<<endl;
	updateRange(tree,1,0,n-1,1,3,10);
	for(int i=1;i<=9;i++)
	cout<<tree[i]<<" ";
	cout<<endl;*/
	update_tree(tree,lazy,0,n-1,1,3,1,10);
	for(int i=1;i<=9;i++)
	cout<<lazy[i]<<" ";
	cout<<endl;
	for(int i=1;i<=9;i++)
	cout<<tree[i]<<endl;
	//cout<<query(tree,1,0,n-1,qs,qe)<<endl;
	
	
}
