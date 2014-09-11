#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define pi 3.1415
#define NO_OF_BOTS 11

int compare(double one[], double two[], int len) // returns the smaller of the two
{
	int k=0;
	for(int i=0;i<len;i++)
	{
		
		if(one[i]<two[i])
		{
			k=1;
			break;
		}
		if(one[i]>two[i])
		{
			k=2;
			break;
		}
		
	}
	if(k==1)
		return 1;
	if(k==2)
		return 2;
	return 0;
}

bool is_lyndon_word(double angles[], int len) //here len is the number of robots
{
	//the rotations of the angles are stored in the 2D array gen
	double gen[len][len];
	int rotated_element_number[len], count=0, rotation;
	for(rotation=0; rotation<len; rotation++) 
	{
		for(int i=0; i<len; i++) 
		{
			rotated_element_number[i] = i + rotation;
			while(rotated_element_number[i] > (len-1))
				rotated_element_number[i] -= len;
			gen[count][i]=angles[rotated_element_number[i]];
		}
		count++;
	}		
	for (int i=0;i<len;i++)
	{
		for(int j=0;j<len;j++)
		{
			printf("%lf\t", gen[i][j]);
		}
		printf("\n");
	}

	double one[len], two[len];
	int smallest=0;

	int y=0;
	while(y<len)
	{
		for(int i=0;i<len;i++)
		{
			one[i]=gen[i][smallest];
			two[i]=gen[i][y];
		}
		int result=compare(one,two,4);
		if(result==2)
			smallest=y;
		y++;
	}
	smallest+=1;
	cout<<"\nsmallest is: "<<smallest<<"\n";
	if(smallest==1)
		return true;
	else
		return false;

}

int main() 
{
	int len=5;

	//This part will be executed in each bot...............................
	bool lws[len];
	int lws_count=0, n=-1, m=-1; int leader;
	for(int i=0;i<len;i++)
		lws[i]=false;
	for(int i=0;i<NO_OF_BOTS;i++)						//**len=NO_OF_BOTS is basically the number of bots, no of angles, the length of the word
	{
		double angles[len];
		double angles_cap[len];  //these are the two arrays wrt to the bot i. TO DO **
		if(is_lyndon_word(angles,len)==1 || is_lyndon_word(angles_cap,len)==1)
		{
			lws[i]=true;
		}
		for(int i=0;i<len;i++)
			if(lws[i]==true)
				lws_count++;

		if(lws_count==1)
		{
			//this bot is the leader
		}
		else if(lws_count==2)
		{
			for(int i=0;i<len;i++)
			{
				if(lws[i]==true)
				{
					if(m>n)
						n=i;
					else
						m=i;
				}
			}
		}
		else
			cout<<"super duper genorai!!!";
		if((m-n-1)%2!=0)
			leader=(m+n)/2;
		else
		{
			leader=n+(len-(m-n+1)/2)+1;
		}
	}

}