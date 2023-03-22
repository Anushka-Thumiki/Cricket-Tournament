#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define PR_SIZE 20
#define SIZE 50

struct player
{
	char player_name[SIZE];
	int player_id;
	int match_id;
	int previous_total_score;
	float previous_avg;
	int previous_total_wickets;
	float previous_wicket_avg;
	int total_runs_in_last_five_matches;
	int total_wickets_in_last_five_matches;
	int century;
	int present_match_score;
	int present_match_wicket;
	char player_role[PR_SIZE];
	char out_or_not[3];
};

struct team
{
	struct player p[15];
};

struct match_played
{
	int match_id;
	int teams_played[2];
	int highest_run;
	char name_highest_run[SIZE];
	char man_of_the_match[SIZE];
	int wicket_taken_by_pacer;
	int match_result;
};

struct max_run
{
	int run;
	char name[SIZE];
};

struct player_role
{
	char name[SIZE];
	int id;
	int score;
	float avg;
};

//Question 1
void form_team(struct team t[SIZE],int n)
{
	int i,j,k;
	printf("Enter team id:");
	scanf("%d",&k);
	
	struct player_role batsmen[SIZE];
	struct player_role bowler[SIZE];
	struct player_role all_rounder[SIZE];
	int num1=0,num2=0,num3=0;
	
	for (i = 0; i < n; i++)
	{
		if (strcmp(t[k].p[i].player_role,"batsman") == 0)
		{
			strcpy(batsmen[num1].name,t[k].p[i].player_name);
			
			batsmen[num1].id = t[k].p[i].player_id;
			
			batsmen[num1].score = t[k].p[i].previous_total_score;
			
			batsmen[num1].avg = t[k].p[i].previous_avg;
			
			num1++;
		}
		else if ((strcmp(t[k].p[i].player_role,"bowler-pacer") == 0) || (strcmp(t[k].p[i].player_role,"bowler-spinner") == 0))
		{
			strcpy(bowler[num2].name,t[k].p[i].player_name);
			
			bowler[num2].id = t[k].p[i].player_id;
			
			bowler[num2].score = t[k].p[i].previous_total_wickets;
			
			bowler[num2].avg = t[k].p[i].previous_wicket_avg;
			
			num2++;
		}
		else
		{
			strcpy(all_rounder[num3].name,t[k].p[i].player_name);
			
			all_rounder[num3].id = t[k].p[i].player_id;
			
			all_rounder[num3].score = t[k].p[i].previous_total_wickets;
			
			all_rounder[num3].avg = t[k].p[i].previous_wicket_avg;
			
			num3++;
		}
	}
		
	char str[SIZE];
	int tmp;
	float temp;
	
	//batsmen
	for (i = 0; i < num1-1; i++)
	{
		for (j = 0; j < num1-1-i; j++)
		{
			if (batsmen[j].score < batsmen[j+1].score)
			{
				strcpy(str,batsmen[j].name);
			    strcpy(batsmen[j].name,batsmen[j+1].name);
			    strcpy(batsmen[j+1].name,str);
			    
			    tmp = batsmen[j].id;
			    batsmen[j].id = batsmen[j+1].id;
			    batsmen[j+1].id = tmp;
			    
			    tmp = batsmen[j].score;
			    batsmen[j].score = batsmen[j+1].score;
			    batsmen[j+1].score = tmp;
			    
			    temp = batsmen[j].avg;
			    batsmen[j].avg = batsmen[j+1].avg;
			    batsmen[j+1].avg = temp;
			}
			else if ((batsmen[j].score == batsmen[j+1].score) && (batsmen[j].avg < batsmen[j+1].avg))
			{
				strcpy(str,batsmen[j].name);
			    strcpy(batsmen[j].name,batsmen[j+1].name);
			    strcpy(batsmen[j+1].name,str);
			    
			    tmp = batsmen[j].id;
			    batsmen[j].id = batsmen[j+1].id;
			    batsmen[j+1].id = tmp;
			    
			    temp = batsmen[j].avg;
			    batsmen[j].avg = batsmen[j+1].avg;
			    batsmen[j+1].avg = temp;
			}
		}
	}
	
	//bowler
	for (i = 0; i < num2-1; i++)
	{
		for (j = 0; j < num2-1-i; j++)
		{
			if (bowler[j].score < bowler[j+1].score)
			{
				strcpy(str,bowler[j].name);
			    strcpy(bowler[j].name,bowler[j+1].name);
			    strcpy(bowler[j+1].name,str);
			    
			    tmp = bowler[j].id;
			    bowler[j].id = bowler[j+1].id;
			    bowler[j+1].id = tmp;
			    
			    tmp = bowler[j].score;
			    bowler[j].score = bowler[j+1].score;
			    bowler[j+1].score = tmp;
			    
			    temp = bowler[j].avg;
			    bowler[j].avg = bowler[j+1].avg;
			    bowler[j+1].avg = temp;
			}
			else if ((bowler[j].score == bowler[j+1].score) && (bowler[j].avg < bowler[j+1].avg))
			{
				strcpy(str,bowler[j].name);
			    strcpy(bowler[j].name,bowler[j+1].name);
			    strcpy(bowler[j+1].name,str);
			    
			    tmp = bowler[j].id;
			    bowler[j].id = bowler[j+1].id;
			    bowler[j+1].id = tmp;
			    
			    temp = bowler[j].avg;
			    bowler[j].avg = bowler[j+1].avg;
			    bowler[j+1].avg = temp;
			}
		}
	}
	
	//all-rounder
	for (i = 0; i < num3-1; i++)
	{
		for (j = 0; j < num3-1-i; j++)
		{
			if (all_rounder[j].score < all_rounder[j+1].score)
			{
				strcpy(str,all_rounder[j].name);
			    strcpy(all_rounder[j].name,all_rounder[j+1].name);
			    strcpy(all_rounder[j+1].name,str);
			    
			    tmp = all_rounder[j].id;
			    all_rounder[j].id = all_rounder[j+1].id;
			    all_rounder[j+1].id = tmp;
			    
			    tmp = all_rounder[j].score;
			    all_rounder[j].score = all_rounder[j+1].score;
			    all_rounder[j+1].score = tmp;
			    
			    temp = all_rounder[j].avg;
			    all_rounder[j].avg = all_rounder[j+1].avg;
			    all_rounder[j+1].avg = temp;
			}
			else if ((all_rounder[j].score == all_rounder[j+1].score) && (all_rounder[j].avg < all_rounder[j+1].avg))
			{
				strcpy(str,all_rounder[j].name);
			    strcpy(all_rounder[j].name,all_rounder[j+1].name);
			    strcpy(all_rounder[j+1].name,str);
			    
			    tmp = all_rounder[j].id;
			    all_rounder[j].id = all_rounder[j+1].id;
			    all_rounder[j+1].id = tmp;
			    
			    temp = all_rounder[j].avg;
			    all_rounder[j].avg = all_rounder[j+1].avg;
			    all_rounder[j+1].avg = temp;
			}
		}
	}
	for (i = 0; i < 5; i++)
	{
		printf("Player name : %s\n",batsmen[i].name);
		printf("Player id : %d\n",batsmen[i].id);
		printf("Player role: Batsman\n\n");
	}
	for (i = 0; i < 4; i++)
	{
		printf("Player name : %s\n",bowler[i].name);
		printf("Player id : %d\n",bowler[i].id);
		printf("Player role: Bowler\n\n");
	}
	for (i = 0; i < 2; i++)
	{
		printf("Player name : %s\n",all_rounder[i].name);
		printf("Player id : %d\n",all_rounder[i].id);
		printf("Player role: All rounder\n\n");
	}
}

