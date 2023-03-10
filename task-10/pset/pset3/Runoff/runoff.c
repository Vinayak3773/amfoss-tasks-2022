#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

int preferences[MAX_VOTERS][MAX_CANDIDATES];

typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

candidate candidates[MAX_CANDIDATES];

int voter_count;
int candidate_count;

bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    for (int i = 0; i < voter_count; i++)
    {

        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    while (true)
    {
        tabulate();

        bool won = print_winner();
        if (won)
        {
            break;
        }

        int min = find_min();
        bool tie = is_tie(min);

        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        eliminate(min);

        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

bool vote(int voter, int rank, string name)
{
    for (int c = 0; c < candidate_count; c++)
    {
        if (strcmp(name, candidates[c].name) == 0)
        {
            preferences[voter][rank] = c;
            return true;
        }
    }
    return false;
}

void tabulate(void)
{
    for (int v = 0; v < voter_count; v++)
    {
        for (int r = 0; r < candidate_count; r++)
        {
            int c = preferences[v][r];
            if (candidates[c].eliminated == false)
            {
                candidates[c].votes++;
                break;
            }
        }
    }
}

bool print_winner(void)
{
    for (int c = 0; c < candidate_count; c++)
    {
        if (candidates[c].votes > (voter_count / 2))
        {
            printf("%s\n", candidates[c].name);
            return true;
        }
    }
    return false;
}

int find_min(void)
{
    int voteCount = voter_count;
    for (int c = 0; c < candidate_count; c++)
    {
        if (candidates[c].votes < voteCount && candidates[c].eliminated == false)
        {
            voteCount = candidates[c].votes;
        }
    }
    return voteCount;
}

bool is_tie(int min)
{
    int tieCount = 0;
    int onRun = 0;

    for (int c = 0; c < candidate_count; c++)
    {
        if (candidates[c].eliminated == false && candidates[c].votes == min)
        {
            tieCount++;
            onRun++;
        }
        else if (candidates[c].eliminated == false)
        {
            onRun++;
        }
    }
    if (tieCount == onRun)
    {
        return true;
    }
    return false;
}
void eliminate(int min)
{
    for (int c = 0; c < candidate_count; c++)
    {
        if (candidates[c].eliminated == false && candidates[c].votes == min)
        {
            candidates[c].eliminated = true;
        }
    }
}
