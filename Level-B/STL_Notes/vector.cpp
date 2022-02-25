#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>

#include<sstream>

using namespace std;

#define all(v) ((v).begin()),((v).end())
#define sz(v)  ((int)((v).size()))

typedef vector<int>::iterator vecIt;
typedef vector<int> vi;

// ############# Vector utilities 
void printVec(vector<int> v2, string s = "")
{
	cout << s;
	for (int i = 0; i < (int)v2.size(); ++i)
		cout << v2[i] << " ";
	cout << "\n";
}

bool isOdd(int n) { return n % 2 != 0; }

bool isEqual(int a, int b) { return abs(a - b) < 2; }

void vectorManipulation() {

	// fill v1 with certain portion from v2 -> starting with 2nd index till fourth index index 
	const int lenght = 10;
	int array[lenght] = { 4, 2, 3, 2, 9, 2, 17, 17, 17, 20 };
	vi v1(array, array + lenght);
	vi v2(v1.begin() + 2, v1.begin() + 5); // start included, end excluded
	printVec(v2, "V2: ");

	// Distance between 2 iterators = Equal to subtracting their iterators: E.g. it2 - it1	(where it2 is bigger)
	cout << "distance: " << distance(v2.begin(), v2.begin() + 3) << "\n";
	// cout << "distance: " << distance(v2.begin() + 4, v2.begin()) << "\n";

	// replace and replace_if
	vector<int> v3 = v2;	// copy v2 to another vector v3
	replace(all(v3), 2, 7); // replace 2's in v3 with 7's
	printVec(v3, "V3: ");
	replace_if(all(v3), isOdd, 15); // replace the odd numbers with 15 in v3
	printVec(v3, "V3: ");

	//search for 3 consecutive elements with value 17, returns pointer to the first  17 in 3 consecutives
	vecIt it = search_n(all(v1), 3, 17);
	if (it != v1.end())
		cout << "3 Consecutive 17s from index in v1: " << it - v1.begin() << "\n";

	it = search(all(v1), all(v2));			// search if v2 is subvector of v1  -> return iterator to first element of v1 in v2
	if (it != v1.end())
		cout << "sub-vector from index: " << it - v1.begin() << "\n";

	// unique/binary_search/lower_bound/upper_bound must applied on sorted array.
	int arr[] = { 4, 2, 3, 2, 9, 2, 17, 17, 17, 20 };
	vi v5(arr, arr + 10);
	sort(all(v5));

	// 1) binary_search returns 1 if it is found, 0 otherwise
	bool ans = binary_search(all(v5), 7);	//v2 must be sorted first - O(logn)
	cout << "Searching for 17: " << ans << "\n";

	// 2) lower_bound returns pointer to first element greater than or equal to a given element. 
	// if the given element is repeated multiple times, it will return pointer to its first occ.
	it = lower_bound(all(v5), 17);
	if (it != v5.end())
		cout << "First element >= 17 at index " << it - v5.begin() << "\n";

	// 3) upper_bound returns pointer to first element greater than a given element.
	it = upper_bound(all(v5), 17);
	if (it != v5.end())
		cout << "First element > 17 at index " << it - v5.begin() << "\n";

	// 4) unique returns iterator to last element of unique sorted array.
	// unique(all(v5));	// 2 2 2 3 4 17 17 17 20 => // 2 3 4 17 20 17 17 17 20 
	// printVec(v5, "Unique v5 : ");
	v5.resize(unique(all(v5)) - v5.begin());
	printVec(v5, "Removing duplicates: ");

	// set_intersection/set_difference/set_union/set_symmetric_difference  must applied on 	SORTED 	array.
	vi v6(arr, arr + 10);
	v5 = v6;
	v5.push_back(v6.back());
	v5.push_back(v6.back() + 20);
	v5.push_back(20);
	v5.push_back(v6.back() + 7);
	sort(all(v5));
	sort(all(v6));
	printVec(v5, "V5 : ");
	printVec(v6, "V6 : ");

	// 1) set_intersection gets common elements between 2 vectors and push them in another vector
	vi v;
	set_intersection(all(v5),all(v6),back_inserter(v)); // if v1 and v2 has "a" repeated m times, then v will has "a" m times
	printVec(v, "set intersection : ");                // if v1 has "a" n times && v2 has "a" m times  -> v will have "a" repeated min(m,n) times.

	// 2) set_difference gets elements that are in first vector but not in second vector
	v.clear();
	set_difference(all(v5),all(v6),back_inserter(v));
	printVec(v, "set difference : "); // if v1 has "a" n times && v2 has "a" m times  -> v will have "a" repeated n-m times.

	// 3) union 2 vectors
	v.clear();
	set_union(all(v5), all(v6), back_inserter(v));
	printVec(v, "set_union: "); // if v1 has "a" n times && v2 has "a" m times  -> v will have "a" repeated max(m,n) times.

	// Get maximum and minumum values in v2
	printVec(v2, "V2 : ");
	int mx = *max_element(v2.begin(), v2.end());
	int mn = *min_element(v2.begin(), v2.end());
	cout << "Maximum: " << mx << " minimum " << mn << "\n";

	// Swap range in v2 with another range in v1 ( begin r1, end r1, begin r2)
	printVec(v2, "V2 : ");
	printVec(v1, "V1 : ");
	swap_ranges(v2.end() - 2, v2.end(), v1.begin()); // swap last 2 numbers in v2 with first 2 numbers in v1
	printVec(v2, "Range swaps ");
	printVec(v1, "Range swaps ");

	// accumulate
	v2.clear();
	v2.push_back(1);
	v2.push_back(3);
	v2.push_back(4);
	printVec(v2, "Accummulate \nNew v2: ");
	int vecSum = accumulate(all(v2), 0); 						// return array SUM
	int vecMul = accumulate(all(v2), 1, multiplies<int>()); 	// return array product

	int sumOfProducts1 = inner_product(all(v2), v2.begin(), 0);			 						// inner product: V1[0] * V1[0] + V2[0]*v2[0]...
	int sumOfProducts2 = inner_product(all(v2), v2.begin(), 0, plus<int>(), multiplies<int>()); // same as above
	int productsOfSum = inner_product(all(v2), v2.begin(), 1, multiplies<int>(), plus<int>()); // 1 * (V1[0] + V1[0]) * (V2[0] + v2[0])
	// 0, 1, 0 are the initial value for accumulation

	cout << "vecSum: " << vecSum << " vecMul: " << vecMul << " sumOfProducts: " << sumOfProducts1 << " productsOfSum:" << productsOfSum << "\n";

	// partial_sum insert at back of v1, at index i we have summation of ith element and all elements before it in vector
	v1.clear();
	partial_sum(all(v2), back_inserter(v1));
	printVec(v1, "Accumulative array: ");

	v1.clear();
	partial_sum(all(v2), back_inserter(v1), minus<int>()); // we could define the operation also as minus instead if summing all pervious elements we could subtract them 
	printVec(v1, "Subtracting array: ");

	// writing to a stream
	ostringstream oss1;
	partial_sum(all(v2), ostream_iterator<int>(oss1, " ")); // instead of back insert to vector, We could write to stream
	cout << "Accumulative array in string: " << oss1.str() << "\n";			// 27 68 149 the partial accumulatation

	cout << "adjacent_difference\n";
	printVec(v1, "V1 : ");
	printVec(v2, "V2 : ");
	adjacent_difference(all(v2), v1.begin()); // subtract each element in v2 from element before it except for first element and puts result in v1
	printVec(v1, "adjacent_difference ");    //v1.begin() here doesn't add elements at begin with pushing the existing ones forward but it replaces them with result

	adjacent_difference(all(v2), v1.begin(), plus <int>()); // add each element in v2 from element before it except for first element and puts result in v1
	printVec(v1, "adjacent_sum ");

	it = adjacent_find(all(v2), isEqual);	//find first 2 adjacent elements who are EQUAL based on equal function
	if (it != v2.end())
		cout << "The 2 adjacent values are: " << *it << " " << *(it + 1) << "\n";

	// insert element at given iterator pointer position
	v2.insert(v2.begin(), 6);
	v2.insert(v2.begin() + 3, 6);
	v2.push_back(6);

	printVec(v2, "V2: ");

	cout << "Count of 6: " << count(all(v2), 6) << "\n";
	count_if(all(v2), isOdd);	// isOdd is a function called for each element in v2

	// remove -> removes all elements which are equal to val and returns an iterator to the new end of that range.
	// remove(all(v2), 6); // forwards the non-removed elements at front
	// printVec(v2, "V2:");

	v2.erase(remove(all(v2), 6), v2.end());	// remove all 6, and preserve order
	printVec(v2, "Remove 6s: ");

	v5 = v6;
	printVec(v5, "V5: before rotation: ");
	rotate(v5.begin(), v5.begin() + 3, v5.end()); 	// (first,middle,last) -> after rotation middle becomes first element -> vector becomes [middle , last][first,middle-1]
	printVec(v5, "V5: after rotation: ");

	//In case listing all next_permutation, you must SORT input first
	sort(all(v2));
	do {
		printVec(v2, "Perm: ");
	} while (next_permutation(all(v2)));	// permutate on any given iterator with compare function 
}