//Question 2
void run_getter(struct match_played m[SIZE],int n)
{
	int i,j,tmp;
	struct max_run h[SIZE];
	for (i = 0; i < n; i++)
	{
		h[i].run = m[i].highest_run;
		strcpy(h[i].name,m[i].name_highest_run);
	}
	char str[SIZE];
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-1-i; j++)
		{
			if (h[j].run < h[j+1].run)
			{
				tmp = h[j].run;
				h[j].run = h[j+1].run;
				h[j+1].run = tmp;
				
				strcpy(str,h[j].name);
				strcpy(h[j].name,h[j+1].name);
				strcpy(h[j+1].name,str);
			}
			else if ((h[j].run == h[j+1].run) && (strcmpi(h[j].name,h[j+1].name) > 0))
			{
				strcpy(str,h[j].name);
				strcpy(h[j].name,h[j+1].name);
				strcpy(h[j+1].name,str);
			}
		}
	}
	tmp = h[0].run;
	i = 0;
	printf("Highest run = %d\n",tmp);
	while (h[i].run == tmp)
	{
		printf("%s\n",h[i].name);
		i++;
	}
}

//Question 3
void man_of_the_match(struct match_played m[SIZE],int n)
{
	int i,j;
	char var[SIZE][SIZE];
	for (i = 0; i < n; i++)
	{
		strcpy(var[i],m[i].man_of_the_match);
	}
	char str[10][SIZE];
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-1-i; j++)
		{
			if (strcmp(var[j],var[j+1]) > 0)
			{
				strcpy(str[0],var[j]);
				strcpy(var[j],var[j+1]);
				strcpy(var[j+1],str[0]);
			}
		}
	}
	int num,max=0;
	i = 0;
	while (i < n)
	{
		j = i;
		int count = 0;
		while (j<n && strcmp(var[j],var[j+1])==0)
		{
			j++;
			count++;
		}
	    if (count > max)
	    {
	    	max = count;
	    	strcpy(str[0],var[j]);
	    	num=1;
		}
		else if (count == max)
		{
			strcpy(str[num],var[j]);
			num++;
		}
		i = j+1;
	}
	i = 0;
	printf("Man of the match:\n");
	while (str[i][0] != '\0')
	{
		printf("\nName = %s",str[i]);
		printf("\nCount = %d\n",max);
		i++;
	}	
}

