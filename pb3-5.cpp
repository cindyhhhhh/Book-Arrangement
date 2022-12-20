#include <stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <stdint.h>
#include <iostream> 
#include <inttypes.h>
#include<string.h>
#include<vector>

using namespace std;

struct Pair
{
	long long x;
	long long y;
	long long time;
};

int main()
{
	long long n;
	int flag;
	cin >> n;
	vector<long long> book1;
	vector<long long> book2;
	vector<long long> book;
	vector<Pair> bookarrage1;
	vector<Pair> bookarrage2;
	vector<Pair> bookarrage;
	long long insert1 = 0;
	long long insert2 = 0;
	long long insert = 0;
	long long odd = 0;
	long long even = 1;
	long long temp;
	long long i;
	long long j;
	long long last1;
	long long last2;
	Pair k;

	long long temp0 = 0;
	long long index;
	long long index2;


	for(long long i = 0; i < n; i++)
	{
		cin >> temp;
		book1.push_back(temp);
		book2.push_back(temp);
		if(temp != 0)
		{
			temp0 += 1;
			index = i;
		}
	}

	cin >> flag;


	if(temp0 == 1)
	{
		book1[index] = book1[index]-1;
		k.x = index;
		k.y = -1;
		k.time = 1;
		bookarrage.push_back(k);
		if(book1[index] != 0)
		{
			if(index == n-1)
			{
				index2 = n-2;
			}
			else
			{
				index2 = index + 1;
			}
			k.x = index2;
			k.y = index;
			k.time = book1[index];
			bookarrage.push_back(k);
			insert += book1[index];
		}
	}

	else
	{
		//deal with 0 begin case
		while(odd < book1.size() && even < book1.size())
		{
			if(book1[odd] == 0 && book1[even] == 0)
			{
				odd += 2;
				even += 2;
			}
			else if(book1[odd] == 0 && book1[even] != 0)
			{
				odd += 2;
				break;
			}
			else
			{
				break;
			}
		}


		//deal with last 0 case
		while(true)
		{
			if(book1[book1.size()-1] == 0)
			{
				book1.pop_back();
				book2.pop_back();
			}
			else
			{
				break;
			}
		}

		//deal with 0
		for(long long i = min(odd, even); i < book1.size(); i++)
		{
			if(book1[i] == 0)
			{
				book1[i] += 1;
				book2[i] += 1;
				insert1 += 1;
				insert2 += 1;
			}
		}


		if(odd <= even)
		{
			i = odd;
			j = even;
		}
		else
		{
			i = even;
			j = odd;
		}

		book = book1;
		bookarrage = bookarrage1;
		insert = insert1;

		if(book[j] > book[i])
		{
			book[j] = book[j]-1;
			k.x = j;
			k.y = -1;
			k.time = 1;
			bookarrage.push_back(k);
		}


		while(true)
		{
			if(i >= book.size()-2 && j >= book.size()-2)
			{
				break;
			}
			if(book[i] != 0)
			{

				if(i == k.y)
				{
					k.x = j;
					k.y = -1;
					k.time = 1;
					bookarrage.push_back(k);
					book[j] -= 1;
				}

				k.x = i;
				k.y = j;
				k.time = book[i];
				bookarrage.push_back(k);
				if(book[i]>=book[j])
				{
					insert += book[i] - book[j];
					book[j] = 0;
				}
				else
				{
					book[j] = book[j] - book[i];
				}
				book[i] = 0;
				i += 2;
			}
			else
			{
				i += 2;
			}

			if(i >= book.size()-2 && j >= book.size()-2)
			{
				break;
			}

			if(book[j] != 0)
			{
				if(j == k.y)
				{
					k.x = i;
					k.y = -1;
					k.time = 1;
					bookarrage.push_back(k);
					book[i] -= 1;
				}
				

				k.x = j;
				k.y = i;
				k.time = book[j];
				bookarrage.push_back(k);
				if(book[j]>=book[i])
				{
					insert += book[j] - book[i];
					book[i] = 0;
				}
				else
				{
					book[i] = book[i] - book[j];
				}
				book[j] = 0;
				j += 2;
			}
			else
			{
				j += 2;
			}
		}



		if(i > j)
		{
			last1 = i;
			last2 = j;
		}
		else
		{
			last1 = j;
			last2 = i;
		}
		
		if(k.y == last2)
		{
			k.x = last1;
			k.y = -1;
			k.time = 1;
			bookarrage.push_back(k);
			book[last1] -= 1;
		}

		if(book[last1]!=0 || book[last2]!=0)
		{
			if(book[last1] >= book[last2])
			{
				k.x = last2;
				k.y = last1;
				k.time = book[last1];
				bookarrage.push_back(k);
				insert += book[last1]-book[last2];
			}
			else if(book[last1] == 0 && book[last2] == 1)
			{
				k.x = last2;
				k.y = -1;
				k.time = 1;
				bookarrage.push_back(k);
			}
			else
			{
				k.x = last2;
				k.y = last1;
				k.time = book[last2]-1;
				bookarrage.push_back(k);
				insert += book[last2]-1-book[last1];

				k.x = last2;
				k.y = -1;
				k.time = 1;
				bookarrage.push_back(k);
			}
		}

		bookarrage1 = bookarrage;
		insert1 = insert;


		if(odd <= even)
		{
			i = odd;
			j = even;
		}
		else
		{
			i = even;
			j = odd;
		}

		book = book2;
		bookarrage = bookarrage2;
		insert = insert2;

		// if(book[j] > book[i])
		// {
		// 	book[j] = book[j]-1;
		// 	k.x = j;
		// 	k.y = -1;
		// 	k.time = 1;
		// 	bookarrage.push_back(k);
		// }


		while(true)
		{
			if(i >= book.size()-2 && j >= book.size()-2)
			{
				break;
			}
			if(book[i] != 0)
			{

				if(i == k.y)
				{
					k.x = j;
					k.y = -1;
					k.time = 1;
					bookarrage.push_back(k);
					book[j] -= 1;
				}

				k.x = i;
				k.y = j;
				k.time = book[i];
				bookarrage.push_back(k);
				if(book[i]>=book[j])
				{
					insert += book[i] - book[j];
					book[j] = 0;
				}
				else
				{
					book[j] = book[j] - book[i];
				}
				book[i] = 0;
				i += 2;
			}
			else
			{
				i += 2;
			}

			if(i >= book.size()-2 && j >= book.size()-2)
			{
				break;
			}

			if(book[j] != 0)
			{
				if(j == k.y)
				{
					k.x = i;
					k.y = -1;
					k.time = 1;
					bookarrage.push_back(k);
					book[i] -= 1;
				}
				

				k.x = j;
				k.y = i;
				k.time = book[j];
				bookarrage.push_back(k);
				if(book[j]>=book[i])
				{
					insert += book[j] - book[i];
					book[i] = 0;
				}
				else
				{
					book[i] = book[i] - book[j];
				}
				book[j] = 0;
				j += 2;
			}
			else
			{
				j += 2;
			}
		}



		if(i > j)
		{
			last1 = i;
			last2 = j;
		}
		else
		{
			last1 = j;
			last2 = i;
		}
		
		if(k.y == last2)
		{
			k.x = last1;
			k.y = -1;
			k.time = 1;
			bookarrage.push_back(k);
			book[last1] -= 1;
		}

		if(book[last1]!=0 || book[last2]!=0)
		{
			if(book[last1] >= book[last2])
			{
				k.x = last2;
				k.y = last1;
				k.time = book[last1];
				bookarrage.push_back(k);
				insert += book[last1]-book[last2];
			}
			else if(book[last1] == 0 && book[last2] == 1)
			{
				k.x = last2;
				k.y = -1;
				k.time = 1;
				bookarrage.push_back(k);
			}
			else
			{
				k.x = last2;
				k.y = last1;
				k.time = book[last2]-1;
				bookarrage.push_back(k);
				insert += book[last2]-1-book[last1];

				k.x = last2;
				k.y = -1;
				k.time = 1;
				bookarrage.push_back(k);
			}
		}

		bookarrage2 = bookarrage;
		insert2 = insert;


		if(insert1 <= insert2)
		{
			insert = insert1;
			bookarrage = bookarrage1;
		}
		else
		{
			insert = insert2;
			bookarrage = bookarrage2;
		}
	}

	printf("%lld\n", insert);
	if(flag == 1)
	{
		for(long long i = 0; i < bookarrage.size(); i++)
		{
			if(bookarrage[i].y >= 0)
			{
				for(long long j = 0; j < bookarrage[i].time; j++)
				{
					printf("%lld ", bookarrage[i].x+1);
					printf("%lld ", bookarrage[i].y+1);
				}
			}
			else
			{
				printf("%lld ", bookarrage[i].x+1);
			}
		}
	}

	return 0;
}
