#include <iostream>
#include <vector>

using namespace std;

struct point
{
	int xVal;
	int yVal;
};

vector<point> createVectPoints()
{
	vector<point> setOfPoints;

	int numOfPoints = 0, i = 0;
	cout << "Enter the number of points: ";
	cin  >> numOfPoints;

	for(i = 0; i < numOfPoints; i++)
	{
		// Create a point and assign xVal and yVal
		point newPoint;
		setOfPoints.push_back(newPoint);
		setOfPoints[i].xVal = i + 1;

		cout << "Enter the value: ";
		cin >> setOfPoints[i].yVal;
	}

	//Printing the vector of points for debug purpose
	for(i = 0; i < numOfPoints; i++)
	{
		cout << "(" << setOfPoints[i].xVal << ", " << setOfPoints[i].yVal << "), " ; 
	}

	return setOfPoints;
}

vector<int> createAreaArray(vector<point> *setOfPoints)
{
	vector<point> *localSetOfPoints = setOfPoints;
	int i = 0, j = 0, tempxVal = 0, tempyVal = 0, arrSize, tempArea;
	//int area[numOfPoints][numOfPoints];
	//vector<int> **areaVect;
	vector<int> areaVect;
	vector<int> :: iterator itr3;

	vector<point> :: iterator itr1, itr2;
	//areaVect = new int*[setOfPoints->size()];
	cout << "sizeof(areaVect): " << sizeof(areaVect) << endl;
	//cout << "areaVect[0][0]:" << areaVect[0][0];

	/* Input prints fine, which means it was received okay within 
	for(itr1 = localSetOfPoints->begin(); itr1 != localSetOfPoints->end(); itr1++)
	{
		cout << itr1->xVal << " " << itr1->yVal << " ";
	}*/

	for(i = 0, itr1 = localSetOfPoints->begin(); /*i < localSetOfPoints->size()*/ itr1 != localSetOfPoints->end(); i++, itr1++)
	{
		//cout << "Printing inside first for loop:\n" << " ";
		//cout << itr1->xVal << " " << (itr1->xVal)-i-1 << " ";
		for(j = i + 1, itr2 = localSetOfPoints->begin()+1+i; /*j < setOfPoints->size()*/ itr2 != localSetOfPoints->end(); j++, itr2++)
		{
			//cout << "Printing inside 2nd for loop:\n" << " ";
		    //cout << itr1->xVal << " " << (itr1->xVal)-i-1 << " ";
			tempxVal = (itr2->xVal)-((itr1->xVal)); //(itr1->xVal)-i-1;?
			cout << "(itr2->xVal): " << (itr2->xVal) << " " ;
			cout << "(itr1->xVal): " << (itr1->xVal) << " " ;
			cout << "tempxVal: " << tempxVal << " " ;
			if(itr1->yVal > itr2->yVal)
			{
				tempyVal = itr2->yVal;
			}
			else
			{
				tempyVal = itr1->yVal;
			}
			//cout << "i: " << i << "j: " << j << endl;
			cout << "tempyVal: " << tempyVal << " " << endl;
			//cout << "tempxVal: " << tempxVal << " " << endl;
			tempArea = tempxVal * tempyVal;
			//cout << "tempArea: " << tempArea ;
			//cout << "tempArea" << tempArea << " " ;
			areaVect.push_back(tempArea);
			//*(*(areaVect + i) + j) = tempxVal * tempyVal;
			//*(*(areaVect + i) + j) = tempxVal * tempyVal;
			/*int tempArea;
			*areaVect->push_back(tempArea);*/
		}
	}
	for(itr3 = areaVect.begin(); itr3 != areaVect.end(); itr3++)
	{
		cout << *itr3 << endl;
	}
	return areaVect;
}

void main()
{
	vector<point> setOfPoints;
	vector<int> areaVect;
	vector<point> :: iterator itr2;
	vector<int> :: iterator itr1;

	setOfPoints = createVectPoints();
	/*for(itr2 = setOfPoints.begin(); itr2 != setOfPoints.end(); itr2++)
	{
		cout << "Printing:" ;
		cout << itr2->xVal << " " << itr2->yVal << " ";
	}*/

	areaVect = createAreaArray(&setOfPoints);
	
	/*for(itr1 = areaVect.begin(); itr1 != areaVect.end(); itr1++)
	{
		cout << "Printing areas: " ;
		cout << *itr1 << " " ;
	}
	cout << endl;
	*/
	while(1);
}