//Question 4
void check(struct match_played m[SIZE],int n)
{
	int i,j,tmp;
	struct max_run h[SIZE];
	for (i = 0; i < n; i++)
	{
		h[i].run = m[i].highest_run;
		strcpy(h[i].name,m[i].name_highest_run);
	}
	char str[SIZE];
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-1-i; j++)
		{
			if (h[j].run < h[j+1].run)
			{
				tmp = h[j].run;
				h[j].run = h[j+1].run;
				h[j+1].run = tmp;
				
				strcpy(str,h[j].name);
				strcpy(h[j].name,h[j+1].name);
				strcpy(h[j+1].name,str);
			}
			else if ((h[j].run == h[j+1].run) && (strcmpi(h[j].name,h[j+1].name) > 0))
			{
				strcpy(str,h[j].name);
				strcpy(h[j].name,h[j+1].name);
				strcpy(h[j+1].name,str);
			}
		}
	}
	tmp = h[0].run;
	i = 0;
	char arr1[10][SIZE];
	int c=0;
	while (h[i].run == tmp)
	{
		strcpy(arr1[c],h[i].name);
		c++;
		i++;
	}
	
	char var[SIZE][SIZE];
	for (i = 0; i < n; i++)
	{
		strcpy(var[i],m[i].man_of_the_match);
	}
	char st[10][SIZE];
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-1-i; j++)
		{
			if (strcmp(var[j],var[j+1]) > 0)
			{
				strcpy(st[0],var[j]);
				strcpy(var[j],var[j+1]);
				strcpy(var[j+1],st[0]);
			}
		}
	}
	int num,max=0;
	i = 0;
	while (i < n)
	{
		j = i;
		int count = 0;
		while (j<n && strcmp(var[j],var[j+1])==0)
		{
			j++;
			count++;
		}
	    if (count > max)
	    {
	    	max = count;
	    	strcpy(st[0],var[j]);
	    	num=1;
		}
		else if (count == max)
		{
			strcpy(st[num],var[j]);
			num++;
		}
		i = j+1;
	}
	i = 0;
	char arr2[10][SIZE];
	c=0;
	while (st[i][0] != '\0')
	{
		strcpy(arr2[c],st[i]);
		c++;
		i++;
	}
	
	int flag=1;
	
	for(i=0;i<c && !flag;i++)
	{
		if(arr1[i]!=arr2[i])
		{
			flag=0;
		}
	}	
	
	if (flag==0)
	{
		printf("\nResults are not same.\n");
	}
	else
	{
		printf("\nResults are same.\n");
	}
	
}

//Question 5
void highest_avg(struct team t[SIZE],int n)
{
	float max_avg=0.0;
	int i,j,id;
	char name[SIZE];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (t[i].p[j].previous_avg > max_avg)
			{
				max_avg = t[i].p[j].previous_avg;
				id = t[i].p[j].player_id;
				strcpy(name,t[i].p[j].player_name);
			}
		}
	}
	printf("Highest average by an individual:\n");
	printf("Average = %.2f",max_avg);
	printf("Player_id = %d",id);
	printf("Name = %s",name);
}