void vectorBasics() {
	vi v(10);			// create vector of size = 10
	vi v1(10, 7);		// create vector of size 10 and elements = 7

	// copy array elements to a vector
	const int len = 6;
	int arr[len] = { 5, 2, 7, 2, 0, 2 };
	vi v2(arr, arr + len);
	printVec(v2, "v2 :");

	// front and back operations (They are by reference same as accessing v[0])
	cout << "Front: " << v2.front() << " last element: " << v2.back() << "\n";
	swap(v2.front(), v2.back());	// back is by reference
	printVec(v2, "swap: ");

	// copy from vector to vector
	vi v3(v1.begin(), v1.end());

	// resize vector
	v.resize(15);

	// What about iterating on vector, Either as in array or using iterators
	for (int i = 0; i < (int)v2.size(); ++i)	// watch out: v.size() return unsigned. Return v.size()-1 may cause problems. Cast to int
		cout << v2[i] << " ";
	cout << "\n";

	// Another way:
	vi::iterator it = v2.begin();
	while (it != v2.end())
	{
		cout << (*it) << " ";		// * works so similar to pointers.
		++it;					// Move to next time
	}
	cout << "\n";

	// Sorting the vector
	sort(v2.begin(), v2.end());		// what if sorting all elements, except 1st 2: 	sort(v2.begin()+2, v2.end());
	printVec(v2, "sorted: ");

	// Sorting decreasing
	sort(v2.begin(), v2.end(), greater<int>());	// let greater first
	sort(v2.rbegin(), v2.rend());
	printVec(v2, "sorted reversed: ");

	// Creating 2D vector of boolean
	vector< vector<bool> > vbs(10, vector<bool>(20, true));	// create array 10 * 20 filled with trues

	// Comparing 2 vectors
	if (v1 < v2)	// same <=, ==, >
		cout << "v1 Smaller than v2\n";
	else
		cout << "v2 Smaller than v1\n";

	// Removing 2nd element
	v2.erase(v2.begin() + 1);				// O(n)
	printVec(v2, "erase 2th: ");

	// insert element at given location
	// 0 -> v2.begin() , 1 -> v2.begin()+1 , 2 -> v2.begin()+2 , 3 -> v2.begin()+3 (4th location)
	v2.insert(v2.begin() + 3, 14);		// O(n)
	printVec(v2, "insert 14 in 4th location: ");

	// push element at end of vector
	v2.push_back(20);
	printVec(v2, "add 20 in back: ");

	// Check if element in array
	if (find(all(v2), 7) != v2.end())	// find is O(n) , v2.end means pointer after last element
		cout << "7 in v2\n";
	if (find(all(v2), 9) == v2.end())
		cout << "9 is not in v2\n";

	// Removing value 7. If element not found, you can't call. Please check first
	v2.erase(find(all(v2), 7)); // remove element that given iterator is pointing to.
	printVec(v2, "after erasing 7 using find: ");

	reverse(all(v2));
	printVec(v2, "Reversed vector: ");

	random_shuffle(all(v2));		// shuffle randomly array numbers
	printVec(v2, "Shuffled vector: ");

	v2.pop_back();	// remove last in O(1)
	printVec(v2, "Last removed: ");

	v2.clear();
	printVec(v2, "Cleared vector: ");
}

int main() {

	cout << "// ============== vector operations ============== //\n";
	vectorBasics();

	// ============ vector manipulation ========= //
	cout << "// ============ vector manipulation ========= //\n";
	vectorManipulation();

	return 0;
}
