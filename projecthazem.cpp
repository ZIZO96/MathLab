#include <iostream>
using namespace std;

// ANA 23ML EDIT FL MKAN ELY ANA 3YZO 

class DynamicFloats
{
	float* p;
	int s;

public :
	DynamicFloats();           //Constructor

	~DynamicFloats();         //Destructor

	void Add(float f);		// Add element f after the last element

	void SetSize(int news);	// Change the size to the news

	int GetSize();	 // Return the current size of the elements
	
	float GetEl(int i);		// Return element at location i

	void SetEl(int i, float f); 	// Change element at location i to value f

	void InsertAt(int i, float f); 	// Insert Element at location i (shift all element after it)

	void Print();			// Print all elements to screen in the formate {1.5,3.7,6.5}

	void RemoveAt(int i);		// Delete Element at location i (shift all element after it)

	void RemoveAll();		// Remove all elements

	int Find(float f);	// Return the index of element of value f (return -1 if not found)

	void RemoveDuplicates();	// Remove Duplicate elements

	void Sort();			// Sort All elements

	float Sum();			// Return the sum of all elements

	

	void Concatenate(DynamicFloats& d);  // Add a copy of all elements of d to the end of (this)

	void InsertAt(int i, DynamicFloats& d);  // Insert a copy of elements of d starting from location i
};







int main()
{
	/*float f = 3,c=5;
	float x;
	int y;
	DynamicFloats A;
	A.SetSize(1);
	A.SetEl(0, f);
	A.Add(c);
	A.Add(f);
	A.Add(c);
	A.Print();
	y = A.Find(c);
	cout << y << endl;
	y = A.GetSize();
	cout << y << endl;
	x = A.GetEl(3);
	cout << x << endl;
	A.SetEl(1, f);
	A.Print();
	y = A.Find(c);
	cout << y << endl;
	A.InsertAt(1, c);
	A.Print();
	A.Sort();
	A.Print();
	A.RemoveDuplicates();
	A.Print();
	*/
	DynamicFloats A,B;
	B.Add(3.5);
	B.Add(2.5);
	B.Add(1.0);
	A.Add(2.0);
	A.Add(2.5);
	B.InsertAt(1,A);
	B.Print();



    return 0;
}







DynamicFloats::DynamicFloats()
{
	p = NULL;
	s = 0;
}


DynamicFloats::~DynamicFloats()
{
	if (p != NULL && s != 0)
		delete[] p;

}


void DynamicFloats::SetSize(int news)
{
	if (s == 0)
	{
		s = news;
		p = new float[s];
		return;
	}

	float* t = new float[news];
	int m = s;

	if (s>news)
		m = news;
	for (int i = 0; i < m; i++)
		t[i] = p[i];
	delete[] p;
	p = t;
	s = news;

}


void DynamicFloats::Add(float f)
{
	SetSize(s + 1);
	p[s - 1] = f;
}


int DynamicFloats::GetSize()
{
	return s;
}


float DynamicFloats::GetEl(int i)
{
	return p[i];
}


void DynamicFloats::SetEl(int i, float f)
{
	p[i] = f;
}


void DynamicFloats::RemoveAt(int i)
{
	if (i == s - 1 && s>1)
		SetSize(s - 1);
	else if (s == 1 && i==0) {
		RemoveAll();
	}
	else
	{
		for (int j = i; j < s - 1; j++)
			p[j] = p[j + 1];
		SetSize(s - 1);
	}
	

}


void DynamicFloats::RemoveAll()
{
	if (p != NULL)
	{
		delete[] p;
		s = 0;
	}

}


int DynamicFloats::Find(float f)
{
	if (s == 0)
		return -1;
	for (int i = 0; i < s; i++)
	{
		if (p[i] == f)
			return i;
	}
	return -1 ;
}

 
 void DynamicFloats::InsertAt(int i, float f) 
 {

	 SetSize(s + 1);
	 for (int j = s-1; j > (s-i-2); j--)
		 p[j] = p[j - 1];
	 p[i] = f;


 }


 void DynamicFloats::Print()
 {
	 if (s == 0)
	 {
		 cout << "There is no elements to print in the array" << endl;
		 return;
	 }
		 cout << "{";
	 for (int i = 0; i < s; i++)
	 {
		 if (i == 0)
		 {
			 cout << p[i];
			 continue;
		 }
		 cout << "," << p[i] ;
	 }
		 cout << "}" << endl;
 }


 float DynamicFloats::Sum()
 {
	 if (s == 0) {
		 cout << "You should insert some elements into your array firstly" << endl;
			 return 0;
	 }
	 float sum=0;
	 for (int i = 0; i < s; i++)
		 sum += p[i];
	 return sum;
 }
 

 void DynamicFloats::RemoveDuplicates()
 {
	 if (s == 0 || s == 1)
		 return;
	 int i=0, j=0;
	 for (i = 0; i < s - 1; i++)
	 {
		 for (j = i + 1; j < s; j++)
		 {
			 if (p[j] == p[i])
			 {
				 RemoveAt(j);
				 j--;
			 }
		 }
	 }


 }


 void DynamicFloats::Sort()
 {
	 if (s == 0 || s == 1)
		 return;
	 for (int i = 0; i < s-1; i++)
	 {
		 float currentMin = p[i];
		 int currentMinIndex = i;

		 for (int j = i + 1; j < s; j++)
		 {
			 if (currentMin > p[j])
			 {
				 currentMin = p[j];
				 currentMinIndex = j;
			 }
		 }

		 if (currentMinIndex != i) {
			 p[currentMinIndex] = p[i];
			 p[i] = currentMin;

		 }
	 }
 }


 void DynamicFloats::Concatenate(DynamicFloats& d)
 {
	 if (s == 0)
	 {
		 SetSize(d.s);
		 for (int i = 0; i < d.s; i++)
			 p[i] = d.GetEl(i);
		 return;
	 }
	 SetSize(s + (d.s));
	 int i, j = 0;
	 for (i = (s-(d.s)); i <s; i++)
	 {
		 p[i] = d.p[j];
		 j++;
	 }
 }


 void DynamicFloats::InsertAt(int i, DynamicFloats& d)
 {
	 int k = s - 1;
	 SetSize(s+(d.s));
	 for (int j = (s - 1); j > ((d.s)+i-1); j--)
	 {
		 p[j] = p[k];
		 k--;
	 }
	 k = 0;
	 for (int j = i; j < (i+(d.s)); j++)
	 {
		 p[j] = d.p[k];
		 k++;
	 }

 }