//Question 6
void wickets_diff(struct team t[SIZE],int n)
{
	int i,j,sum1,sum2,diff;
	sum1 = sum2 = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 15; j++)
		{
			if (strcmpi(t[i].p[j].player_role,"bowler-pacer") == 0)
			{
				sum1 = sum1 + t[i].p[j].previous_total_wickets;
			}
			else if (strcmpi(t[i].p[j].player_role,"bowler-spinner") == 0)
			{
				sum2 = sum2 + t[i].p[j].previous_total_wickets;
			}
		}
	}
	diff = abs(sum1 - sum2);
	printf("Difference in total wickets taken between all pacers and spinners = %d",diff);
}

//Question 7
void mom_k(struct match_played m[SIZE],int n,int k)
{
	int i,j;
	char var[SIZE][SIZE];
	for (i = 0; i < n; i++)
	{
		strcpy(var[i],m[i].man_of_the_match);
	}
	char str[10][SIZE];
	for (i = 0; i < n-1; i++)
	{
		for (j = 0; j < n-1-i; j++)
		{
			if (strcmp(var[j],var[j+1]) > 0)
			{
				strcpy(str[0],var[j]);
				strcpy(var[j],var[j+1]);
				strcpy(var[j+1],str[0]);
			}
		}
	}
	i = 0;
	while (i < n)
	{
		j = i;
		int count = 0;
		while (j<n && strcmp(var[j],var[j+1])==0)
		{
			j++;
			count++;
		}
	    if (count >= k)
	    {
	    	printf("\nName = %s",var[j]);
	    	printf("\nCount = %d\n",count);
		}
		i = j+1;
	}
}

main()
{
	struct team t[SIZE];
	
	int N,i,j;
	printf("Enter number of teams:");
	scanf("%d",&N);
	
	for (i = 0; i < N; i++)
	{
		printf("\nTeam %d:\n",i+1);
		for (j = 0; j < 15; j++)
		{
			printf("Enter player %d details\n",j+1);
			
			printf("Enter player name:");
			scanf("%s",t[i].p[j].player_name);
			
			printf("Enter player id:");
			scanf("%d",&t[i].p[j].player_id);
			
			printf("Enter match id:");
			scanf("%d",&t[i].p[j].match_id);
			
			printf("Enter previous total score:");
			scanf("%d",&t[i].p[j].previous_total_score);
			
			printf("Enter previous average:");
			scanf("%f",&t[i].p[j].previous_avg);
			
			printf("Enter previous total wickets:");
			scanf("%d",&t[i].p[j].previous_total_wickets);
			
			printf("Enter previous wicket average:");
			scanf("%f",&t[i].p[j].previous_wicket_avg);
			
			printf("Enter total runs in last five matches:");
			scanf("%d",&t[i].p[j].total_runs_in_last_five_matches);
			
			printf("Enter total wickets in last five matches:");
			scanf("%d",&t[i].p[j].total_wickets_in_last_five_matches);
			
			printf("Enter total number of centuries:");
			scanf("%d",&t[i].p[j].century);
			
			printf("Enter present match score:");
			scanf("%d",&t[i].p[j].present_match_score);
			
			printf("Enter present match wicket:");
			scanf("%d",&t[i].p[j].present_match_wicket);
			
			printf("Enter player role(bastman/bowler-pacer/bowler-spinner/all-rounder):");
			scanf("%s",t[i].p[j].player_role);
			
			printf("Enter out or not out (Out/Not):");
			scanf("%s",t[i].p[j].out_or_not);
		}
		printf("\n");
	}
	
	struct match_played m[SIZE];
	int no_matches_played;
	no_matches_played = ((N*(N-2))/4) + 3;
	for (i = 0; i < no_matches_played; i++)
	{
		printf("Enter match id:");
		scanf("%d",&m[i].match_id);
		
		printf("Enter teams played:");
		scanf("%d %d",&m[i].teams_played[0],&m[i].teams_played[1]);
		
		printf("Enter highest run:");
		scanf("%d",&m[i].highest_run);
		
		printf("Enter name of player who scored highest run:");
		scanf("%s",m[i].name_highest_run);
		
		printf("Enter name of man of the match:");
		scanf("%s",m[i].man_of_the_match);
		
		printf("Enter wicket taken by pacer:");
		scanf("%d",&m[i].wicket_taken_by_pacer);
		
		printf("Enter team id of winning team or enter -1 for tie:");
		scanf("%d",&m[i].match_result);
	}
	
	form_team(t,N);
	
	run_getter(m,no_matches_played);
	
	man_of_the_match(m,no_matches_played);
	
	check(m,no_matches_played);
	
	highest_avg(t,N);
	
	wickets_diff(t,N);
	
	int k;
	printf("Enter k:");
	scanf("%d",&k);
	mom_k(m,N,k);
}
