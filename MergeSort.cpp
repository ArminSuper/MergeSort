#include<iostream>
using namespace std;

void MSort(int *a,int *TmpArray,int Left,int Right);
void MergeSort(int *a,int N);
void Merge(int *a, int *TmpArray,int Lpos,int Rpos,int RightEnd);


int main()
{
	int a[8] = {1,4,2,5,3,8,7,6};
	MergeSort(a,8);
	
	for(int i = 0; i < 8; i++)
		cout << a[i];
	cout <<endl;
	return 0; 
}

void MSort(int *a,int *TmpArray,int Left,int Right)
{
	int center;

	if(Left < Right)
	{
		center = (Left + Right) / 2;
		MSort(a,TmpArray,Left,center);
		MSort(a,TmpArray,center+1,Right);
		Merge(a,TmpArray,Left,center+1,Right);
	}
}

void MergeSort(int *a,int N)
{
	int *TmpArray;
	
	TmpArray = new int[N];
	if(TmpArray != NULL)
	{
		MSort(a,TmpArray,0,N-1);
		delete [] TmpArray;
	}
	else
		cout << "No Data?"<<endl;
}

void Merge(int *a,int *TmpArray,int Lpos,int Rpos,int RightEnd)
{
	int i,LeftEnd,NumElements,Tmpos;

	LeftEnd = Rpos - 1;
	Tmpos = Lpos;
	NumElements = RightEnd - Lpos + 1;

	while(Lpos <= LeftEnd && Rpos <= RightEnd)
	{
		if(a[Lpos] <= a[Rpos])
			TmpArray[Tmpos++] = a[Lpos++];
		else
			TmpArray[Tmpos++] = a[Rpos++];
	}

	while(Lpos <= LeftEnd)
		TmpArray[Tmpos++] = a[Lpos++];
	while(Rpos <= RightEnd)
		TmpArray[Tmpos++] = a[Rpos++];

	for(i = 0; i < NumElements; i++,RightEnd--)
		a[RightEnd] = TmpArray[RightEnd];
}
